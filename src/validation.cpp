//
// Created by Vaibhav on 23-04-2022.
//
#include <cstring>
#include "instance.hpp"
#include "validation.hpp"

const std::vector<const char*> validation::validationLayers = {
		"VK_LAYER_KHRONOS_validation"
};

bool HelloTriangleApplication::checkValidationSupport()
{
	/*
	 * Checks if the requested layers is present or not.
	 * List all the available layers using vkEnumerateInstanceLayerProperties same as
	 * vkEnumerateInstanceExtensionProperties in getRequiredExtensions() function.
	 */
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	// Check for validation layers. If present, return True else False.
	for (const char* layerName : validation::validationLayers) {
		bool layerFound = false;

		for (const auto& layerProperties : availableLayers) {
			if (std::strcmp(layerName, layerProperties.layerName) == 0) {
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

	// Get required instance extension from GLFW.
	// Return Extension names and Extension Count.
	glfwExtension = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	std::vector<const char*> extensions(glfwExtension, glfwExtension + glfwExtensionCount);

	if (enableValidationLayers) {
		/*
		 * Note: We are using MACRO's. Here, VK_EXT_DEBUG_UTILS_EXTENSION_NAME is same
		 * as VK_EXT_DEBUG_utils string. Macro avoids Typos.
		 */
		extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}
	return extensions;
}

void HelloTriangleApplication::populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo)
{
	createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
	createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
	createInfo.pfnUserCallback = static_cast<PFN_vkDebugUtilsMessengerCallbackEXT>(debugCallback);
	createInfo.pUserData = nullptr; // Optional
}

VkBool32 HelloTriangleApplication::debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData)
{
	std::cerr << "validation Layer: " << pCallbackData->pMessage << std::endl;
	return VK_FALSE;
}

