#include <vkRAII/utils/utils-raii.hpp>

namespace RAII
{
    static std::string AppName = "InitDevice";
    static std::string EngineName = "Vulkan.hpp";

    int InitDevice()
    {
        vk::raii::Context context;

        vk::raii::Instance instance = vk::raii::su::makeInstance(context, AppName, EngineName);

#if !defined(NDEBUG)
        vk::raii::DebugUtilsMessengerEXT debugUtilsMessager(instance, vk::su::makeDebugUtilsMessengerCreateInfoEXT());
#endif
        vk::raii::PhysicalDevice physicalDevice = vk::raii::PhysicalDevices(instance).front();

        uint32_t graphicsQueueFamilyIndex = vk::su::findGraphicsQueueFamilyIndex(physicalDevice.getQueueFamilyProperties());

        float queuePriority = 1.0f;
        vk::DeviceQueueCreateInfo deviceQueueCreateInfo({}, graphicsQueueFamilyIndex, 1, &queuePriority);
        vk::DeviceCreateInfo deviceCreateInfo({}, deviceQueueCreateInfo);

        vk::raii::Device device(physicalDevice, deviceCreateInfo);
        return 0;
    }

}
