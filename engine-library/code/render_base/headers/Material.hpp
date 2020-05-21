/*
 * File: Material.hpp
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
#include <memory>
#include <string>
#include <TShaderProgram.hpp>

namespace example
{
    class Color_Buffer_Rgba8888;
}

namespace Rendering3D
{
    /**
    @brief Material
    */
	class Material
	{

        /**
        @brief The texture of the material
        */
        std::shared_ptr <example::Color_Buffer_Rgba8888> texture;

        /**
        @brief The texture id
        */
        unsigned int texture_id = 0;

        /**
        @brief Flag if this material is transparent or opaque
        */
        bool opaque = true;

        /**
        @brief A reference to the shader program of the material
        */
        std::shared_ptr <TortillaEngine::TShaderProgram> shader_program;

    public:

        /**
        @brief Creates an instance with the texture in the given path
        @param texture_path The path of the texture
        @param opaque If this material is opaque or transparent
        */
        Material(std::string texture_path, bool opaque);

        /**
        @brief Creates a default instance
        */
        Material()
        {}
        
        /**
        @brief Frees the memory
        */
        ~Material();
        
        /**
        @brief Select the texture if needed and activates the shader
        */
        void render();

        /**
        @brief Get if the material is transparent or not
        @return true The material is opaque
        @return false The material is transparent
        */
        bool is_opaque()
        {
            return opaque;
        }

        /**
        @brief Gets a reference to the shader program of this material
        @return The reference of the shader program
        */
        std::shared_ptr <TortillaEngine::TShaderProgram>& get_shader_program()
        {
            return shader_program;
        }

        /**
        @brief Sets the shader program
        @param shader_program The reference of the shader program to set
        */
        void set_shader_program(std::shared_ptr<TortillaEngine::TShaderProgram> shader_program)
        {
            shader_program = shader_program;
        }
               
       
	};
}