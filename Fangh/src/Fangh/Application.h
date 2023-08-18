#pragma once

#include "Core.h"

namespace Fangh
{
	class FANGH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}