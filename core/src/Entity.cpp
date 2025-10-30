#include "Entity.h"

namespace Sirius {
	Entity::Entity() {
		AddComponent<Transform2D>();
	}
}