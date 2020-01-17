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
	class TKernel
	{
		std::multiset<TTask*> tasks;
		bool running;        

	public:

		TKernel() : tasks{ nullptr }, running{false}
        {
            
        }

		void exec()
		{
            float delta_time = 1.f /60.f;
			running = true;

			while (running)
			{
                //TTimer timer;
                //timer.start();

				for (TTask* task : tasks)
				{
					task->initialize();
				}

				for (TTask* task : tasks)
				{
					task->run(delta_time);
				}

				for (TTask* task : tasks)
				{
					task->finalize();
				}
			}
		}

		void stop() { running = false; }

        void add_task   (TTask& task)
        {
            tasks.insert(&task);
        }

        void remove_task(TTask& task)
        {
            tasks.erase(&task);
        }       

        ~TKernel()
        {
            tasks.clear();
        }
	};



}