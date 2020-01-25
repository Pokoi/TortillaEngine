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

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Model_Obj.hpp>
#include <TEntity.hpp>
#include <memory>
#include <TScene.hpp>

namespace TortillaEngine
{
   
    TRenderComponent::TRenderComponent(TEntity* parent, std::string path) : TComponent{parent}, model{ new glt::Model_Obj(path) }
    {
        add_to_update_component();
        subscribe_to_task();       
    }
    

    bool TRenderComponent::parse_component(rapidxml::xml_node<>* component)
    {

        std::string component_name;
        std::string value_name;

        for (
            rapidxml::xml_node<>* component_node = component->first_node();
            component_node;
            component_node = component_node->next_sibling()
            )
        {
            component_name = component_node->name();

            if (component_name.empty()) return true;

            for (
                rapidxml::xml_attribute <>* attribute = component_node->first_attribute();
                attribute;
                attribute = attribute->next_attribute()
                )
            {
                value_name = attribute->value();

                if (value_name.empty()) return true;
            }

            if (component_name == "mesh")
            {
            
            }

            else if (component_name == "camera")
            {

            }
            else if (component_name == "light")
            {

            }
        }


        std::string name = component->value();

        std::string path = "assets//" + name;
        model.reset(new glt::Model_Obj(path));

        return true;
    }

    void TRenderComponent::subscribe_to_task()
    {
        std::dynamic_pointer_cast<TRenderTask>(parent->get_scene()->get_task("TRenderTask"))->add_component(this);
    }

    void TRenderComponent::apply_transform(glm::mat4 & transform)
    {
        model->set_transformation(transform);
    }
}