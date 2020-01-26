/*
 * File: main.cpp
 * File Created: 7th January 2020
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


#include <TWindow.hpp>
#include <iostream>
#include <string>
#include <memory>
#include <TScene.hpp>
#include <TRenderComponent.hpp>
#include <TComponent.hpp>
#include <TSound.hpp>
#include "PlayerController.hpp"
#include "EnemyController.hpp"
#include "GameManager.hpp"

using namespace TortillaEngine;


int main()
{
    
    TWindow window{(char*) "ventana", 1500,900 };
    
    TScene scene(&window);
    scene.load("../../assets/scene.xml");  
    
    //Add the custom components
    std::shared_ptr <TEntity> player = scene.get_entity("Player");
    player->add_component("PlayerController", std::make_shared<PlayerController>(player.get()));

    std::shared_ptr <TEntity> enemy = scene.get_entity("Enemy");
    enemy->add_component("EnemyController", std::make_shared<EnemyController>(enemy.get(), player.get()));

    std::dynamic_pointer_cast<TInputMapperTask>(scene.get_task("TInputMapperTask"))->add_action("KEY_PRESSED_A", "Move Left");
    std::dynamic_pointer_cast<TInputMapperTask>(scene.get_task("TInputMapperTask"))->add_action("KEY_PRESSED_S", "Move Down");
    std::dynamic_pointer_cast<TInputMapperTask>(scene.get_task("TInputMapperTask"))->add_action("KEY_PRESSED_D", "Move Right");
    std::dynamic_pointer_cast<TInputMapperTask>(scene.get_task("TInputMapperTask"))->add_action("KEY_PRESSED_W", "Move Up");
    
    GameManager::get()->limits.max_x = 100;
    GameManager::get()->limits.max_z = 100;
    GameManager::get()->limits.min_x = -100;
    GameManager::get()->limits.min_z = -100;

    scene.run();

	return 0;
}


