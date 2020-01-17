/*
 * File: TCollider.hpp
 * File Created: 16th January 2020
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
#include <declarations.hpp>
#include <TObserver.hpp>
#include <list>

namespace TortillaEngine
{
    class TCollider : public TComponent, TObserver
    {

    public:             

        struct T3Components
        {   
            T3Components()
            {
                x = y = z = 0;
            }

            T3Components(float x, float y, float z) : x{ x }, y{ y }, z{ z }{};
            float x;
            float y;
            float z;

            void operator = (T3Components& other)
            {
                x = other.x;
                y = other.y;
                z = other.z;
            }            
        };

    protected:

        T3Components center;
        T3Components offset;


    public:

        TCollider(
                    TEntity* parent,
                    float x_offset,
                    float y_offset,
                    float z_offset
                 );

        void calculate_center();
        virtual void resize(float x, float y, float z);
        virtual void handle(TMessage& m) override;
                
        virtual void initialize() override {};
        virtual void execute() override {};
        virtual bool parse_component(rapidxml::xml_node<>* component_node) override;
        virtual bool collides(TCollider& other) = 0;
    };
}