/*
 * File: TTransformComponent.cpp
 * File Created: 15th January 2020
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

#include <TTransformComponent.hpp>
#include <TEntity.hpp>
#include <TScene.hpp>
#include <TVariant.hpp>
#include <Math.hpp>


namespace TortillaEngine
{
	TTransformComponent::TTransformComponent	(
													TEntity* entity,
													float x_position,
													float y_position,
													float z_position,
													float pitch_angle,
													float yaw_angle,
													float roll_angle,
													float x_scale,
													float y_scale,
													float z_scale
												) : TComponent (entity)
	{
        transformation = new glt::Matrix44();
        translate(x_position	, y_position, z_position);
		rotate	 (pitch_angle	, yaw_angle	, roll_angle);
		scale	 (x_scale		, y_scale	, z_scale	);
	}

    TTransformComponent::TTransformComponent(glt::Matrix44 transformation)
    {
        this->transformation = &transformation;
    }

    TTransformComponent::~TTransformComponent()
    {
        delete transformation;
    }

    glt::Matrix44* TTransformComponent::get_transformation() const
    {
        return transformation;
    }
    	

	inline void TTransformComponent::translate	(float x		  , float y			, float z			)
	{        
        *transformation = glm::translate(*transformation, glt::Vector3{ x,y,z });       
    }

	inline void TTransformComponent::rotate		(float pitch_angle, float yaw_angle	, float roll_angle	)
	{
		if (pitch_angle)
		{
            *transformation = glm::rotate(*transformation, pitch_angle, glm::vec3(1.f, 0.f, 0.f));
		}
		if (yaw_angle)
		{
            *transformation = glm::rotate(*transformation, yaw_angle, glm::vec3(0.f, 1.f, 0.f));
		}
		if (roll_angle)
		{
            *transformation = glm::rotate(*transformation, roll_angle, glm::vec3(0.f, 0.f, 1.f));
		}
	}

	inline void TTransformComponent::scale		(float scale_x	  , float scale_y	, float scale_z		)
	{
        *transformation = glm::scale(*transformation, glm::vec3(scale_x, scale_y, scale_z));
    }
		

	/*TTransformComponent TTransformComponent::operator*(TTransformComponent& other) const
	{

        //return transformation->get_transformation() * other.get_transformation()->get_transformation();
	}*/

	void TTransformComponent::operator=(TTransformComponent& other)
	{
		transformation = other.get_transformation();
	}

    float* TTransformComponent::get_position()
    {
        glm::vec3 vector_position = glt::extract_translation(*transformation);
        
        float position[]
        {
            position[0],
            position[1],
            position[2]
        };

        return position;
    }

    bool TTransformComponent::parse_component(rapidxml::xml_node<>* component_node)
    {
        return false;
    }
}