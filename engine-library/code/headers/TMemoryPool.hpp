/*
 * File: TMemoryPool.hpp
 * File Created: 9th January 2020
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

#include <cstdint>

namespace TortillaEngine
{
    /**
    @brief Class for memory management
    */
	class TMemoryPool
	{
        /**
        @brief The array of reserved bytes.
        */
		uint8_t *	pool;

        /**
        @brief The count of reserved bytes.
        */
		size_t		size;

        /**
        @brief The count of allocated bytes.
        */
		size_t		allocated;

	public:
		
        /**
        @brief Creates a memory pool of the given size.
        @param size The amount of bytes to reserve.
        */
		TMemoryPool(size_t size) : size{ size }, allocated{0}
		{
			pool = new uint8_t[size];
		}

        /**
        @brief Frees the memory in the destruction of the object.
        */
		~TMemoryPool() { delete[] pool; }

        /**
        @brief Gives where to allocate a count of bytes.
        @param allocation_size The amount of bytes to allocate.
        @return A pointer where allocate the memory.
        */
		void * allocate(size_t allocation_size)
		{
			void * offset = nullptr;

			if (allocation_size < size - allocated)
			{
				offset		 = pool + allocated;				
				allocated	+= allocation_size;				
			}

			return offset;			
		}

        /**
        @brief Gives the reserved bytes.
        @return The amount of reserved bytes.
        */
		size_t get_size()			const { return this->size;					 }
        
        /**
        @brief Gives the amount of allocated bytes.
        @return The amount of allocated bytes.
        */
        size_t get_allocated()		const { return this->allocated;				 }

        /**
        @brief Gives the amount of free bytes in the pool.
        @return The amount of free space in the pool.
        */
		size_t get_available_size() const { return this->size - this->allocated; }

	};
}