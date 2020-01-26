/*
 * File: EnemyController.hpp
 * File Created: 24th January 2020
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

#pragma once

#include <TSound.hpp>
#include <TScene.hpp>
using namespace TortillaEngine;

/**
@brief Manager of the game 
*/
class GameManager
{

private:

    /**
    @brief Reference to the sound effect
    */
    TSound* sound_effect;   
   

public:

    /**
    @brief The limits of the player's movement
    */
    struct
    {  
        float max_x = 3.5;
        float max_z = 3.5;
        float min_x = -3.5;
        float min_z = -3.5;

    } limits;

    /**
    @brief Gets an instance. If its not created, it create one
    */
    static GameManager * get()
    {
        static GameManager * instance;

        if (instance == nullptr)
        {
            instance = new GameManager();
        }

        return instance;
    }

private:

    /**
    @brief Create the component
    */
    GameManager() 
    {
        sound_effect = nullptr;
    }

public:

    /**
    @brief Plays the sound
    */
    void play_sound()
    {        
        if (sound_effect != nullptr)
        {
            sound_effect->PlaySoundEffect(-1, 1);
        }
        
    }

    /**
    @brief Sets the sound
    @param path The asset path
    */
    void set_sound(char* path)
    {
        sound_effect = new TSound;
        sound_effect->LoadSound(path);
    }

    /**
    @brief Reset the game scene
    @param scene A reference to the scene to reset
    */
    void reset_game(TScene * scene)
    {
        scene->reset();
    }
   
};