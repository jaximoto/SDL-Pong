
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp)
target_link_libraries(Test PRIVATE vendor)

#add_executable(Test)
#target_sources(Test PRIVATE main.cpp)