/*
 * File: TShaderProgram.hpp
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

#pragma once
#include <TShader.hpp>
#include <string>
#include <memory>
#include <map>

namespace TortillaEngine
{
    class TShaderProgram
    {
        /**
        @brief The collection of shaders this shader program has
        */
        std::map<std::string, std::shared_ptr<TShader>> shaders;

        /**
        @brief The id of the shader program
        */
        unsigned int id;

    public:

        /**
        @brief Creates an instance
        */
        TShaderProgram();

        /**
        @brief Frees the memory
        */
        ~TShaderProgram();

        /**
        @brief Activates the shader program to use it in the render
        */
        void activate();

        /**
        @brief Adds a given shader to the shader program 
        @param shader The shader to add to the shader program
        */
        void add(TShader& shader);

        /**
        @brief Removes a given shader from the shader program 
        @param shader The shader to remove from the shader program 
        */
        void remove(TShader& shader);

        /**
        @brief Gets a shader reference from the shader program
        @param key The key name of the shader
        */
        std::shared_ptr <TShader>& get_shader(std::string key)
        {
            return shaders[key];
        }

        /**
        @brief Gets the location of a uniform param 
        @param uniform_param_name The name of the uniform param of the desired location
        @return The location of the uniform param
        */
        unsigned int get_location(std::string uniform_param_name);

    };

}