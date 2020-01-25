/*
 * File: UnitTesting.hpp
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

#include <TWindow.hpp>
#include <iostream>
#include <string>
#include <memory>
#include <TScene.hpp>
#include <TRenderComponent.hpp>
#include <TComponent.hpp>
#include <TSound.hpp>
#include "PlayerController.hpp"
#include <TSphereCollider.hpp>
#include <TInputTask.hpp>
#include <TRenderTask.hpp>
#include <TCameraComponent.hpp>
#include <TLightComponent.hpp>
#include <Windows.h>

using namespace TortillaEngine;

class UnitTesting
{

private:
    
    UnitTesting()
    {}

public:

    static UnitTesting* get()
    {
        static UnitTesting * instance;
        
        if (instance == nullptr)
        {
            instance = new UnitTesting();
        }

        return instance;
    }


    void CreateWindowTEST()
    {
        // error: ninguno
        // observaciones: se cierra inmediatamente

        TWindow window((char*)"ventana", 1280, 720);
    }
    /*
    */
    void WindowRenderCycleTEST()
    {
        //error:

        TWindow window((char*)"ventana", 1280, 720);
        window.reset();
        window.swap_buffers();
    }

    void CreateSceneTEST()
    {
        //error:

        TWindow window((char*)"ventana", 1280, 720);
        TScene scene(&window);
    }

    void CreateEntityTEST()
    {
        //error:

        TWindow window((char*)"ventana", 1280, 720);
        TScene scene(&window);
        TEntity player("Player", &scene, nullptr);
    }

   
    void AddComponentToEntityTEST()
    {
        //error:

        TWindow window((char*)"ventana", 1280, 720);
        TScene scene(&window);
        TEntity player("Player", &scene, nullptr);

        player.add_component("Collider", std::make_shared<TSphereCollider>( &player, 0, 0, 0, 5 ));

    }

    void TransformComponentTEST()
    {
        // error:

        TWindow window((char*)"ventana", 1280, 720);
        TScene scene(&window);
        TEntity player("Player", &scene, nullptr);

        float* initial_position = player.get_transform().get_position();
        
        std::cout << "x: " << initial_position[0] << " y:" << initial_position[1] << " z: " << initial_position[2] << "\n";
        
        player.get_transform().translate(10, 10, 10);

        float* final_position = player.get_transform().get_position();
        std::cout << "x: " << final_position[0] << " y:" << final_position[1] << " z: " << final_position[2] << "\n";
    
    }
    /*

    void InputEntityMessageTEST()
    {
        //error:

        TWindow window((char*)"ventana", 1280, 720);
        TScene scene(&window);
        TEntity player("Player", &scene, nullptr);

        player.add_component("Controller", std::make_shared<PlayerController>(new PlayerController{ &player }));

        TInputTask input{ &scene };

        while (true)
        {
            input.run(0);
            Sleep(500);
        }
    }
    */
    /*
    void RenderTEST()
    {
        TWindow window((char*)"ventana", 1280, 720);
        TScene scene(&window);
        TEntity player("Player", &scene, nullptr);

        TEntity camera("Camera", &scene, nullptr);
        std::shared_ptr<TCameraComponent> camera_component{ new TCameraComponent{ &camera, 1.f, 2000.f, 60.f, 1.f } };
        camera.add_component("Camera", camera_component);

        TEntity light("Light", &scene, nullptr);
        std::shared_ptr<TLightComponent> light_component{ new TLightComponent{ &light, {1, 0, 0}, 0.7f } };
        light.add_component("Light", light_component);

        std::shared_ptr < TRenderComponent> render_component{ new TRenderComponent{ &player, "../../assets/head.obj" } };
        player.add_component("Render Model",render_component);

        

        TRenderTask render{ &scene };
        render.add_camera(camera_component.get());
        render.add_light(light_component.get());
        render.add_component(render_component.get());

        while (true)
        {
            //window.reset();
            render.run(0);
            //window.swap_buffers();
            Sleep(500);
        }
    }
    */

    void SoundTEST()
    {
        TSound* sound_effect = new TSound;
        sound_effect->LoadSound((char*)"../../assets/sound.wav");
        sound_effect->PlaySoundEffect(-1, 1);
    }

    
    

};