/*
 * File: TCollisionsTask.hpp
 * File Created: 16th December 2019
 * ������������������������
 * Author: Jesus Fermin, 'Pokoi', Villar  (hello@pokoidev.com)
 * ������������������������
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

    class TCollisionsTask : public TTask
    {
        std::vector<TCollider*> colliders;

    public:

        TCollisionsTask(TScene* scene, int priority = 3) : TTask(priority, scene) 
        { 
           
        }

        void add_collider(TCollider * collider)
        {
            if (collider != nullptr)
            {
                colliders.push_back(collider);
            }
        }

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

        virtual void run(float delta);
    };
}