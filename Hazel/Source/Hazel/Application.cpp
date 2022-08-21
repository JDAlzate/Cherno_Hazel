#include "hzpch.h"
#include "Application.h"

#include "Log.h"
#include "Events/AppEvent.h"

namespace Hazel
{
	void Application::Run()
	{
		const WindowResizeEvent event(30, 30);
		HZ_TRACE(event);

		while (true);
	}
}