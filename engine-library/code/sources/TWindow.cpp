
/*
 * File: TWindow.cpp
 * File Created: 7th January 2020
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

#include <TWindow.hpp>
#include <SDL.h>
#include <OpenGL.hpp>
#include <iostream>
#include <initialize.hpp>

namespace TortillaEngine
{   
    /**
    @brief Creates a window with default values
    */
    TWindow::TWindow()
    {
        window = nullptr;
        context = nullptr;

        if (engine::initialize (SDL_INIT_VIDEO))
        {
            SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 3);
            SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 2);

            window = SDL_CreateWindow
            (
                "untitled",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                500,
                600,
                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
            );
                      

            if (window)
            {
                context = SDL_GL_CreateContext (window);                
            }
        }

        std::cout << "Created";
    }


    /**
    @brief Creates a window with the given values
    @param window_name The name
    @param width The window width in pixels
    @param height The window height in pixels
    */
    TWindow::TWindow	(
						    char * window_name,
						    int			width,
						    int			height
					    )
	{
		window	= nullptr; 
		context = nullptr;

		if (engine::initialize (SDL_INIT_VIDEO))
        {
            SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 3);
            SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 2);

            window = SDL_CreateWindow
            (
                window_name,
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                width,
                height,
                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
            );           

            if (window)
            {
                context = SDL_GL_CreateContext (window);        

                if (context)  glt::initialize_opengl_extensions();
            }
        }
			

	}

    /**
    @brief Destructor method for memory management
    */
	TWindow::~TWindow()
	{
		if ( context != nullptr )
		{
			SDL_GL_DeleteContext(context);
		}

		if (window != nullptr)
		{
			SDL_DestroyWindow( window );
		}
	}

    /**
    @brief Clears the window
    */
    void TWindow::reset()
    {
        if (context != nullptr)
        {
            glClearColor(0.5f, 0.5f, 0.5f, 1.f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
    }

    /**
    @brief Swaps the windows buffers
    */
    void TWindow::swap_buffers() const
    {
        if (context != nullptr)
        {
            SDL_GL_SwapWindow(window);
        }
    }

    /**
    @brief Gets the event index
    @param e The event
    @return The index
    */
    int TWindow::poll_events(SDL_Event & e)
    {
        return SDL_PollEvent(&e);
    }
	
}