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
        std::shared_ptr <class example::Color_Buffer_Rgba8888> texture;

        /**
        @brief The texture id
        */
        unsigned int texture_id;

    public:

        /**
        @brief Creates an instance with the texture in the given path
        @param texture_path The path of the texture 
        */
        Material(std::string texture_path);

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
       
	};
}