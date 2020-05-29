#ifndef _VENDINGMACHINELOGGER_H_
#define _VENDINGMACHINELOGGER_H_

#include <string>

class VendingMachineLogger
{
protected:
    virtual void LogMessage(std::string message) = 0;

public:
    virtual ~VendingMachineLogger() { };

    void LogInformation(std::string text);
    void LogError(std::string errorText);
};

#endif // _VENDINGMACHINELOGGER_H_
