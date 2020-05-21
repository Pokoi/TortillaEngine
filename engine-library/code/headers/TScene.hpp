/*
 * File: TScene.hpp
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

#include <TKernel.hpp>
#include <TWindow.hpp>
#include <TEntity.hpp>
#include <TDispatcher.hpp>
#include <TCollisionsTask.hpp>
#include <TInputTask.hpp>
#include <TInputMapperTask.hpp>
#include <TRenderTask.hpp>
#include <TScriptTask.hpp>
#include <rapidxml-1.13/rapidxml.hpp>

#include <map>
#include <string>
#include <memory>



namespace TortillaEngine
{
    /**
    @brief A game scene 
    */
    class TScene
    {
        /**
        @brief A reference to this scene kernel task manager
        */
		TKernel * own_kernel = new TKernel();

        /**
        @brief A reference to the window this scene belongs to
        */
		TWindow * window;

        /**
        @brief The collection of entities in the scene. 
        */
        std::map<std::string, std::shared_ptr<TEntity> > entities;
		
        /**
        @brief A reference to the message dispatcher
        */
        TDispatcher     * message_dispatcher;	

        /**
        @brief The task to manage the input events
        */
        std::shared_ptr <TInputTask       > input      = nullptr;
        /**
        @brief The task to manage the input event - messages conversion
        */
        std::shared_ptr <TInputMapperTask > mapper     = nullptr;
        /**
        @brief The task to manage the scripts execution
        */
        std::shared_ptr <TScriptTask      > scripts    = nullptr;
        /**
        @brief The task to manage the collisions in game
        */
        std::shared_ptr <TCollisionsTask  > collisions = nullptr;
        /**
        @brief The task to manage the render
        */
        std::shared_ptr <TRenderTask      > render     = nullptr;
        
        /**
        @brief The path of the file of the scene
        */
        std::string scene_path;


    public:

        /**
        @brief Creates a scene in the given window
        @param window A reference to the window this scene belongs to
        */
		TScene(TWindow* window) : window{ window }
		{
            message_dispatcher = &(TDispatcher::instance());
            
            //Creates the tasks
            creates_tasks();
		}

        /**
        @brief Creates a scene in base of a xml file data
        @param window A reference to the window this scene belongs to
        @param path The path of the xml file with the data to load
        */
		TScene(TWindow* window, const std::string& path) : window{window}
		{		
            //Creates the tasks
            creates_tasks();

            load(path);     
		}
       
        /**
        @brief Destructor method for memory management
        */
        ~TScene()
        {            
            delete own_kernel;                   
        }	

        /**
        @brief Gets a reference to the window this scene belongs to
        @return A reference to the window this scene belongs to
        */
		TWindow     *   get_window() 
        { 
            return window;
        }
        
        /**
        @brief Gets a reference to the kernel 
        @return A reference to the kernel
        */
        TKernel     *   get_kernel() 
        { 
            return  own_kernel;
        }
        
        /**
        @brief Gets a reference to the message dispatcher
        @param A reference to the message dispatcher
        */
        TDispatcher *   get_dispatcher() 
        {
            return message_dispatcher;
        }

        /**
        @brief Runs the scene
        */
        void            run()
        {           
            own_kernel->exec();
        }

        /**
        @brief Get an entity of this scene with the given name
        @param name The name of the entity to get
        @return The reference of the entity
        */
        std::shared_ptr<TEntity>  get_entity(const std::string & name)
        {
            return entities[name];
        }        
        
        /**
        @brief Adds a given entity to the scene collection of entities
        @param entity A reference to the entity to add
        */
        void add_entity(std::shared_ptr<TEntity> entity)
        {
            entities[entity->get_name()] = entity;
        }

        /**
        @brief Gets a task by his type
        @param type The type of the task
        @return A reference to the task. If the task does not exist, it returns nullptr
        */
        std::shared_ptr<TTask> get_task(const std::string& type)
        {
            if (type == "TInputTask"        ) return input;
            if (type == "TInputMapperTask"  ) return mapper;
            if (type == "TRenderTask"       ) return render;
            if (type == "TCollisionsTask"   ) return collisions;
            if (type == "TScriptTask"       ) return scripts;

            return nullptr;
        }
		
        /**
        @brief Stops the execution and reloads the scene before resuming the execution
        */
        void reset()
        {
            own_kernel->stop();
            load(scene_path);
            run();
        }
        
        /**
        @brief Loads the scene data from an xml file
        @param path The xml file path
        */
		void load(const std::string& path);
		
        /**
        @brief Parse the scene data from a xml node
        @param node The xml node with the data
        */
        void parse_scene     (rapidxml::xml_node<>* node);

        /**
        @brief Parse all the entities data from a xml node
        @param node The xml node with the data
        */
        void parse_entities  (rapidxml::xml_node<>* node); 

        /**
        @brief Parse all the shaders data from a xml node
        @param node The xml node with the data
        */
        void parse_shaders(rapidxml::xml_node<>* node);

        /**
        @brief Parse all the materials data from a xml node
        @param node The xml node with the data
        */
        void parse_materials(rapidxml::xml_node<>* node);

        /**
        @brief Parse the skybox data from a xml node
        @param node The xml node with the data
        */
        void parse_skybox(rapidxml::xml_node<>* node);

        /**
        @brief Gets the path of the xml file with this scene data
        @return The file path
        */
        std::string get_path() { return scene_path; }

        /**
        @brief Creates the tasks
        */
        void creates_tasks()
        {
            input       = std::make_shared<TInputTask       >(this);
            mapper      = std::make_shared<TInputMapperTask >(this);
            scripts     = std::make_shared<TScriptTask      >(this);
            collisions  = std::make_shared<TCollisionsTask  >(this);
            render      = std::make_shared<TRenderTask      >(this);

            own_kernel->add_task(*input);
            own_kernel->add_task(*mapper);
            own_kernel->add_task(*scripts);
            own_kernel->add_task(*collisions);
            own_kernel->add_task(*render);
        }

    };
}