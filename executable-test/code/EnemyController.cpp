/*
 * File: EnemyController.cpp
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

#include "EnemyController.hpp"
#include "GameManager.hpp"
#include <TEntity.hpp>
#include <TScene.hpp>
#include <TScriptTask.hpp>
#include <memory>
#include <math.h>

 /**
@brief Creates the controller
@param parent A reference to the entity this component is attached to
@param target A reference to the entity to follow
*/
EnemyController::EnemyController(
                                    TEntity* parent,
                                    TEntity* target
                                ) 
                                :   TScriptComponent{ parent },
                                    target{target}
{
    subscribe_to_task();
}

/**
@brief Handles the recieved messages
@param m The message
*/
void EnemyController::handle(TMessage& m)
{
    if (
        m.get_id() == parent->get_name() + "_COLLIDES" &&
        m["collision"].to_string() == target->get_name()
        )
    {
        GameManager::get()->reset_game(parent->get_scene());
    }
}

/**
@brief Load the data from a xml file
@param component_node The xml node with the data
*/
bool EnemyController::parse_component(rapidxml::xml_node<>* component_node)
{
    return false;
}

/**
@brief Executes the component
*/
void EnemyController::execute()
{
    glm::vec4 target_position  = target->get_transform().get_position();
    glm::vec4 self_position    = parent->get_transform().get_position();

    double delta_x = (double)target_position.x - (double)self_position.x;
    double delta_y = (double)target_position.y - (double)self_position.y;
    double delta_z = (double)target_position.z - (double)self_position.z;

    float magnitude = sqrt(
                            (delta_x * delta_x) +
                            (delta_y * delta_y) +
                            (delta_z * delta_z)
                        );
    float normalized_x = delta_x / magnitude;
    float normalized_y = delta_y / magnitude;
    float normalized_z = delta_z / magnitude;

    parent->get_transform().translate(
                                        normalized_x * movement_speed,
                                        normalized_y * movement_speed,
                                        normalized_z * movement_speed
                                      );
}

/**
@brief Subscribes to the script task
*/
void EnemyController::subscribe_to_task()
{    
    std::dynamic_pointer_cast<TScriptTask>(parent->get_scene()->get_task("TScriptTask"))->add_script(this);
}
