#include <gtest/gtest.h>
#include "RAII-tests/Index.h"
TEST(VulkanRAII, InitInstance)
{
	EXPECT_NO_THROW(RAII::InitInstance());
}