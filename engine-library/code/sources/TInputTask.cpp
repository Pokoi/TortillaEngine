/*
 * File: TTask.cpp
 * File Created: 16th January 2020
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

#include <SDL.h>
#include <TInputTask.hpp>
#include <TKernel.hpp>
#include <TScene.hpp>


namespace TortillaEngine
{
    /**
    @brief Execute the input detection.
    @param delta The time between execution calls.
    */
    void TInputTask::run(float delta)
    {
        SDL_Event event;

        while (owner_scene->get_window()->poll_events(event))
        {
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE)
            {
                owner_scene->get_kernel()->stop();
            }

            if (event.type == SDL_KEYDOWN)
            {
                //Create an event
                events.push_back(std::make_shared<TEvent>(TEvent::Type::KEY_PRESSED, keyboard.translate_sdl_code(event.key.keysym.sym).get_name() ));
            }               
            
        }
    }
}