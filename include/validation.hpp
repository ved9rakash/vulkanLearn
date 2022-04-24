//
// Created by Vaibhav on 23-04-2022.
//

#ifndef VULKANLEARN_VALIDATION_HPP
#define VULKANLEARN_VALIDATION_HPP

#include <vector>


#ifdef NDEBUG
	const bool enableValidationLayers = false;
#else
	const bool enableValidationLayers = true;
#endif //NDEBUG

namespace validation {
	extern const std::vector<const char*> validationLayers;
}




#endif //VULKANLEARN_VALIDATION_HPP
