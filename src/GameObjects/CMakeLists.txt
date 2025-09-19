add_library(gameObjects
	DrawableGameObject.cpp
	DrawableGameObject.hpp
	UDGameObject.cpp
	UDGameObject.hpp
	UpdateableGameObject.cpp
	UpdateableGameObject.hpp
	GameObject.cpp
	GameObject.hpp
	Drawable.hpp
	Updateable.hpp
)

target_include_directories(gameObjects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
