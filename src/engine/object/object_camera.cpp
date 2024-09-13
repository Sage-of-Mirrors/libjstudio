#include "engine/object/object_camera.hpp"

#include <iostream>

constexpr int VAR_EYE_X = 0;
constexpr int VAR_EYE_Y = 1;
constexpr int VAR_EYE_Z = 2;
constexpr int VAR_TARGET_X = 3;
constexpr int VAR_TARGET_Y = 4;
constexpr int VAR_TARGET_Z = 5;
constexpr int VAR_0026 = 6;
constexpr int VAR_FOVY = 7;
constexpr int VAR_NEAR_PLANE = 8;
constexpr int VAR_FAR_PLANE = 9;

void JStudio::Engine::TObjectCamera::Update()
{
	float eyePos[3] { mVariables[0].GetValue(), mVariables[1].GetValue(), mVariables[2].GetValue() };
	float targetPos[3] { mVariables[3].GetValue(), mVariables[4].GetValue(), mVariables[5].GetValue() };

	mDebugStream << "v " << eyePos[0] << " " << eyePos[1] << " " << eyePos[2] << std::endl;
	mDebugStream << "v " << targetPos[0] << " " << targetPos[1] << " " << targetPos[2] << std::endl;
} // TObjectCamera::Update

glm::vec3 JStudio::Engine::TObjectCamera::GetEyePosition()
{
	return { mVariables[VAR_EYE_X].GetValue(), mVariables[VAR_EYE_Y].GetValue() , mVariables[VAR_EYE_Z].GetValue() };
} // TObjectCamera::GetEyePosition

glm::vec3 JStudio::Engine::TObjectCamera::GetTargetPosition()
{
	return { mVariables[VAR_TARGET_X].GetValue(), mVariables[VAR_TARGET_Y].GetValue(), mVariables[VAR_TARGET_Z].GetValue() };
} // TObjectCamera::GetTargetPosition

float JStudio::Engine::TObjectCamera::GetFovY()
{
	return mVariables[VAR_FOVY].GetValue();
} // TObjectCamera::GetFovY

float JStudio::Engine::TObjectCamera::GetNearPlane()
{
	return mVariables[VAR_NEAR_PLANE].GetValue();
} // TObjectCamera::GetNearPlane

float JStudio::Engine::TObjectCamera::GetFarPlane()
{
	return mVariables[VAR_FAR_PLANE].GetValue();
} // TObjectCamera::GetFarPlane
