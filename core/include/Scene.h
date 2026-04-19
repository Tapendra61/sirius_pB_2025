#pragma once

#include <memory>

#include "EntityManager.h"

namespace sr {
	class Scene {
	  private:
		std::unique_ptr<EntityManager> entity_manager_;

	  public:
		Scene();
		~Scene();
	};
} // namespace sr