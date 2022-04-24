//
// Created by Vaibhav on 23-04-2022.
//
#include <cstring>
#include "instance.hpp"
#include "validation.hpp"

#include <iostream>

VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
	auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
	if (func != nullptr) {
		return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
	} else {
		return VK_ERROR_EXTENSION_NOT_PRESENT;
	}
}

void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
	auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
	if (func != nullptr) {
		func(instance, debugMessenger, pAllocator);
	}
}

void HelloTriangleApplication::run()
{
	initWindow();
	initVulkan();
	mainLoop();
	cleanUp();
}

void HelloTriangleApplication::initWindow()
{
	/*
	 * GLFW is used as Window creator/initializer.
	 * Initialize GLFW3.
	 * As GLFW3 is designed for openGL configurations we have to tell
	 * it to not create openGL context. That is by specifying, GLFW_NO_API
	 */
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	//	 Resizable window takes more care.
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	//	800, 600, "Vulkan", Optional to specify monitor, only for openGL
	window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
	createInstance();
}

void HelloTriangleApplication::initVulkan()
{
	//	Initialize Vulkan in GLFW Created window.
	createInstance();
	setupDebugMessenger();
}

void HelloTriangleApplication::mainLoop()
{
	/*
	 * main loop.
	 * Infinite loop to make application continuously running
	 * until error or window close operation is performed.
	 */
	while (!glfwWindowShouldClose(window)) {
	//	Events that are performed using keyboard/mouse or any external I/O device.
		glfwPollEvents();
	}
}

void HelloTriangleApplication::createInstance()
{
	/*
	 * Creating/Initializing an Instance to connect vulkan library
	 * to our application. Additional, Specifying details about drivers.
	 */
	if (enableValidationLayers && !checkValidationSupport()) {
		throw std::runtime_error("Validation Layers requested, but not available.");
	}

	//  Optional. Graphics driver related structure initialization
	//  optimize application.
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

    /*
     * Not Optional. Tell the vulkan driver which global variables
     * and validation layers we want to use. Global means, which apply to
     * whole program and not to specific device.
    */

	//Create Vulkan instance information.
	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	// Get Required Extensions in vector data structure and assign to
	// create structure
	auto extensions = getRequiredExtensions();
	createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	createInfo.ppEnabledExtensionNames = extensions.data();


	if (enableValidationLayers) {
		createInfo.enabledLayerCount = static_cast<uint32_t>(validation::validationLayers.size());
		createInfo.ppEnabledLayerNames = validation::validationLayers.data();
	} else {
		createInfo.enabledLayerCount = 0;
	}

	/* Creating Vulkan instance.
	 * Takes createInfo, pAllocator and VkInstance Object.
	 * Almost all vulkan functions return VkResults type value, i.e VK_SUCCESS or VK_FALSE.
	 * We only need to check this output(VkResult) value, and it automatically
	 * will be saved inside VkInstance object.
	*/
	//VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
		throw std::runtime_error("Failed to create vulkan Instance!");
	}
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
		 * as VK_EXT_DEBUG_utils string. Macro avoids Typo.
		 */
		extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}
	return extensions;
}

VkBool32 HelloTriangleApplication::debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData)
{
	std::cerr << "validation Layer: " << pCallbackData->pMessage << std::endl;
	return VK_FALSE;
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

void HelloTriangleApplication::setupDebugMessenger()
{
	if (!enableValidationLayers)
		return ;

	VkDebugUtilsMessengerCreateInfoEXT createInfo{};
	populateDebugMessengerCreateInfo(createInfo);

	if (CreateDebugUtilsMessengerEXT(instance, &createInfo, nullptr, &debugMessenger) != VK_SUCCESS) {
		throw std::runtime_error("Failed to setup debug messenger");
	}
}

void HelloTriangleApplication::cleanUp()
{
	/*
	 * Explicit Destructor to destroy or deAllocate dynamic memory or
	 * clean up resources. At last destroying and terminating GLFW itself.
	 */

	if (enableValidationLayers) {
		DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
	}

	vkDestroyInstance(instance, nullptr);

	glfwDestroyWindow(window);

	glfwTerminate();
}