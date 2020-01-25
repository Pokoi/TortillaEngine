/*
 * File: TLightComponent.hpp
 * File Created: 20th January 2020
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

#include <declarations.hpp>
#include <TComponent.hpp>
#include <memory>

namespace TortillaEngine
{

    class TLightComponent : public TComponent
    {

    public:

        struct TColor
        {
            TColor()
            {
                red = green = blue = 0.f;
            }

            TColor(float red, float green, float blue) : red{ red }, green{ green }, blue{ blue }{}

            float red;
            float blue;
            float green;

        };

    private:

        std::shared_ptr<glt::Light> light;
        TColor                      light_color{ 0.f, 0.f, 0.f };
        float                       intensity;

    public:

        TLightComponent(
                            TEntity * parent,
                            TColor    light_color,
                            float     intensity
                        );

        void    set_color(float red, float green, float blue);
        void    set_color(TColor color);
        
        TColor  get_color();

        void    set_intensity(float intensity);
        float   get_intensity();
       

        virtual bool    parse_component(rapidxml::xml_node<>* component_node);

        std::shared_ptr<glt::Light> get_light();

        virtual void subscribe_to_task() override;


    };

}