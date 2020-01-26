/*
 * File: TKernel.hpp
 * File Created: 9th January 2020
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

#include <set>

#include <TTask.hpp>
#include <TTimer.hpp>
#include <TCollisionsTask.hpp>

namespace TortillaEngine
{
    /**
    @brief Management of the tasks execution cycle
    */
	class TKernel
	{
        /**
        @brief The collection of tasks
        */
		std::multiset<TTask*> tasks;
		bool running;        

	public:

        /**
        @brief Creates a kernel
        */
		TKernel() : tasks{ nullptr }, running{false}
        {
            
        }

        /**
        @brief Executes all the tasks in order or priority before initialize them.
        */
		void exec()
		{
            float delta_time = 1.f /60.f;
			running = true;

			for (TTask* task : tasks)
			{
				task->initialize();
			}

			while (running)
			{   
				for (TTask* task : tasks)
				{
                    if (task != nullptr)
                    {
					    task->run(delta_time);
                    }
				}
			}

			for (TTask* task : tasks)
			{
				task->finalize();
			}
		}

        /**
        @brief Stops the execution
        */
		void stop() { running = false; }

        /**
        @brief Adds a given task to the collection of tasks
        @param task A reference to the task to add.
        */
        void add_task   (TTask& task)
        {
            tasks.insert(&task);
        }

        /**
        @brief Removes a given task from the collection of tasks
        @param A reference to the task to removes.
        */
        void remove_task(TTask& task)
        {
            tasks.erase(&task);
        }       

        /**
        @brief Destructor method for memory management
        */
        ~TKernel()
        {
            tasks.clear();
        }
	};



}