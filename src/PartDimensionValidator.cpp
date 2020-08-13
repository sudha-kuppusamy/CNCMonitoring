/*
 * PartDimensionValidator.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#include "PartDimensionValidator.h"

PartDimensionValidator::PartDimensionValidator(){

}

PartDimensionValidator::~PartDimensionValidator(){

}
bool PartDimensionValidator::Validate(float dimension, float maxLimit)
{
    if(dimension > maxLimit)
    {
        return false;
    }
    else
    {
        return true;
    }
}


