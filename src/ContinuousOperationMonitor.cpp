/*
 * ContinuouOper.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */


#include "FactoryRegistration.h"
#include "Alarm.h"
#include "ContinuousOperationMonitor.h"

namespace FactoryRegistration {
    FactoryRegistration<ContinuousOperationMonitor> _ContinuousOp("continuousOper");
}

ContinuousOperationMonitor::ContinuousOperationMonitor()
{
    // set default limit for continuous operation as 6.5h
    limit = 6.5;
    continuousOperValidator.reset(new ContinuousOperationValidator());
}

ContinuousOperationMonitor::~ContinuousOperationMonitor(){
    continuousOperValidator.reset(nullptr);
}
void ContinuousOperationMonitor::SetLimit(float maxLimit)
{
    limit = maxLimit;
}

float ContinuousOperationMonitor::GetLimit()
{
    return limit;
}

bool ContinuousOperationMonitor::SetData(float val)
{
    continuousOp = val;
    return Validate(continuousOp, limit);
}

bool ContinuousOperationMonitor::Validate(float dim, float limit)
{
    if(dim > limit)
        return false;
    else
        return true;
}
