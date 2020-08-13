/*
 * FactoryRegistration.h
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#ifndef INCLUDE_FACTORYREGISTRATION_H_
#define INCLUDE_FACTORYREGISTRATION_H_

#include <memory>
#include "Factory.h"

namespace FactoryRegistration
{
    template <typename T>
    class FactoryRegistration
    {
    public:
        FactoryRegistration(const std::string& name)
        {
            std::cout << "FactoryRegistration " << name.c_str() << endl;
              Factory::Instance()->Register(name,
                                            []()->void* { return static_cast<T*>(new T());});
              std::cout << "FactoryRegistration done for " << name.c_str() << endl;;
        }
    };
}


#endif /* INCLUDE_FACTORYREGISTRATION_H_ */
