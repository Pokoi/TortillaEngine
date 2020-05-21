/*
 * File: TSound.hpp
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
#include <declarations.hpp>

namespace TortillaEngine
{
    /**
    @brief Class for sound effects audio management
    */
	class TSound : public TAudio
	{
        /**
        @brief The source of the sound effect
        */
		T_Chunk * sound_source;

	public:

        /**
        @brief Creates a new sound effect object
        */
        TSound() : sound_source{ nullptr }, TAudio{}{}
        
        /**
        @brief Creates a new sound effect object with a sound located in the given path
        @param sound_path The path where the sound file is located
        */
		TSound(char* sound_path);

        /**
        @brief Frees the heap memory 
        */
        ~TSound()
        {
            //delete sound_source;
        }
        
        /**
        @brief Loads an audio file for this sound effect object
        @param path The path where the sound file is located
        */
		void LoadSound(char* path);

		/**
		@brief Plays the sound source in loop
		@param channel Index of the channel. Use "-1" to use the first free channel
		@param loops Count of loops. For infinite loop use "-1" value
		*/
		void PlaySoundEffect(int channel, int loops);

		/**
		@brief Fades the sound source in loop
		@param channel Index of the channel. Use "-1" to use the first free channel
		@param loops Count of loops. For infinite loop use "-1" value
		@param fade_duration_in_milliseconds Fades the sound over this amount of milliseconds
		*/
		void PlaySoundWithFade(int channel, int loops, int fade_duration_in_milliseconds);

        /**
        @brief Frees the channel        
        */
		void FreeSound();
		

	};
}
