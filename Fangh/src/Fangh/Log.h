#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

// Core Log Macros
#define FH_CORE_ERROR(...) ::Fangh::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FH_CORE_WARN(...) ::Fangh::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FH_CORE_INFO(...) ::Fangh::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FH_CORE_TRACE(...) ::Fangh::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FH_CORE_FATAL(...) ::Fangh::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define FH_ERROR(...) ::Fangh::Log::GetClientLogger()->error(__VA_ARGS__)
#define FH_WARN(...) ::Fangh::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FH_INFO(...) ::Fangh::Log::GetClientLogger()->info(__VA_ARGS__)
#define FH_TRACE(...) ::Fangh::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FH_FATAL(...) ::Fangh::Log::GetClientLogger()->fatal(__VA_ARGS__)

namespace Fangh
{
	class FANGH_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};
}