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



namespace TortillaEngine
{
   
    class TScene
    {
		TKernel * own_kernel = new TKernel();
		TWindow * window;
        std::map<std::string, TEntity* > entities;
		
        TDispatcher     * message_dispatcher;	

        TInputTask      * input      = nullptr;
        TRenderTask     * render     = nullptr;
        TCollisionsTask * collisions = nullptr;
        TScriptTask     * scripts    = nullptr;

        std::string scene_path;


    public:

		TScene(TWindow* window) : window{ window }
		{
            message_dispatcher = &(TDispatcher::instance());
            
            render      = new TRenderTask    { this };
            input       = new TInputTask     { this };
            collisions  = new TCollisionsTask{ this };
            scripts     = new TScriptTask    { this };

            own_kernel -> add_task( * render      );
            own_kernel -> add_task( * input       );
            own_kernel -> add_task( * collisions  );
            own_kernel->add_task(*scripts);

		}

		TScene(TWindow* window, const std::string& path) : window{window}
		{
            collisions = new TCollisionsTask{ this };
			load(path);

            render      = new TRenderTask    { this };
            input       = new TInputTask     { this };
            collisions  = new TCollisionsTask{ this };

            own_kernel -> add_task( * render      );
            own_kernel -> add_task( * input       );
            own_kernel -> add_task( * collisions  );
		}
       
        ~TScene()
        {
            entities.clear();            

            delete own_kernel;
            //delete window;           
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

        TEntity     *   get_entity(std::string name)
        {
            return entities[name];
        }

        TCollisionsTask* get_collision_task()
        {
            return collisions;
        }
		
        //load scene
		void load(const std::string& path);
		//Cada vez que se encuentra un tag entity extrae su id y lo añade al mapa
		//Después extrae cada componente y los va añadiendo a la entidad

        void parse_scene     (rapidxml::xml_node<>* node);
        void parse_entities  (rapidxml::xml_node<>* node);       

        std::string get_path() { return scene_path; }

    };
}