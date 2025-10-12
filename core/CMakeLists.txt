add_library(siriuscore STATIC
	src/Animation.cpp
	src/AssetLoader.cpp
	src/Transform.cpp
)

target_include_directories(siriuscore PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}
)