/*
 * TemperatureValidator.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#include "TemperatureValidator.h"

TemperatureValidator::TemperatureValidator()
{

}

TemperatureValidator::~TemperatureValidator()
{

}

bool TemperatureValidator::Validate(float temp, float maxLimit)
{
    if(temp > maxLimit)
    {
        return false;
    }
    else
    {
        return true;
    }
}

