/*
* File: vbo.cpp
* File Created: 14th May 2020
* ––––––––––––––––––––––––
* Author: Jesus Fermin, 'Pokoi', Villar(hello@pokoidev.com)
* ––––––––––––––––––––––––
* MIT License
*
* Copyright(c) 2020 Pokoidev
*
*Permission is hereby granted, free of charge, to any person obtaining a copy of
* this softwareand associated documentation files(the "Software"), to deal in
* the Software without restriction, including without limitation the rights to
* use, copy, modify, merge, publish, distribute, sublicense, and /or sell copies
* of the Software, and to permit persons to whom the Software is furnished to do
*so, subject to the following conditions :
*
*The above copyright noticeand this permission notice shall be included in all
* copies or substantial portions of the Software.
*
*THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include <vbo.hpp>
#include <glad.h>

namespace Rendering3D
{
    /**
    @brief Creates a buffer
    */
    Vbo::Vbo(void* content, Vbo::content type, size_t content_size, BufferObject::draw drawing)
        :
        content_type(type),
        BufferObject(drawing)
    {
        size = content_size;

        glGenBuffers(1, &id);
        open_buffer();

        glBufferData(GL_ARRAY_BUFFER, content_size, content, buffer_draw_type);
    }

    /**
    @brief Frees the memory
    */
    Vbo::~Vbo()
    {
        glDeleteBuffers(1, &id);
    }

    /**
    @brief Opens the buffer for operations
    */
    void Vbo::open_buffer()
    {
        glBindBuffer(GL_ARRAY_BUFFER, id);
    }

    /**
    @brief Closes the buffer after operations
    */
    void Vbo::close_buffer()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}