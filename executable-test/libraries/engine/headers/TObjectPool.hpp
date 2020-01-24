/*
 * File: TObjectPool.hpp
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
    @brief A template class for memory management object oriented
    */
	template <typename T>
	class TObjectPool
	{

    private:
        
		struct Node
		{
			uint8_t object[sizeof(T)];
			Node *  next;

            bool operator == const(const Node & other)
            {
                return object == other.object;
            }

		};

        uint8_t *   pool;
        size_t      size;
        Node    *   free;

    public:
        TObjectPool(size_t size) : size{ size }
        {
            pool = new uint8_t[size * sizeof(Node)];
            free = reinterpret_cast <Node*>(pool);
            
            link_nodes(free);
        }

        ~TObjectPool() { delete[] pool; }

        T* allocate()
        {
            if (free == nullptr)
            {
                return nullptr;
            }

            Node    * free_to_return = free;
            
            free = free->next;
            
            return reinterpret_cast <T*> (free_to_return);
        }

        void deallocate(T* to_deallocate)
        {
            if (to_deallocate)
            {
                Node * deallocated_node = reinterpret_cast <Node*>(to_deallocate);
                Node * node             = pool;
                Node * end              = pool + (size * sizeof(Node);

                while (node < end)
                {
                    if (node == deallocated_node)
                    {
                        node->next  = free;
                        free        = node;

                        break;
                    }
                    ++node;
                }                     

            }
        }

    private:

        void link_nodes(Node* first)
        {
            for (
                    Node* node = first, Node* end = node + (size * sizeof(Node);
                          node < end;
                          node++;
				)
            {
                node->next = node + 1;
            }

            first[size - 1].next = nullptr;
        }
	};

}