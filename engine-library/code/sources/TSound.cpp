/*
 * File: TSound.cpp
 * File Created: 9th December 2019
 * 末末末末末末末末末末末末
 * Author: Jesus Fermin, 'Pokoi', Villar  (hello@pokoidev.com)
 * 末末末末末末末末末末末末
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

#include <TSound.hpp>
#include <SDL_mixer.h>

 /**
@brief Creates a new sound effect object with a sound located in the given path
@param sound_path The path where the sound file is located
*/
TortillaEngine::TSound::TSound(char* sound_path)
{
	//LoadSound(sound_path);
}

/**
@brief Loads an audio file for this sound effect object
@param path The path where the sound file is located
*/
 void TortillaEngine::TSound::LoadSound(char* path)
{
	//sound_source = (Mix_LoadWAV(path));
}

/**
@brief Plays the sound source in loop
@param channel Index of the channel. Use "-1" to use the first free channel
@param loops Count of loops. For infinite loop use "-1" value
*/
void TortillaEngine::TSound::PlaySoundEffect(int channel, int loops)
{
	/*if (sound_source != nullptr)
	{
		Mix_PlayChannel(channel, sound_source, loops);
	}*/
}

/**
@brief Fades the sound source in loop
@param channel Index of the channel. Use "-1" to use the first free channel
@param loops Count of loops. For infinite loop use "-1" value
@param fade_duration_in_milliseconds Fades the sound over this amount of milliseconds
*/
void TortillaEngine::TSound::PlaySoundWithFade(int channel, int loops, int fade_duration_in_milliseconds)
{
	/*if (sound_source != nullptr)
	{
		Mix_FadeInChannel(channel, sound_source, loops, fade_duration_in_milliseconds);
	}*/
}

/**
@brief Frees the channel
*/
void TortillaEngine::TSound::FreeSound()
{
	//Mix_FreeChunk(sound_source);
}
