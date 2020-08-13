/*
 * Temperature.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#include "TemperatureMonitor.h"

#include "FactoryRegistration.h"
#include "Alarm.h"

namespace FactoryRegistration {
    FactoryRegistration<TemperatureMonitor> _Temperature("temperature");
}

TemperatureMonitor::TemperatureMonitor()
{
    // set limit by default
    limit = 37.0;
    tempValidator.reset(new TemperatureValidator());
}

TemperatureMonitor::~TemperatureMonitor()
{
    tempValidator.reset(nullptr);
}

void TemperatureMonitor::SetLimit(float maxLimit)
{
    limit = maxLimit;
}
float TemperatureMonitor::GetLimit()
{
    return limit;
}
bool TemperatureMonitor::SetData(float val)
{
    temperature = val;
    return ValidateData(temperature, limit);
}

bool TemperatureMonitor::ValidateData(float temp, float limit)
{
    return tempValidator->Validate(temp, limit);
}
