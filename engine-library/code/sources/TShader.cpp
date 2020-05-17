/*
 * File: TShader.cpp
 * File Created: 16th May 2020
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

#include <TShader.hpp>
#include <fstream>
#include <sstream>
#include <glad.h>

namespace TortillaEngine
{
    /**
    @brief Creates an instance
    @param file_path The path where the shader file is
    @param type The type of shader
    @param name The name of the shader
    */
    TShader::TShader(
                        std::string file_path,
                        TShaderTypes type,
                        std::string name
                    ) : 
                        type {type},
                        name {name}
    {
        std::fstream reader(file_path, std::fstream::in | std::fstream::binary);
        
        if (reader.is_open())
        {
            reader.seekg(0, std::fstream::end);

            size_t size = size_t(reader.tellg());

            if (reader.good() && size > 0)
            {
                content.resize(size);

                reader.seekg(0, std::fstream::beg);

                reader.read(&content.front(), size);                
            }
        }

        switch (type)
        {
            case TShaderTypes::VERTEX   : id = glCreateShader(GL_VERTEX_SHADER)  ; break;
            case TShaderTypes::FRAGMENT : id = glCreateShader(GL_FRAGMENT_SHADER); break;            
        }
        
        const char* shader_code[] = { content.c_str() };
        const GLint shader_size[] = { (int)content.size() };

        glShaderSource(id, 1, shader_code, shader_size);
        glCompileShader(id);
        
    }

    /**
    @brief Releases the memory
    */
    TShader::~TShader()
    {
        glDeleteShader(id);
    }
}