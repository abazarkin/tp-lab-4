#ifndef _TESTCOMMONS_H_
#define _TESTCOMMONS_H_

#include <iostream>
#include <vector>
#include "VendingMachineDrink.h"
#include "VendingMachineLogger.h"

static std::vector<VendingMachineDrink> drinks =
{
    VendingMachineDrink(0, 1, "Water"),
    VendingMachineDrink(1, 2, "Tea"),
    VendingMachineDrink(2, 5, "Coffee")
};

class TestVendingMachineLogger : public VendingMachineLogger
{
private:
    std::ostringstream *m_streamWriter;

protected:
    virtual void LogMessage(std::string message) override { *m_streamWriter << message; }

public:
    TestVendingMachineLogger(std::ostringstream *streamWriter) { m_streamWriter = streamWriter; }
};

#endif // _TESTCOMMONS_H_
