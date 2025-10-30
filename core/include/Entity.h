#pragma once
#include <vector>
#include<memory>
#include<type_traits>

#include"Core.h"

namespace Sirius {
	class Entity {
	  private:
		std::vector<std::unique_ptr<Component>> components;

	  public:
		Entity();

		template<typename T>
		void AddComponent() noexcept {
			static_assert(std::is_base_of<Component, T>::value, "Type T must inherit from base class of Component!");
			components.push_back(std::make_unique<T>());
		}
		template<typename T>
		T* GetComponent() {
			static_assert(std::is_base_of<Component, T>::value, "Type T must inherit from base class of Component!");

			for(auto& component : components) {
				if(auto ptr = dynamic_cast<T*>(component.get())) {
					return ptr;
				}
			}

			return nullptr;
		}
	};
} // namespace Sirius