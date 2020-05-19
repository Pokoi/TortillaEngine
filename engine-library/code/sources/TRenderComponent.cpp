/*
 * File: TRenderComponent.cpp
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

#include <TRenderComponent.hpp>
#include <glm.hpp>
#include <TEntity.hpp>
#include <memory>
#include <TScene.hpp>

namespace TortillaEngine
{
    /**
    @brief Creates the component with the given values.
    @param parent A reference to the entity this component is attached to.
    @param path The path for obj file with the 3D mesh
    */
    TRenderComponent::TRenderComponent(TEntity* parent, std::string path) : TComponent{parent}, model{ std::make_shared <Rendering3D::Model> (path) }
    {
        add_to_update_component();
        subscribe_to_task();       
    }
    
    /**
    @brief Loads the component data from a xml node
    @param component_node The xml node with the data
    */
    bool TRenderComponent::parse_component(rapidxml::xml_node<>* component)
    {
        for (
            rapidxml::xml_node<>* render = component->first_node();
            render;
            render = render->next_sibling()
            )
        {
            std::string value = render->value();

            if ((std::string)render->name() == "asset")
            {
                model = std::make_shared < Rendering3D::Model>(value);
            }            
        }

        add_to_update_component();
        subscribe_to_task();
        
        return true;
    }

    /**
    @brief Subscribes to the render task
    */
    void TRenderComponent::subscribe_to_task()
    {
        std::dynamic_pointer_cast<TRenderTask>(parent->get_scene()->get_task("TRenderTask"))->add_component(this);
    }

    /**
    @brief Applies a given transformation to the model
    @param transfrom The transformation to apply
    */
    void TRenderComponent::apply_transform(glm::mat4 transform)
    {
        model->apply_transformations(transform);
    }
}