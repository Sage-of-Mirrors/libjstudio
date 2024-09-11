#include "engine/object/object_camera.hpp"

#include <iostream>

void JStudio::Engine::TObjectCamera::Update()
{
	float eyePos[3] { mVariables[0].GetValue(), mVariables[1].GetValue(), mVariables[2].GetValue() };
	float targetPos[3] { mVariables[3].GetValue(), mVariables[4].GetValue(), mVariables[5].GetValue() };

	mDebugStream << "v " << eyePos[0] << " " << eyePos[1] << " " << eyePos[2] << std::endl;
	mDebugStream << "v " << targetPos[0] << " " << targetPos[1] << " " << targetPos[2] << std::endl;
}
