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

#include <Cube.hpp>
#include <TEntity.hpp>
#include <Render_Node.hpp>
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
        for (
            rapidxml::xml_node<>* render = component->first_node();
            render;
            render = render->next_sibling()
            )
        {
            std::string value = render->value();

            if ((std::string)render->name() == "asset")
            {
                model = std::make_shared < glt::Model_Obj>(glt::Model_Obj(value));
            }            
        }

        add_to_update_component();
        subscribe_to_task();
        
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