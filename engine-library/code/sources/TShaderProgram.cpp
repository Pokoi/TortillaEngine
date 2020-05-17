/*
 * File: TShaderProgram.cpp
 * File Created: 17th May 2020
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

#include <TShaderProgram.hpp>
#include <glad.h>

namespace TortillaEngine
{

    /**
    @brief Creates an instance
    */
    TShaderProgram::TShaderProgram()
    {
        id = glCreateProgram();
    }

    /**
    @brief Frees the memory
    */
    TShaderProgram::~TShaderProgram()
    {
        glDeleteProgram(id);
    }

    /**
    @brief Activates the shader program to use it in the render
    */
    void TShaderProgram::activate()
    {
        glUseProgram(id);
    }

    /**
    @brief Adds a given shader to the shader program
    @param shader The shader to add to the shader program
    */
    void TShaderProgram::add(TShader& shader)
    {
        shaders[shader.get_name()] = std::make_shared <TShader> (shader);

        glAttachShader(id, shader.get_id());
        glLinkProgram(id);
        glDeleteShader(shader.get_id());
    }

    /**
    @brief Removes a given shader from the shader program
    @param shader The shader to remove from the shader program
    */
    void TShaderProgram::remove(TShader& shader)
    {
        shaders.erase(shader.get_name());
        
        glDetachShader(id, shader.get_id());
    }


}
