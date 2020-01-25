/*
 * File: TAudio.cpp
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

#include <TAudio.hpp>
#include <SDL_mixer.h>
#include <SDL.h>


namespace TortillaEngine
{
    /**
    @brief Creates an audio object
    */
    TAudio::TAudio()
    {
        /*int flags = MIX_INIT_OGG | MIX_INIT_MOD;

        if (SDL_Init(flags) == -1)
        {
            printf("SDL_Init: %s\n", SDL_GetError());
            exit(1);
        }

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
        {
            printf("Mix_OpenAudio: %s\n", Mix_GetError());
            exit(2);
        }

        OpenMixer();*/
    }

	/**
	@brief Opens the mixer
	*/
	void TAudio::OpenMixer(   
                                    int     frequency,
                                    int     channels,
                                    int     chunk_size
                                 )
	{
        /*Uint16  format = MIX_DEFAULT_FORMAT;
		Mix_OpenAudio(frequency, format, channels, chunk_size);*/
	}

	/**
	@brief Sets the volume of a specific channel
	@param channel Index of the channel. Use "-1" to set the volume of all channels
	@param volume Volume level in the range of 0-128
	*/
	void TAudio::SetVolumeOfChannel(int channel, int volume)
	{
		//Mix_Volume(channel, volume);
	}

	/**
	@brief Gets the volume level of a specific channel
	@param channel Index of the channel.
	*/
	int TAudio::GetVolumeOfChannel(int channel)
	{
        return -1;// return Mix_Volume(channel, -1);
	}

	/**
	@brief Pauses a channel
	@param channel The specific channel
	*/
	void TAudio::PauseChannel(int channel)
	{
		//Mix_Pause(channel);
	}

	/**
	@brief Resumes a channel
	@param channel The specific channel
	*/
	void TAudio::ResumeChannel(int channel)
	{
		//Mix_Resume(channel);
	}

	/**
	@brief Check if a specific channel is being played
	@param channel The specific channel.  Use "-1" to check all channels
	*/
	bool TAudio::IsChannelPlaying(int channel)
	{
        return false;// return Mix_Playing(channel) != 0;
	}

	/**
	@brief Closes the mixer
	*/
	void TAudio::CloseMixer()
	{
		//Mix_CloseAudio();
	}


	/**
	@brief Halts playing a specific channel.
	@param channel The specific channel. Use "-1" to halt all channels
	*/
	void TAudio::HaltChannel(int channel)
	{
		//Mix_HaltChannel(channel);
	}

	/**
	@brief Halts playing the music.
	*/
	void TAudio::HaltMusic()
	{
		//Mix_HaltMusic();
	}


}
