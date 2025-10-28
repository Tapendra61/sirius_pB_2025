#pragma once
#include "Component.h"
#include "Transform.h"
#include <vector>

namespace Sirius {
	class Entity {
	  private:
		std::vector<Component> components;

	  public:
		Entity();

		void AddComponent(Component component);
		Component& GetComponent();
	};
} // namespace Sirius