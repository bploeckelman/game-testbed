#pragma once
/************************************************************************/                                                                  
/* MainWindow
/* ----------
/* The main sfml window for an application
/************************************************************************/
//#include "SceneManager.h"

#include <SFML/Window.hpp>
//#include <SFML/Graphics/Sprite.hpp>

#include <string>


class MainWindow : public sf::Window
{
public:
	MainWindow();
	~MainWindow();

private:
	static const std::string		title;
	static const sf::VideoMode		videoMode;
	static const unsigned int		windowStyle;
	static const sf::WindowSettings	windowSettings;

//	SceneManager sceneManager;
	sf::Clock timer;

	void init();
	void cleanup();
	void mainLoop();
	void update(const sf::Clock& clock);
	void render(const sf::Clock& clock);

	void setupOpenGLState();
	void setupPerspective();

	void handleEvents();

	void renderTestCube();
};
