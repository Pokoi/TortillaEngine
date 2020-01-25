/*
 * File: TCameraComponent.hpp
 * File Created: 17th January 2020
 * 末末末末末末末末末末末末
 * Author: Jesus Fermin, 'Pokoi', Villar  (hello@pokoidev.com)
 * 末末末末末末末末末末末末
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

#include <declarations.hpp>
#include <TComponent.hpp>
#include <memory>

namespace TortillaEngine
{

    class TCameraComponent : public TComponent
    {
        std::shared_ptr<glt::Camera> camera;

    public:

        TCameraComponent(
                            TEntity* parent,
                            float near_field,
                            float far_field,
                            float fov,
                            float aspect_ratio
                        );


        virtual bool    parse_component(rapidxml::xml_node<>* component_node);

        std::shared_ptr<glt::Camera> get_camera();

        virtual void subscribe_to_task() override;
    };

    
}