#include "engine/object/object_control.hpp"

#include <iostream>

constexpr int VAR_MESSAGE_HALT = 0x00;

void JStudio::Engine::TObjectControl::Update()
{
	std::cout << "Control state: " << (mVariables[VAR_MESSAGE_HALT].GetValue() != 0.0f) << std::endl;
} // TObjectControl::Update

bool JStudio::Engine::TObjectControl::GetMessageHalt()
{
	return mVariables[VAR_MESSAGE_HALT].GetValue() != 0.0f;
} // TObjectControl::GetMessageHalt

void JStudio::Engine::TObjectControl::ClearMessageHalt()
{
	mVariables[VAR_MESSAGE_HALT].SetImmediateUpdate(0.0f);
} // TObjectControl::ClearMessageHalt
