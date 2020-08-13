/*
 * ContinuousOper.h
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#ifndef SRC_CONTINUOUSOPERATIONMONITOR_H_
#define SRC_CONTINUOUSOPERATIONMONITOR_H_

#include <memory>
#include "../include/IDataMonitor.h"
#include "ContinuousOperationValidator.h"


class ContinuousOperationMonitor : public IDataMonitor
{
private:
    float limit;
    float continuousOp;
    std::unique_ptr<ContinuousOperationValidator> continuousOperValidator;
public:
    ContinuousOperationMonitor();
    ~ContinuousOperationMonitor();

    void SetLimit(float maxLimit);
    float GetLimit();
    bool SetData(float data);
    bool Validate(float dim, float limit);
};


#endif /* SRC_CONTINUOUSOPERATIONMONITOR_H_ */
