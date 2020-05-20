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
#include <glad.h>

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

            mesh = std::make_shared<Mesh>(std::make_shared<Vao> (vao));
        }
	}  
    
    /**
    @brief Render the model
    @param view The view reference
    */
    void Model::Render()
    {
        mesh->Render();
    }

    /**
    @brief Gets the material reference of the given mesh by index
    @param index The index of the mesh to get the material attached to
    @return The material reference
    */
	std::shared_ptr<Material>& Model::get_material(size_t index)
	{
		return mesh->get_material();
	}

    /**
    @brief Apply the matrix transformation of the transform to the model
    @param transform The transformation matrix to apply
    */
    void Model::apply_transformations(glm::mat4 transform)
    {
        mesh->apply_transform(transform);
    }
}