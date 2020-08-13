/*
 * class Factory.h
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#ifndef CNC_FACTORY_H
#define CNC_FACTORY_H

#include <map>
#include <string>
#include <iostream>

using namespace std;

class Factory
{
public:
    typedef void* (*CreateImplFn)(void);

    static Factory* Instance();

    bool Create(const std::string& name);
    void* GetObj(const std::string& name);
    void Delete();

    bool Register(const std::string& name, CreateImplFn creator);

private:
    static Factory* singleton;

    std::map<std::string, std::pair<CreateImplFn, void*>> factoryMap;
};

#endif /* CNC_FACTORY_H */
