/*
 * File: Camera.hpp
 * File Created: 14th February 2020
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

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>


namespace Rendering3D
{
    /**
    @brief: Class that manages camera behaviour    
    */
    class Camera
    {

        /**
        @brief The camera projection 
        */
        glm::mat4 projection;
       
        /**
        @brief Initial field of view 
        */
        float initial_fov = 80.f;

        /**
        @brief Current field of view
        */
        float current_fov = 80.f;

        /**
        @brief The aspect ratio
        */
        float aspect_ratio = 1;

        /**
        @brief Near render plane
        */
        float near_plane = 1;

        /**
        @brief Camera render distance. This determinates the far plane
        */
        float render_distance = 50;

    public:

        /**
        @brief Creates a camera instance. Default projection values are:
        ** near field: 1
        ** far field: 51
        ** field of view: initial_fov value
        ** aspect ratio: 1
        */
        Camera() : projection{ glm::perspective(initial_fov, 
                                                aspect_ratio,
                                                near_plane,
                                                near_plane + render_distance
                                               ) }
        {}

        /**
        @brief Creates a camera instance. 
        @param initial_fov The fov of the camera
        @param aspect_ratio The aspect ratio
        @param near_plane The near render plane
        @param render_distance The render distance. This determinates the far plane
        */
        Camera( float initial_fov, 
                float aspect_ratio, 
                float near_plane, 
                float render_distance
              ) : projection{ glm::perspective(initial_fov,
                                                aspect_ratio,
                                                near_plane,
                                                near_plane + render_distance
                                               ) },
                initial_fov{initial_fov},
                aspect_ratio{aspect_ratio},
                near_plane{near_plane},
                render_distance{render_distance}
        {}
        

        /**
        @brief Gets the projection matrix
        @return The matrix projection
        */
        glm::mat4 get_projection()
        {
            return projection;
        }

        /**
        @brief Sets a projection matrix
        @param projection The projection to set
        */
        void set_projection(glm::mat4 projection)
        {
            this->projection = projection;
        }
    

        /**
        @brief Change the field of view
        @param view The view reference
        @param modificator The modification to apply
        */
        void change_fov(float modificator);
    };
}

