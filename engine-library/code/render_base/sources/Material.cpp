/*
 * File: Material.cpp
 * File Created: 14th February 2020
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

#include <Material.hpp>
extern "C"
{
#include <targa.h>
}

#include <glad.h>
#include <Color_Buffer_Rgba8888.hpp>

namespace Rendering3D
{
    /**
    @brief Creates an instance with the texture in the given path
    @param texture_path The path of the texture
    @param opaque If this material is opaque or transparent
    */
    Material::Material(std::string texture_path, bool opaque = true) : opaque{opaque}
    {
        tga_image  loaded;

        if (tga_read(&loaded, texture_path.c_str()) == TGA_NOERR)
        {
            texture = std::make_shared<example::Color_Buffer_Rgba8888>(loaded.width, loaded.height);

            tga_convert_depth(&loaded, texture->bits_per_color());
            tga_swap_red_blue(&loaded);

            example::Color_Buffer_Rgba8888::Color * loaded_pixels     = reinterpret_cast<example::Color_Buffer_Rgba8888::Color*> (loaded.image_data);
            example::Color_Buffer_Rgba8888::Color * loaded_pixels_end = loaded_pixels + loaded.width * loaded.height;
            example::Color_Buffer_Rgba8888::Color * buffer_pixels     = texture->colors();

            while (loaded_pixels < loaded_pixels_end)
            {
                *buffer_pixels++ = *loaded_pixels++;
            }

            tga_free_buffers(&loaded);
        
            glEnable(GL_TEXTURE_2D);
            glGenTextures(1, &texture_id);
            glBindTexture(GL_TEXTURE_2D, texture_id);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

            glTexImage2D
            (
                GL_TEXTURE_2D,
                0,
                GL_RGBA,
                texture->get_width(),
                texture->get_height(),
                0,
                GL_RGBA,
                GL_UNSIGNED_BYTE,
                texture->colors()
                );
        }        
    }

    /**
    @brief Frees the memory
    */
    Material::~Material()
    {
        if (texture.get())
        {
            glDeleteTextures(1, &texture_id);
        }
    }

    /**
    @brief Select the texture if needed and activates the shader
    */
    void Material::render()
    {
        if (texture.get())
        {
            glBindTexture(GL_TEXTURE_2D, texture_id);
        }
    }
}