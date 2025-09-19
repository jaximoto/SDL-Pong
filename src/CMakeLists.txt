
add_subdirectory(Color)
add_subdirectory(GameObjects)
add_subdirectory(GameState)
add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} 
PRIVATE vendor
PUBLIC Color
PUBLIC GameObjects
PUBLIC GameState)






#file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
#target_include_directories((${PROJECT_NAME} PRIVATE src)
#add_executable(${PROJECT_NAME} ${SOURCES})
#target_sources(${PROJECT_NAME} PRIVATE main.cpp)
#target_link_libraries(${PROJECT_NAME} PRIVATE vendor)


#add_executable(Test)
#target_sources(Test PRIVATE main.cpp)