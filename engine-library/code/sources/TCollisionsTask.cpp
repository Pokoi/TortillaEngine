/*
 * File: TCollisionsTask.cpp
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

#include <TCollisionsTask.hpp>
#include <TVariant.hpp>
#include <TScene.hpp>
#include <string>

namespace TortillaEngine
{
    /**
    @brief Execute the collision detection check of all the subscribed colliders.
    @param delta The time between execution calls.
    */
    void TCollisionsTask::run(float delta)
    {
        
        for (TCollider* collider1 : colliders)
        {
            for (TCollider* collider2 : colliders)
            {
                if (collider1->collides(*collider2))
                {
                    //When a collision occurs, a message its sent with the info of the collision
                    TMessage message(collider1->get_parent()->get_name() + "_COLLIDES");
                    TVariant value(collider2->get_parent()->get_name());
                    message.add_parameter("collision", value);
                    owner_scene->get_dispatcher()->send(message);
                }
            }
        }        
    }
}