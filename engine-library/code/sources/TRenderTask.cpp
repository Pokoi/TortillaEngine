/*
 * File: TRenderTask.cpp
 * File Created: 16th January 2020
 * 末末末末末末末末末末末末
 * Author: Jesus Fermin, 'Pokoi', Villar  (hello@pokoidev.com)
 * 末末末末末末末末末末末末
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
#include <Model_Obj.hpp>
#include <Render_Node.hpp>


namespace TortillaEngine
{
    TRenderTask::TRenderTask(TScene* scene, int priority = 1)
        :TTask{priority, scene} 
    {
        renderer.reset(new glt::Render_Node);
    }

    void TRenderTask::run(float delta) 
    {
        owner_scene->get_window()->reset();
        renderer->render();
        owner_scene->get_window()->swap_buffers();
    }

    void TRenderTask::add_component(TRenderComponent * component)
    {
        renderer->add(component->get_parent()->get_name(), component->get_model());
    }
}