#ifndef ALARM_H
#define ALARM_H

#include <string>

using namespace std;
typedef enum
{
    FaultInEnvironment,
    FaultInMachine
}__attribute__ ((packed, aligned (1))) Fault;

class Alarm
{
private:
    static Alarm* singleton;
public:
    static Alarm* Instance();
    void Trigger(Fault fault, const std::string& dataType, float inVal, float limit);
    void Trigger(Fault fault, const std::string& dataType);
};

#endif
