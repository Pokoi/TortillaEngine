#include "..\headers\TKeyboardInput.h"
/*
 * File: TKeyboardInput.cpp
 * File Created: 15th December 2019
 * ––––––––––––––––––––––––
 * Author: Jesus Fermin, 'Pokoi', Villar  (hello@pokoidev.com)
 * ––––––––––––––––––––––––
 * MIT License
 *
 * Copyright (c) 2019 Pokoidev
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

#include <TKeyboardInput.h>
#include <SDL.h>

namespace TortillaEngine
{
    TKeyboardInput::TKey TKeyboardInput::translate_sdl_code(int sdl_code)
    {
        int sdl_codes[50]
        {
            {SDLK_0},
            {SDLK_1}, {SDLK_2}, {SDLK_3},
            {SDLK_4}, {SDLK_5}, {SDLK_6},
            {SDLK_7}, {SDLK_8}, {SDLK_9},

            {SDLK_a}, {SDLK_b}, {SDLK_c},
            {SDLK_d}, {SDLK_e}, {SDLK_f},
            {SDLK_g}, {SDLK_h}, {SDLK_i},
            {SDLK_j}, {SDLK_k}, {SDLK_l},
            {SDLK_m}, {SDLK_n},
            {SDLK_o}, {SDLK_p}, {SDLK_q},
            {SDLK_r}, {SDLK_s}, {SDLK_t},
            {SDLK_u}, {SDLK_v}, {SDLK_w},
            {SDLK_x}, {SDLK_y}, {SDLK_z},

            {SDLK_PERIOD}, {SDLK_COMMA}, {SDLK_MINUS},

            {SDLK_SPACE} ,	{SDLK_BACKSPACE},
            {SDLK_TAB}   ,  {SDLK_ESCAPE}   ,
            {SDLK_RETURN},

            {SDLK_LALT}  ,	{SDLK_RALT}  ,
            {SDLK_LCTRL} ,	{SDLK_RCTRL} ,
            {SDLK_LSHIFT},	{SDLK_RSHIFT},
        };

        int length = sizeof(sdl_codes) / sizeof(sdl_codes[0]);

        for (int i = 0; i < length; ++i)
        {
            if (sdl_codes[i] == sdl_code)
            {
                return KeyboardKeys[i];
            }
        }

        return {};
       
    }
}