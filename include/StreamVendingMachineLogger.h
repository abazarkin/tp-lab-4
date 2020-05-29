#ifndef _STREAMVENDINGMACHINELOGGER_H_
#define _STREAMVENDINGMACHINELOGGER_H_

#include <iostream>
#include "VendingMachineLogger.h"

class StreamVendingMachineLogger : public VendingMachineLogger
{
private:
    std::ostream *m_streamWriter;

protected:
    virtual void LogMessage(std::string message) override;

public:
    StreamVendingMachineLogger(std::ostream *streamWriter);
};

#endif // _STREAMVENDINGMACHINELOGGER_H_
