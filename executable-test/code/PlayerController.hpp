/*
 * File: PlayerController.hpp
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

#include <TObserver.hpp>
#include <TComponent.hpp>
#include <TKeyboardInput.h>

using namespace TortillaEngine;

class PlayerController : public TObserver, public TComponent
{
private:
    float movement_speed = 2.f;
    
    TKeyboardInput::TKey vertical_positive_movement_key  ;
    TKeyboardInput::TKey vertical_negative_movement_key  ;
    TKeyboardInput::TKey horizontal_positive_movement_key;
    TKeyboardInput::TKey horizontal_negative_movement_key;
    
       
public:

    PlayerController(TEntity* player);
    
    virtual void    handle(TMessage& m) override;
    virtual bool    parse_component(rapidxml::xml_node<>* component_node);
    
    
    void set_vertical_positive_movement_key(TKeyboardInput::TKey key)
    {
        vertical_positive_movement_key = key;
    }
    void set_vertical_negative_movement_key(TKeyboardInput::TKey key)
    {
        vertical_negative_movement_key = key;
    }
    void set_horizontal_positive_movement_key(TKeyboardInput::TKey key)
    {
        horizontal_positive_movement_key = key;
    }
    void set_horizontal_negative_movement_key(TKeyboardInput::TKey key)
    {
        horizontal_negative_movement_key = key;
    }
    
    void set_speed(float speed) { this->movement_speed = speed; }

    bool able_to_increase_vertical_position();
    bool able_to_decrease_vertical_position();
    bool able_to_increase_horizontal_position();
    bool able_to_decrease_horizontal_position();
};