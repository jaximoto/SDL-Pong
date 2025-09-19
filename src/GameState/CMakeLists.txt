add_library(gameState
	GameState.cpp
	GameState.hpp
)

target_include_directories(gameState PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
