/*
 * File: TTask.hpp
 * File Created: 9th January 2020
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

#include <TScene.hpp>

namespace TortillaEngine
{
	class TTask
	{
	protected:

		int         priority;
		TScene   *  owner_scene;

	public:

		TTask(int priority) : priority(priority) {}

		void virtual	run(float delta) = 0;
		void			initialize();
		void			finalize();

		int             get_priority()                   const
        { 
            return this->priority;
        }

		bool            operator < (const TTask & other) const
		{
			return this->priority < other.get_priority();
		}
        
        void            set_scene(TScene& scene) 
        {
            owner_scene = &scene;
        }
        TScene  *       get_scene()
        {
            return owner_scene;
        }

	};


	//TASK PRIORITY
	//input task
	//input mapper
}

// La tarea de render es un sistema que recorre todas las entidades que tengan un componente de render. Pilla el transform de cada entidad 
// y se lo aplica a cada componente de render que tenga vinculado. DEspués llama a render node render y después a swap buffer de la ventana
// Por tanto los pasos son:
// actualizar matrices; clear window; render_node -> render(); swap buffers