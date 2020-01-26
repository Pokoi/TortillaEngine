/*
 * File: TUpdateComponent.hpp
 * File Created: 25th January 2020
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

#include <TScriptComponent.hpp>
#include <declarations.hpp>
#include <list>

namespace TortillaEngine
{
    /**
    @brief Script component that updates other components
    */
    class TUpdateComponent : public TScriptComponent
    {
    private:
        
        /**
        @brief Collection of the subscribed components
        */
        std::list<TComponent*> components;

    public:

        /**
        @brief Creates the component
        @param parent A reference to the entity this component is attached to
        */
        TUpdateComponent(TEntity* parent) : TScriptComponent{ parent } 
        {
            subscribe_to_task();
        }

        /**
        @brief Adds a component to the collection of subscribed components
        @param component The component to add
        */
        void add_component(TComponent* component)
        {
            if (component != nullptr)
            {
                components.push_back(component);
            }
        }
        
        /**
        @brief Removes a component from the collection of subscribed components
        @param component The component to unsubscribe
        */
        void remove_component(TComponent* component)
        {
            if (component != nullptr)
            {
                std::list<TComponent*>::iterator it = std::find(components.begin(), components.end(), component);
                if (it != components.end())
                {
                    components.erase(it);
                }
            }
        }

        /**
        @brief Executes the component, updating all the subscribed components
        */
        virtual void    execute();

        /**
        @brief Subscribe the component to the script task
        */
        virtual void    subscribe_to_task() override;
    };
}