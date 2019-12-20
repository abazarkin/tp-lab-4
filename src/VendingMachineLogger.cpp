#include "VendingMachineLogger.h"

using namespace std::string_literals;

void VendingMachineLogger::LogInformation(std::string text)
{
    LogMessage(text);
};
void VendingMachineLogger::LogError(std::string errorText)
{
    LogMessage("An error has encountered:"s + "\n"s);
    LogMessage(errorText + "\n"s);
    LogMessage("The vending machine will reboot now."s + "\n"s);
};
