#include "Entity.h"
#include <cstdint>
#include <memory>
#include <type_traits>
#include <vector>

namespace sr {
	class EntityManager {
	  private:
		std::vector<std::unique_ptr<Entity>> entities_;
		uint64_t next_entity_id = 1;

	  public:
		/// Adds a new component of type T to the global EntityManager.
		template <typename T>
		T* CreateEntity() {
			static_assert(std::is_base_of_v<Entity, T>, "Type T must inherit from base class of Entity to be created!");

			auto entity = std::make_unique<T>();
			entity->SetEntityId(GenerateEntityId());

			T* entity_ptr = entity.get();
			entities_.push_back(std::move(entity));

			return entity_ptr;
		}
		
		/// Removes the specified Entity from the global EntityManager by it's id.
		/// Returns true if successful.
		bool RemoveEntity (uint64_t entity_id);
		
		/// Removes the specified Entity from the global EntityManager by it's pointer
		/// Returns true if successful.
		bool RemoveEntity (Entity* entity);
		
		Entity* GetEntity(const uint64_t entity_id);

	  private:
		/// Generates a unique ID for a newly created Entity.
		uint64_t GenerateEntityId();
	};
} // namespace sr