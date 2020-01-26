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
#include <TRenderTask.hpp>
#include <memory>
#include <TScene.hpp>

namespace TortillaEngine
{
    /**
    @brief Creates a light with the given values
    @param parent The entity this component is attached to
    @param light_color The color of the light
    @param intensity The light intesity
    */
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

        add_to_update_component();
        subscribe_to_task();
    }

    /**
    @brief Sets the color of the light
    @param red The red color component in range 0-1
    @param green The green color component in range 0-1
    @param blue The blue color component in range 0-1
    */
    void TLightComponent::set_color(float red, float green, float blue)
    {
        light_color.red = red;
        light_color.green = green;
        light_color.blue = blue;

        light->set_color({ red, green, blue });
    }

    /**
    @brief Sets the color of the light
    @param color The color of the light
    */
    void TLightComponent::set_color(TLightComponent::TColor color)
    {
        light_color = color;

        light->set_color({ light_color.red, light_color.green, light_color.blue });
    }

    /**
    @brief Gets the color of the light
    @return The color
    */
    TLightComponent::TColor TLightComponent::get_color()
    {
        return light_color;
    }

    /**
    @brief Sets the light intensity
    @param intensity The intensity of the light in range 0-1
    */
    void TLightComponent::set_intensity(float intensity)
    {
        this->intensity = intensity;
        light->set_intensity(intensity);
    }

    /**
    @brief Gets the light intensity
    @return The intensity of the light in range 0-1
    */
    float TLightComponent::get_intensity()
    {
        return intensity;
    }

    /**
    @brief Load the component data from a xml node
    @param component_node The xml node with the data
    */
    bool TLightComponent::parse_component(rapidxml::xml_node<>* component_node)
    {
        float red_color     = 0;
        float green_color   = 0;
        float blue_color    = 0;

        for (
            rapidxml::xml_node<>* light = component_node->first_node();
            light;
            light = light->next_sibling()
            )
        {
            std::string value   = light->value();

            if ((std::string)light->name() == "intensity")
            {
                set_intensity(std::stof(value));
            }
            else if ((std::string)light->name() == "redcolor")
            {
                red_color = std::stof(value);
            }
            else if ((std::string)light->name() == "greencolor")
            {
                green_color = std::stof(value);
            }
            else if ((std::string)light->name() == "bluecolor")
            {
                blue_color = std::stof(value);
            }
        }

        set_color({red_color, green_color, blue_color});

        return true;
    }

    /**
    @brief Gets a reference to the light
    @return The reference to the light
    */
    std::shared_ptr<glt::Light> TLightComponent::get_light()
    {
        return light;
    }

    /**
    @brief Adds the ligth to the render task
    */
    void TLightComponent::subscribe_to_task()
    {
        std::dynamic_pointer_cast<TRenderTask>(parent->get_scene()->get_task("TRenderTask"))->add_light(this);
    }

    /**
    @brief Applies the given transform to the light
    @param transform The transformation to apply
    */
    void TLightComponent::apply_transform(glm::mat4& transform)
    {
        light->set_transformation(transform);
    }

}