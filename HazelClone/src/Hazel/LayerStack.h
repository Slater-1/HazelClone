#pragma once

#include "Hazel/Core.h"
#include "Layer.h"

#include <vector>

namespace Hazel {

	class HAZEL_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		// stores layers and overlays
		// layers are stored on left side of vector
		// overlays are stored on right side of vector
		// Ex: { L, L, L, O, O }
		std::vector<Layer*> m_Layers;

		// tracks the boundary between layers and overlays
		// in the above example, this iterator would point to the 3rd layer
		std::vector<Layer*>::iterator m_LayerInsert;
	};

}

