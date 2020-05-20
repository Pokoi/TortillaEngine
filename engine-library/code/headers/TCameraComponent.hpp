/*
 * File: TCameraComponent.hpp
 * File Created: 17th January 2020
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
#include <Camera.hpp>
#include <memory>
#include <glm.hpp>

namespace TortillaEngine
{
    /**
    @brief Camera component
    */
    class TCameraComponent : public TComponent
    {
        /**
        @brief A reference to the camera
        */
        std::shared_ptr<Rendering3D::Camera> camera;

    public:

        /**
        @brief Creates a camera with the given values
        @param parent A reference to the entity this component is attached to
        @param near_field Near field of render
        @param far_field Far field of render
        @param fov Camera field of view
        @param aspect_ratio Camera aspect ratio
        */
        TCameraComponent(
                            TEntity* parent,
                            float near_field,
                            float far_field,
                            float fov,
                            float aspect_ratio
                        );


        /**
        @brief Loads the component data from a xml node
        @param component_node The xml node with the data
        */
        virtual bool    parse_component(rapidxml::xml_node<>* component_node);

        /**
        @brief Gets a reference of the camera
        @return The reference to the camera
        */
        std::shared_ptr<Rendering3D::Camera> get_camera();

        /**
        @brief Subscribe to the render task
        */
        virtual void subscribe_to_task() override;

        /**
        @brief Apply the given transform to the camera
        @param transfrom The transform to apply
        */
        void  apply_transform(glm::mat4 transform) override;
    };

    
}