/*
 * File: CubemapTexture.cpp
 * File Created: 20th May 2020
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
 * SOFTWARE
*/

#pragma once

#include <CubemapTexture.hpp>
#include <Color_Buffer_Rgba8888.hpp>
#include <vector>
#include <memory>

extern "C"
{
#include <targa.h>
}

#include <glad.h>

namespace Rendering3D
{
    /**
    @brief Creates an instance
    @param path The path of the texture
    */
    CubemapTexture::CubemapTexture(std::string path)
    {
        std::vector <std::shared_ptr <example::Color_Buffer_Rgba8888>> texture_sides(6);

        for (size_t texture_index = 0; texture_index < 6; ++texture_index)
        {

            std::shared_ptr< example::Color_Buffer_Rgba8888 > buffer;

            // Se carga el archivo TGA:

            tga_image loaded_image;
            std::string side_path = path + char('0' + texture_index) + ".tga";
            
            if (tga_read(&loaded_image, side_path.c_str()) == TGA_NOERR)
            {
                // Se crea un b�fer con el formato de p�xel adecuado:

                buffer.reset(new example::Color_Buffer_Rgba8888(loaded_image.width, loaded_image.height));

                // Se convierte el b�fer de la imagen cargada al formato de p�xel adecuado:

                tga_convert_depth(&loaded_image, buffer->bits_per_color());
                tga_swap_red_blue(&loaded_image);

                example::Color_Buffer_Rgba8888::Color* loaded_image_pixels = reinterpret_cast<example::Color_Buffer_Rgba8888::Color*>(loaded_image.image_data);
                example::Color_Buffer_Rgba8888::Color* loaded_image_pixels_end = loaded_image_pixels + loaded_image.width * loaded_image.height;
                example::Color_Buffer_Rgba8888::Color* texture_buffer_pixels = buffer->colors();

                while (loaded_image_pixels < loaded_image_pixels_end)
                {
                    *texture_buffer_pixels++ = *loaded_image_pixels++;
                }

                tga_free_buffers(&loaded_image);
            }

            texture_sides[texture_index] = buffer;

            if (!texture_sides[texture_index]) return;
        }
        
        glEnable(GL_TEXTURE_CUBE_MAP);

        glGenTextures(1, &texture_id);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, texture_id);
               

        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
                

        static const GLenum texture_target[] =
        {
            GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
            GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
            GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
            GL_TEXTURE_CUBE_MAP_POSITIVE_X,
            GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
            GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
        };

        for (size_t texture_index = 0; texture_index < 6; texture_index++)
        {
            example::Color_Buffer_Rgba8888& texture = *texture_sides[texture_index];

            glTexImage2D
            (
                texture_target[texture_index],
                0,
                GL_RGBA,
                texture.get_width(),
                texture.get_height(),
                0,
                GL_RGBA,
                GL_UNSIGNED_BYTE,
                texture.colors()
                );
        }

    }

    /**
    @brief Releases the memory
    */
    CubemapTexture::~CubemapTexture()
    {
        glDeleteTextures(1, &texture_id);
    }
}