/*
 * IDataValidator.h
 *
 *  Created on: Aug 12, 2020
 *      Author: sudha
 */

#ifndef INCLUDE_IDATAVALIDATOR_H_
#define INCLUDE_IDATAVALIDATOR_H_


class IDataValidator
{
public:
    virtual ~IDataValidator() {};
    virtual bool Validate(float val, float limit) {};
};


#endif /* INCLUDE_IDATAVALIDATOR_H_ */
