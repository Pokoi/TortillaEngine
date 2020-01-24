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
    /**
    @brief A class to allow to save objects of diferent primitives types
    */
    class TVariant
    {
    private:

        /**
        @brief The types of the data value
        */
        enum class Type
        {
            INT, STRING, BOOLEAN, FLOAT
        };

        /**
        @brief The data value
        */
        union Value
        {
            int         int_value;
            const char* string_value;
            bool        bool_value;
            float       float_value;
        };

        /**
        @brief The type of this data value
        */
        Type    type;

        /**
        @brief The data value
        */
        Value   value;

    public:

        /**
        @brief Creates a default variant object. By default is int whit value 0.
        */
        TVariant()
        {
            this->type = TVariant::Type::INT;
            this->value.int_value = 0;
        }

        /**
        @brief Creates an int data variant object.
        @param value The value 
        */
        TVariant(int value)
        {
            this->type              = TVariant::Type::INT;
            this->value.int_value   = value;
        }

        /**
        @brief Creates a float data variant object.
        @param value The value
        */
        TVariant(float value)
        {
            this->type              = TVariant::Type::FLOAT;
            this->value.float_value = value;
        }

        /**
        @brief Creates a bool data variant object.
        @param value The value.
        */
        TVariant(bool value)
        {
            this->type              = TVariant::Type::BOOLEAN;
            this->value.bool_value  = value;
        }

        /**
        @brief Creates a string data variant object.
        @param value The value
        */
        TVariant(std::string value)
        {
            this->type               = TVariant::Type::STRING;
            this->value.string_value = value.c_str();
        }

        /**
        @brief Gives the data value type.
        @return The type of the data value.
        */
        Type    get_type()  const { return this->type;  }

        /**
        @brief Gives the data value.
        @return The data value
        */
        Value   get_value() const { return this->value; }
                  
        /**
        @brief Frees the memory in the destruction.
        */
        ~TVariant()
        {
            if (this->type == TVariant::Type::STRING)
            {
                delete [] value.string_value;
            }
        }

    public:    

        /**
        @brief Overloading of the = operator to copy the value and type of another variant
        @param other The variant object to copy
        */
        void operator = (const TVariant& other)
        {
            if (this != &other)
            {
                this->type  = other.get_type();
                this->value = other.get_value();
            }
        }

        /**
        @brief Overloading of the = operator to asign the value to the variant object
        @param value The value to asign
        */
        TVariant & operator = (int value)
        {
            this->type              = TVariant::Type::INT;
            this->value.int_value   = value;
        }

        /**
        @brief Overloading of the = operator to asign the value to the variant object
        @param value The value to asign
        */
        TVariant & operator = (float value)
        {
            this->type              = TVariant::Type::FLOAT;
            this->value.float_value   = value;
        }

        /**
        @brief Overloading of the = operator to asign the value to the variant object
        @param value The value to asign
        */
        TVariant & operator = (bool value)
        {
            this->type              = TVariant::Type::BOOLEAN;
            this->value.bool_value  = value;
        }

        /**
        @brief Overloading of the = operator to asign the value to the variant object
        @param value The value to asign
        */
        TVariant & operator = (std::string value)
        {
            this->type               = TVariant::Type::STRING;
            this->value.string_value = value.c_str();
        }
        
        /**
        @brief Gives the data value as float
        @return The data value as float
        */
        float to_float()
        {
            return this->value.float_value;
        }

        /**
        @brief Gives the data value as int
        @return The data value as int
        */
        int to_int()
        {
            return this->value.int_value;
        }

        /**
        @brief Gives the data value as bool
        @return The data value as bool
        */
        bool to_bool()
        {
            return this->value.bool_value;
        }

        /**
        @brief Gives the data value as string
        @return The data value as string
        */
        std::string to_string()
        {
            return this->value.string_value;
        }
    };

}