/*
 * File: TScriptTask.hpp
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


#include <TScriptComponent.hpp>
#include <TTask.hpp>
#include <vector>

namespace TortillaEngine
{
    /**
    @brief Task that manage all the scripts in a scene.
    */
    class TScriptTask : public TTask
    {
        /**
        @brief Collection of scripts subscribed to the task.
        */
        std::vector<TScriptComponent*> scripts;

    public:

        /**
        @brief Creates the task.
        @param scene A reference to the scene where this task belong.
        @param priority The execution order in kernel.
        */
        TScriptTask(TScene* scene, int priority = 3) : TTask(priority, scene)
        {

        }

        /**
        @brief Subscribe a script to the collection.
        @param script A reference to the script to add.
        */
        void add_script(TScriptComponent* script)
        {
            if (script != nullptr)
            {
                scripts.push_back(script);
            }
        }

        /**
        @brief Unsubscribe a script to the collection.
        @param script A reference to the script to remove.
        */
        void remove_script(TScriptComponent* script)
        {
            if (script != nullptr)
            {
                std::vector<TScriptComponent*>::iterator it = std::find(scripts.begin(), scripts.end(), script);
                if (it != scripts.end())
                {
                    scripts.erase(it);
                }
            }
        }

        /**
        @brief Execute all the scripts subscribed to the collection in order of subscription.
        @param delta The time between execution calls.
        */
        virtual void run(float delta)
        {
            for (TScriptComponent* script : scripts)
            {
                script->execute();
            }
        }
    };
}