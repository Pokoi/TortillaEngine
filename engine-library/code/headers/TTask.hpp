/*
 * File: TTask.hpp
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

#pragma once

namespace TortillaEngine
{
    /**
    @brief Forward declaration
    */
    class TScene;

    /**
    @brief Base class for all the tasks
    */
    class TTask
    {
    protected:

        /**
        @brief The execution priority order
        */
        int         priority;

        /**
        @brief A reference to the scene this task belongs to
        */
        TScene* owner_scene;

    public:

        /**
        @brief Creates a task with the given data
        @param priority The execution priority order
        @param scene A reference to the scene this task belongs to
        */
        TTask(int priority, TScene* scene) : priority{ priority }, owner_scene{ scene } {}

        /**
        @brief Destructor method for memory management
        */
        ~TTask()
        {
        }

        /**
        @brief Executes the task
        @param delta The time between calls
        */
        void virtual	run(float delta) {}

        /**
        @brief Initializes the task
        */
        void			initialize() {}

        /**
        @brief Finalizes the task
        */
        void			finalize() {}

        /**
        @brief Gets the execution priority order
        @return The execution priority order
        */
        int             get_priority()                   const
        {
            return this->priority;
        }

        /**
        @brief Compares the tasks execution priority order
        @param other A reference to the task to compare with
        @return If this priority is lower than the given task one
        */
        bool            operator < (const TTask& other) const
        {
            return this->priority < other.get_priority();
        }

        /**
        @brief Sets the scene this task belongs to
        @param scene A scene reference to set to
        */
        void            set_scene(TScene& scene)
        {
            owner_scene = &scene;
        }

        /**
        @brief Gets the scene this task belongs to
        @return A reference to the scene this task belongs to
        */
        TScene* get_scene()
        {
            return owner_scene;
        }

    };
}

	