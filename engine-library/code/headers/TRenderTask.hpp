/*
 * File: TRenderTask.hpp
 * File Created: 16th January 2020
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

#include <TTask.hpp>
#include <declarations.hpp>
#include <TRenderComponent.hpp>
#include <TCameraComponent.hpp>
#include <TLightComponent.hpp>
#include <memory>
#include <vector>
#include <TShaderProgram.hpp>
#include <TFramebuffer.hpp>

namespace TortillaEngine
{
    /**
    @brief Render management.
    */
    class TRenderTask : public TTask
    {        

        /**
        @brief A collection of the components subscribed to the task
        */
        std::vector<TRenderComponent*> render_components;

        /**
        @brief A collection of the light components in the scene
        */
        std::vector<TLightComponent*> lights_components;

        /**
        @brief A reference to the scene camera
        */
        TCameraComponent* camera;

        /**
        @brief The framebuffer of the render for the post processing
        */
        std::shared_ptr<TFramebuffer> framebuffer;

    public:

        /**
        @brief Creates the task with the given values
        @param scene A reference to the scene this task belongs to
        @param priority The execution priority order
        */
        TRenderTask(TScene* scene, int priority = 5);

        /**
        @brief The destructor method for memory management
        */
        ~TRenderTask();

        /**
        @brief Executes the task rendering all the components subscribed to the task
        */
        void run(float delta) override;

        /**
        @brief Adds a model/mesh to the subscribed component collection
        @param component A reference to the component to add
        */
        void add_component(TRenderComponent* component);

        /**
        @brief Adds a camera to the subscribed component collection
        @param camera A reference to the camera to add
        */
        void add_camera(TCameraComponent* camera);

        /**
        @brief Adds a light to the subscribed component collection
        @param light A reference to the light to add
        */
        void add_light(TLightComponent* light);

    };
}