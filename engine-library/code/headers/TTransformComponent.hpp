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
#include <declarations.hpp>
#include <TComponent.hpp>
#include <rapidxml-1.13/rapidxml.hpp>

namespace TortillaEngine
{
    /**
    @brief Transform component 
    */
    class TTransformComponent : public TComponent
	{
        /**
        @brief Transformation matrix
        */
        glm::mat4* transformation;

    public:

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
        TTransformComponent	(
								TEntity* entity,
								float	 x_position		= 0,
								float	 y_position		= 0,
								float	 z_position		= 0,
								float	 pitch_angle	= 0,
								float	 yaw_angle		= 0,
								float	 roll_angle		= 0,
								float	 x_scale		= 1,
								float	 y_scale		= 1,
								float    z_scale		= 1
							);

        /**
        @brief Creates a component in base of a given transformation matrix
        @param transformation A reference of the transformation matrix
        */
		TTransformComponent (glm::mat4 & transformation);
       
        /**
        @brief Destructor method for memory management
        */
        ~TTransformComponent();

        /**
        @brief Gets the transformation matrix
        @return A reference to the transformation matrix
        */
        glm::mat4*	get_transformation() const;
		
        /**
        @brief Translates the matrix
        @param x Translation in x axis
        @param y Translation in y axis
        @param z Translation in z axis
        */
		void translate	(float x			, float y		 , float z			);        
		
        /**
        @brief Rotates the matrix
        @param pitch_angle Rotation in x axis
        @param yaw_angle Rotation in y axis
        @param roll_angle Rotation in z axis
        */
        void rotate		(float pitch_angle	, float yaw_angle, float roll_angle	);        
		
        /**
        @brief Scale the matrix
        @param scale_x Scale in x axis
        @param scale_y Scale in y axis
        @param scale_z Scale in z axis
        */
        void scale		(float scale_x		, float scale_y	 , float scale_z	);      
        
        /**
        @brief Initializes the component
        */
        virtual void    initialize() override {}

        /**
        @brief Executes the component
        */
		virtual void    execute() override {}

        /**
        @brief Loads the component data from a xml file
        @param component_node The xml node with the data
        */
        virtual bool    parse_component(rapidxml::xml_node<>* component_node) override;
        

		//TTransformComponent operator * (TTransformComponent& other) const;
		
        /**
        @brief Copy the transform component
        @param other A reference to the transform component to copy
        */
        void				operator = (TTransformComponent& other);
        
        /**
        @brief Gets the position
        @return The position
        */
        glm::vec4 get_position();

    };
}
