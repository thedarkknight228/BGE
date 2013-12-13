#pragma once
#include <memory>
#include "PhysicsController.h"
#include "GameComponent.h"


using namespace std;

namespace BGE
{
	class PhysicsFactory
	{
	private:
		
	public:
		PhysicsFactory(btDiscreteDynamicsWorld * dynamicsWorld);
		~PhysicsFactory(void);

		shared_ptr<PhysicsController> CreateBox(float width, float height, float depth, glm::vec3 pos, glm::quat quat, glm::vec3 color);
		shared_ptr<PhysicsController> CreateBoundryWall(float width, float height, float depth, glm::vec3 pos, glm::quat quat);
		shared_ptr<PhysicsController> CreateSphere(float radius, glm::vec3 pos, glm::quat quat, glm::vec3 Color);
		shared_ptr<PhysicsController> Snowman(float radius, glm::vec3 pos, glm::quat quat, glm::vec3 Color);
		shared_ptr<PhysicsController> CreateCylinder(float radius, float height, glm::vec3 pos, glm::quat quat, glm::vec3 color);
		shared_ptr<PhysicsController> CreateVehicle(glm::vec3 pos);
		shared_ptr<PhysicsController> CreateCameraPhysics();
		shared_ptr<PhysicsController> CreateGroundPhysics();
		shared_ptr<PhysicsController> CreateFromModel(string name, glm::vec3 pos, glm::quat quat, glm::vec3 scale = glm::vec3(1));

		void BowlingPins(glm::vec3 startAt, float width, float depth, float blockHeight);
		
		void CreateSnowman(glm::vec3 Position, float Amount);
		void CreateRagDoll(glm::vec3 Position, float Amount);

		void CreateChristmasTree(glm::vec3 startAt, float width, float height, float blockWidth = 10, float blockHeight = 10, float blockDepth = 10);

		void CreateRamp(glm::vec3 startAt, float width, float height, float blockWidth = 20, float blockHeight = 50, float blockDepth = 1);
		void CreateSeeSaw(glm::vec3 startAt, float width, float height, float blockWidth = 1, float blockHeight = 70, float blockDepth = 20);

		void CreateDomino2(glm::vec3 startAt, float width, float height, float blockWidth = 20, float blockHeight = 50, float blockDepth = 2);
		void CreateRoof(glm::vec3 startAt, float width, float height, float blockWidth = 50, float blockHeight = 2, float blockDepth = 50);
		void CreateWall(glm::vec3 startAt, float width, float height, float blockWidth = 10, float blockHeight = 5, float blockDepth = 5);
		void CreateSecondWall(glm::vec3 startAt, float width, float height, float blockWidth = 5, float blockHeight = 5, float blockDepth = 1.5f);

		shared_ptr<PhysicsController> CreateRandomObject(glm::vec3 point, glm::quat q);
		btDiscreteDynamicsWorld * dynamicsWorld;
	};
}
