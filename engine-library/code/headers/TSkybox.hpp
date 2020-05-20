/*
 * File: TSkybox.hpp
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


#pragma once

#include "vao.hpp"
#include "vbo.hpp"
#include "TShaderProgram.hpp"
#include <memory>
#include <string>
#include <CubemapTexture.hpp>
#include <glm.hpp>
#include <TComponent.hpp>

namespace TortillaEngine
{
    class TSkybox : public TComponent
    {
        /**
        @brief Vao of the cube that contains the skybox
        */
        Rendering3D::Vao cube_vao;

        /**
        @brief Shader program of the skybox
        */
        std::shared_ptr<TShaderProgram> shader_program;
        
        /**
        @brief The cached model view matrix id
        */
        unsigned int model_view_matrix_id = 0;

        /**
        @brief The cached projection view id
        */
        unsigned int projection_view_id = 0;

        /**
        @brief The cubemap texture
        */
        Rendering3D::CubemapTexture texture;

    public:

        /**
        @brief Create an instance        
        */
        TSkybox()
        {     }


        /**
        @brief Create an instance 
        @param texture_path The path of the texture of the skybox 
        @param vertex_shader_file The path of the vertex shader
        @param fragment_shader_file The path of the fragment shader
        */
        TSkybox(std::string texture_path, std::string vertex_shader_file, std::string fragment_shader_file);
               

        /**
        @brief Render the skybox
        @param camera_projection The projection matrix of the camera
        @paran model_view The camera transformation matrix
        */
        void render(glm::mat4 camera_projection, glm::mat4 model_view);

        /**
        @brief Set the shader program
        @param shader_program The shader program to set
        */
        void set_shader_program(std::shared_ptr<TShaderProgram> shader_program)
        {
            this->shader_program = shader_program;
        }

        /**
        @brief Load the component values from a xml
        @param component_node The xml node with this component info
        */
        virtual bool    parse_component(rapidxml::xml_node<>* component_node) override;

    };
}
