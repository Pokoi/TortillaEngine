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
#include <map>
#include <TShaderProgram.hpp>
#include <TFramebuffer.hpp>
#include <TBatch.hpp>
#include <TSkybox.hpp>
#include <Material.hpp>

namespace TortillaEngine
{
    /**
    @brief Render management.
    */
    class TRenderTask : public TTask
    {        

        /**
        @brief A collection of render batches
        */
        std::vector<std::shared_ptr<TBatch>> render_batches;

        /**
        @brief The light component in the scene
        */
        TLightComponent* light;

        /**
        @brief A reference to the scene camera
        */
        TCameraComponent* camera;

        /**
        @brief The framebuffer of the render for the post processing
        */
        std::shared_ptr<TFramebuffer> framebuffer;

        /**
        @brief A reference to the skybox object
        */
        std::shared_ptr<TSkybox> skybox;

        /**
        @brief A collection of the shader programs in the program
        */
        std::map<std::string, std::shared_ptr<TShaderProgram>> shader_programs;

        /**
        @brief A collection of the materials in the program
        */
        std::map<std::string, std::shared_ptr<Rendering3D::Material>> materials;


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

        /**
        @brief Adds a shader program to the collection of shader programs
        @param name The name of the shader program
        @param shader_program The shader program to add
        */
        void add_shader_program(std::string name, std::shared_ptr<TShaderProgram> shader_program)
        {
            shader_programs[name] = shader_program;
        }

        /**
        @brief Gets a reference to a shader program by name
        @param name The name of the shader program to get
        @return A reference to the shader program 
        */
        std::shared_ptr<TShaderProgram>& get_shader_program(std::string name)
        {
            return shader_programs[name];
        }

        /**
        @brief Adds a material to the collection of materials
        @param name The name of the material
        @param material The material to add
        */
        void add_material(std::string name, std::shared_ptr<Rendering3D::Material> material)
        {
            materials[name] = material;
        }

        /**
        @brief Gets a reference to a material by name
        @param name The name of the material to get
        @return A reference to the material
        */
        std::shared_ptr<Rendering3D::Material>& get_material(std::string name)
        {
            return materials[name];
        }

        /**
        @brief Sets the skybox reference of the render task
        @param skybox The skybox reference to set
        */
        void set_skybox(std::shared_ptr<TSkybox> skybox)
        {
            this->skybox = skybox;
        }

    };
}