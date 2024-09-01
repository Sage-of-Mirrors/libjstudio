#include "engine/object/object_camera.hpp"

#include <iostream>

void JStudio::Engine::TObjectCamera::Update()
{
	float eyePos[3] { mVariables[0].GetValue(), mVariables[1].GetValue(), mVariables[2].GetValue() };
	std::cout << "TObjectCamera::Update(): EyePos at (" << eyePos[0] << ", " << eyePos[1] << ", " << eyePos[2] << ")" << std::endl;
}
