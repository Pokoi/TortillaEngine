/*
 * File: TScene.cpp
 * File Created: 14th January 2020
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

#include <TScene.hpp>
#include <fstream>
#include <rapidxml-1.13/rapidxml.hpp>
#include <string>

#include <TSphereCollider.hpp>
#include <TCameraComponent.hpp>
#include <TRenderComponent.hpp>
#include <TLightComponent.hpp>
#include <TTransformComponent.hpp>

namespace TortillaEngine
{

    void TScene::load(const std::string& path)
    {        
        scene_path = path;
        rapidxml::xml_document<> doc;

        std::ifstream xml_file(path);
        std::vector<char> buffer((std::istreambuf_iterator<char>(xml_file)), std::istreambuf_iterator<char>());
        buffer.push_back('\0');

        doc.parse<0>(&buffer[0]);
        rapidxml::xml_node<>* root = doc.first_node();

        if (root && (std::string) root->name() == "scene")
        {
            parse_scene(root);
        }
    }

    void TScene::parse_scene(rapidxml::xml_node<>* node)
    {
        for (
                rapidxml::xml_node <> * entities = node->first_node();
                entities;
                entities = entities->next_sibling()
            )
        {
            if (entities->type() == rapidxml::node_element)
            {
                if ((std::string) entities->name() == "entities")
                {
                    parse_entities(entities);
                }
            }
        }
    }

    void TScene::parse_entities(rapidxml::xml_node<>* node)
    {
        std::shared_ptr<TEntity> new_entity = nullptr;

        for (
            rapidxml::xml_node <>* entity = node->first_node();
            entity;
            entity = entity->next_sibling()
            )
        {
            if (entity->type() == rapidxml::node_element)
            {
                if ((std::string)entity->name() != "entity") return;
            }

            for (
                rapidxml::xml_attribute<>* attributes = entity->first_attribute();
                attributes;
                attributes = attributes->next_attribute()
                )
            {
                if ((std::string)attributes->name() == "name")
                {
                    new_entity = std::make_shared<TEntity>(std::string(attributes->value()), this, nullptr);
                    add_entity(new_entity);

                    for (
                        rapidxml::xml_node<>* components = entity->first_node();
                        components;
                        components = components->next_sibling()
                        )
                    {
                        if (components->type() == rapidxml::node_element)
                        {
                            if ((std::string)components->name() == "components")
                            {
                                for (
                                        rapidxml::xml_node <> * component = components ->first_node();
                                        component;
                                        component = component ->next_sibling()
                                    )
                                {
                                    if (component->type() == rapidxml::node_element)
                                    {
                                        if ((std::string)component->name() != "component") return;
                                    }

                                    for (
                                            rapidxml::xml_attribute<> * attribute = component ->first_attribute();
                                            attribute;
                                            attribute = attribute ->next_attribute()
                                        )
                                    {
                                        if ((std::string)attribute->name() == "type")
                                        {
                                            std::string type = attribute->value();

                                            if ((std::string)type == "sphere collider")
                                            {
                                                std::shared_ptr<TSphereCollider> collider = std::make_shared<TSphereCollider>(new_entity.get(), 0, 0, 0, 0);
                                                new_entity->add_component("TSphereCollider", collider);
                                                collider->parse_component(component);
                                            }
                                            else if ((std::string)type == "camera")
                                            {
                                                std::shared_ptr<TCameraComponent> camera = std::make_shared<TCameraComponent>(new_entity.get(), 0, 0, 0, 0);
                                                new_entity->add_component("TCameraComponent", camera);
                                                camera->parse_component(component);
                                            }
                                            else if ((std::string)type == "light")
                                            {
                                                TLightComponent::TColor color{ 0,0,0 };
                                                std::shared_ptr<TLightComponent> light = std::make_shared<TLightComponent>(new_entity.get(), color, 0);
                                                new_entity->add_component("TLightComponent", light);
                                                light->parse_component(component);
                                            }
                                            else if ((std::string)type == "render")
                                            {
                                                std::shared_ptr<TRenderComponent> render = std::make_shared<TRenderComponent>(new_entity.get());
                                                new_entity->add_component("TRenderComponent", render);
                                                render->parse_component(component);
                                            }
                                            else if ((std::string)type == "transform")
                                            {
                                                new_entity->get_transform().parse_component(component);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
            }
        }
    }
}