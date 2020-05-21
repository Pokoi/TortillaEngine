/*
 * File: TSkybox.cpp
 * File Created: 20th May 2020
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
 * SOFTWA
*/

#include <TSkybox.hpp>
#include <glad.h>
#include <TShader.hpp>
#include <gtc/type_ptr.hpp>

namespace TortillaEngine
{
 
    /**
    @brief Create an instance
    @param texture_path The path of the texture of the skybox
    @param vertex_shader_file The path of the vertex shader
    @param fragment_shader_file The path of the fragment shader
    */
    TSkybox::TSkybox(
                        std::string texture_path, 
                        std::string vertex_shader_file, 
                        std::string fragment_shader_file
                    ) : texture (texture_path)
    {
        GLfloat coordinates[] =
        {
            -1.0f, +1.0f, -1.0f,
            -1.0f, -1.0f, -1.0f,
            +1.0f, -1.0f, -1.0f,
            +1.0f, -1.0f, -1.0f,
            +1.0f, +1.0f, -1.0f,
            -1.0f, +1.0f, -1.0f,
            -1.0f, -1.0f, +1.0f,
            -1.0f, -1.0f, -1.0f,
            -1.0f, +1.0f, -1.0f,
            -1.0f, +1.0f, -1.0f,
            -1.0f, +1.0f, +1.0f,
            -1.0f, -1.0f, +1.0f,
            +1.0f, -1.0f, -1.0f,
            +1.0f, -1.0f, +1.0f,
            +1.0f, +1.0f, +1.0f,
            +1.0f, +1.0f, +1.0f,
            +1.0f, +1.0f, -1.0f,
            +1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f, +1.0f,
            -1.0f, +1.0f, +1.0f,
            +1.0f, +1.0f, +1.0f,
            +1.0f, +1.0f, +1.0f,
            +1.0f, -1.0f, +1.0f,
            -1.0f, -1.0f, +1.0f,
            -1.0f, +1.0f, -1.0f,
            +1.0f, +1.0f, -1.0f,
            +1.0f, +1.0f, +1.0f,
            +1.0f, +1.0f, +1.0f,
            -1.0f, +1.0f, +1.0f,
            -1.0f, +1.0f, -1.0f,
            -1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f, +1.0f,
            +1.0f, -1.0f, -1.0f,
            +1.0f, -1.0f, -1.0f,
            -1.0f, -1.0f, +1.0f,
            +1.0f, -1.0f, +1.0f,
        };

        cube_vao.add_vertices(coordinates, 108 * sizeof(GLfloat));        
        
        shader_program = std::make_shared<TShaderProgram>();

        shader_program->activate();

        TShader vertex_shader(vertex_shader_file, TShader::VERTEX, "skybox_vertex_shader");
        TShader fragment_shader(vertex_shader_file, TShader::FRAGMENT, "skybox_fragment_shader");

        shader_program->add(vertex_shader);
        shader_program->add(fragment_shader);

        model_view_matrix_id    = shader_program->get_location("model_view_matrix");
        projection_view_id      = shader_program->get_location("projection_matrix");      
    
    }

    /**
    @brief Render the skybox
    @param camera_projection The projection matrix of the camera
    @paran model_view The camera transformation matrix
    */
    void TSkybox::render(glm::mat4 camera_projection, glm::mat4 model_view)
    {
        shader_program->activate();

        glBindTexture(GL_TEXTURE_CUBE_MAP, texture.get_id());

        glUniformMatrix4fv(model_view_matrix_id, 1, GL_FALSE, glm::value_ptr(model_view));
        glUniformMatrix4fv(projection_view_id, 1, GL_FALSE, glm::value_ptr(camera_projection));

        glDepthMask(GL_FALSE);

        glBindVertexArray(cube_vao.get_id());
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glBindVertexArray(0);

        glDepthMask(GL_TRUE);

    }    

}