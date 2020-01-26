/*
 * File: EnemyController.hpp
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
#include <TScriptComponent.hpp>

using namespace TortillaEngine;

/**
@brief Controller of enemy behaviour
*/
class EnemyController : public TObserver, public TScriptComponent
{
private:

    /**
    @brief Movement speed
    */
    float movement_speed = 0.03f;

    /**
    @brief A reference to the entity this component is attached to
    */
    TEntity* target;

public:
    /**
    @brief Creates the controller
    @param parent A reference to the entity this component is attached to
    @param target A reference to the entity to follow 
    */
    EnemyController(TEntity* parent, TEntity* target);

    /**
    @brief Handles the recieved messages
    @param m The message
    */
    virtual void handle(TMessage& m) override;

    /**
    @brief Load the data from a xml file
    @param component_node The xml node with the data
    */
    virtual bool parse_component(rapidxml::xml_node<>* component_node);
    
    /**
    @brief Executes the component
    */
    virtual void execute();

    /**
    @brief Subscribes to the script task
    */
    virtual void subscribe_to_task() override;
};