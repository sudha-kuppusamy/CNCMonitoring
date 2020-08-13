/*
 * CNCMonitoring.h
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#ifndef INCLUDE_CNCMONITORING_H_
#define INCLUDE_CNCMONITORING_H_
#include <string>

#include "../src/TemperatureMonitor.h"
#include "PartDimensionMonitor.h"
#include "ContinuousOperationMonitor.h"

typedef enum
{
    ALL_OK = 0xFF,
    NO_POWER = 0x01,
    CONTROLLER_BOARD_NOT_OK = 0x02,
    NO_DATA_CONIGURED = 0x03,
}Status;

class CNCMonitoring
{
public:
    //void Init();

    bool Init(const std::string& dataType, float maxLimit);
    void DeInit();

    bool CheckStartupStatus(Status Status);
    bool SetDataValue(const std::string& dataType, float dataVal);
};


#endif /* INCLUDE_CNCMONITORING_H_ */
