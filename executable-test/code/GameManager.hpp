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

class GameManager
{

private:

    TSound* sound_effect;   
   

public:

    struct
    {  
        float max_x = 0;
        float max_z = 0;
        float min_x = 0;
        float min_z = 0;

    } limits;

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

    GameManager() 
    {
        sound_effect = nullptr;
    }

public:
    void play_sound()
    {
        
        if (sound_effect != nullptr)
        {
            sound_effect->PlaySoundEffect(-1, 1);
        }
        
    }

    void set_sound(char* path)
    {
        sound_effect = new TSound;
        sound_effect->LoadSound(path);
    }

    void reset_game(TScene * scene)
    {
        scene->reset();
    }
   
};