/*
 * File: TInputTask.hpp
 * File Created: 16th December 2019
 * ––––––––––––––––––––––––
 * Author: Jesus Fermin, 'Pokoi', Villar  (hello@pokoidev.com)
 * ––––––––––––––––––––––––
 * MIT License
 *
 * Copyright (c) 2019 Pokoidev
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

#include <TTask.hpp>
#include <TKeyboardInput.h>
#include <TEvent.hpp>
#include <list>
#include <memory>

namespace TortillaEngine
{
    /**
    @brief The task class to manage the input.
    */
    class TInputTask : public TTask
    {
        /**
        @brief Reference to the keyboard manager.
        */
        TKeyboardInput keyboard;

        /**
        @brief Collection of events
        */
        std::list<std::shared_ptr<TEvent>> events;

    public:

        /**
        @brief Creates the task.
        @param scene A reference to the scene where this task belong.
        @param priority The execution order in kernel. 
        */
        TInputTask(TScene* scene, int priority = 2 ) : TTask(priority, scene) { }

        /**
        @brief Execute the input detection.
        @param delta The time between execution calls.
        */
        virtual void run(float delta) override;

        /**
        @brief Gets the first event of the collection of events.        
        */
        std::shared_ptr<TEvent> get_event()
        {
            std::shared_ptr<TEvent> event = events.front();
            events.pop_front();
            return event;
        }

    };
}