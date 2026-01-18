#include "EntityManager.h"
#include <cstdint>

namespace sr {

	bool EntityManager::RemoveEntity(uint64_t entity_id) {
		auto it = std::remove_if(entities_.begin(), entities_.end(),
								 [entity_id](const std::unique_ptr<Entity>& e) { return e->GetEntityId() == entity_id; });

		if(it != entities_.end()) {
			entities_.erase(it, entities_.end());
			return true;
		}
		return false;
	}

	bool EntityManager::RemoveEntity(Entity* entity) {
		return RemoveEntity(entity->GetEntityId());
	}
	
	Entity* EntityManager::GetEntity(const uint64_t entity_id) {
		for(const auto& entity : entities_) {
			if(entity->GetEntityId() == entity_id) {
				return entity.get();
			}
		}
		
		return nullptr;
	}

	uint64_t EntityManager::GenerateEntityId() {
		return next_entity_id++;
	}
} // namespace sr