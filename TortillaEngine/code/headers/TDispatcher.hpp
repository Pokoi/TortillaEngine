/*
 * File: TDispatcher.hpp
 * File Created: 13th January 2020
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
#include <map>
#include <list>
#include <TObserver.hpp>

namespace TortillaEngine
{
    class TDispatcher
    {

        std::map<const char*, std::list<TObserver*>> observers;

    public: 
        
        static TDispatcher& instance()
        {
            static TDispatcher instance;
            return instance;
        }

        void add(TObserver& observer, const char* id)
        {
            observers[id].push_back(&observer);
        }

        void send(const TMessage& message)
        {
            auto list = observers.find(message.get_id());

            if (list != observers.end)
            {
                for (auto& observer : list->second)
                {
                    observer->handle(message);
                }
            }
        }

        void remove(TObserver& observer, const char* id)
        {
          std::map<const char*, std::list<TObserver*>>::iterator it = observers.find(observer);
          observers.clear(it);
        }

    private:

        TDispatcher() {}
    };
}