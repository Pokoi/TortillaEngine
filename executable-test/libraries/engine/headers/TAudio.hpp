/*
 * File: TAudio.hpp
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

#pragma once
#include <memory>

namespace TortillaEngine 
{
    /**
    @brief Class for audio management.
    */
	class TAudio
	{		
		
	public:
		
        /**
        @brief Creates an audio object
        */
        TAudio();

		/**
		@brief Opens the mixer
		*/
		void OpenMixer	( 
								int frequency  = 22050,
								int channels   = 2, 
								int chunk_size = 4096
								);

		/**
		@brief Sets the volume of a specific channel
		@param channel Index of the channel. Use "-1" to set the volume of all channels
		@param volume Volume level in the range of 0-128
		*/
		void SetVolumeOfChannel(int channel, int volume);

		/**
		@brief Gets the volume level of a specific channel
		@param channel Index of the channel.
		*/
		int GetVolumeOfChannel(int channel);

		/**
		@brief Pauses a channel 
		@param channel The specific channel
		*/
		void PauseChannel	(int channel);

		/**
		@brief Resumes a channel
		@param channel The specific channel
		*/
		void ResumeChannel	(int channel);

		/**
		@brief Check if a specific channel is being played
		@param channel The specific channel.  Use "-1" to check all channels
		*/
		bool IsChannelPlaying(int channel);

		/**
		@brief Halts playing a specific channel.
		@param channel The specific channel. Use "-1" to halt all channels
		*/
		void HaltChannel(int channel);

		/**
		@brief Halts playing the music.
		*/
		void HaltMusic();

		/**
		@brief Closes the mixer
		*/
		void CloseMixer();

	};
}