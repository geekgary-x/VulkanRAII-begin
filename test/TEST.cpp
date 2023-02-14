#include <gtest/gtest.h>
#include "RAII-tests/Index.h"
TEST(VulkanRAII, InitInstance)
{
	EXPECT_NO_THROW(RAII::InitInstance());
}

TEST(VulkanRAII, EnumerateDevices)
{
	EXPECT_NO_THROW(RAII::EnumerateDevices());
}

TEST(VulkanRAII, InitDevice)
{
	EXPECT_NO_THROW(RAII::InitDevice());
}