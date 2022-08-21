#pragma once

#include "Core.h"
#include "Window.h"

namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_bRunning = true;
	};

	// To be defined in client
	Application* CreateApplication();
}
