/*
 * File: TScriptComponent.hpp
 * File Created: 24th January 2020
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

namespace TortillaEngine
{
    /**
    @brief Component with script behaviour
    */
    class TScriptComponent : public TComponent
    {
    public:

        /**
        @brief Creates a TScriptComponent child of the given entity.
        @param parent The Entity this component will be attached to.
        */
        TScriptComponent(TEntity* parent) : TComponent{ parent } {}

        /**
        @brief Initializes the values.        
        */
        virtual void initialize() override  {}
        
        /**
        @brief Execute the script behaviour.
        */
        virtual void execute() override     {}
        
        /**
        @brief Load the component info from a xml node.
        @param component_node A reference to the node with this component info.
        */
        virtual bool parse_component(rapidxml::xml_node<>* component_node) override {}
       
    };

}
