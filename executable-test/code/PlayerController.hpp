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
#include <string>

using namespace TortillaEngine;

/**
@brief The controller of player's behaviour
*/
class PlayerController : public TObserver, public TComponent
{
private:

    /**
    @brief The player movement speed
    */
    float movement_speed = 0.05f;
      
       
public:

    /**
    @brief Creates the component
    @param player A reference to the entity this component is attached to
    */
    PlayerController(TEntity* player);
    
    /**
    @brief Handle the messages
    @param m The message
    */
    virtual void    handle(TMessage& m) override;
    
    /**
    @brief Load the component data from a xml file
    @param component_node The xml node with the data
    */
    virtual bool    parse_component(rapidxml::xml_node<>* component_node);
       
    /**
    @brief Sets the speed of the player character
    @param speed The desired speed
    */
    void set_speed(float speed) { this->movement_speed = speed; }
    
    /**
    @brief Checks if the player character can moves towards lower z values
    */
    bool able_to_increase_vertical_position();
    /**
    @brief Checks if the player character can moves towards greater z values
    */
    bool able_to_decrease_vertical_position();
    /**
    @brief Checks if the player character can moves towards lower x values
    */
    bool able_to_increase_horizontal_position();
    /**
    @brief Checks if the player character can moves towards greater x values
    */
    bool able_to_decrease_horizontal_position();
};