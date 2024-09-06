#pragma once

#include "types.h"

namespace JStudio
{
	namespace IO
	{
		constexpr uint32_t STB_MAGIC              = 0x53544200; // STB file identifier. Equivalent to "STB\0".
		constexpr uint16_t STB_BOM                = 0xFEFF;     // Endianness check?
		constexpr uint16_t STB_VERSION            = 0x0003;
		constexpr char STB_WATERMARK[]            = "jstudio";
		constexpr uint32_t FVB_MAGIC              = 0x46564200; // Function values section identifier. Equivalent to "FVB\0".

		constexpr uint16_t FUNCVAL_COMPOSITE      = 0x0001;
		constexpr uint16_t FUNCVAL_CONSTANT       = 0x0002;
		constexpr uint16_t FUNCVAL_TRANSITION     = 0x0003;
		constexpr uint16_t FUNCVAL_LIST           = 0x0004;
		constexpr uint16_t FUNCVAL_LIST_PARAMETER = 0x0005;
		constexpr uint16_t FUNCVAL_HERMITE        = 0x0006;

		constexpr uint32_t FOURCC_FUNCVALUES      = 0x4A465642; // Identifier for function values section. Equivalent to "JFVB".
		constexpr uint32_t FOURCC_CAMERA          = 0x4A434D52; // Identifier for camera object. Equivalent to "JCMR".
		constexpr uint32_t FOURCC_SOUND           = 0x4A534E44; // Identifier for sound objects. Equivalent to "JSND".
		constexpr uint32_t FOURCC_ACTOR           = 0x4A414354; // Identifier for actor objects. Equivalent to "JACT".
		constexpr uint32_t FOURCC_MESSAGE         = 0x4A4D5347; // Identifier for message object. Equivalent to "JMSG".
		constexpr uint32_t FOURCC_PARTICLE        = 0x4A505443; // Identifier for particle objects. Equivalent to "JPTC".
		constexpr uint32_t FOURCC_CONTROL         = 0xFFFFFFFF; // Identifier for control section.
	} // namespace IO
} // namespace JStudio
