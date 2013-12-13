#include "WinterWonderland.h"
#include "PhysicsController.h"
#include "Sphere.h"
#include "PhysicsCamera.h"
#include "Box.h"
#include "Cylinder.h"
#include "Steerable3DController.h"
#include "SteeringControler.h"
#include "Ground.h"
#include "Content.h"
#include <btBulletDynamicsCommon.h>
#include <gtc/quaternion.hpp>
#include <gtx/quaternion.hpp>
#include <gtx/euler_angles.hpp>
#include <gtx/norm.hpp>
#include "VectorDrawer.h"
#include "Utils.h"
#include "SnowEffect.h"
#include "FountainEffect.h"

using namespace BGE;

WinterWonderland::WinterWonderland(void)
{
	physicsFactory = NULL;
	dynamicsWorld = NULL;
	broadphase = NULL;
	dispatcher = NULL;
	solver = NULL;
	fullscreen = false;
	ySpeed = 5.0f;
}

WinterWonderland::~WinterWonderland(void)
{
}

shared_ptr<PhysicsController> car;

bool WinterWonderland::Initialise() 
{
	// Set up the collision configuration and dispatcher
    collisionConfiguration = new btDefaultCollisionConfiguration();
    dispatcher = new btCollisionDispatcher(collisionConfiguration);

	shared_ptr<SnowEffect> snow = make_shared<SnowEffect>(); // Created the snow effect
	Attach(snow); // Added the snow to the scene
    // The world.
	btVector3 worldMin(-1000,-1000,-1000);
	btVector3 worldMax(1000,1000,1000);
	broadphase = new btAxisSweep3(worldMin,worldMax);
	solver = new btSequentialImpulseConstraintSolver();
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
    dynamicsWorld->setGravity(btVector3(0,-20,0));

	physicsFactory = make_shared<PhysicsFactory>(dynamicsWorld);

	physicsFactory->CreateGroundPhysics();
	physicsFactory->CreateCameraPhysics();

	//Particle Effect around Snowman
	SnowmanFountain0 = make_shared<FountainEffect>(500);
	SnowmanFountain0->position = glm::vec3(-30, 0, 0);
	SnowmanFountain0->diffuse = glm::vec3(1,1, 0);
	Attach(SnowmanFountain0);
	//Particle Effect around Snowman
	SnowmanFountain1 = make_shared<FountainEffect>(500);
	SnowmanFountain1->position = glm::vec3(-30, 50, 0);
	SnowmanFountain1->diffuse = glm::vec3(1,1, 0);
	Attach(SnowmanFountain1);

	//************************************************************************************************************************************
	// Creating the small building and the ramp that will hold the sphere that will roll down the ramp
	// Then the domino and seesaw are created
	//************************************************************************************************************************************
	//Creating Ramp
	physicsFactory->CreateSecondWall(glm::vec3(-180,0,250), 5,4,5,5,10); // The left wall created
	physicsFactory->CreateSecondWall(glm::vec3(-160,0,250), 5,4,5,5,10); // The right wall created
	physicsFactory->CreateRoof(glm::vec3(-170,0,265), 1, 1,30,2,50); // The roof is created
	physicsFactory->CreateRoof(glm::vec3(-178,0,265), 1, 1,10,5,40); // Left slider created
	physicsFactory->CreateRoof(glm::vec3(-162,0,265), 1, 1,10,5,40); // Right slider created

	physicsFactory->CreateSphere(10, glm::vec3(-170, 50, 240), glm::quat(), glm::vec3(1,0,0)); // The sphere is created

	physicsFactory->CreateRamp(glm::vec3(-170,0,220), 1, 1); // The three ramp components created
	physicsFactory->CreateRamp(glm::vec3(-174,0,215), 1, 1, 8,50,1);
	physicsFactory->CreateRamp(glm::vec3(-164,0,215), 1, 1, 8,50,1);

	//Creating Domino Effect
	physicsFactory->CreateDomino2(glm::vec3(-170,0,-120), 8, 1); // The line of dominos are created
	physicsFactory->CreateSeeSaw(glm::vec3(-150,0,-160), 1, 1); // The flat timber is created to place on cylinder
	glm::quat CylinderRotationFlat = glm::angleAxis(90.0f ,glm::vec3(1,0,0)); // The cylinder is rotated
	physicsFactory->CreateCylinder(5, 20, glm::vec3(-155, 0, -160), CylinderRotationFlat, glm::vec3(1,0,0)); // The cylinder is created
	shared_ptr<PhysicsController> cube = physicsFactory->CreateBox(3,3,3, glm::vec3(-120, 10, -160), glm::quat(), glm::vec3(1,1,1)); // The small cude is that is placed on the seesaw is created

	physicsFactory->CreateSecondWall(glm::vec3(-169,0,-140), 1, 5); // The small tower is created that will hold the end ball
	physicsFactory->CreateSphere(10, glm::vec3(-170, 35,-140), glm::quat(), glm::vec3(1,0,0)); // The sphere is created that will be knocked of the tower and fall onto the seesaw

	//************************************************************************************************************************************
	// My lawnmower is created that is cutting all the grass for me manually
	//************************************************************************************************************************************
	//Lawnmower
	shared_ptr<PhysicsController> car = physicsFactory->CreateVehicle(glm::vec3(-50,10,200));

	Smoke = make_shared<FountainEffect>(500);
	Smoke->diffuse = glm::vec3(1,1, 0);
	Smoke->worldMode = world_modes::from_parent; // Particles that act as grass or snow
	car->Attach(Smoke);

	//************************************************************************************************************************************
	//************************************************************************************************************************************

	// Bowling
	physicsFactory->BowlingPins(glm::vec3(600,0,0), 10, 10, 20);
	//Snowmans
	physicsFactory->CreateSnowman(glm::vec3(5,20,0), 2); // Snowman is created

	//Christmas Tree
	physicsFactory->CreateChristmasTree(glm::vec3(400,0,200), 30,30); // Christmas tree is created

	//Rag Dolls
	physicsFactory->CreateRagDoll(glm::vec3(100,50,-100), 5); // The rag dolls are created 

	//************************************************************************************************************************************
	//************************************************************************************************************************************
	fountainTheta = 0.0f; 
	if (!Game::Initialise()) 
	{
		return false;
	}

	camera->GetController()->position = glm::vec3(450,100, 800);

	return true;
}

