#pragma once

#include "Entity.h"
#include <cstdint>
#include <memory>
#include <type_traits>
#include <vector>

namespace sr {
	class EntityManager {
	  private:
		std::vector<std::unique_ptr<Entity>> entities_;
		std::vector<Entity*> pentding_start_;
		uint64_t next_entity_id = 1;

	  public:
		/// Adds a new Entity of type T to the EntityManager.
		template <typename T>
		T* CreateEntity() {
			static_assert(std::is_base_of_v<Entity, T>, "Type T must inherit from base class of Entity to be created!");

			auto entity = std::make_unique<T>();
			entity->SetEntityId(GenerateEntityId());

			T* entity_ptr = entity.get();
			entities_.push_back(std::move(entity));

			pending_start_.push_back(entity_ptr);

			return entity_ptr;
		}

		/// Calls Start on all Entities whose Start call is pending
		void FlushPendingStarts();

		/// Calls Update on all Entities whose Start is not pending
		void UpdateAll(float dt);

		/// Calls LateUpdate on all Entities whose Start is not pending
		void LateUpdateAll(float dt);

		/// Removes the specified Entity from the global EntityManager by it's id.
		/// Returns true if successful.
		bool RemoveEntity(uint64_t entity_id);

		/// Removes the specified Entity from the global EntityManager by it's pointer
		/// Returns true if successful.
		bool RemoveEntity(Entity* entity);

		/// Returns the pointer to specified Entity by it's id
		Entity* GetEntity(const uint64_t entity_id);

		/// Clear the entities list
		bool Clear();

	  private:
		/// Generates a unique ID for a newly created Entity.
		uint64_t GenerateEntityId();
	};
} // namespace sr
