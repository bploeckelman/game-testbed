/************************************************************************/
/* MainWindow
/* ----------
/* The main sfml window for an application
/************************************************************************/
#include "MainWindow.h"
//#include "SceneManager.h"
#include "Logger.h"

#include <SFML/Graphics.hpp>

const float PI = 3.14159265358979323846f;

// Application window settings, video mode, window style
const std::string MainWindow::title("Game Testbed");

const unsigned int width  = 1280;
const unsigned int height = 1024;
const unsigned int bpp    = 32;
const sf::VideoMode MainWindow::videoMode(width, height, bpp);

const unsigned int depth		= 24;
const unsigned int stencil		= 0;
const unsigned int antialiasing = 2;
const sf::WindowSettings MainWindow::windowSettings(depth, stencil, antialiasing);
const unsigned int MainWindow::windowStyle = sf::Style::Close | sf::Style::Resize;


MainWindow::MainWindow()
	: sf::Window(videoMode, title, windowStyle, windowSettings),
//	sceneManager(),
	timer()
{
	init();
}

MainWindow::~MainWindow()
{
	cleanup();
}

void MainWindow::init()
{
	Log("Window initializing...");
	setupOpenGLState();
	setupPerspective();

//	sceneManager.setup();

	mainLoop();
}

void MainWindow::cleanup()
{
	Log("Window cleaning up...");
}

void MainWindow::mainLoop()
{
	Log("Entering main loop...");
	sf::Clock clock;
	timer.Reset();
	while( IsOpened() )
	{
		update(clock);
		render(clock);
		clock.Reset();
	}
}

void MainWindow::update(const sf::Clock& clock)
{
	handleEvents();

//	sceneManager.update(clock, GetInput());
}

void MainWindow::render(const sf::Clock& clock)
{
	SetActive();

//	sceneManager.render(clock);

	Display();
}

void MainWindow::setupOpenGLState()
{
	SetFramerateLimit(60);

	glDisable(GL_LIGHTING);

	glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_POINTS);
	glEnable(GL_POINT_SMOOTH);

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glClearDepth(1.f);

	glClearColor(0.1f, 0.1f, 0.1f, 1.f);
}

void MainWindow::setupPerspective()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	const float aspect = static_cast<float>(GetWidth() / GetHeight());
	const float fov    = 70.f;
	const float _near  = 1.f;
	const float _far   = 100000.f;
	const float side   = tan((fov * (PI / 180.f)) / 2.f) * _near;

	glFrustum(-side, side, -side / aspect, side / aspect, _near, _far);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void MainWindow::handleEvents()
{
	sf::Event ev;
	while( GetEvent(ev) )
	{
		// Close the window
		if( ev.Type == sf::Event::Closed
		|| (ev.Type == sf::Event::KeyPressed && ev.Key.Code == sf::Key::Escape) )
		{
			Close();
		}

		// Toggle rendering states
/*
		if( ev.Type == sf::Event::KeyPressed )
		{
			if( ev.Key.Code == sf::Key::Num1 )
				sceneManager.toggleRenderState(SceneManager::textures);
			if( ev.Key.Code == sf::Key::Num2 )
				sceneManager.toggleRenderState(SceneManager::wireframe);
			if( ev.Key.Code == sf::Key::Num3 )
				sceneManager.toggleRenderState(SceneManager::points);
		}
*/
	}
}
