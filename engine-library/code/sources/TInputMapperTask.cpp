/*
 * File: TInputMapperTask.cpp
 * File Created: 25th January 2020
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

#include <TInputMapperTask.hpp>
#include <fstream>
#include <TScene.hpp>

namespace TortillaEngine
{
    /**
    @brief Recives the events in order and launch the messages of the actions.
    @param delta The time between execution calls.
    */
    void TInputMapperTask::run(float delta)
    {   
        std::shared_ptr<TInputTask> input = std::dynamic_pointer_cast<TInputTask>(owner_scene->get_task("TInputTask"));

        while(!input->event_pool_empty())
        { 
            std::shared_ptr<TEvent> event = input ->get_event();
        
            if (event != nullptr)
            {
                std::string key = event->to_string();

                //Only sends a message if the action map contains this key 
                if (actions.find(key) != actions.end())
                {                
                    owner_scene->get_dispatcher()->send({actions[key]});
                }
            }
        }
    }

    void TInputMapperTask::load_from_xml(const std::string& path)
    {        
        rapidxml::xml_document<> doc;

        std::ifstream xml_file(path);
        std::vector<char> buffer((std::istreambuf_iterator<char>(xml_file)), std::istreambuf_iterator<char>());
        buffer.push_back('\0');

        doc.parse<0>(&buffer[0]);
        rapidxml::xml_node<>* root = doc.first_node();

        if (root && (std::string) root->name() == "input")
        {
            for (
                rapidxml::xml_node <>* actions = root->first_node();
                actions;
                actions = actions->next_sibling()
                )
            {
                if (actions->type() == rapidxml::node_element)
                {
                    if ((std::string) actions->name() == "actions")
                    {
                        for (
                            rapidxml::xml_node <>* action = actions->first_node();
                            action;
                            action = action->next_sibling()
                            )
                        {
                            std::string key_name;
                            std::string action_name;

                            if (action->type() == rapidxml::node_element)
                            {
                                if ((std::string)action->name() != "action") return;
                            }

                            for (
                                rapidxml::xml_attribute<>* attributes = action->first_attribute();
                                attributes;
                                attributes = attributes->next_attribute()
                                )
                            {
                                if ((std::string)attributes->name() == "name")
                                {
                                    action_name = (std::string) attributes->value();
                                    
                                    for (
                                        rapidxml::xml_node<>* key = action->first_node();
                                        key;
                                        key = key->next_sibling()
                                        )
                                    {
                                        if ((std::string)key->name() == "key")
                                        {
                                            key_name = key->value();
                                        }
                                    }
                                }
                            }
                        
                            add_action(key_name, action_name);
                        }
                    }
                }
            }
        }


    }

}