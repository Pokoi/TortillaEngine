/*
 * File: PlayerController.cpp
 * File Created: 24th January 2020
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

#include "PlayerController.hpp"
#include <TEntity.hpp>
#include <TScene.hpp>
#include "GameManager.hpp"
#include <string>

/**
@brief Creates the component
@param player A reference to the entity this component is attached to
*/
PlayerController::PlayerController(TEntity* player)
    : TComponent{ player }
{
    parent->get_scene()->get_dispatcher()->add(*this, "Move Up");
    parent->get_scene()->get_dispatcher()->add(*this, "Move Down");
    parent->get_scene()->get_dispatcher()->add(*this, "Move Left");
    parent->get_scene()->get_dispatcher()->add(*this, "Move Right");
}

/**
@brief Handle the messages
@param m The message
*/
void PlayerController::handle(TMessage& m)
{
    
    if (m.get_id() == "Move Up")
    {
        if (able_to_decrease_vertical_position())
        {
            parent->get_transform().translate(0, 0, -movement_speed);
        }
        else
        {
            GameManager::get()->play_sound();
        }
    }
    if (m.get_id() == "Move Down")
    {
        if (able_to_increase_vertical_position())
        {
            parent->get_transform().translate(0, 0, movement_speed);
        }
        else
        {
            GameManager::get()->play_sound();
        }
    }
    if (m.get_id() == "Move Left")
    {
        if (able_to_decrease_horizontal_position())
        {
            parent->get_transform().translate(-movement_speed, 0, 0);
        }
        else
        {
            GameManager::get()->play_sound();
        }
    }
    if (m.get_id() == "Move Right")
    {
        if (able_to_increase_horizontal_position())
        {
            parent->get_transform().translate(movement_speed, 0, 0);
        }
        else
        {
            GameManager::get()->play_sound();
        }
    }
    
}

/**
@brief Load the component data from a xml file
@param component_node The xml node with the data
*/
bool PlayerController::parse_component(rapidxml::xml_node<>* component_node)
{
    return false;
}

/**
@brief Checks if the player character can moves towards lower z values
*/
bool PlayerController::able_to_increase_vertical_position()
{
    float z = parent->get_transform().get_position().z;
    return z < GameManager::get()->limits.max_z;
}

/**
@brief Checks if the player character can moves towards greater z values
*/
bool PlayerController::able_to_decrease_vertical_position()
{
    float z = parent->get_transform().get_position().z;
    return  z > GameManager::get()->limits.min_z;
}

/**
@brief Checks if the player character can moves towards lower x values
*/
bool PlayerController::able_to_increase_horizontal_position()
{
    float x = parent->get_transform().get_position().x;
    return x < GameManager::get()->limits.max_x;
}

/**
@brief Checks if the player character can moves towards greater x values
*/
bool PlayerController::able_to_decrease_horizontal_position()
{
    float x = parent->get_transform().get_position().x;
    return x > GameManager::get()->limits.min_x;
}
