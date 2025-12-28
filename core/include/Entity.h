#pragma once
#include<memory>
#include<type_traits>
#include<typeindex>
#include<unordered_map>

#include"Core.h"

namespace Sirius {
	class Entity {
	  private:
		std::unordered_map<std::type_index, std::unique_ptr<Component>> components;

	  public:
		Entity();

		template<typename T>
		void AddComponent() {
			static_assert(std::is_base_of<Component, T>::value, "Type T must inherit from base class of Component!");
			
			std::type_index type_idx(typeid(T));
			
			if(components.find(type_idx) == components.end()) {
				components[type_idx] = std::make_unique<T>();
			}
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