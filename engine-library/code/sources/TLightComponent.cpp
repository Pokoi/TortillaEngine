/*
 * File: TLightComponent.cpp
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

#include <TLightComponent.hpp>
#include <TEntity.hpp>
#include <Light.hpp>


namespace TortillaEngine
{
    TLightComponent::TLightComponent(
                                        TEntity * parent,
                                        TColor    light_color,
                                        float     intensity
                                    ) 
                                    :  
                                        TComponent{ parent },
                                        light{ new glt::Light() },
                                        light_color{light_color},
                                        intensity{ intensity }
    {
        light->set_color({ light_color.red, light_color.green, light_color.blue });
        light->set_intensity(intensity);
    }

    void TLightComponent::set_color(float red, float green, float blue)
    {
        light_color.red = red;
        light_color.green = green;
        light_color.blue = blue;

        light->set_color({ red, green, blue });
    }

    void TLightComponent::set_color(TLightComponent::TColor color)
    {
        light_color = color;

        light->set_color({ light_color.red, light_color.green, light_color.blue });
    }

    TLightComponent::TColor TLightComponent::get_color()
    {
        return light_color;
    }

    void TLightComponent::set_intensity(float intensity)
    {
        this->intensity = intensity;
        light->set_intensity(intensity);
    }

    float TLightComponent::get_intensity()
    {
        return intensity;
    }

    bool TLightComponent::parse_component(rapidxml::xml_node<>* component_node)
    {
        return false;
    }

}