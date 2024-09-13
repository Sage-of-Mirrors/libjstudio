#pragma once

#include "types.h"
#include "object.hpp"

#include "engine/value/variablevalue.hpp"

#include <glm/glm.hpp>

#include <string>
#include <sstream>
#include <fstream>

namespace JStudio
{
	namespace Engine
	{
		class TObjectCamera : public TObject
		{
			static const uint32_t NUM_CAMERA_VARIABLES = 10;

			TVariableValue mVariables[NUM_CAMERA_VARIABLES];

			std::stringstream mDebugStream;

		public:
			TObjectCamera()
			{
				mNumVariables = NUM_CAMERA_VARIABLES;
				mVariablesHead = mVariables;

				mType = EObjectType::CAMERA;
			}

			virtual ~TObjectCamera() { }

			void Update() override;

			glm::vec3 GetEyePosition();
			glm::vec3 GetTargetPosition();
			float GetFovY();
			float GetNearPlane();
			float GetFarPlane();

			void WriteDebugStream()
			{
				std::ofstream stream;
				stream.open("C:\\Hacking\\jabtest.obj");

				std::string s = mDebugStream.str();
				stream << s;

				stream.flush();
				stream.close();
			}
		};
	} // namespace Engine
} // namespace JStudio
