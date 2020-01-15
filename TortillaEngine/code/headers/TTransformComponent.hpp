/*
 * File: TTransformComponent.hpp
 * File Created: 14th January 2020
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
#include <TComponent.hpp>
#include <glm/glm.hpp>
#include <Node.hpp>

namespace TortillaEngine
{
    class TTransformComponent : TComponent
    {
        glm::vec3 position;
        glm::vec3 scale;
        
        // Rotation in y axis
        float yaw;
        // Rotation in z axis
        float roll;        
        // Rotation in X axis
        float pitch;

        std::shared_ptr<glt::Node> transform;


    public:
        TTransformComponent(TEntity* entity);

        glm::vec3   get_position() const 
        { 
            return position;
        }

        glm::vec3   get_scale   () const
        {
            return scale;
        }

        float       get_yaw     () const
        {
            return yaw;
        }

        float       get_roll    () const
        {
            return roll;
        }

        float       get_pitch   () const
        {
            return pitch;
        }


        void translate      (float x            , float y           , float z           )
        {
            set_position(x, y, z);

            transform->translate(position);
        }
        
        void rotate         (float pitch_angle  , float yaw_angle   , float roll_angle  )
        {
            set_rotation(pitch_angle, yaw_angle, roll_angle);

            transform->rotate_around_x(pitch);
            transform->rotate_around_y(yaw);
            transform->rotate_around_z(roll);
        }
        
        void scale          (float scale_x      , float scale_y     , float scale_z     )
        {
            set_scale(scale_x, scale_y, scale_z);

            transform->scale(scale.x, scale.y, scale.z);
        }
        
        void set_position   (float x            , float y           , float z           )
        {
            position = glm::vec3(x, y, z);
        }
        
        void set_rotation   (float pitch_angle  , float yaw_angle   , float roll_angle  )
        {
            pitch   = glm::radians(pitch_angle);
            yaw     = glm::radians(yaw_angle);
            roll    = glm::radians(roll_angle);
        }
        
        void set_scale      (float scale_x      , float scale_y     , float scale_z     )
        {
            scale = glm::vec3(scale_x, scale_y, scale_z);            
        }

       
        virtual void    initialize() override {}

        virtual void    execute() override    {}

        virtual bool    parse_component(rapidxml::xml_node<>* component_node) override;
        

		TTransformComponent operator * (TTransformComponent& other) const 
        {
            //TODO : preguntar sobre el significado de multiplicar dos transforms
        }

    };
}
