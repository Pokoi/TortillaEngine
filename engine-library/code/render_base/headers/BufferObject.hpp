/*
* File: BufferObject.hpp
* File Created: 13th May 2020
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

#pragma once
#include <glad.h>


namespace Rendering3D
{

    class BufferObject
    {
    public:
        enum draw {static_draw, stream_draw, dynamic_draw};
        

    protected:
        draw buffer_draw_type;
        GLuint id;
        size_t size;

        BufferObject(BufferObject::draw type) : buffer_draw_type {type}
        {}

    public:

        virtual void open_buffer()  = 0;
        virtual void close_buffer() = 0;

        size_t get_size()
        {
            return size;
        }
    };

}