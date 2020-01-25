/*
 * File: TCollisionsTask.hpp
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
#include <TCollider.hpp>
#include <TEntity.hpp>
#include <vector>

namespace TortillaEngine
{
    class TScene;

    /**
    @brief The task class to manage collisions in a scene.
    */
    class TCollisionsTask : public TTask
    {
        /**
        @brief The collection of colliders subscribed to the task         
        */
        std::vector<TCollider*> colliders;

    public:

        /**
        @brief Creates the task.
        @param scene A reference to the scene where this task belong.
        @param priority The execution order in kernel.
        */
        TCollisionsTask(TScene* scene, int priority = 4) : TTask(priority, scene) 
        { 
           
        }

        /**
        @brief Subscribe a collider to the collection.
        @param collider A reference to the collider to add.
        */
        void add_collider(TCollider * collider)
        {
            if (collider != nullptr)
            {
                colliders.push_back(collider);
            }
        }

        /**
        @brief Unsubscribe a collider to the collection.
        @param collider A reference to the script to remove.
        */
        void remove_collider(TCollider* collider)
        {
            if (collider != nullptr)
            {
                std::vector<TCollider*>::iterator it = std::find(colliders.begin(), colliders.end(), collider);
                if(it != colliders.end())
                { 
                    colliders.erase(it);
                }
            }
        }

        /**
        @brief Execute the collision detection check of all the subscribed colliders.
        @param delta The time between execution calls.
        */
        virtual void run(float delta);
    };
}
