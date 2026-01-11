#pragma once
#include <memory>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include "Component.h"

namespace sr {
	class Entity {
	  private:
		std::unordered_map<std::type_index, std::unique_ptr<Component>> components;

	  public:
		Entity();

		template <typename T>
		void AddComponent() {
			static_assert(std::is_base_of<Component, T>::value, "Type T must inherit from base class of Component!");

			std::type_index typeIndex(typeid(T));

			if (components.find(typeIndex) == components.end()) {
				components[typeIndex] = std::make_unique<T>();
			}
		}

		template <typename T>
		T* GetComponent() const {
			static_assert(std::is_base_of_v<Component, T>, "Type T must inherit from base class of Component!");

			std::type_index typeIndex(typeid(T));
			auto iter = components.find(typeIndex);
			if (iter != components.end()) {
				return static_cast<T*>(iter->second.get());
			}

			return nullptr;
		}

		template <typename T>
		bool RemoveComponent() {
			static_assert(std::is_base_of_v<Component, T>, "Type T must inherit from base class of Component!");
			return components.erase(std::type_index(typeid(T))) > 0;
		}

		template <typename T>
		bool HasComponent() const {
			static_assert(std::is_base_of_v<Component, T>, "Type T must inherit from base class of Component!");
			return components.find(std::type_index(typeid(T))) != components.end();
		}
	};
} // namespace sr