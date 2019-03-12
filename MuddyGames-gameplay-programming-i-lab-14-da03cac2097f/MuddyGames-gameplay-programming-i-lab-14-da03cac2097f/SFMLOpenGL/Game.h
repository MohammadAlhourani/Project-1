#ifndef GAME_H
#define GAME_H

#include <string>
#include <sstream>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <Debug.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <GameObject.h>

using namespace std;
using namespace sf;
using namespace glm;

const int m_maxCube{ 2 };

class Game
{
public:
	Game();
	Game(sf::ContextSettings settings);
	~Game();
	void run();
private:
	
	int m_player{ 0 };

	GameObject* game_object[m_maxCube];
	RenderWindow window;
	Clock clock;
	Time time;
	bool animate = false;
	bool allowJump = false;
	vec3 animation = vec3(0.0f);
	float rotation = 0.0f;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	void jump();

	void collision();
};

#endif  // ! GAME_H