/*
 * File: TComponent.hpp
 * File Created: 13th January 2020
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

#include <glm.hpp>
#include <rapidxml-1.13/rapidxml.hpp>

namespace TortillaEngine
{
    /**
    @brief Forward declaration
    */
    class TEntity;

    /**
    @brief Base class of every component attached to an entity
    */
    class TComponent
    {
    protected:

        /**
        @brief A refence to the entity this component is attached to
        */
        TEntity*    parent;

    public:

        /**
        @brief Creates a component. By default, his entity is null
        @param parent A reference to the entity this component is attached to
        */
        TComponent(TEntity* parent = nullptr) : parent{ parent } {}
        
        /**
        @brief Destructor method for memory management
        */
        virtual         ~TComponent() {}

        /**
        @brief Initialization of component values
        */
        virtual void    initialize() {}

        /**
        @brief Execution of the component behaviour.
        */
        virtual void    execute() {}

        /**
        @brief Applies a given transformation to itself
        @param transfrom A reference to the transformation to apply
        */
        virtual void    apply_transform(glm::mat4 transform) {}

        /**
        @brief Load the component values from a xml
        @param component_node The xml node with this component info
        */
        virtual bool    parse_component(rapidxml::xml_node<>* component_node) { return false; }

        /**
        @brief Gets a refence of the entity this component is attached to
        @return A reference of the entity this component is attached to.
        */
        TEntity*        get_parent() { return parent; }
        /**
        @brief Adds this component to the update component of the entity. If no update component is added, it creates one.
        */
        virtual void    add_to_update_component();

        /**
        @brief Subscription of the component to the task that manages it
        */
        virtual void    subscribe_to_task() {}
    };
}

