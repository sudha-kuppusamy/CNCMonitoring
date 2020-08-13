/*
 * ContinuousOperationValidator.h
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#ifndef SRC_CONTINUOUSOPERATIONVALIDATOR_H_
#define SRC_CONTINUOUSOPERATIONVALIDATOR_H_


#include "IDataValidator.h"


class ContinuousOperationValidator : public IDataValidator
{
public:
    bool Validate(float op, float limit);
};

#endif /* SRC_CONTINUOUSOPERATIONVALIDATOR_H_ */
