/*
 * PartDimensionValidator.h
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#ifndef SRC_PARTDIMENSIONVALIDATOR_H_
#define SRC_PARTDIMENSIONVALIDATOR_H_

#include "IDataValidator.h"

class PartDimensionValidator : public IDataValidator
{
public:
    PartDimensionValidator();
    ~PartDimensionValidator();
    bool Validate(float dimension, float maxLimit);
};

#endif /* SRC_PARTDIMENSIONVALIDATOR_H_ */
