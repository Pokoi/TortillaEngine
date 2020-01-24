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
using namespace TortillaEngine;


int main()
{
    // TEST DE CREAR VENTANA
	// error: ninguno
    // observaciones: se cierra inmediatamente    
    TWindow window ((char *) "ventana", 1280, 720);    
    
	return 0;
}



void Test()
{

    // TEST DE CREAR VENTANA
    // error: ninguno
    // observaciones: se cierra inmediatamente
    /*
    char name [] = "ventana";
    TWindow window (name, 1280, 720);
    window.reset();
    window.swap_buffers();
    */


    /*

    // Crear escena
    TScene scene(&window);

    TEntity player("Player", &scene, nullptr);
    player.add_component("Render", std::make_shared<TRenderComponent>(new TRenderComponent{ &player }));



    scene.run();
    */

    // TEST DE SONIDO
    // error: no se encontró SDL_mixer.dll
    /*
    TSound * sound_effect = new TSound;
    sound_effect->LoadSound((char *)"../../assets/sound.wav");
    sound_effect->PlaySound(-1,1);
    */
}