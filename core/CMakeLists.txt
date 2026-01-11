set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(siriuscore STATIC
	src/Animation.cpp
	src/AssetLoader.cpp
	src/Transform2D.cpp
	src/Engine.cpp
	src/CustomCamera.cpp
	src/Entity.cpp
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