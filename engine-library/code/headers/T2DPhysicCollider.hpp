/*
 * File: T2DPhysicCollider.hpp
 * File Created: 8th April 2020
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

#include <memory>
#include <glm/glm.hpp>

namespace TortillaEngine
{
    class T2DPhysicCollider
    {
        std::shared_ptr<class b2FixtureDef> fixture = nullptr;
     

    public:

        T2DPhysicCollider   (
                                std::shared_ptr<class T2DPhysicBody> & body, 
                                glm::vec2 local_position, 
                                float radius, 
                                float density       = 1.f,
                                float friction      = 0.f,
                                float restitution   = 0.f
                            );

        T2DPhysicCollider   (
                                std::shared_ptr<class T2DPhysicBody> & body, 
                                glm::vec2 local_position,
                                glm::vec2 vertices[4],                                
                                float density       = 1.f,
                                float friction      = 0.f,
                                float restitution   = 0.f
                            );

        T2DPhysicCollider   (
                                std::shared_ptr<class T2DPhysicBody>& body, 
                                glm::vec2 local_position, 
                                glm::vec2 origin, 
                                glm::vec2 end, 
                                float density       = 1.f, 
                                float friction      = 0.f,
                                float restitution   = 0.f
                            );

        void set_density     (float value);
        void set_friction    (float value);
        void set_restitution (float value);
        
        float get_density();
        float get_friction();
        float get_restitution();

        class b2FixtureDef& get_fixture()
        {
            return *fixture;
        }

    };
}