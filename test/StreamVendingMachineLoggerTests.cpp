#include <string>
#include "gtest/gtest.h"
#include "StreamVendingMachineLogger.h"

TEST(StreamVendingMachineLogger, LogInformation_Test1)
{
    std::ostringstream streamWriter;
    StreamVendingMachineLogger logger(&streamWriter);

    logger.LogInformation("Some Information");

    EXPECT_EQ("Some Information", streamWriter.str());
}
TEST(StreamVendingMachineLogger, LogInformation_Test2)
{
    std::ostringstream streamWriter;
    StreamVendingMachineLogger logger(&streamWriter);

    logger.LogInformation("Another Information");

    EXPECT_EQ("Another Information", streamWriter.str());
}

TEST(StreamVendingMachineLogger, LogError_Test1)
{
    std::ostringstream streamWriter;
    StreamVendingMachineLogger logger(&streamWriter);

    logger.LogError("Some Error Text");

    EXPECT_EQ(std::string("An error has encountered:") + "\n"
        + "Some Error Text" + "\n"
        + "The vending machine will reboot now." + "\n", streamWriter.str());
}
TEST(StreamVendingMachineLogger, LogError_Test2)
{
    std::ostringstream streamWriter;
    StreamVendingMachineLogger logger(&streamWriter);

    logger.LogError("Another Error Text");

    EXPECT_EQ(std::string("An error has encountered:") + "\n"
        + "Another Error Text" + "\n"
        + "The vending machine will reboot now." + "\n", streamWriter.str());
}