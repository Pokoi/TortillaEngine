/*
 * File: TMessage.hpp
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
#include <string>
#include <list>
#include <TVariant.hpp>

namespace TortillaEngine
{
    /**
    @brief Messages form the send - receive messages system
    */
    class TMessage
    {
        /**
        @brief The message id. Observers subscribes in base of this id.
        */
        std::string id;
        /**
        @brief Collection of parameters attached to this message.
        */
        std::map<std::string, TVariant> parameters;

    public:

        /**
        @brief Creates a message with the given id.
        @param id The message id.
        */
        TMessage(std::string id) 
		{
			this->id = id;
		}

        /**
        @brief Attaches a new parameter to the message.
        @param key The key of this param in the collection of parameters in the message
        @param value The parameter to attach
        */
        void add_parameter(const std::string & key, TVariant& value)
        {
            parameters[key] = value;
        }

        /**
        @brief Gets the id of the message
        @return The message id.
        */
        std::string get_id() { return id; }

        /**
        @brief Operator [] overloading to get a parameter in base of this key
        @param key The key of the parameter to get
        @return A reference to the parameter 
        */
        TVariant& operator[] (std::string key)
        {
            return parameters[key];
        }

        ~TMessage()
        {
            
        }
    };

}