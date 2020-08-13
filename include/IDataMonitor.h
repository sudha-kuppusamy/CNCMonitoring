/*
 * IData.h
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#ifndef INCLUDE_IDATAMONITOR_H_
#define INCLUDE_IDATAMONITOR_H_

class IDataMonitor
{
public:
    virtual ~IDataMonitor() {};
    virtual void SetLimit(float maxLimit) = 0;
    virtual float GetLimit() = 0;
    virtual bool SetData(float data) = 0;
};

#endif /* INCLUDE_IDATAMONITOR_H_ */
