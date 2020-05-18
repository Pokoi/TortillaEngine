/*
 * File: TRenderTask.cpp
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

#include <TRenderTask.hpp>
#include <TRenderComponent.hpp>
#include <TScene.hpp>
#include <Light.hpp>

#include <glad.h>


namespace TortillaEngine
{
    /**
    @brief Creates the task with the given values
    @param scene A reference to the scene this task belongs to
    @param priority The execution priority order
    */
    TRenderTask::TRenderTask(TScene* scene, int priority)
        :TTask{priority, scene} 
    {
        gladLoadGL();
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
    }

    /**
    @brief The destructor method for memory management
    */
    TRenderTask::~TRenderTask()
    {

    }

    /**
    @brief Executes the task rendering all the components subscribed to the task
    */
    void TRenderTask::run(float delta) 
    {        
        owner_scene ->get_window()->reset();
        
        //skybox 

        // lights

        // models opaque
        for (auto& model : render_components)
        {

        }

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // transparent models
        for (auto& model : render_components)
        {

        }

        glDisable(GL_BLEND);

        // Post process

        owner_scene ->get_window()->swap_buffers();
    }

    /**
    @brief Adds a model/mesh to the subscribed component collection
    @param component A reference to the component to add
    */
    void TRenderTask::add_component(TRenderComponent * component)
    {
       // renderer->add(component->get_parent()->get_name(), component->get_model());
    }

    /**
    @brief Adds a camera to the subscribed component collection
    @param camera A reference to the camera to add
    */
    void TRenderTask::add_camera(TCameraComponent* camera)
    {
        this->camera = camera;
    }

    /**
    @brief Adds a light to the subscribed component collection
    @param light A reference to the light to add
    */
    void TRenderTask::add_light(TLightComponent* light)
    {
      // renderer->add(light->get_parent()->get_name(), light->get_light());
    }
   
}