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
    /**
    @brief Light component
    */
    class TLightComponent : public TComponent
    {

    public:

        /**
        @brief Color with red, green and blue components
        */
        struct TColor
        {
            /**
            @brief Creates a color with default values (0.0 per component)
            */
            TColor()
            {
                red = green = blue = 0.f;
            }

            /**
            @brief Creates a color with the given values
            @param red The red component value
            @param green The green component value
            @param blue The blue component value
            */
            TColor(float red, float green, float blue) : red{ red }, green{ green }, blue{ blue }{}

            /**
            @brief The red component
            */
            float red;
            /**
            @brief The blue component
            */
            float blue;
            /**
            @brief The green component
            */
            float green;

        };

    private:

        /**
        @brief A reference to the light
        */
        std::shared_ptr<glt::Light> light;

        /**
        @brief The light color
        */
        TColor                      light_color{ 0.f, 0.f, 0.f };
        
        /**
        @brief The light intensity
        */
        float                       intensity;

    public:

        /**
        @brief Creates a light with the given values
        @param parent The entity this component is attached to
        @param light_color The color of the light
        @param intensity The light intesity
        */
        TLightComponent(
                            TEntity * parent,
                            TColor    light_color,
                            float     intensity
                        );

        /**
        @brief Sets the color of the light
        @param red The red color component in range 0-1
        @param green The green color component in range 0-1
        @param blue The blue color component in range 0-1
        */
        void    set_color(float red, float green, float blue);
        
        /**
        @brief Sets the color of the light
        @param color The color of the light
        */
        void    set_color(TColor color);
        
        /**
        @brief Gets the color of the light
        @return The color 
        */
        TColor  get_color();

        /**
        @brief Sets the light intensity
        @param intensity The intensity of the light in range 0-1
        */
        void    set_intensity(float intensity);

        /**
        @brief Gets the light intensity
        @return The intensity of the light in range 0-1
        */
        float   get_intensity();
       
        /**
        @brief Load the component data from a xml node
        @param component_node The xml node with the data 
        */
        virtual bool    parse_component(rapidxml::xml_node<>* component_node);

        /**
        @brief Gets a reference to the light
        @return The reference to the light
        */
        std::shared_ptr<glt::Light> get_light();

        /**
        @brief Adds the ligth to the render task
        */
        virtual void subscribe_to_task() override;

        /**
        @brief Applies the given transform to the light
        @param transform The transformation to apply
        */
        void    apply_transform(glm::mat4 transform) override;
    };

}