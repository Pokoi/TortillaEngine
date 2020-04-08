/*
 * File: T2DPhysicBody.hpp
 * File Created: 31st March 2020
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

#include <T2DPhysicCollider.hpp>  // For the collider list

#include <TComponent.hpp>
#include <list>
#include <memory>

namespace TortillaEngine
{
    class T2DPhysicBody : public TComponent
    {
    public:
        enum body_types {STATIC, DYNAMIC, KINEMATIC};

    private:
        std::shared_ptr<class b2Body> body = nullptr;
        class b2MassData* mass_data = nullptr;

        std::list <std::shared_ptr<T2DPhysicCollider> > colliders;

    public:
        T2DPhysicBody(class T2DPhysicWorld & world, body_types type);
        ~T2DPhysicBody();

        float get_mass();

        bool is_dynamic();
        bool is_static();
        bool is_kinematic();

        void set_dynamic();
        void set_static();
        void set_kinematic();
        
        void set_mass(float mass);
        void set_position(glm::vec2 new_position);

        void activate();
        void inactivate();

        void add_collider(T2DPhysicCollider& collider);
    };
}