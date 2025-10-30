#pragma once
#include <vector>
#include<type_traits>

#include"Core.h"

namespace Sirius {
	class Entity {
	  private:
		std::vector<Component> components;

	  public:
		Entity();

		template<typename T>
		void AddComponent();
		Component& GetComponent();
	};
} // namespace Sirius