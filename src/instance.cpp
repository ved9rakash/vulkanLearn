//
// Created by Vaibhav on 23-04-2022.
//
#include "helloTriangle.hpp"

#include <iostream>


void HelloTriangleApplication::run()
{
	/*
	 * Main application function.
	 * Calls GLFW to create window.
	 * Calls Vulkan to set up vulkan environment.
	 * Calls mainloop() for window to work and interact.
	 * At last, Calls clea up function to clean memory.
	 */

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

	//	Resizable window takes more care.
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	//	800, 600, "Vulkan", Optional to specify monitor, only for openGL
	window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
	createInstance();
}

void HelloTriangleApplication::initVulkan()
{
	//	Initialize Vulkan in GLFW Created window.

	//Creating instance.
	createInstance();
	setupDebugMessenger();
	pickPhysicalDevice();
	createLogicDevice();
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
		// enableValidationLayers = true for Debug Builds.
		// checkValidationSupport() to check if layers are present.
		throw std::runtime_error("Validation Layers requested, but not available.");
	}

	/*
	 * Optional.
	 * Graphics driver related structure initialization for optimizing application.
	*/
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

    /*
     * Not Optional.
     * Tell the vulkan driver which global variables and validation
     * layers we want to use. Global means, which apply to whole
     * program and not to specific device.
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


	VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
	if (enableValidationLayers) {
		createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		createInfo.ppEnabledLayerNames = validationLayers.data();

		populateDebugMessengerCreateInfo(debugCreateInfo);
		createInfo.pNext = static_cast<VkDebugUtilsMessengerCreateInfoEXT*>(&debugCreateInfo);
	} else {
		createInfo.enabledLayerCount = 0;
		createInfo.pNext = nullptr;
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

void HelloTriangleApplication::cleanUp()
{
	/*
	 * Explicit Destructor to destroy or deAllocate dynamic memory or
	 * clean up resources. At last destroying and terminating GLFW itself.
	 */
	vkDestroyDevice(device, nullptr);

	if (enableValidationLayers) {
		DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
	}

	vkDestroyInstance(instance, nullptr);

	glfwDestroyWindow(window);

	glfwTerminate();
}