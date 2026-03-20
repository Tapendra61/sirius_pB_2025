#include "Entity.h"
#include "Transform2D.h"

namespace sr {
	Entity::Entity() {
		AddComponent<Transform2D>();
	}
} // namespace sr