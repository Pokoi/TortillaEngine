/*
 * File: T2DPhysicBody.cpp
 * File Created: 8th January 2020
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

#include <T2DPhysicBody.hpp>
#include <T2DPhysicWorld.hpp>
#include <box2d.h>

namespace TortillaEngine
{
    T2DPhysicBody::T2DPhysicBody(class T2DPhysicWorld& world, body_types type)
    {
        body = world.create_body();

        if      (type == body_types::DYNAMIC    ) set_dynamic();
        else if (type == body_types::STATIC     ) set_static();
        else if (type == body_types::KINEMATIC  ) set_kinematic();

        mass_data = new b2MassData();
        activate();
    }

    T2DPhysicBody::~T2DPhysicBody()
    {
        delete mass_data;        
    }

    float T2DPhysicBody::get_mass()
    {
        
        return body->GetMass();
    }

    bool T2DPhysicBody::is_dynamic()
    {
        return body->GetType() == b2BodyType::b2_dynamicBody;
    }

    bool T2DPhysicBody::is_static()
    {
        return body->GetType() == b2BodyType::b2_staticBody;
    }

    bool T2DPhysicBody::is_kinematic()
    {
        return body->GetType() == b2BodyType::b2_kinematicBody;
    }

    void T2DPhysicBody::set_dynamic()
    {
        body->SetType(b2_dynamicBody);
    }
    
    void T2DPhysicBody::set_static()
    {
        body->SetType(b2_staticBody);
    }

    void T2DPhysicBody::set_kinematic()
    {
        body->SetType(b2_kinematicBody);
    }
    
    void T2DPhysicBody::set_mass(float mass)
    {        
        mass_data->mass = mass;
        body->SetMassData(mass_data);
        body->ResetMassData();
    }
    
    void T2DPhysicBody::set_position(glm::vec2 new_position)
    {
        body->SetTransform(b2Vec2{ new_position.x, new_position.y }, 0);
    }
    
    void T2DPhysicBody::activate()
    {
        body->SetActive(true);
    }
    
    void T2DPhysicBody::inactivate()
    {
        body->SetActive(false);
    }
    void T2DPhysicBody::add_collider(T2DPhysicCollider& collider)
    {
        colliders.push_back(std::make_shared<T2DPhysicCollider>(collider));
        body->CreateFixture(&collider.get_fixture());
    }
}