//************************************************************************************************************************************
// The below code is used for making the particles rotate around the snowman that is build. There are two that circle around the whole 
// body.
//************************************************************************************************************************************
void BGE::WinterWonderland::ParticleAroundSnowman(float timeDelta)
{
	int FOUNTAIN_HEIGHT = 300;
	for (int i = 0 ; i < fountains.size() ; i ++)
	{
		if (i % 2 == 0)
		{
			fountains[i]->position.y = FOUNTAIN_HEIGHT + (glm::sin(fountainTheta) * FOUNTAIN_HEIGHT);
		}
		else
		{
			fountains[i]->position.y = FOUNTAIN_HEIGHT - (glm::sin(fountainTheta) * FOUNTAIN_HEIGHT);
		}
	}
	float scale = 30.0f + (glm::sin(fountainTheta) / 3.0f);
	fountainTheta += timeDelta;
	if (fountainTheta >= glm::pi<float>() * 2.0f)
	{
		fountainTheta = 0.0f;
	}

	SnowmanFountain0->position.x = glm::sin(fountainTheta) * 30;
	SnowmanFountain0->position.z = - glm::cos(fountainTheta) * 30;
	SnowmanFountain0->position.y -= timeDelta * ySpeed;
	if (SnowmanFountain0->position.y > 50)
	{
		ySpeed = -ySpeed;
		SnowmanFountain0->position.y = 50;
	}

	if (SnowmanFountain0->position.y < 0)
	{
		ySpeed = -ySpeed;
		SnowmanFountain0->position.y = 0;
	}

	SnowmanFountain1->position.x = glm::sin(fountainTheta) * -30;
	SnowmanFountain1->position.z = glm::cos(fountainTheta) * 30;
	SnowmanFountain1->position.y += timeDelta * ySpeed;
	if (SnowmanFountain1->position.y > 50)
	{
		ySpeed = -ySpeed;
		SnowmanFountain1->position.y = 50;
	}

	if (SnowmanFountain1->position.y < 0)
	{
		ySpeed = -ySpeed;
		SnowmanFountain1->position.y = 0;
	}
}

//************************************************************************************************************************************
//************************************************************************************************************************************
void BGE::WinterWonderland::Update(float timeDelta)
{
	ParticleAroundSnowman(timeDelta);

	dynamicsWorld->stepSimulation(timeDelta,100);

	Game::Update(timeDelta);
}

void BGE::WinterWonderland::Cleanup()
{
	Game::Cleanup();
}
