#pragma once

#include "Event.h"

namespace Hazel
{
	class HAZEL_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) :
			Width(width), Height(height) {}

		unsigned int GetWidth() const { return Width; }
		unsigned int GetHeight() const { return Height; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "WindowResizeEvent: " << Width << ", " << Height;
			return stream.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EC_Application)

	private:
		unsigned int Width, Height;
	};

	class HAZEL_API WindowCloseEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EC_Application)
	};

	class HAZEL_API AppTickEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EC_Application)
	};

	class HAZEL_API AppUpdateEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EC_Application)
	};

	class HAZEL_API AppRenderEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EC_Application)
	};
}