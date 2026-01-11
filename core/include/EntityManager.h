#include "Entity.h"
#include <cstdint>
#include <memory>
#include <type_traits>
#include <vector>

namespace sr {
	class EntityManager {
	  private:
		std::vector<std::unique_ptr<Entity>> entities_;
		uint16_t next_entity_id = 1;

	  public:
		template <typename T>
		T* CreateEntity() {
			static_assert(std::is_base_of_v<Entity, T>, "Type T must inherit from base class of Entity!");

			auto entity = std::make_unique<T>();
			entity->SetEntityId(GenerateEntityId());

			T* entity_ptr = entity.get();
			entities_.push_back(std::move(entity));

			return entity_ptr;
		}
		
		
		
	  private:
		uint64_t GenerateEntityId();
	};
} // namespace sr