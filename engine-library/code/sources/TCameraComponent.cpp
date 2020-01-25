/*
 * File: TCameraComponent.cpp
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

#include <TCameraComponent.hpp>
#include <Camera.hpp>


namespace TortillaEngine
{
    TCameraComponent::TCameraComponent  (
                                            TEntity* parent,
                                            float near_field = 1.f,
                                            float far_field = 2000.f,
                                            float fov = 0.5f,
                                            float aspect_ratio = 1.f
                                        ) : TComponent{ parent }, camera{ new glt::Camera (fov, near_field, far_field, aspect_ratio)}
    {
        camera->translate(glt::Vector3(0,0,1.2f));
        add_to_update_component();
    }

    bool TCameraComponent::parse_component(rapidxml::xml_node<>* component_node)
    {
        return false;
    }

    std::shared_ptr<glt::Camera> TCameraComponent::get_camera()
    {
        return camera;
    }
}