#pragma once

#ifdef FH_PLATFORM_WINDOWS
	#ifdef FH_BUILD_DLL
		#define FANGH_API __declspec(dllexport)
	#else
		#define FANGH_API __declspec(dllimport)
	#endif
#else
	#error Fangh Engine Only Supports Windows
#endif