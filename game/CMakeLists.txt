add_executable(siriusgame
	src/Main.cpp
	src/Player.cpp
	src/SceneManager.cpp
	src/Settings.cpp
	src/AppManager.cpp
)

target_include_directories(siriusgame PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_SOURCE_DIR}/dependencies/include
)

target_link_libraries(siriusgame PRIVATE siriuscore)