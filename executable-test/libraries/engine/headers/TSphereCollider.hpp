/*
 * File: TSphereCollider.hpp
 * File Created: 16th January 2020
 * ������������������������
 * Author: Jesus Fermin, 'Pokoi', Villar  (hello@pokoidev.com)
 * ������������������������
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

#include <TCollider.hpp>
#include <cstdlib>

namespace TortillaEngine
{
    class TSphereCollider : TCollider
    {
        float radius; 

    public:

        TSphereCollider(
                        TEntity* parent,
                        float x_offset,
                        float y_offset,
                        float z_offset,
                        float radius
                       ) : TCollider(parent, x_offset, y_offset, z_offset)
        {
            this->radius = radius;
        }

        float get_radius()
        {
            return radius;
        }

        virtual void resize(float x, float y, float z) 
        {
            if (x == y && y == z)
            {
                this->radius *= x;
            }
            
            TCollider::resize(x, y, z);
        }

        virtual void handle(TMessage& m)
        {
            TCollider::handle(m);
        }

        virtual void initialize() override {};
        virtual void execute() override {};
        virtual bool parse_component(rapidxml::xml_node<>* component_node) override;        
        
        virtual bool collides(TCollider& other)
        {
            TSphereCollider* collider = dynamic_cast<TSphereCollider*>(&other);

            if (collider != nullptr)
            {
                return ((   pow(center.x - collider->center.x   , 2) +
                            pow(center.y - collider->center.y   , 2) +
                            pow(center.z - collider->center.z   , 2)
                        ) < pow(radius + collider->get_radius() , 2)
                       );                
            }
            return false;
        }

    };


}