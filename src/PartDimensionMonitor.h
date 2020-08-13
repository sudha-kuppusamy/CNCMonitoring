/*
 * PartDimension.h
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#ifndef SRC_PARTDIMENSIONMONITOR_H_
#define SRC_PARTDIMENSIONMONITOR_H_

#include <memory>
#include "../include/IDataMonitor.h"
#include "PartDimensionValidator.h"

class PartDimensionMonitor : public IDataMonitor
{
private:
    float limit;
    float dimension;
    std::unique_ptr<PartDimensionValidator> partDimValidator;
public:
    PartDimensionMonitor();
    ~PartDimensionMonitor();

    void SetLimit(float maxLimit);
    float GetLimit();
    bool SetData(float data);
    bool Validate(float dimension, float limit);
};






#endif /* SRC_PARTDIMENSIONMONITOR_H_ */
