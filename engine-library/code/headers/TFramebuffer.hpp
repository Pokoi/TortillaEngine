/*
 * File: TFramebuffer.hpp
 * File Created: 18th May 2020
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

#include <TShaderProgram.hpp>

namespace TortillaEngine
{
    class TFramebuffer
    {
    private:

        /**
        @brief The width of the framebuffer
        */
        const unsigned int width;

        /**
        @brief The height of the framebuffer
        */
        const unsigned int height;

        /**
        @brief The id of the framebuffer
        */
        unsigned int id;

        /**
        @brief The id of the out texture
        */
        unsigned int out_texture_id;

        /**
        @brief The Z buffer id
        */
        unsigned int z_buffer_id;

        /**
        @brief The triangle vbo 0 for the framebuffer render
        */
        unsigned int triangle_vbo_0;
        
        /**
        @brief The triangle vbo 1 for the framebuffer render
        */
        unsigned int triangle_vbo_1;

        /**
        @brief The effect shader program
        */
        TShaderProgram effect;

    public:

        /**
        @brief Creates an instance
        @param width The width of the framebuffer
        @param height The height of the framebuffer
        */
        TFramebuffer( unsigned int width, unsigned int height);


        /**
        @brief Render the framebuffer
        */
        void render();
        
        /**
        @brief Get a reference to the shader program of the effect
        @return The reference to the shader program
        */
        TShaderProgram& get_effect_shader_program()
        {
            return effect;
        }
    };

}