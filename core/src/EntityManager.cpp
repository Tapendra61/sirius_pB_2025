#include "EntityManager.h"
#include <algorithm>
#include <cstdint>

namespace sr {
	void EntityManager::FlushPendingStarts() {
		size_t length = pentding_start_.size();
		for (size_t i = 0; i < length; i++) {
			pentding_start_[i]->Start();
		}

		pentding_start_.clear();
	}

	void EntityManager::UpdateAll(float dt) {
		for (auto& entity : entities_) {
			entity->Update(dt);
		}
	}

	void EntityManager::LateUpdateAll(float dt) {
		for (auto& entity : entities_) {
			entity->LateUpdate(dt);
		}
	}

	bool EntityManager::RemoveEntity(uint64_t entity_id) {
		auto it = std::remove_if(entities_.begin(), entities_.end(), [entity_id](const std::unique_ptr<Entity>& e) {
			return e->GetEntityId() == entity_id;
		});

		if (it != entities_.end()) {
			entities_.erase(it, entities_.end());
			return true;
		}
		return false;
	}

	bool EntityManager::RemoveEntity(Entity* entity) {
		return RemoveEntity(entity->GetEntityId());
	}

	Entity* EntityManager::GetEntity(const uint64_t entity_id) {
		for (const auto& entity : entities_) {
			if (entity->GetEntityId() == entity_id) {
				return entity.get();
			}
		}

		return nullptr;
	}

	bool EntityManager::Clear() {
		entities_.clear();
		return entities_.empty();
	}

	uint64_t EntityManager::GenerateEntityId() {
		return next_entity_id++;
	}
} // namespace sr