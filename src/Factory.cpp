/*
 * Factory.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#include <stdarg.h>
#include <stdio.h>
#include "Factory.h"

Factory* Factory::singleton = nullptr;

Factory* Factory::Instance()
{
    if (singleton == nullptr)
        singleton = new Factory();

    return singleton;
}

bool Factory::Register(const std::string& name, CreateImplFn creator)
{
    if (creator == nullptr)
    {
        return false;
    }

    auto it = factoryMap.find(name);
    if (it != factoryMap.end())
    {
        // name already registered
        return false;
    }

    std::cout << "register " << name << " at factory" << std::endl;
    factoryMap.insert(std::make_pair(name, std::make_pair(creator, nullptr)));

    return true;
}

bool Factory::Create(const std::string& name)
{
    // check for NULL
    if (name.empty())
        return false;

    typename std::map<std::string, std::pair<CreateImplFn, void*>>::iterator it;
    it = factoryMap.begin();

    it = factoryMap.find(name);
    if (it == factoryMap.end())
    {
        cout << "implementation " << name << " %s not registered to factory" << endl;
        return false;
    }

    it->second.second = it->second.first();
}

void* Factory::GetObj(const std::string& name)
{
    // check for NULL
    if (name.empty())
        return nullptr;

    typename std::map<std::string, std::pair<CreateImplFn, void*>>::iterator it;
    it = factoryMap.begin();

    it = factoryMap.find(name);
    if (it == factoryMap.end())
    {
        std::cout << "implementation " << name << " %s not registered to factory" << endl;
        return nullptr;
    }

    return it->second.second;
}

void Factory::Delete()
{
    typename std::map<std::string, std::pair<CreateImplFn, void*>>::iterator it;
    for( it = factoryMap.begin(); it != factoryMap.end(); it++ )
    {
        if(it->second.second != nullptr)
        {
//             delete it->second.second;
        }
    }
}
