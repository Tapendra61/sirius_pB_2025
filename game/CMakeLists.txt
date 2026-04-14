set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(siriusgame
	src/Main.cpp
	src/Player.cpp
	src/SceneManager.cpp
	src/Settings.cpp
	src/AppManager.cpp
)

target_include_directories(siriusgame PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(siriusgame PRIVATE siriuscore)