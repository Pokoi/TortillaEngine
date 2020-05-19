/*
 * File: TBatch.hpp
 * File Created: 19th May 2020
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
#include <TRenderComponent.hpp>
#include <vector>
#include <memory>

namespace TortillaEngine
{
    class TBatch
    {
        /**
        @brief A pointer to the shader program of this collection of meshes
        */
        std::shared_ptr<TShaderProgram> shader_program;

        /**
        @brief The collection of meshes that shares the same shader program
        */
        std::vector<TRenderComponent*> render_components;

    public:

        /**
        @brief Creates an instance
        @param shader The shader of this batch
        */
        TBatch(std::shared_ptr<TShaderProgram> shader) : shader_program{shader}
        {}
        
        /**
        @brief Adds a render component if has the same shader program
        @param component The component to add
        @return If the component was added or not
        */
        bool add_render_component(TRenderComponent* component)
        {
            if (component->get_model()->get_material(0)->get_shader_program()->get_id() == shader_program->get_id())
            {
                render_components.push_back(component);
                return true;
            }

            return false;
        }

        /**
        @brief Gets the components in this batch
        @return The components collection
        */
        std::vector<TRenderComponent*>& get_components()
        {
            return render_components;
        }


        /**
        @brief Gets a reference to the shader program
        @return The shader program reference
        */
        std::shared_ptr<TShaderProgram>& get_shader_program()
        {
            return shader_program;
        }

    };
}
