#pragma once
#include "Game.h"
#include "PhysicsController.h"
#include "PhysicsFactory.h"
#include <btBulletDynamicsCommon.h>
#include "FountainEffect.h"

namespace BGE
{
	class WinterWonderland :
		public Game
	{
	private:
		btBroadphaseInterface* broadphase;
 
		// Set up the collision configuration and dispatcher
		btDefaultCollisionConfiguration * collisionConfiguration;
		btCollisionDispatcher * dispatcher;
 
		// The actual physics solver
		btSequentialImpulseConstraintSolver * solver;

	public:
		WinterWonderland(void);
		~WinterWonderland(void);
		shared_ptr<FountainEffect> Smoke;
		bool Initialise();
		void Update(float timeDelta);
		vector<shared_ptr<FountainEffect>> fountains;
		shared_ptr<FountainEffect> SnowmanFountain0;
		shared_ptr<FountainEffect> SnowmanFountain1;
		float fountainTheta;
		float ySpeed;
		void Cleanup();
		void CreateWall();
		void ChimneySmoke();
		void ParticleAroundSnowman(float timeDelta);
		
		// The world.
		std::shared_ptr<PhysicsFactory> physicsFactory;
		btDiscreteDynamicsWorld * dynamicsWorld;
	};
}

