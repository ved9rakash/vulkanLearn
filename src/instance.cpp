//
// Created by Vaibhav on 23-04-2022.
//
#include <cstring>
#include "instance.hpp"

#include <iostream>

void HelloTriangleApplication::run()
{
	initVulkan();
	mainLoop();
	cleanUp();
}

void HelloTriangleApplication::initVulkan()
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);		// Not openGL API
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);		// Resizable window is more Advanced.

	window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
	createInstance();
}

void HelloTriangleApplication::createInstance()
{
	if (enableValidationLayers && !checkValidationSupport()) {
		throw std::runtime_error("Validation Layers requested, but not available.");
	}

//	Optional. Graphics driver related structure initialization.
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

/*
 * Not Optional. Tell the vulkan driver which global variables
 * and validation layers we want to use.
*/
	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	auto extensions = getRequiredExtensions();
	createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	createInfo.ppEnabledExtensionNames = extensions.data();


	if (enableValidationLayers) {
		createInfo.enabledLayerCount = static_cast<uint32_t>(validation::validationLayers.size());
		createInfo.ppEnabledLayerNames = validation::validationLayers.data();
	} else {
		createInfo.enabledLayerCount = 0;
	}

	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

	if (result != VK_SUCCESS) {
		throw std::runtime_error("Failed to create vulkan Instance!");
	}
}

void HelloTriangleApplication::mainLoop()
{
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
}

void HelloTriangleApplication::cleanUp()
{
	vkDestroyInstance(instance, nullptr);

	glfwDestroyWindow(window);

	glfwTerminate();
}

bool HelloTriangleApplication::checkValidationSupport()
{
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : validation::validationLayers) {
		bool layerFound = false;

		for (const auto& layerProperties : availableLayers) {
			if (strcmp(layerName, layerProperties.layerName) == 0) {
				layerFound = true;
				break;
			}
		}
		if (!layerFound) {
			return false;
		}
	}
	return true;
}

std::vector<const char*> HelloTriangleApplication::getRequiredExtensions()
{
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtension;
	glfwExtension = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	std::vector<const char*> extensions(glfwExtension, glfwExtension + glfwExtensionCount);

	if (enableValidationLayers) {
		/*
		 * Note: We are using MACRO's. Here, VK_EXT_DEBUG_UTILS_EXTENSION_NAME is same
		 * as VK_EXT_DEBUG_utils string. Macro avoids Typo.
		 */
		extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}
	return extensions;
}

VkBool32 HelloTriangleApplication::debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagBitsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData)
{
	std::cerr << "validation Layer: " << pCallbackData->pMessage << std::endl;
}
