/*
 * CNCMonitoring.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#include "Alarm.h"
#include "FactoryRegistration.h"
#include "CNCMonitoring.h"

#include "../include/IDataMonitor.h"

using namespace std;
const string statusString[] = {"ALL_OK", "NO POWER", "CONTROLLER BOARD NOT OK", "NO DATA CONIGURED"};

bool CNCMonitoring::Init(const std::string& dataType, float maxLimit){
    Factory::Instance()-> Create(dataType);

    IDataMonitor* ptr = move(static_cast<IDataMonitor*>(Factory::Instance()-> GetObj(dataType)));
    if(ptr == nullptr)
    {
        std::cout << "Init: Object for " << dataType << " not created yet!!!" << std::endl;
        return false;
    }
    else
    {
        ptr->SetLimit(maxLimit);
        return true;
    }
}

bool CNCMonitoring::SetDataValue(const std::string& dataType, float dataVal)
{
    bool retcode = true;
    IDataMonitor* ptr = static_cast<IDataMonitor*>(Factory::Instance()-> GetObj(dataType));
    if(ptr == nullptr)
    {
        std::cout << "SetDataValue: Object for " << dataType << " not created yet!!!" << std::endl;
        retcode = false;
    }
    else
    {
        if(!ptr->SetData(dataVal))
        {
            Alarm::Instance()->Trigger(FaultInEnvironment, dataType, dataVal, ptr->GetLimit());
            retcode = false;
        }
    }
    
    return retcode;
}

void CNCMonitoring::DeInit()
{
    Factory::Instance()-> Delete();
}
bool CNCMonitoring::CheckStartupStatus(Status status)
{
    if(status == ALL_OK)
    {
        return true;
    }
    else
    {
        Alarm::Instance()->Trigger(FaultInEnvironment, statusString[status]);
        return false;
    }
}
