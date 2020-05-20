/*
 * File: vao.hpp
 * File Created: 12th May 2020
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

#include <vector>
#include <vbo.hpp>
#include <ebo.hpp>
#include <memory>

namespace Rendering3D
{
    class Vao
    {        
        enum locations {VERTICES = 0, UVS = 2, NORMALS = 3};

        unsigned int id;

       std::shared_ptr<Vbo> vertices;
       std::shared_ptr<Vbo> uvs;
       std::shared_ptr<Vbo> normals;
       std::shared_ptr<Ebo> indices;


    public:

        /**
        @brief Creates a vao
        */
        Vao();

        /**
        @brief Frees the memory used by the vao
        */
        ~Vao();

        /**
        @brief Opens the vao for operations
        */
        void open_vao();

        /**
        @brief Closes the vao after operations
        */
        void close_vao();

        /**
        @brief Add the vertices VBO
        @param data The vertices data
        @param data_size Size of the data
        */
        void add_vertices(void* data, size_t data_size);

        /**
        @brief Add the uvs VBO
        @param data The uvs data
        @param data_size Size of the data
        */
        void add_uvs(void* data, size_t data_size);

        /**
        @brief Add the normals VBO
        @param data The normals data
        @param data_size Size of the data
        */
        void add_normals(void* data, size_t data_size);

        /**
        @brief Add the indices EBO
        @param data The indices data
        @param data_size Size of the data
        */
        void add_indices(void* data, size_t data_size);

        /**
        @brief Do the draw call 
        */
        void render();

        /**
        @brief Get the vao id
        @return The id
        */
        unsigned int get_id()
        {
            return id;
        }

    };

}
