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
#include <TObserver.hpp>
#include <list>

namespace TortillaEngine
{
    /**
    @brief Class for collision component management      
    */
    class TCollider : public TComponent
    {

    public:             

        /**
        @brief Struct with 3 float components
        */
        struct T3Components
        {   
            /**
            @brief Creates a default instance. By default the value of each component is 0.
            */
            T3Components()
            {
                x = y = z = 0;
            }

            /**
            @brief Creates an instance with the given values.
            @param x The value of the x component
            @param y The value of the y component
            @param z The value of the z component
            */
            T3Components(float x, float y, float z) : x{ x }, y{ y }, z{ z }{};
            
            /**
            @brief The x component
            */
            float x;

            /**
            @brief The y component
            */
            float y;

            /**
            @brief The z component
            */
            float z;

            /**
            @brief Overloading of the = operator to copy the values of another object
            @param other The object to copy
            */
            void operator = (T3Components& other)
            {
                x = other.x;
                y = other.y;
                z = other.z;
            }            
        };

    protected:

        /**
        @brief The center coordinates of the collider
        */
        T3Components center;

        /**
        @brief The offset in each axis with parent's center
        */
        T3Components offset;


    public:

        /**
        @brief Creates a collider with the given values.
        @param parent The entity this collider is attached to.
        @param x_offset The offset in x axis with parent position.
        @param y_offset The offset in y axis with parent position.
        @param z_offset The offset in z axis with parent position.
        */
        TCollider(
                    TEntity* parent,
                    float x_offset,
                    float y_offset,
                    float z_offset
                 );

        /**
        @brief Calculates the center of the collider
        */
        void         calculate_center();

        /**
        @brief Apply an scale to the collider
        @param x The scale in x axis
        @param y The scale in y axis
        @param z The scale in z axis
        */
        virtual void resize(float x, float y, float z);        
        
        /**
        @brief Initialize the component values       
        */
        virtual void initialize() override {}

        /**
        @brief Execute the component
        */
        virtual void execute() override {}
        
        /**
        @brief Load the component info from a xml node.
        @param component_node A reference to the node with this component info.
        */
        virtual bool parse_component(rapidxml::xml_node<>* component_node) override;
        
        /**
        @brief Checks if there is a collision between this and other collider
        @param other The collider with check collision to
        @return If there is a collision
        */
        virtual bool collides(TCollider& other) = 0;

        /**
        @brief Apply the transform of the parent
        */
        virtual void apply_transform(glm::mat4 & transform) override;

        /**
        @brief Subscription of the component to the task that manages it
        */
        virtual void subscribe_to_task() override;
    };
}