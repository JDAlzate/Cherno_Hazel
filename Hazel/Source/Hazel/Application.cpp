#include "hzpch.h"
#include "Application.h"
#include "Events/AppEvent.h"

namespace Hazel
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	void Application::Run()
	{
		while (m_bRunning)
		{
			m_Window->OnUpdate();
		}
	}
}