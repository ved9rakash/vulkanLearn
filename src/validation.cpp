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