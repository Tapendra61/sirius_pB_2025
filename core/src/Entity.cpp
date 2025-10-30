#include "Entity.h"

namespace Sirius {
	Entity::Entity() {
		AddComponent<Transform2D>();
	}

	template<typename T>
	void Entity::AddComponent() noexcept {
		static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component base class.");

		T componentInstance;
		components.push_back(componentInstance);
	}
}