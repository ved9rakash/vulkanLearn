
#ifndef GLFW_INCLUDE_VULKAN
	#define GLFW_INCLUDE_VULKAN
#endif //GLFW_INCLUDE_VULKAN

#include "helloTriangle.hpp"

#include <iostream>
#include <cstdlib>
#include <vector>


int main()
{
/*	To check extension support currently available. */

//	uint32_t extensionCount = 0;
//	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
//	std::vector<VkExtensionProperties> extensions(extensionCount);
//	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
//
//	std::cout << "Available Extensions are:\n";
//	for (const auto& extension : extensions ) {
//		std::cout << extension.extensionName << '\n';
//	}


	HelloTriangleApplication app{};
	try {
		app.run();
	} catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}