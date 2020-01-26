/*
 * File: TComponent.hpp
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

#include <TComponent.hpp>
#include <TUpdateComponent.hpp>
#include <TEntity.hpp>
#include <memory>
#include <list>

namespace TortillaEngine
{
  
    /**
    @brief Adds this component to the update component of the entity. If no update component is added, it creates one.
    */
   void TComponent::add_to_update_component()
   {
       if (!parent->has_component("TUpdateComponent"))
       {
           parent->add_component("TUpdateComponent", std::make_shared<TUpdateComponent>(parent));
       }
       
       std::shared_ptr<TUpdateComponent> update = std::dynamic_pointer_cast<TUpdateComponent>(parent->get_component("TUpdateComponent"));
       
       if (update != nullptr)
       {
            update->add_component(this);
       }
       
   }
}