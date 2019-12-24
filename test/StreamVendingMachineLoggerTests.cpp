#include "gtest/gtest.h"
#include "StreamVendingMachineLogger.h"

using namespace std::string_literals;

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

    EXPECT_EQ("An error has encountered:"s + "\n"s
        + "Some Error Text"s + "\n"s
        + "The vending machine will reboot now."s + "\n"s, streamWriter.str());
}
TEST(StreamVendingMachineLogger, LogError_Test2)
{
    std::ostringstream streamWriter;
    StreamVendingMachineLogger logger(&streamWriter);

    logger.LogError("Another Error Text");

    EXPECT_EQ("An error has encountered:"s + "\n"s
        + "Another Error Text"s + "\n"s
        + "The vending machine will reboot now."s + "\n"s, streamWriter.str());
}