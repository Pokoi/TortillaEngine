/*
 * File: TShader.hpp
 * File Created: 16th May 2020
 * 末末末末末末末末末末末末
 * Author: Jesus Fermin, 'Pokoi', Villar  (hello@pokoidev.com)
 * 末末末末末末末末末末末末
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

#include <string>

namespace TortillaEngine
{
    class TShader
    {
    public:
        enum TShaderTypes {VERTEX, FRAGMENT};

    private:
        std::string name;
        std::string content;
        TShaderTypes type;
        unsigned int id;

    public:

        /**
        @brief Creates an instance
        @param file_path The path where the shader file is
        @param type The type of shader
        @param name The name of the shader
        */
        TShader(std::string file_path, TShaderTypes type, std::string name);
        
        /**
        @brief Releases the memory
        */
        ~TShader();

        /**
        @brief Gets the id of the shader
        @return The shader id
        */
        unsigned int get_id()
        {
            return id;
        }

        /**
        @brief Gets the name of the shader
        @return The name of the shader
        */
        std::string get_name()
        {
            return name;
        }

    };
}