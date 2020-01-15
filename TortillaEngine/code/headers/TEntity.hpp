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



namespace TortillaEngine
{
    class TScene;

    class TEntity
    {
        
        std::map<std::string, std::list <std::shared_ptr <TComponent>> > components;
        
        TTransformComponent   transform;        
		TEntity             * parent;
        TScene              * scene;
        std::string           name;

    public:

        TEntity(std::string name, TScene* scene) : scene{ scene }, name{ name }, transform{ {this} } {}
               
        void add_component(const std::string type, std::shared_ptr <TComponent>& component)
        {
            components[type].push_back(component);           
        }

        std::list <std::shared_ptr <TComponent>> get_component(const std::string type)
        {
            if (!has_component(type))
            {
                std::shared_ptr <TComponent> new_component (nullptr);
                new_component = std::make_shared<TComponent>(this);
                add_component(type, new_component);
            }
            return components[name];
        }

        bool has_component(const std::string type)
        {
            return components[type].size() != 0;
        }

		TTransformComponent get_transform()
		{
			if (parent) return parent->get_transform() * this->transform;
			else return this->transform;
		}

        TScene* get_scene()
        {
            return scene;
        }

        ~TEntity ()
        {
            delete parent;
            delete scene;
            components.clear();
        }
    };

}