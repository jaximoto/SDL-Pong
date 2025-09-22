
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS *.cpp *.hpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE src ../include)

target_link_libraries(${PROJECT_NAME} 
PRIVATE SDL3::SDL3)


