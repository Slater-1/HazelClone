#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Hazel/Window.h"

namespace Hazel {

	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in a CLIENT
	Application* CreateApplication();

}
