/*
 * File: Mesh.hpp
 * File Created: 11th February 2020
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

#include <vector>			// For collections
#include <memory>			// For shared_ptr

#include <vao.hpp>
#include <vbo.hpp>
#include <ebo.hpp>
#include <Material.hpp>

namespace Rendering3D
{
    /**
    @brief Class that manages meshs
    */
	class Mesh
	{

        typedef glm::mat4 mat4;

        
        /**
        @brief The vao of the mesh
        */
        std::shared_ptr <Vao> vao;
		
        /**
        @brief A pointer to the material
        */
        std::shared_ptr <Material> material;
        
        /**
        @brief The model view matrix
        */
        mat4 model_view_matrix;

	public:

        /**
        @brief Creates an instance of this class.
        @param vao The collecion of data       
        */
		Mesh (std::shared_ptr<Vao> vao);

        /**
        @brief Render the mesh        
        */
		void Render();

        /**
        @brief Sets the material
        @param material The given material
        */
		void set_material(std::shared_ptr <Material> material)
		{
			this->material = material;
		}

        /**
        @brief Gets a refence to the material
        @return A reference to the material
        */
		std::shared_ptr <Material> & get_material()
		{
			return material;
		}

        /**
        @brief Apply the matrix transformation to the mesh
        @param transformation The transformation to apply
        */
        void apply_transform(mat4 transformation);


    private:

        

	};
}