
add_subdirectory(Color)
add_subdirectory(GameObjects)
add_subdirectory(GameState)
add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} 
PRIVATE vendor
PUBLIC color
PUBLIC gameObjects
PUBLIC gameState)

