/*
 * File: Model.hpp
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

#include <vector>						// For collections

#include <string>						// For path and name
#include <memory>						// For shared_ptr
#include <Mesh.hpp>						// For collection of meshes

#include <glm.hpp>


namespace Rendering3D
{
	struct Transform;

    /**
    @brief Model class    
    */
	class Model
	{
        /**
        @brief The mesh of this model
        */
		std::shared_ptr<Mesh>	mesh;
		               

	public:

        /**
        @brief Creates a instance of model
        @param mesh_path The path of the mesh
        */
		Model(std::string mesh_path);


        /**
        @brief Update the model
        @param delta The delta time
        @param view The view reference
        */
		void Update(float delta, class View& view);		

        /**
        @brief Render the model
        @param view The view reference
        */
        void Render(glm::mat4 view);

        /**
        @brief Gets the material reference of the given mesh by index
        @param index The index of the mesh to get the material attached to
        @return The material reference
        */
		class Material& get_material(size_t index);
	
	};
}
