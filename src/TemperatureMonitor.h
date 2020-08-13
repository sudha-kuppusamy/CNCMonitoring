/*
 * Temperature.h
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#ifndef SRC_TEMPERATUREMONITOR_H_
#define SRC_TEMPERATUREMONITOR_H_

#include <memory>
#include "../include/IDataMonitor.h"
#include "TemperatureValidator.h"

class TemperatureMonitor : public IDataMonitor
{
private:
    float limit;
    float temperature;
    std::unique_ptr<TemperatureValidator> tempValidator;

public:
    TemperatureMonitor();
    ~TemperatureMonitor();
    void SetLimit(float maxLimit);
    float GetLimit();
    bool SetData(float value);
    bool ValidateData(float temp, float limit);
};


#endif /* SRC_TEMPERATUREMONITOR_H_ */
