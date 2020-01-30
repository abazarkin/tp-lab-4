#include "VendingMachineLogger.h"

void VendingMachineLogger::LogInformation(std::string text)
{
    LogMessage(text);
};
void VendingMachineLogger::LogError(std::string errorText)
{
    LogMessage(std::string("An error has encountered:") + "\n");
    LogMessage(errorText + "\n");
    LogMessage(std::string("The vending machine will reboot now.") + "\n");
};
