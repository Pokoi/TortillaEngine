/*
 * File: TEntity.hpp
 * File Created: 13th January 2020
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
#include <TTransformComponent.hpp>
#include <TComponent.hpp>
#include <map>
#include <memory>
#include <string>
#include <list>



namespace TortillaEngine
{
    /**
    @brief Forward declaration
    */
    class TScene;

    /**
    @brief An object in the scene
    */
    class TEntity
    {
        
        /**
        @brief The collection of components this entity has attached to itself.
        */
        std::map<std::string, std::shared_ptr <TComponent>> components;
        
        /**
        @brief The transform component of this entity. All entity must to have a transfrom. 
        */
        TTransformComponent   transform;

        /**
        @brief A reference to this entity parent in scene hierarchy
        */
        TEntity             * parent;
        
        /**
        @brief A reference to the scene this entity belongs to
        */
        TScene              * scene;

        /**
        @brief The name of the entity
        */
        std::string           name;

    public:

        /**
        @brief Creates an entity with the given values
        @param name The name of the entity
        @param scene A reference to the scene this entity belongs to
        @param parent A reference to this entity parent in scene hierarchy
        */
        TEntity(const std::string & name, TScene* scene, TEntity* parent) : scene{ scene }, name{ name }, transform{ this }, parent{parent} {}
               
        ~TEntity ()
        {}

        /**
        @brief Adds a component to this entity
        @param type The type of the component added
        @param component The component to add to the entity
        */
        void add_component(const std::string type, std::shared_ptr <TComponent> component)
        {
            components[type] = component;           
        }

        /**
        @brief Gets a reference to a component attached to this entity of the given type. If the component doesn't exist, creates one.
        @param type The type of the component to get
        @return A reference to the component
        */
        std::shared_ptr <TComponent> get_component(const std::string & type)
        {
            if (!has_component(type))
            {
                std::shared_ptr <TComponent> new_component (nullptr);
                new_component = std::make_shared<TComponent>(this);
                add_component(type, new_component);
            }
            return components[type];
        }

        /**
        @brief Gets the name of the entity
        @return The name of the entity
        */
        std::string get_name() 
        { 
            return name;
        }

        /**
        @brief Check if the entity has an attached component of the given type
        @param type The type of the component
        @return If the entity has attached a component of this type
        */
        bool has_component(const std::string type)
        {          
            return components.find(type) != components.end();
        }

        /**
        @brief Gets the local transfrom component of the entity
        @return The transfrom component
        */
		TTransformComponent get_transform()
		{
            return this->transform;            
            /*
			if (parent) return parent->get_transform() * this->transform;
			else return this->transform;
            */
		}

        /**
        @brief Gets a reference of the scene this entity belongs to.
        */
        TScene* get_scene()
        {
            return scene;
        }

    };

}