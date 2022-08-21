#pragma once

#include "Event.h"

namespace Hazel
{
	class HAZEL_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return KeyCode; }

		EVENT_CLASS_CATEGORY(EC_Keyboard | EC_Input)

	protected:
		KeyEvent(int keyCode) : KeyCode(keyCode) {}

	protected:
		int KeyCode;
	};

	class HAZEL_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount) :
			KeyEvent(keyCode), RepeatCount(0) {}

		inline int GetRepeatCount() const { return RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "KeyPressedEvent: " << KeyCode << " (" << RepeatCount << " repeats)";
			return stream.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int RepeatCount;
	};

	class HAZEL_API KeyReleasedEVent : public KeyEvent
	{
	public:
		KeyReleasedEVent(int keyCode) : KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "KeyReleasedEvent: " << KeyCode;
			return stream.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}