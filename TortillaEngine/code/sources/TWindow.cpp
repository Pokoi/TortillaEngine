#include "..\headers\TWindow.hpp"
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

namespace TortillaEngine
{
	TWindow::TWindow()
	{
		window	= nullptr;
		context = nullptr;

		if (SDL_Init(SDL_INIT_VIDEO))
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			window = SDL_CreateWindow(
										"Untitled",
										SDL_WINDOWPOS_CENTERED,
										SDL_WINDOWPOS_CENTERED,
										600,
										400,
										SDL_WINDOW_RESIZABLE
									);
			if (window != nullptr)
			{
				context = SDL_GL_CreateContext(window);
			}
	}

	TWindow::TWindow	(
						std::string window_name,
						int			width,
						int			height
					)
	{
		window	= nullptr; 
		context = nullptr;

		if (SDL_Init(SDL_INIT_VIDEO))
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			window = SDL_CreateWindow	(
											window_name.c_str(),
											SDL_WINDOWPOS_CENTERED,
											SDL_WINDOWPOS_CENTERED,
											width,
											height,
											SDL_WINDOW_RESIZABLE
										);
			if (window != nullptr)
			{
				context = SDL_GL_CreateContext(window);
			}
		}
			

	}
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
	
}