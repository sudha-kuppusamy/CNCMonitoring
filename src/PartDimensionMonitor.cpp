/*
 * PartDimension.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#include "PartDimensionMonitor.h"

#include "FactoryRegistration.h"
#include "Alarm.h"

namespace FactoryRegistration {
    FactoryRegistration<PartDimensionMonitor> _PartDimension("partDimension");
}

PartDimensionMonitor::PartDimensionMonitor()
{
    limit = 0.7;
    partDimValidator.reset(new PartDimensionValidator());
}

PartDimensionMonitor::~PartDimensionMonitor()
{
    partDimValidator.reset(nullptr);
}
void PartDimensionMonitor::SetLimit(float maxLimit)
{
    limit = maxLimit;
}

float PartDimensionMonitor::GetLimit()
{
    return limit;
}

bool PartDimensionMonitor::SetData(float dim)
{
    dimension = dim;
    return partDimValidator->Validate(dimension, limit);
}
bool PartDimensionMonitor::Validate(float dim, float limit)
{
    if(dim > limit)
        return false;
    else
        return true;
}
