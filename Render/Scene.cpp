/************************************************************************/
/* Scene
/* -----
/* A scene consisting of a camera and a number of game objects
/************************************************************************/
#include "Scene.h"
#include "../Core/Common.h"

#include <glm/glm.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Input.hpp>
#include <SFML/System/Randomizer.hpp>

using namespace sf;


Scene::Scene()
	: camera(nullptr)
	, cameras()
{
	init();
}

Scene::~Scene()
{
	cleanup();
}

void Scene::setup()
{
	// load textures

	// setup meshes

	// create and position cameras
	cameras.push_back(Camera());
	camera = &(cameras.back());
}

void Scene::update( const Clock& clock, const Input& input )
{
	camera->processInput(input, clock);
}

void Scene::render( const Clock& clock )
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(180.f, 1.f, 0.f, 0.f);

	camera->apply();

	glPushMatrix();
//		skybox.render(*camera);
	glPopMatrix();

	glPushMatrix();
//		ground.render();
	glPopMatrix();

	const float s = 5.f;
	for(int x = 0; x < 50; ++x)
	for(int z = 0; z < 50; ++z)
	{
		const float r = Randomizer::Random(0.f, 1.f);
		const float g = Randomizer::Random(0.f, 1.f);
		const float b = Randomizer::Random(0.f, 1.f);
		glColor3f(r, g, b);
		renderTestCube(glm::vec3(s * x, 0.f, s * z));
	}
}

void Scene::init()
{
	Log("Initializing scene...");
}

void Scene::cleanup()
{
	Log("Cleaning up scene...");
}

void Scene::renderTestCube(const glm::vec3& position, const float scale)
{
	glPushMatrix();

	glTranslated(position.x, position.y, position.z);

	const float nl = -0.5f * scale;
	const float pl =  0.5f * scale;

	glBegin(GL_QUADS);

	glNormal3d( 0,0,1);
	glVertex3d(pl,pl,pl);
	glVertex3d(nl,pl,pl);
	glVertex3d(nl,nl,pl);
	glVertex3d(pl,nl,pl);

	glNormal3d( 0, 0, -1);
	glVertex3d(pl,pl, nl);
	glVertex3d(pl,nl, nl);
	glVertex3d(nl,nl, nl);
	glVertex3d(nl,pl, nl);

	glNormal3d( 0, 1, 0);
	glVertex3d(pl,pl,pl);
	glVertex3d(pl,pl,nl);
	glVertex3d(nl,pl,nl);
	glVertex3d(nl,pl,pl);

	glNormal3d( 0,-1,0);
	glVertex3d(pl,nl,pl);
	glVertex3d(nl,nl,pl);
	glVertex3d(nl,nl,nl);
	glVertex3d(pl,nl,nl);

	glNormal3d( 1,0,0);
	glVertex3d(pl,pl,pl);
	glVertex3d(pl,nl,pl);
	glVertex3d(pl,nl,nl);
	glVertex3d(pl,pl,nl);

	glNormal3d(-1,0,0);
	glVertex3d(nl,pl,pl);
	glVertex3d(nl,pl,nl);
	glVertex3d(nl,nl,nl);
	glVertex3d(nl,nl,pl);

	glEnd();

	glPopMatrix(); 
}