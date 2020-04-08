/*
 * File: T2DPhysicCollider.cpp
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

#include <T2DPhysicCollider.hpp>
#include <T2DPhysicBody.hpp>
#include <box2d.h>

namespace TortillaEngine
{
    T2DPhysicCollider::T2DPhysicCollider (
                                            std::shared_ptr<class T2DPhysicBody>& body, 
                                            glm::vec2 local_position,
                                            float radius,
                                            float density,
                                            float friction,
                                            float restitution
                                         )
    {
        fixture = std::make_shared<b2FixtureDef>();

        set_density(density);
        set_friction(density);
        set_restitution(restitution);

        b2CircleShape shape;
        shape.m_p.Set(local_position.x, local_position.y);
        shape.m_radius = radius;

        fixture->shape = &shape;

        body->add_collider(*this);
    }

    T2DPhysicCollider::T2DPhysicCollider (
                                            std::shared_ptr<class T2DPhysicBody>& body, 
                                            glm::vec2 local_position, 
                                            glm::vec2 vertices[4],                                            
                                            float density,
                                            float friction,
                                            float restitution
                                        )
    {
        fixture = std::make_shared<b2FixtureDef>();

        set_density(density);
        set_friction(density);
        set_restitution(restitution);

        b2Vec2 parsed_vertices[4];
        
        parsed_vertices[0].Set(vertices[0].x, vertices[0].y);
        parsed_vertices[1].Set(vertices[1].x, vertices[1].y);
        parsed_vertices[2].Set(vertices[2].x, vertices[2].y);
        parsed_vertices[3].Set(vertices[3].x, vertices[3].y);
                    

        b2PolygonShape shape;
        shape.Set(parsed_vertices, 4);        
        
        fixture->shape = &shape;

        body->add_collider(*this);
    }

    T2DPhysicCollider::T2DPhysicCollider (
                                            std::shared_ptr<class T2DPhysicBody>& body,
                                            glm::vec2 local_position,
                                            glm::vec2 origin,
                                            glm::vec2 end,
                                            float density,
                                            float friction,
                                            float restitution
                                        )
    {
        fixture = std::make_shared<b2FixtureDef>();

        set_density(density);
        set_friction(density);
        set_restitution(restitution);

        b2Vec2 parsed_vertices[2];

        parsed_vertices[0].Set(origin.x, origin.y);
        parsed_vertices[1].Set(end.x, end.y);      

        b2EdgeShape shape;
        shape.Set(parsed_vertices[0], parsed_vertices[1]);

        fixture->shape = &shape;

    }

    void T2DPhysicCollider::set_density(float value)
    {
        fixture->density = value;
    }

    void T2DPhysicCollider::set_friction(float value)
    {
        fixture->friction = value;
    }

    void T2DPhysicCollider::set_restitution(float value)
    {
        fixture->restitution = value;
    }

    float T2DPhysicCollider::get_density()
    {
        return fixture->density;
    }

    float T2DPhysicCollider::get_friction()
    {
        return fixture->friction;
    }

    float T2DPhysicCollider::get_restitution()
    {
        return fixture->restitution;
    }

}