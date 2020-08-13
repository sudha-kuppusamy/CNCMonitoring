/*
 * ContinuousOperationValidator.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#include "ContinuousOperationValidator.h"

bool ContinuousOperationValidator::Validate(float op, float limit)
{
    if(op > limit)
    {
        return true;
    }
    else
    {
        return false;
    }
}
