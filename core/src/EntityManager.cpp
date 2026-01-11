#include "EntityManager.h"
#include <cstdint>

namespace sr {
	uint64_t EntityManager::GenerateEntityId() {
		return next_entity_id++;
	}
} // namespace sr