/*
 * File: Mesh.cpp
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

#include <Mesh.hpp>

#include <Model.hpp>		// For constructor assignation

#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <glad.h>


namespace Rendering3D
{
     
    /**
    @brief Creates an instance of this class.
    @param vao The collecion of data
    */
    Mesh::Mesh(std::shared_ptr<Vao> vao) : vao{ vao }
    {
    
    }

	
    /**
    @brief Render the mesh    
    */
	void Mesh::Render()
	{ 
        // Model View
        unsigned int model_view_matrix_id = material->get_shader_program()->get_location("model_view_matrix");      
        glUniformMatrix4fv(model_view_matrix_id, 1, GL_FALSE, glm::value_ptr(model_view_matrix));

        // Normal matrix
        glm::mat4 normal_matrix = glm::transpose(glm::inverse(model_view_matrix));
        unsigned int normal_matrix_id = material->get_shader_program()->get_location("model_normal_matrix");
        glUniformMatrix4fv(normal_matrix_id, 1, GL_FALSE, glm::value_ptr(normal_matrix));

        material->render();
        vao->render();
	}

    /**
    @brief Apply the matrix transformation to the mesh
    @param transformation The transformation to apply
    */
    void Mesh::apply_transform(glm::mat4 transformation)
    {
        model_view_matrix = transformation;
    }
   
}
