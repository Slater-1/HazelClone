#include "hzpch.h"
#include "Application.h"

#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"

#include <GLFW/glfw3.h>

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

		Application::Application()
		{
			m_Window = std::unique_ptr<Window>(Window::Create());
			m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
		}

		Application::~Application()
		{
		}

		void Application::OnEvent(Event& e)
		{
			HZ_CORE_INFO("{0}", e);
		}

		void Application::Run()
		{
			while (m_Running)
			{
				m_Window->OnUpdate();
				glClearColor(1, 0, 1, 1);
				glClear(GL_COLOR_BUFFER_BIT);
			}
		}

}