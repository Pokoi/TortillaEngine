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
#include <glm.hpp>

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

    /**
    @brief Gets the location of a uniform param
    @param uniform_param_name The name of the uniform param of the desired location
    @return The location of the uniform param
    */
    unsigned int TShaderProgram::get_location(std::string uniform_param_name)
    {
        return glGetUniformLocation(id, uniform_param_name.c_str());
    }

    /**
    @brief Set the value of a uniform param
    @param location The location of the uniform param to set
    @param value The value to set
    */
    void TShaderProgram::set_uniform_value(unsigned int location, float value)
    {
        glUniform1f(location, value);
    }

    /**
    @brief Set the value of a uniform param
    @param location The location of the uniform param to set
    @param value The value to set
    */
    void TShaderProgram::set_uniform_value(unsigned int location, int value)
    {
        glUniform1i(location, value);
    }

    /**
    @brief Set the value of a uniform param
    @param location The location of the uniform param to set
    @param value The value to set
    */
    void TShaderProgram::set_uniform_value(unsigned int location, float value_0, float value_1, float value_2)
    {
        glUniform3f(location, value_0, value_1, value_2);
    }

    /**
    @brief Set the value of a uniform param
    @param location The location of the uniform param to set
    @param value The value to set
    */
    void TShaderProgram::set_uniform_value(unsigned int location, float value_0, float value_1, float value_2, float value_3)
    {
        glUniform4f(location, value_0, value_1, value_2, value_3);
    }    


}
