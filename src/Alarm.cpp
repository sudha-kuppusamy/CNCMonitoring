/*
 * Alarm.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#include <iostream>
#include "Alarm.h"

Alarm* Alarm::singleton = nullptr;

Alarm* Alarm::Instance()
{
    if (singleton == nullptr)
        singleton = new Alarm();

    return singleton;
}
void Alarm::Trigger(Fault fault, const std::string& dataType, float inVal, float limit)
{
    if(fault == FaultInEnvironment)
    {
        std::cout << "Fault in the environment: " << dataType << "(" << inVal << ")" << " is more than " << limit << " ,  please check!!!" << std::endl;
    }
    else
    {
        std::cout << "Fault in the Machine: " << dataType << "(" << inVal << ")" << " is more than " << limit << " ,  please check!!!" << std::endl;
    }
}

void Alarm::Trigger(Fault fault, const std::string& dataType)
{
    if(fault == FaultInEnvironment)
    {
        std::cout << "Fault in the environment: " << dataType << " ,  please check!!!" << std::endl;
    }
    else
    {
        std::cout << "Fault in the Machine: " << dataType << " ,  please check!!!" << std::endl;
    }
}
