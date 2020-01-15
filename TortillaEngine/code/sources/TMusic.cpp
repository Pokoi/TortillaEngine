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

#include <TMusic.hpp>
#include <SDL_mixer.h>

inline TortillaEngine::TMusic::TMusic(char* music_path)
{
	LoadMusic(music_path);
}

inline void TortillaEngine::TMusic::LoadMusic(char* path)
{
	music_source = std::make_shared<Mix_Music>(Mix_LoadMUS(path));
}

/**
Plays the music source in loop
@param loops Count of loops. For infinite loop use "-1" value
*/

inline void TortillaEngine::TMusic::PlayMusic(int loops)
{
	if (music_source != nullptr)
	{
		Mix_PlayMusic(music_source.get(), loops);
	}
}

/**
Fades the music source in loop
@param loops Count of loops. For infinite loop use "-1" value
@param fade_duration_in_milliseconds Fades the music over this amount of milliseconds
*/

inline void TortillaEngine::TMusic::PlayMusicWithFade(int loops, int fade_duration_in_milliseconds)
{
	if (music_source != nullptr)
	{
		Mix_FadeInMusic(music_source.get(), loops, fade_duration_in_milliseconds);
	}
}

inline void TortillaEngine::TMusic::FreeMusic()
{
	Mix_FreeMusic(music_source.get());
}
