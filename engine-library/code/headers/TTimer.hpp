/*
 * File: TTimer.hpp
 * File Created: 15th January 2020
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

#pragma once

#include <cstdint>

namespace TortillaEngine
{
    /**
    @brief Timer for time management
    */
    class TTimer
    {
        /**
        @brief Number of ticks in the timer
        */
        uint32_t ticks;

    public:

        /**
        @brief Creates and starts a timer
        */
        TTimer() 
        {
            start();
        }

        /**
        @brief Starts the timer
        */
        void        start();
        
        /**
        @brief Gets the elapsed time in seconds
        @return The elapsed time
        */
        float       elapsed_seconds() const;
        
        /**
        @brief Gets the elapsed time in milliseconds
        @return The elapsed time
        */
        uint32_t    elapsed_milliseconds() const;
    };
}