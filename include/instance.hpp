//
// Created by Vaibhav on 23-04-2022.
//

#ifndef VULKANLEARN_INSTANCE_HPP
#define VULKANLEARN_INSTANCE_HPP

#ifndef GLFW_INCLUDE_VULKAN
	#define GLFW_INCLUDE_VULKAN
#endif //GLFW_INCLUDE_VULKAN

#include "validation.hpp"

#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "vulkan/vulkan.h"

#include <stdexcept>
#include <vector>


class HelloTriangleApplication {
public:
	void run();

private:
	void initVulkan();
	void mainLoop();
	void cleanUp();
	void createInstance();
	bool checkValidationSupport();
	std::vector<const char*> getRequiredExtensions();
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
			VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
			VkDebugUtilsMessageTypeFlagBitsEXT messageType,
			const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
			void* pUserData
			);

private:
	static constexpr uint32_t WIDTH = 800;
	static constexpr uint32_t HEIGHT = 600;
	GLFWwindow* window;
	VkInstance instance;
};

#endif //VULKANLEARN_INSTANCE_HPP
