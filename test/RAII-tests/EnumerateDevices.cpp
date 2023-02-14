#include <vkRAII/utils/utils-raii.hpp>
#include <iostream>
namespace RAII
{
    static std::string AppName = "EnumerateDevices";
    static std::string EngineName = "Vulkan.hpp";

    int EnumerateDevices()
    {
        vk::raii::Context context;

        vk::raii::Instance instance = vk::raii::su::makeInstance(context, AppName, EngineName);

#if !defined(NDEBUG)
        vk::raii::DebugUtilsMessengerEXT debugUilesMessager(instance, vk::su::makeDebugUtilsMessengerCreateInfoEXT());
#endif // !defined(NDEBUG)

        vk::raii::PhysicalDevices pyhsicalDevices(instance);
        return 0;
    }
}
