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

namespace TortillaEngine
{
    class TTransformComponent : TComponent
	{
		glm::mat4 transformation;

    public:
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

		TTransformComponent(glm::mat4 transformation);
       
		glm::mat4	get_transformation() const
		{
			return transformation;
		}

		void translate	(float x			, float y		 , float z			);        
		void rotate		(float pitch_angle	, float yaw_angle, float roll_angle	);        
		void scale		(float scale_x		, float scale_y	 , float scale_z	);
       

        virtual void    initialize() override {}

		virtual void    execute() override {};

        virtual bool    parse_component(rapidxml::xml_node<>* component_node) override;
        

		TTransformComponent operator * (TTransformComponent& other) const;
		void				operator = (TTransformComponent& other);
        

    };
}
