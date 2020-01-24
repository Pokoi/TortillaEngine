/*
 * File: TKeyboardInput.hpp
 * File Created: 12th December 2019
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

#pragma once

#include <string>

namespace TortillaEngine
{
	class TKeyboardInput 
	{

    public:

		struct TKey 
		{
		private:
			std::string common_name;          

		public:
			
            TKey(std::string name) : common_name{ name }    {}
            TKey()                 : common_name{ "UNKWON" }{}
            
            std::string get_name()
            {
                return common_name;
            }
            
		};

	private:


		const TKey KeyboardKeys[50]
		{
			{"NUM_0"}, 
			{"NUM_1"}, {"NUM_2"}, {"NUM_3"},
			{"NUM_4"}, {"NUM_5"}, {"NUM_6"},
			{"NUM_7"}, {"NUM_8"}, {"NUM_9"},
			
			{"A"}, {"B"}, {"C"}, 
			{"D"}, {"E"}, {"F"},
			{"G"}, {"H"}, {"I"},
			{"J"}, {"K"}, {"L"},
			{"M"}, {"N"}, 
			{"O"}, {"P"}, {"Q"},
			{"R"}, {"S"}, {"T"},
			{"U"}, {"V"}, {"W"},
			{"X"}, {"Y"}, {"Z"},
			
			{"."}, {","}, {"-"},
			
			{"SPACE"},	{"BACK_SPACE"},
			{"TAB"},	{"ESCAPE"},
			{"ENTER"},	
			
			{"L_ALT"},		{"R_ALT"},			
			{"L_CTR"},		{"R_CTR"},
			{"L_SHIFT"},	{"R_SHIFT"},
		};

	public:

        TKeyboardInput() {}

        TKey translate_sdl_code(int sdl_code);

	};
}