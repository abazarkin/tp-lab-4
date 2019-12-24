#include "gtest/gtest.h"
#include "TestCommons.h"
#include "VendingMachineLogger.h"

using namespace std::string_literals;

TEST(VendingMachineLogger, LogInformation_Test1)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);

    logger.LogInformation("Some Information");

    EXPECT_EQ("Some Information", streamWriter.str());
}
TEST(VendingMachineLogger, LogInformation_Test2)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);

    logger.LogInformation("Another Information");

    EXPECT_EQ("Another Information", streamWriter.str());
}

TEST(VendingMachineLogger, LogError_Test1)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);

    logger.LogError("Some Error Text");

    EXPECT_EQ("An error has encountered:"s + "\n"s
        + "Some Error Text"s + "\n"s
        + "The vending machine will reboot now."s + "\n"s, streamWriter.str());
}
TEST(VendingMachineLogger, LogError_Test2)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);

    logger.LogError("Another Error Text");

    EXPECT_EQ("An error has encountered:"s + "\n"s
        + "Another Error Text"s + "\n"s
        + "The vending machine will reboot now."s + "\n"s, streamWriter.str());
}
