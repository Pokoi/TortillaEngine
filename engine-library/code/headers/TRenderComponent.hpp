/*
 * File: TRenderComponent.hpp
 * File Created: 17th January 2020
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

#include <TComponent.hpp>
#include <memory>
#include <string>
#include <Model.hpp>

namespace TortillaEngine
{
    /**
    @brief Render component for 3D models and meshes
    */
    class TRenderComponent : public TComponent
    {
        /**
        @brief A reference to the model 
        */
        std::shared_ptr<Rendering3D::Model> model;
                

    public:

        /**
        @brief Creates the component with default values. By default, the model is null.
        */
        TRenderComponent(TEntity* parent = nullptr) : TComponent{ parent } 
        {
            model = nullptr;
        }

        /**
        @brief Creates the component with the given values.
        @param parent A reference to the entity this component is attached to.
        @param path The path for obj file with the 3D mesh
        */
        TRenderComponent(TEntity* parent, std::string path);
        
        /**
        @brief Gets a reference to the model
        @return A reference to the model 
        */
        std::shared_ptr<Rendering3D::Model> get_model()
        {
            return model;
        }

        /**
        @brief Applies a given transformation to the model
        @param transfrom The transformation to apply
        */
        void            apply_transform(glm::mat4 transform ) override;

        /**
        @brief Executes the component
        */
        virtual void    execute() {}

        /**
        @brief Loads the component data from a xml node
        @param component_node The xml node with the data
        */
        virtual bool    parse_component(rapidxml::xml_node<>* component_node);

        /**
        @brief Subscribes to the render task
        */
        virtual void    subscribe_to_task() override;

    };
}
