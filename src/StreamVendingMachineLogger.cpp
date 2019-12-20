#include <iostream>
#include "StreamVendingMachineLogger.h"

void StreamVendingMachineLogger::LogMessage(std::string message) { *m_streamWriter << message; };

StreamVendingMachineLogger::StreamVendingMachineLogger(std::ostream *streamWriter)
{
    m_streamWriter = streamWriter;
};
