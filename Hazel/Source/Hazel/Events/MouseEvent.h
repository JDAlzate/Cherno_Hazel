#pragma once

#include "Hazel/Events/Event.h"

namespace Hazel
{
	class HAZEL_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) :
			MouseX(x), MouseY(y) {}

		inline float GetX() const { return MouseX; } 
		inline float GetY() const { return MouseY; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseMovedEvent: " << MouseX << ", " << MouseY;
			return stream.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EC_Mouse | EC_Input)
	private:
		float MouseX, MouseY;
	};

	class HAZEL_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) :
			OffsetX(xOffset), OffsetY(yOffset) {}

		inline float GetOffsetX() const { return OffsetX; }
		inline float GetOffsetY() const { return OffsetY; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseScrolledEvent: " << OffsetX << ", " << OffsetY;
			return stream.str();
		}

	private:
		float OffsetX, OffsetY;
	};

	class HAZEL_API MouseButtonEvent : public Event
	{
	public:
		inline int GetButton() const { return Button; }

		EVENT_CLASS_CATEGORY(EC_Mouse | EC_Input)
	protected:
		MouseButtonEvent(int button) : Button(button) {}

		int Button;
	};

	class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseButtonPressedEvent: " << Button;
			return stream.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseButtonReleasedEvent: " << Button;
			return stream.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
