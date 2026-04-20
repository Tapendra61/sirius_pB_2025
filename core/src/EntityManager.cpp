#include "EntityManager.h"
#include <algorithm>
#include <cstdint>
#include <memory>
#include <unordered_set>

namespace sr {
	void EntityManager::FlushPendingStarts() {
		std::vector<Entity*> batch;
		batch.swap(pending_start_);
		for (Entity* e : batch)
			e->Start();
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
		if (!GetEntity(entity_id))
			return false;

		pending_destroy_.push_back(entity_id);
		return true;
	}

	bool EntityManager::RemoveEntity(Entity* entity) {
		return entity && RemoveEntity(entity->GetEntityId());
	}

	Entity* EntityManager::GetEntity(const uint64_t entity_id) {
		for (const auto& entity : entities_) {
			if (entity->GetEntityId() == entity_id) {
				return entity.get();
			}
		}

		return nullptr;
	}

	void EntityManager::FlushPendingDestroys() {
		if (pending_destroy_.empty())
			return;

		std::sort(pending_destroy_.begin(), pending_destroy_.end());
		pending_destroy_.erase(std::unique(pending_destroy_.begin(), pending_destroy_.end()), pending_destroy_.end());

		std::unordered_set<uint64_t> to_destroy(pending_destroy_.begin(), pending_destroy_.end());

		// Scrub from pending_start_ first - don't start Start() an entity that's about to be destroyed immediately
		pending_start_.erase(std::remove_if(pending_start_.begin(), pending_start_.end(),
											[&](Entity* e) { return to_destroy.count(e->GetEntityId()) > 0; }),
							 pending_start_.end());

		entities_.erase(
			std::remove_if(entities_.begin(), entities_.end(),
						   [&](const std::unique_ptr<Entity>& e) { return to_destroy.count(e->GetEntityId()) > 0; }),
			entities_.end());

		pending_destroy_.clear();
	}

	bool EntityManager::Clear() {
		entities_.clear();
		pending_start_.clear();
		pending_destroy_.clear();
		return entities_.empty();
	}

	uint64_t EntityManager::GenerateEntityId() {
		return next_entity_id++;
	}
} // namespace sr