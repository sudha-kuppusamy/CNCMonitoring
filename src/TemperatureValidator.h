/*
 * TemperatureValidator.h
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#ifndef SRC_TEMPERATUREVALIDATOR_H_
#define SRC_TEMPERATUREVALIDATOR_H_

#include "IDataValidator.h"

class TemperatureValidator : public IDataValidator
{
public:
    TemperatureValidator();
    ~TemperatureValidator();
    bool Validate(float temperature, float maxLimit);
};

#endif /* SRC_TEMPERATUREVALIDATOR_H_ */
