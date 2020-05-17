/*
 * File: vao.cpp
 * File Created: 14th May 2020
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

#include <vao.hpp>
#include <glad.h>

 /**
 @brief Creates a vao
 */
Rendering3D::Vao::Vao()
{
    glGenVertexArrays(1, &id);
}

/**
 @brief Frees the memory used by the vao
 */
Rendering3D::Vao::~Vao()
{
    glDeleteVertexArrays(1, &id);
}

/**
@brief Opens the vao for operations
*/
void Rendering3D::Vao::open_vao()
{
    glBindVertexArray(id);
}

/**
@brief Closes the vao after operations
*/
void Rendering3D::Vao::close_vao()
{
    glBindVertexArray(0);
}

/**
@brief Add the vertices VBO
@param data The vertices data
@param data_size Size of the data
*/
void Rendering3D::Vao::add_vertices(void* data, size_t data_size)
{
    open_vao();

    vertices = std::make_shared<Vbo>(data, Vbo::content::_float, data_size, BufferObject::draw::static_draw);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(locations::VERTICES, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

    close_vao();
}

/**
@brief Add the uvs VBO
@param data The uvs data
@param data_size Size of the data
*/
void Rendering3D::Vao::add_uvs(void* data, size_t data_size)
{
    open_vao();

    uvs = std::make_shared<Vbo>(data, Vbo::content::_float, data_size, BufferObject::draw::static_draw);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(locations::UVS, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

    close_vao();
}

/**
@brief Add the normals VBO
@param data The normals data
@param data_size Size of the data
*/
void Rendering3D::Vao::add_normals(void* data, size_t data_size)
{
    open_vao();

    normals = std::make_shared<Vbo>(data, Vbo::content::_float, data_size, BufferObject::draw::static_draw);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(locations::NORMALS, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

    close_vao();
}

/**
@brief Add the indices EBO
@param data The indices data
@param data_size Size of the data
*/
void Rendering3D::Vao::add_indices(void* data, size_t data_size)
{
    open_vao();

    indices = std::make_shared<Ebo>(data, data_size, BufferObject::draw::static_draw);

    close_vao();
}

/**
@brief Do the draw call
*/
void Rendering3D::Vao::render()
{
    open_vao();
    glDrawElements(GL_TRIANGLES, indices->get_size(), GL_UNSIGNED_INT, 0);
    close_vao();
}
