file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ./*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE vendor)






#file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
#target_include_directories((${PROJECT_NAME} PRIVATE src)
#add_executable(${PROJECT_NAME} ${SOURCES})
#target_sources(${PROJECT_NAME} PRIVATE main.cpp)
#target_link_libraries(${PROJECT_NAME} PRIVATE vendor)


#add_executable(Test)
#target_sources(Test PRIVATE main.cpp)