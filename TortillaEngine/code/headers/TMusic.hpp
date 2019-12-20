/*
 * File: TMusic.cpp
 * File Created: 9th December 2019
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
#include <TAudio.hpp>

namespace TortillaEngine
{
	class TMusic : public TAudio
	{
		std::shared_ptr	<Mix_Music> music_source;

	public:
		
		TMusic() : music_source { nullptr } {}

		TMusic(char* music_path);

		inline void LoadMusic(char* path);

		/**
		Plays the music source in loop
		@param loops Count of loops. For infinite loop use "-1" value
		*/
		inline void PlayMusic(int loops);

		/**
		Fades the music source in loop
		@param loops Count of loops. For infinite loop use "-1" value
		@param fade_duration_in_milliseconds Fades the music over this amount of milliseconds
		*/
		inline void PlayMusicWithFade(int loops, int fade_duration_in_milliseconds);

		inline void FreeMusic();
	};
}