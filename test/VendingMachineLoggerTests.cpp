#include <string>
#include "gtest/gtest.h"
#include "TestCommons.h"
#include "VendingMachineLogger.h"

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

    EXPECT_EQ(std::string("An error has encountered:") + "\n"
        + "Some Error Text" + "\n"
        + "The vending machine will reboot now." + "\n", streamWriter.str());
}
TEST(VendingMachineLogger, LogError_Test2)
{
    std::ostringstream streamWriter;
    TestVendingMachineLogger logger(&streamWriter);

    logger.LogError("Another Error Text");

    EXPECT_EQ(std::string("An error has encountered:") + "\n"
        + "Another Error Text" + "\n"
        + "The vending machine will reboot now." + "\n", streamWriter.str());
}
