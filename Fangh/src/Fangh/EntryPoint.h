#pragma once

#ifdef FH_PLATFORM_WINDOWS

extern Fangh::Application* Fangh::CreateApplication();

int main(int argc, char** argv)
{
	Fangh::Log::Init();
	FH_CORE_WARN("Initialized Log");
	FH_INFO("Fangh Engine Initialized");

	auto app = Fangh::CreateApplication();
	app->Run();

	delete app;

	return 0;
}

#endif // FH_PLATFORM_WINDOWS
