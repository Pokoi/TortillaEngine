/*
 * File: TCollider.cpp
 * File Created: 16th January 2020
 * 末末末末末末末末末末末末
 * Author: Jesus Fermin, 'Pokoi', Villar  (hello@pokoidev.com)
 * 末末末末末末末末末末末末
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

#include <TCollider.hpp>
#include <glm/glm.hpp>
#include <Node.hpp>
#include <TEntity.hpp>
#include <TScene.hpp>
#include <string>

namespace TortillaEngine
{
    /**
    @brief Creates a collider with the given values.
    @param parent The entity this collider is attached to.
    @param x_offset The offset in x axis with parent position.
    @param y_offset The offset in y axis with parent position.
    @param z_offset The offset in z axis with parent position.
    */
    TCollider::TCollider(
                            TEntity* parent,
                            float x_offset,
                            float y_offset,
                            float z_offset
                        ) : TComponent(parent)
    {
        this->offset.x = x_offset;
        this->offset.y = y_offset;
        this->offset.z = z_offset;

        calculate_center();

        parent->get_scene()->get_dispatcher()->add(*this, parent->get_name() + "_RESIZED");
        parent->get_scene()->get_dispatcher()->add(*this, parent->get_name() + "_MOVED");

        parent->get_scene()->get_collision_task()->add_collider(this);
    }
    
    /**
    @brief Calculates the center of the collider
    */
    void TCollider::calculate_center()
    {
        float* parent_position = parent->get_transform().get_position();

        this->center.x = *parent_position;
        this->center.y = *(parent_position + 1);
        this->center.z = *(parent_position + 2);
    }
    
    /**
    @brief Apply an scale to the collider
    @param x The scale in x axis
    @param y The scale in y axis
    @param z The scale in z axis
    */
    void TCollider::resize(float x, float y, float z)
    {
        this->offset.x *= x;
        this->offset.y *= y;
        this->offset.z *= z;

        calculate_center();
    }

    /**
    @brief Handle the messages this collider is subscribed to
    @param m The message
    */
    void TCollider::handle(TMessage& m)
    {
        //Resizes the collider when parents entity is resized
        if (m.get_id() == parent->get_name() + "_RESIZED")
        {
            resize(m["x"].to_float(), m["y"].to_float(), m["z"].to_float());
        }

        //Moves the collider when parents entity is moved
        if (m.get_id() == parent->get_name() + "_MOVED")
        {
            calculate_center();
        }
    }
   
    /**
    @brief Load the component info from a xml node.
    @param component_node A reference to the node with this component info.
    */
    bool TCollider::parse_component(rapidxml::xml_node<>* component_node)
    {
        return false;
    }
};
