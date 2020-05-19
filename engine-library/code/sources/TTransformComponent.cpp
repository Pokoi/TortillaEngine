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
#include <gtc/matrix_transform.inl>


namespace TortillaEngine
{
    /**
    @brief Creates a component with the given values
    @param entity A reference to the entity this component is attached to
    @param x_position The x component of the position data
    @param y_position The y component of the position data
    @param z_position The z component of the position data
    @param pitch_angle The rotation in x axis
    @param yaw_angle The rotation in y axis
    @param roll_angle The rotation in z axis
    @param x_scale The x component of the scale data
    @param y_scale The y component of the scale data
    @param z_scale The z component of the scale data
    */
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
        transformation = new glm::mat4();
        translate(x_position	, y_position, z_position);
		rotate	 (pitch_angle	, yaw_angle	, roll_angle);
		scale	 (x_scale		, y_scale	, z_scale	);
	}

    /**
    @brief Creates a component in base of a given transformation matrix
    @param transformation A reference of the transformation matrix
    */
    TTransformComponent::TTransformComponent(glm::mat4 & transformation)
    {        
        this->transformation = &transformation;
    }

    /**
    @brief Destructor method for memory management
    */
    TTransformComponent::~TTransformComponent()
    {        
    }

    /**
    @brief Gets the transformation matrix
    @return A reference to the transformation matrix
    */
    glm::mat4 TTransformComponent::get_transformation() const
    {
        if (parent->get_parent())
        {
            return (*transformation) * parent->get_parent()->get_transform().get_transformation();
        }

        return (*transformation);
    }
    	
    /**
    @brief Translates the matrix
    @param x Translation in x axis
    @param y Translation in y axis
    @param z Translation in z axis
    */
	inline void TTransformComponent::translate	(float x		  , float y			, float z			)
	{        
        *transformation = glm::translate(*transformation, glm::vec3{ x,y,z });       
    }

    /**
    @brief Rotates the matrix
    @param pitch_angle Rotation in x axis
    @param yaw_angle Rotation in y axis
    @param roll_angle Rotation in z axis
    */
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

    /**
    @brief Scale the matrix
    @param scale_x Scale in x axis
    @param scale_y Scale in y axis
    @param scale_z Scale in z axis
    */
	inline void TTransformComponent::scale		(float scale_x	  , float scale_y	, float scale_z		)
	{
        *transformation = glm::scale(*transformation, glm::vec3(scale_x, scale_y, scale_z));
    }
		

	/*TTransformComponent TTransformComponent::operator*(TTransformComponent& other) const
	{

        //return transformation->get_transformation() * other.get_transformation()->get_transformation();
	}*/

    /**
    @brief Copy the transform component
    @param other A reference to the transform component to copy
    */
	void TTransformComponent::operator=(TTransformComponent& other)
	{
		transformation = other.get_transformation();
	}

    /**
    @brief Gets the position
    @return The position
    */
    glm::vec4 TTransformComponent::get_position()
    {
        return (*transformation)[3];      
        
    }

    /**
    @brief Loads the component data from a xml file
    @param component_node The xml node with the data
    */
    bool TTransformComponent::parse_component(rapidxml::xml_node<>* component_node)
    {      

        for (
            rapidxml::xml_node<>* transform = component_node->first_node();
            transform;
            transform = transform->next_sibling()
            )
        {
            std::string value = transform->value();

            if ((std::string)transform->name() == "xposition")
            {
                translate(std::stof(value), 0, 0);
            }

            else if ((std::string)transform->name() == "yposition")
            {
                translate(0,std::stof(value), 0);
            }

            else if ((std::string)transform->name() == "zposition")
            {
                translate(0,0,std::stof(value));
            }

            else if ((std::string)transform->name() == "pitch")
            {
                rotate(std::stof(value), 0, 0);
            }

            else if ((std::string)transform->name() == "yaw")
            {
                rotate(0,0,std::stof(value));
            }

            else if ((std::string)transform->name() == "roll")
            {
                rotate(0,0,std::stof(value));
            }

            else if ((std::string)transform->name() == "xscale")
            {
                scale(std::stof(value), 1, 1);
            }

            else if ((std::string)transform->name() == "yscale")
            {
                scale(1,std::stof(value), 1);
            }

            else if ((std::string)transform->name() == "zscale")
            {
                scale(1,1,std::stof(value));
            }

        }


        return true;
    }
}