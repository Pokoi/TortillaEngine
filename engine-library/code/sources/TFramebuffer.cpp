/*
 * File: TFramebuffer.cpp
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

#include <TFramebuffer.hpp>
#include <glad.h>


namespace TortillaEngine
{
    /**
    @brief Creates an instance
    @param width The width of the framebuffer
    @param height The height of the framebuffer
    */
    TFramebuffer::TFramebuffer (
                                unsigned int width,
                                unsigned int height
                               ) : 
                                width{ width },
                                height{height}
    {
        // Frambuffer creation
        glGenFramebuffers(1, &id);
        activate();


        // Out texture creation
        glGenTextures(1, &out_texture_id);
        glBindTexture(GL_TEXTURE_2D, out_texture_id);

        glTexImage2D
        (
            GL_TEXTURE_2D,
            0,
            GL_RGB,
            width,
            height,
            0,
            GL_RGB,
            GL_UNSIGNED_BYTE,
            0
        );

        // Z Buffer creation
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        glGenRenderbuffers(1, &z_buffer_id);
        glBindRenderbuffer(GL_RENDERBUFFER, z_buffer_id);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, z_buffer_id);


        // Framebuffer configuration
        glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, out_texture_id, 0);
        const GLenum draw_buffer = GL_COLOR_ATTACHMENT0;
        glDrawBuffers(1, &draw_buffer);

        // Framebuffer release
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        // Quad for framebuffer render
        static const GLfloat triangle_positions[] =
        {
            +1.0f, -1.0f, 0.0f,
            +1.0f, +1.0f, 0.0f,
            -1.0f, +1.0f, 0.0f, 
            +1.0f, -1.0f, 0.0f, 
            -1.0f, +1.0f, 0.0f,
            -1.0f, -1.0f, 0.0f
        };

        static const GLfloat triangle_texture_uv[] =
        {
            +1.0f,  0.0f,
            +1.0f, +1.0f,
             0.0f, +1.0f,
            +1.0f, 0.0f, 
             0.0f, +1.0f,
             0.0f, 0.0f
        };

        glGenBuffers(1, &triangle_vbo_0);
        glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo_0);
        glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_positions), triangle_positions, GL_STATIC_DRAW);

        glGenBuffers(1, &triangle_vbo_1);
        glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo_1);
        glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_texture_uv), triangle_texture_uv, GL_STATIC_DRAW);
    }

    /**
    @brief Render the framebuffer
    */
    void TFramebuffer::render()
    {
        glViewport(0, 0, width, height);

        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        glUseProgram(effect.get_id());

        glBindTexture(GL_TEXTURE_2D, out_texture_id);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo_0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo_1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

        glDrawArrays(GL_TRIANGLES, 0, 3);
    
    }

    /**
    @brief Bind the framebuffer to activate it
    */
    void TFramebuffer::activate()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, id);
    }
    

}