#pragma once

#ifdef FH_PLATFORM_WINDOWS

extern Fangh::Application* Fangh::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Fangh::CreateApplication();
	app->Run();
	delete app;
}

#endif // FH_PLATFORM_WINDOWS
