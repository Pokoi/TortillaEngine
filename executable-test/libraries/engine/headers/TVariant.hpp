/*
 * File: TVariant.hpp
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
#include <string>


namespace TortillaEngine
{

    class TVariant
    {
    private:

        enum class Type
        {
            INT, STRING, BOOLEAN, FLOAT
        };

        union Value
        {
            int         int_value;
            const char* string_value;
            bool        bool_value;
            float       float_value;
        };

        Type    type;
        Value   value;

    public:

        TVariant()
        {
            this->type = TVariant::Type::INT;
            this->value.int_value = 0;
        }

        TVariant(int value)
        {
            this->type              = TVariant::Type::INT;
            this->value.int_value   = value;
        }

        TVariant(float value)
        {
            this->type              = TVariant::Type::FLOAT;
            this->value.float_value = value;
        }

        TVariant(bool value)
        {
            this->type              = TVariant::Type::BOOLEAN;
            this->value.bool_value  = value;
        }

        TVariant(std::string & value)
        {
            this->type               = TVariant::Type::STRING;
            this->value.string_value = value.c_str();
        }

        Type    get_type()  const { return this->type;  }
        Value   get_value() const { return this->value; }
                  

        ~TVariant()
        {
            if (this->type == TVariant::Type::STRING)
            {
                delete [] value.string_value;
            }
        }

    public:    

        void operator = (const TVariant& other)
        {
            if (this != &other)
            {
                this->type  = other.get_type();
                this->value = other.get_value();
            }
        }

        TVariant & operator = (int value)
        {
            this->type              = TVariant::Type::INT;
            this->value.int_value   = value;
        }

        TVariant & operator = (float value)
        {
            this->type              = TVariant::Type::FLOAT;
            this->value.float_value   = value;
        }

        TVariant & operator = (bool value)
        {
            this->type              = TVariant::Type::BOOLEAN;
            this->value.bool_value  = value;
        }

        TVariant & operator = (std::string value)
        {
            this->type               = TVariant::Type::STRING;
            this->value.string_value = value.c_str();
        }
         
        float to_float()
        {
            return this->value.float_value;
        }

        int to_int()
        {
            return this->value.int_value;
        }

        bool to_bool()
        {
            return this->value.bool_value;
        }

        std::string to_string()
        {
            return this->value.string_value;
        }
    };

}