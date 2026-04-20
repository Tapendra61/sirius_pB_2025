#pragma once

#include <memory>
#include <string>

#include "EntityManager.h"

namespace sr {
	class Scene {
	  private:
		std::string scene_name_;
		std::unique_ptr<EntityManager> entity_manager_;

	  public:
		Scene(const std::string scene_name);
		std::string GetSceneName() const {
			return scene_name_;
		}

		void FlushPendingStarts();
		void UpdateAll(float dt);
		void LateUpdateAll(float dt);
	};
} // namespace sr