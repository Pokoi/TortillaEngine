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
#include <TRenderTask.hpp>
#include <TScriptTask.hpp>
#include <rapidxml-1.13/rapidxml.hpp>

#include <map>
#include <string>
#include <memory>



namespace TortillaEngine
{
   
    class TScene
    {
		TKernel * own_kernel = new TKernel();
		TWindow * window;
        std::map<const std::string &, std::shared_ptr<TEntity> > entities;
		
        TDispatcher     * message_dispatcher;	

        std::shared_ptr <TInputTask     > input      = nullptr;
        std::shared_ptr <TRenderTask    > render     = nullptr;
        std::shared_ptr <TCollisionsTask> collisions = nullptr;
        std::shared_ptr <TScriptTask    > scripts    = nullptr;

        std::string scene_path;


    public:

		TScene(TWindow* window) : window{ window }
		{
            message_dispatcher = &(TDispatcher::instance());
            
            //Creates the tasks
            creates_tasks();
		}

		TScene(TWindow* window, const std::string& path) : window{window}
		{		
            //Creates the tasks
            creates_tasks();

            load(path);     
		}
       
        ~TScene()
        {            
            delete own_kernel;                   
        }	

		TWindow     *   get_window() 
        { 
            return window;
        }
        
        TKernel     *   get_kernel() 
        { 
            return  own_kernel;
        }
        
        TDispatcher *   get_dispatcher() 
        {
            return message_dispatcher;
        }

        void            run()
        {
            own_kernel->exec();
        }

        std::shared_ptr<TEntity>  get_entity(const std::string & name)
        {
            return entities[name];
        }        
        
        void add_entity(std::shared_ptr<TEntity> entity)
        {
            entities[entity->get_name()] = entity;
        }

        std::shared_ptr<TTask> get_task(const std::string& type)
        {
            if (type == "TInputTask"     ) return input;
            if (type == "TRenderTask"    ) return render;
            if (type == "TCollisionsTask") return collisions;
            if (type == "TScriptTask"    ) return scripts;

            return nullptr;
        }
		
        
		void load(const std::string& path);
		

        void parse_scene     (rapidxml::xml_node<>* node);
        void parse_entities  (rapidxml::xml_node<>* node);       

        std::string get_path() { return scene_path; }

        void creates_tasks()
        {
            render      = std::make_shared<TRenderTask    >(this);
            input       = std::make_shared<TInputTask     >(this);
            collisions  = std::make_shared<TCollisionsTask>(this);
            scripts     = std::make_shared<TScriptTask    >(this);

            own_kernel->add_task(*render);
            own_kernel->add_task(*input);
            own_kernel->add_task(*collisions);
            own_kernel->add_task(*scripts);
        }

    };
}