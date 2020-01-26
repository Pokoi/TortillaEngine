/*
 * File: TTimer.cpp
 * File Created: 15th January 2020
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

#include <TTimer.hpp>
#include <SDL.h>

namespace TortillaEngine
{
    /**
    @brief Starts the timer
    */
    void TTimer::start()
    {
        ticks = SDL_GetTicks();
    }

    /**
    @brief Gets the elapsed time in seconds
    @return The elapsed time
    */
    float TTimer::elapsed_seconds() const
    {
        return float(elapsed_milliseconds()) * 0.001f;
    }

    /**
    @brief Gets the elapsed time in milliseconds
    @return The elapsed time
    */
    uint32_t TTimer::elapsed_milliseconds() const
    {
        return SDL_GetTicks() - ticks;
    }
}