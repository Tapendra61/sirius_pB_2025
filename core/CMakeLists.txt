add_library(siriuscore STATIC
	src/Animation.cpp
	src/AssetLoader.cpp
	src/Transform.cpp
)

target_include_directories(siriuscore PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_SOURCE_DIR}/dependencies/include
)

target_link_directories(siriuscore PUBLIC
	${CMAKE_SOURCE_DIR}/dependencies/libs
)

target_link_libraries(siriuscore PUBLIC
	raylib
	winmm
	opengl32
	gdi32
)