#pragma once
#include "Component.h"
#include <cstdint>
#include <memory>
#include <type_traits>
#include <typeindex>
#include <unordered_map>

namespace sr {
	class Entity {
	  private:
		uint64_t entity_id_ = 0;
		std::unordered_map<std::type_index, std::unique_ptr<Component>> components;

	  public:
		Entity();
		virtual ~Entity() = default;

		virtual void Start() {}
		virtual void Update(float deltaTime) {}
		virtual void LateUpdate(float deltaTime) {}

		uint64_t GetEntityId() const {
			return entity_id_;
		}

		void SetEntityId(uint64_t value) {
			entity_id_ = value;
		}

		template <typename T>
		void AddComponent() {
			static_assert(std::is_base_of<Component, T>::value, "Type T must inherit from base class of Component!");

			std::type_index typeIndex(typeid(T));

			if (components.find(typeIndex) == components.end()) {
				components[typeIndex] = std::make_unique<T>();
			}
		}

		template <typename T>
		const T* GetComponent() const  {
			static_assert(std::is_base_of_v<Component, T>, "Type T must inherit from base class of Component!");

			std::type_index typeIndex(typeid(T));
			auto iter = components.find(typeIndex);
			if (iter != components.end()) {
				return static_cast<const T*>(iter->second.get());
			}

			return nullptr;
		}
		
		template<typename T>
		T* GetComponent() {
			return const_cast<T*>(
				static_cast<const Entity*>(this)->GetComponent<T>()
			);
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