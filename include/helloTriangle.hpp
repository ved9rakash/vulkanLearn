//
// Created by Vaibhav on 23-04-2022.
//

#ifndef VULKANLEARN_HELLOTRIANGLE_HPP
#define VULKANLEARN_HELLOTRIANGLE_HPP

#ifndef GLFW_INCLUDE_VULKAN
	#define GLFW_INCLUDE_VULKAN
#endif //GLFW_INCLUDE_VULKAN

#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "vulkan/vulkan.h"

#include <stdexcept>
#include <vector>
#include <optional>

//	Enable validation layers checking if(BUILD == DEBUG)
#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif //NDEBUG

//	Validation layers
const std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"
};

struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;

	bool isComplete() {
		return graphicsFamily.has_value();
	}
};


class HelloTriangleApplication {
public:
	void run();

private:
	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanUp();
	void createInstance();
	bool checkValidationSupport();
	std::vector<const char*> getRequiredExtensions();
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
			VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
			VkDebugUtilsMessageTypeFlagsEXT messageType,
			const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
			void* pUserData
			);
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	void setupDebugMessenger();
	void pickPhysicalDevice();
	bool isDeviceSuitable(VkPhysicalDevice device);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	void createLogicDevice();

private:
	//	Window Initialization
	static constexpr uint32_t WIDTH = 800;
	static constexpr uint32_t HEIGHT = 600;
	GLFWwindow* window;

	//	Instance object
	VkInstance instance;

	// Debug messenger to manage debug callback.
	VkDebugUtilsMessengerEXT debugMessenger;


	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice device;
	VkQueue graphicsQueue;
};

VkResult CreateDebugUtilsMessengerExt(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);


#endif //VULKANLEARN_HELLOTRIANGLE_HPP
