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
#include <string>
#include <algorithm>
#include <TObserver.hpp>



namespace TortillaEngine
{
    /**
    @brief Management of messages
    */
    class TDispatcher
    {
        /**
        @brief Collection of subscribed observers 
        */
        std::map<std::string, std::list<TObserver*>> observers;

    public: 
        
        /**
        @brief Gets an instance of the dispatcher
        @return A instance of the dispatcher.
        */
        static TDispatcher& instance()
        {
            static TDispatcher instance;
            return instance;
        }

        /**
        @brief Adds an observer to the collection of subscribed observers
        @param observer A reference from the observer
        @param id The message id is subscribed to
        */
        void add(TObserver& observer, std::string id)
        {
            observers[id].push_back(&observer);
        }

        /**
        @brief Sends a message to all the observers subscribed to this message id
        @param message The message to send
        */
        void send(TMessage message)
        {
            auto list = observers.find(message.get_id());

            if (list != observers.end())
            {
                for (auto& observer : list->second)
                {
                    observer->handle(message);
                }
            }
        }

        /**
        @brief Removes an observer from the collection of subscribed observers
        @param observer A reference to the observer to unsubscribe
        @param id The id of the message this observer want to unsubscribe
        */
        void remove(TObserver& observer, std::string id)
        {			
            /*std::map<std::string, std::list<TObserver*>>::const_iterator it = std::find(observers.begin(), observers.end(), observer);
            observers.erase(it); */
        }

    private:

        TDispatcher() {}
    };
}