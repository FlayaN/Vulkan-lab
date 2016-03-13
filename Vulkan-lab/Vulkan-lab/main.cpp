#define VKCPP_ENHANCED_MODE
#include <vk_cpp.h>

int main()
{
	vk::ApplicationInfo appInfo;
	appInfo.pApplicationName("VoxelWorldTestRenderApp");
	appInfo.pEngineName("VoxelWorld");

	appInfo.apiVersion(VK_API_VERSION);

	vk::InstanceCreateInfo createInfo;
	createInfo.pApplicationInfo(&appInfo);
	//vk::AllocationCallbacks allocationCallbacks;
	vk::Instance instance;
	vk::Result result = vk::createInstance(&createInfo, nullptr, &instance);


	std::vector<vk::PhysicalDevice> devices;
	devices = instance.enumeratePhysicalDevices();

	////std::string graphicsCardName = 
	//auto ddsa = devices[0].getProperties();

	//auto tmp = devices[0].getMemoryProperties();

	vk::Device device;
	vk::DeviceCreateInfo deviceCreateInfo;
	//deviceCreateInfo.queueCreateInfoCount(1);

	vk::DeviceQueueCreateInfo deviceQueueCreateInfo;
	//deviceQueueCreateInfo.

	deviceCreateInfo.pQueueCreateInfos(&deviceQueueCreateInfo);

	auto physicalDevice = devices[0];

	result = physicalDevice.createDevice(&deviceCreateInfo, nullptr, &device);

	std::vector<vk::QueueFamilyProperties> queueProps;
	//queueProps.resize(queueCount);

	queueProps = physicalDevice.getQueueFamilyProperties();

	////vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueCount, queueProps.data());

	for(auto& queueProp : queueProps)
	{
		if (queueProp.queueFlags() & vk::QueueFlagBits::eGraphics)
			break;
	}



	return 1;
}