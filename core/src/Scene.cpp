#include "Scene.h"

namespace sr {
	Scene::Scene(const std::string scene_name) : scene_name_(scene_name) {}

	void Scene::FlushPendingStarts() {
		entity_manager_->FlushPendingStarts();
	}

	void Scene::UpdateAll(float dt) {
		entity_manager_->UpdateAll(dt);
	}

	void Scene::LateUpdateAll(float dt) {
		entity_manager_->LateUpdateAll(dt);
	}
} // namespace sr