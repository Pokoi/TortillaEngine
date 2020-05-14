/*
 * File: Model.cpp
 * File Created: 11th February 2020
 * ––––––––––––––––––––––––
 * Author: Jesus Fermin, 'Pokoi', Villar  (hello@pokoidev.com)
 * ––––––––––––––––––––––––
 * MIT License
 *
 * Copyright (c) 2020 Pokoidev
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#define TINYOBJLOADER_IMPLEMENTATION

#include <Model.hpp>
#include <tiny_obj_loader.h> // For load the obj file

#include <Scaling.hpp>		// For Update transformations
#include <Rotation.hpp>		// For Update transformations
#include <Projection.hpp>	// For Update transformations
#include <Translation.hpp>	// For Update transformations

#include <Transform.hpp>    // For Transform

#include <View.hpp>

#include <glad.h>

#include <cmath>

namespace Rendering3D
{

    /**
    @brief Creates a instance of model
    @param mesh_path The path of the mesh
    */
	Model::Model(std::string mesh_path)
	{		

		/////////////////////////////////////////////////////////////////////////////////////
		// Code based in code snippet from tinyobjloader repository README 
		// https://github.com/syoyo/tinyobjloader/blob/master/README.md
		// Visited on: February 11th, 2020

		tinyobj::attrib_t attrib;
		std::vector<tinyobj::shape_t> shapes;
		std::vector<tinyobj::material_t> materials;

		std::string warn;
		std::string err;

        if (tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, mesh_path.c_str()))
        {

            std::vector<GLfloat> vertices   = attrib.vertices;
            std::vector<GLfloat> uv         = attrib.texcoords;
            std::vector<GLfloat> normals    = attrib.normals;
            std::vector<GLint>   indices;

            // This approach only supports one shape per model.
            // For more shapes you must do this process in a loop. Tortilla Engine is not prepared for that
            for (auto& index : shapes[0].mesh.indices)
            {
                indices.push_back(index.vertex_index);
            }

            // Vertex Array Object
            Vao vao;          

            vao.add_vertices (vertices.data(), vertices.size() * sizeof(GLfloat));
            vao.add_uvs      (uv.data()      , uv.size()       * sizeof(GLfloat));
            vao.add_normals  (normals.data() , normals.size()  * sizeof(GLfloat));
            vao.add_indices  (indices.data() , indices.size()  * sizeof(GLint));

            mesh = std::make_shared<Mesh>(vao, this);
        }
	}
  

    /**
    @brief Update the model
    @param delta The delta time
    @param view The view reference
    */
	void Model::Update(float delta, View & view)
	{
		transform->update_transform();
		
		// Apply camera transformations      
        transformation = view.get_camera().get_transform().get_inverse_transformation() * toolkit::Matrix44f(view.get_camera().get_projection()) * toolkit::Matrix44f(get_transform().get_transformation());
        
		// Transformation per vertex        
        for (size_t index = 0; index < original_vertices.size(); ++index)
        {
            toolkit::Point4f& vertex	= transformed_vertices[index]	= toolkit::Matrix44f(transformation) * toolkit::Matrix41f(original_vertices[index]);
            toolkit::Vector4f& normal	= transformed_normals[index]	= toolkit::Matrix44f(transformation) * toolkit::Matrix41f(original_normals[index]);

            // Normalize last value for perspective transformation
            float vertex_divisor = 1.f / vertex[3];

            vertex[0] *= vertex_divisor;
            vertex[1] *= vertex_divisor;
            vertex[2] *= vertex_divisor;
            vertex[3] = 1.f;

            float normal_divisor = 1.f / normal[3];

            normal[0] *= normal_divisor;
            normal[1] *= normal_divisor;
            normal[2] *= normal_divisor;
            normal[3] = 1.f;

            float v = std::sqrt(std::pow(normal[0], 2) + std::pow(normal[1], 2) + std::pow(normal[2], 2));
            v = 1 / v;
            normal[0] *= v;
            normal[1] *= v;
            normal[2] *= v;
            normal[3] = 0.f;
        }   
	}
    
    /**
    @brief Render the model
    @param view The view reference
    */
    void Model::Render(glm::mat4 view)
    {
        mesh->Render(view);
    }

    /**
    @brief Gets the material reference of the given mesh by index
    @param index The index of the mesh to get the material attached to
    @return The material reference
    */
	Material& Model::get_material(size_t index)
	{
		return meshes[index]->get_material();
	}
}