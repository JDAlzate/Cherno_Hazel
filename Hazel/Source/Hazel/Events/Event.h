#pragma once

#include <functional>
#include "Hazel/Core.h"
#include <string>

namespace Hazel
{
	enum class EventType
	{
		None = 0,
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,
		AppTick,
		AppUpdate,
		AppRender,
		KeyPressed,
		KeyReleased,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EC_Application	= 1 << 0,
		EC_Input		= 1 << 1,
		EC_Keyboard		= 1 << 2,
		EC_Mouse		= 1 << 3,
		EC_MouseButton	= 1 << 4
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HAZEL_API Event
	{
		friend class EventDispatcher;
	public:
		Event() : m_bHandled(false) {}
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(const EventCategory category) const { return GetCategoryFlags() & category; }

	protected:
		bool m_bHandled;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		explicit EventDispatcher(Event& event) : m_Event(event) {}
		
		template<typename T>
		bool Dispatch(EventFn<T> function)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_bHandled = function(*static_cast<T*>(&m_Event));
				return true;
			}
			
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator << (std::ostream& os, const Event& event)
	{
		return os << event.ToString();
	}
}