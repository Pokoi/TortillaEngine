/*
 * File: TWindow.hpp
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

#pragma once

#include <string>
#include <declarations.hpp>

namespace TortillaEngine
{
    /**
    @brief Window management 
    */
	class TWindow
	{

    public:
        
	private:

        /**
        @brief A reference to the window
        */
		SDL_Window		*	window;
        
        /**
        @brief The context of the window
        */
		SDL_GLContext		context;

        /**
        @brief The window width
        */
        unsigned int width;

        /**
        @brief The window height
        */
        unsigned int height;

	public:
        
        /**
        @brief Creates a window with default values
        */
		TWindow	();

        /**
        @brief Creates a window with the given values
        @param window_name The name 
        @param width The window width in pixels
        @param height The window height in pixels
        */
		TWindow	(
					char *      window_name,
					int			width,
					int			height
				);

        /**
        @brief Destructor method for memory management
        */
		~TWindow	();

        /**
        @brief Clears the window
        */
        void reset();

        /**
        @brief Swaps the windows buffers
        */
        void swap_buffers() const;

        /**
        @brief Gets the event index
        @param e The event
        @return The index
        */
        int  poll_events(SDL_Event & e);

        /**
        @brief Gets the width of the window
        @return The width of the window
        */
        unsigned int get_width()
        {
            return width;
        }

        /**
        @brief Gets the height of the window
        @return The height of the window
        */
        unsigned int get_height()
        {
            return height;
        }

	};
}