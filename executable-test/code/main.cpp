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
#include "UnitTesting.hpp"
using namespace TortillaEngine;


int main()
{
    
    /////////////////////////////////////////
    //  Window
    UnitTesting::get()->CreateWindowTEST();
    UnitTesting::get()->WindowRenderCycleTEST();

    /////////////////////////////////////////
    //  Sound
    //UnitTesting::get()->SoundTEST();

    /////////////////////////////////////////
    //  Scene
    UnitTesting::get()->CreateSceneTEST();

    /////////////////////////////////////////
    //  Entities and component
    //UnitTesting::get()->CreateEntityTEST();
    //UnitTesting::get()->AddComponentToEntityTEST();
    UnitTesting::get()->TransformComponentTEST();

    /////////////////////////////////////////
    //  Input and Messages
    //UnitTesting::get()->InputEntityMessageTEST();

    /////////////////////////////////////////
    //  Render
    //UnitTesting::get()->RenderTEST();

    
	return 0;
}


