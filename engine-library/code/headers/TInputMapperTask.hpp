/*
 * File: TInputMapperTask.hpp
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

#include <TTask.hpp>
#include <TInputTask.hpp>
#include <rapidxml-1.13/rapidxml.hpp>
#include <memory>
#include <map>
#include <string>

namespace TortillaEngine
{
    class TInputMapperTask : public TTask
    {
        std::map<std::string, std::string > actions;

    public:

        /**
        @brief Creates the task.
        @param scene A reference to the scene where this task belong.
        @param priority The execution order in kernel.
        */
        TInputMapperTask(TScene* scene, int priority = 2) : TTask(priority, scene)
        {}

        /**
        @brief Add an action to the action map.
        @param key The input id of the action.
        @param action_name The name of the action
        */
        void add_action(const std::string& key, const std::string& action_name)
        {            
            actions[key] = action_name;
        }       

        /**
        @brief Recives the events in order and launch the messages of the actions.
        @param delta The time between execution calls.
        */
        virtual void run(float delta);

        /**
        @brief Loads the map from a xml file.
        @param The path of the file to load.
        */
        void load_from_xml(const std::string& path);


    };
}