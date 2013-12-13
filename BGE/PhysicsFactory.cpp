#include "PhysicsFactory.h"
#include "Game.h"
#include "Sphere.h"
#include "Box.h"
#include "Cylinder.h"
#include "Ground.h"
#include "Content.h"
#include "PhysicsCamera.h"
#include "Model.h"
#include "dirent.h"
#include "Utils.h"
using namespace BGE;

PhysicsFactory::PhysicsFactory(btDiscreteDynamicsWorld * dynamicsWorld)
{
	this->dynamicsWorld = dynamicsWorld;
}


PhysicsFactory::~PhysicsFactory(void)
{
}

//************************************************************************************************************************************
// Making Bowling. 
//************************************************************************************************************************************
void PhysicsFactory::BowlingPins(glm::vec3 startAt, float width, float depth, float blockHeight)
{
	float y = startAt.y;
	float gap = 3;
	float radius = 3.0f;
	glm::vec3 UpPosition;
	int Indent = 3;

	/*for (int d = 0 ; d < depth ; d ++)
	{
		for (int w = 0 ; w < width ; w ++)	
		{
			if(d == 0)
			{
				float x = startAt.x - ((radius * 2 + gap) * w);
				float z = (((radius * 2) + gap) / 2.0f) + (((radius * 2) + gap) * d);
				CreateCylinder(radius, blockHeight, glm::vec3(x, y, z), glm::quat(), glm::vec3(1,0.5f,0.9f));
			}
			else if(d > 1)
			{
				if(w == 0)
				{
					float x = (startAt.z - (radius * 2 + gap) * Indent);
					float z = (((radius * 2) + gap) / 2.0f) + (((radius * 2) + gap) * d);
					CreateCylinder(radius, blockHeight, glm::vec3(x, y, z), glm::quat(), glm::vec3(1,0.5f,0.9f));
					Indent += radius*2; // So the next row doesnt start at 0
					UpPosition = glm::vec3(x,y,z); // To be used to reference the last placed shape
				}
				else if(w > 0)
				{
					float x = (UpPosition.x) - ((radius*2 + gap) * w);
					float z = (((radius * 2) + gap) / 2.0f) + (((radius * 2) + gap) * d);
					CreateCylinder(radius, blockHeight, glm::vec3(x, y, z), glm::quat(), glm::vec3(1,0.5f,0.9f));
				}
				//float x = startAt.x - ((radius * 2 + gap + (gap/2)) * w);
				//float z = (((radius * 2) + gap) / 2.0f) + (((radius * 2) + gap) * d);
				//CreateCylinder(radius, blockHeight, glm::vec3(x, y, z), glm::quat(), glm::vec3(1,0.5f,0.9f));
			}
		}
		width = width - 1;
	}*/

	/*for(int q = 0; q < 10; q++)
	{
		float x = startAt.x + ((radius * 2 + gap) * q);
		CreateCylinder(radius, blockHeight, glm::vec3(startAt.x,startAt.y,startAt.z), glm::quat(), glm::vec3(1,0.5f,0.9f));
	}
	for(int w = 0; w < 9; w++)
	{
		float x = startAt.x + ((radius * 2 + gap) * w);
		CreateCylinder(radius, blockHeight, glm::vec3(startAt.x,startAt.y,startAt.z + (radius*2 + gap)), glm::quat(), glm::vec3(1,0.5f,0.9f));
	}
	for(int e = 0; e < 8; e++)
	{
		float x = startAt.x + ((radius * 3 + gap) * e);
		CreateCylinder(radius, blockHeight, glm::vec3(startAt.x,startAt.y,startAt.z + (radius*3 + gap)), glm::quat(), glm::vec3(1,0.5f,0.9f));
	}
	for(int r = 0; r < 7; r++)
	{
		float x = startAt.x + ((radius * 4 + gap) * r);
		CreateCylinder(radius, blockHeight, glm::vec3(startAt.x,startAt.y,startAt.z + (radius*4 + gap)), glm::quat(), glm::vec3(1,0.5f,0.9f));
	}
	for(int t = 0; t < 6; t++)
	{
		float x = startAt.x + ((radius * 5 + gap) * t);
		CreateCylinder(radius, blockHeight, glm::vec3(startAt.x,startAt.y,startAt.z + (radius*5 + gap)), glm::quat(), glm::vec3(1,0.5f,0.9f));
	}
	for(int y = 0; y < 5; y++)
	{
		float x = startAt.x + ((radius * 6 + gap) * y);
		CreateCylinder(radius, blockHeight, glm::vec3(startAt.x,startAt.y,startAt.z + (radius*6 + gap)), glm::quat(), glm::vec3(1,0.5f,0.9f));
	}
	for(int u = 0; u < 4; u++)
	{
		float x = startAt.x + ((radius * 7 + gap) * u);
		CreateCylinder(radius, blockHeight, glm::vec3(startAt.x,startAt.y,startAt.z + (radius*7 + gap)), glm::quat(), glm::vec3(1,0.5f,0.9f));
	}
	for(int i = 0; i < 3; i++)
	{
		float x = startAt.x + ((radius * 8 + gap) * i);
		CreateCylinder(radius, blockHeight, glm::vec3(startAt.x,startAt.y,startAt.z + (radius*8 + gap)), glm::quat(), glm::vec3(1,0.5f,0.9f));
	}
	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x,startAt.y,startAt.z + (radius*9 + gap)), glm::quat(), glm::vec3(1,0.5f,0.9f));
	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + ((radius * 10 + gap),startAt.y,startAt.z + (radius*10 + gap)), glm::quat(), glm::vec3(1,0.5f,0.9f));*/


	//Creating the pins manually because i only started this with an hour to go and I tried doing it in for loop above but didn't get working in time
	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x,startAt.y,startAt.z), glm::quat(), glm::vec3(1,0.5f,0.9f));
	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 5,startAt.y,startAt.z), glm::quat(), glm::vec3(1,0.5f,0.9f));
	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 10,startAt.y,startAt.z), glm::quat(), glm::vec3(1,0.5f,0.9f));
	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 15,startAt.y,startAt.z), glm::quat(), glm::vec3(1,0.5f,0.9f));
	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 20,startAt.y,startAt.z), glm::quat(), glm::vec3(1,0.5f,0.9f));

	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 4,startAt.y,startAt.z + 10), glm::quat(), glm::vec3(1,0.5f,0.9f));
	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 8,startAt.y,startAt.z + 10), glm::quat(), glm::vec3(1,0.5f,0.9f));
	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 12,startAt.y,startAt.z + 10), glm::quat(), glm::vec3(1,0.5f,0.9f));
	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 16,startAt.y,startAt.z + 10), glm::quat(), glm::vec3(1,0.5f,0.9f));

	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 5,startAt.y,startAt.z + 20), glm::quat(), glm::vec3(1,0.5f,0.9f));
	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 10,startAt.y,startAt.z + 20), glm::quat(), glm::vec3(1,0.5f,0.9f));
	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 15,startAt.y,startAt.z + 20), glm::quat(), glm::vec3(1,0.5f,0.9f));

	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 6.25f,startAt.y,startAt.z + 30), glm::quat(), glm::vec3(1,0.5f,0.9f));
	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 12.5f,startAt.y,startAt.z + 30), glm::quat(), glm::vec3(1,0.5f,0.9f));

	CreateCylinder(radius, blockHeight, glm::vec3(startAt.x + 10,startAt.y,startAt.z + 40), glm::quat(), glm::vec3(1,0.5f,0.9f));

	// Creating the boundry walls
	CreateBoundryWall(10, 100, 300, glm::vec3(550,0,0), glm::quat());
	CreateBoundryWall(10, 100, 300, glm::vec3(700,0,0), glm::quat());
	CreateBoundryWall(155, 100, 10, glm::vec3(622,0,-150), glm::quat());

	// Creating the bowling ball and stick to hit the ball with
	CreateSphere(5, glm::vec3(605, 0, 200), glm::quat(), glm::vec3(1,0,0));
	CreateCylinder(3, 100, glm::vec3(650,0,300), glm::angleAxis(90.0f ,glm::vec3(1,0,0)), glm::vec3(0,0,1));
}

//************************************************************************************************************************************
// This function takes in 2 parameters the position of the first snowman and then the amount of them that you require.
// It goes around a for loop for each snowman being built, if the loop is on its second loop around or greater it adds to the 
// position of the first snowman so it is placed beside the previous one.
// Then each body part is created.
// The nose it set to zero gravity so it doesn't fall and the rest are all kinematic objects.
// Each shape being created takes in an extra parameter which is the colour you want it to be. 
//************************************************************************************************************************************
void PhysicsFactory::CreateSnowman(glm::vec3 Position, float Amount)
{
	for(int k = 0; k < Amount; k++)
	{
		if(k > 0)
		{
			Position.x = Position.x + 50;
		}
		shared_ptr<PhysicsController> BottomPart = Snowman(20, Position, glm::quat(), glm::vec3(239,208,207)); 
		shared_ptr<PhysicsController> MiddlePart = Snowman(15, glm::vec3(Position.x, Position.y + 30, Position.z), glm::quat(), glm::vec3(239,208,207)); 
		shared_ptr<PhysicsController> TopPart = Snowman(8, glm::vec3(Position.x, Position.y + 50, Position.z), glm::quat(), glm::vec3(239,208,207));
		shared_ptr<PhysicsController> eyeleft = CreateBoundryWall(1,1,1, glm::vec3(Position.x - 3, Position.y + 53, Position.z + 10), glm::quat()); 
		shared_ptr<PhysicsController> eyeright = CreateBoundryWall(1,1,1, glm::vec3(Position.x + 3, Position.y + 53, Position.z + 10), glm::quat());
		shared_ptr<PhysicsController> Nose = CreateBox(1,1,6, glm::vec3(Position.x, Position.y + 50, Position.z + 5), glm::quat(), glm::vec3(0.9f,0.4f,0));
		shared_ptr<PhysicsController> button1 = CreateBoundryWall(5,5,5, glm::vec3(Position.x - 1, Position.y + 35, Position.z + 13), glm::quat()); 
		shared_ptr<PhysicsController> button2 = CreateBoundryWall(5,5,5, glm::vec3(Position.x -1, Position.y + 10, Position.z + 16), glm::quat()); 
		shared_ptr<PhysicsController> button3 = CreateBoundryWall(5,5,5, glm::vec3(Position.x - 1, Position.y - 5, Position.z + 18), glm::quat());

		Nose->rigidBody->setGravity(btVector3(0,0,0));
	}
}
//************************************************************************************************************************************
// The same thing is done here as with the snowman. It akes in its position and the amount, then loops around each one being created.
// It creates all the body part and sets them all to zero.
// Each shape being created takes in an extra parameter which is the colour you want it to be. 
// Then the last thing is the joints for each body part is constructed making all the body parts tramsform into a rag doll.
//************************************************************************************************************************************
void PhysicsFactory::CreateRagDoll(glm::vec3 Position, float Amount)
{
	for(int i = 0; i < Amount; i++)
	{
		if(i > 0)
		{
			Position.x = Position.x + 20;
		}
		shared_ptr<PhysicsController> Head = CreateSphere(2.5f, glm::vec3(Position.x, Position.y + 15, Position.z),glm::quat(), glm::vec3(1,0.8f,0.8f));
		shared_ptr<PhysicsController> Body = CreateBox(8,20,2, Position, glm::quat(), glm::vec3(0,0,1));
		shared_ptr<PhysicsController> ArmLeftUpper = CreateBox(2,6,2, glm::vec3(Position.x -7, Position.y + 7, Position.z), glm::quat(), glm::vec3(0,0,1));
		shared_ptr<PhysicsController> ArmLeftLower = CreateBox(2,6,2, glm::vec3(Position.x - 7, Position.y, Position.z), glm::quat(), glm::vec3(1,0.8f,0.8f));
		shared_ptr<PhysicsController> ArmRightUpper = CreateBox(2,6,2, glm::vec3(Position.x + 6, Position.y + 7, Position.z), glm::quat(), glm::vec3(0,0,1));
		shared_ptr<PhysicsController> ArmRightLower = CreateBox(2,6,2, glm::vec3(Position.x + 6, Position.y, Position.z), glm::quat(), glm::vec3(1,0.8f,0.8f));
		shared_ptr<PhysicsController> LegLeftUpper = CreateBox(2,6,2, glm::vec3(Position.x - 2, Position.y - 13, Position.z), glm::quat(), glm::vec3(1,0.5f,0));
		shared_ptr<PhysicsController> LegLeftLower = CreateBox(2,6,2, glm::vec3(Position.x - 2, Position.y - 20, Position.z), glm::quat(), glm::vec3(1,0.8f,0.8f));
		shared_ptr<PhysicsController> LegRightUpper = CreateBox(2,6,2, glm::vec3(Position.x + 2, Position.y - 13, Position.z), glm::quat(), glm::vec3(1,0.5f,0));
		shared_ptr<PhysicsController> LegRightLower = CreateBox(2,6,2, glm::vec3(Position.x + 2, Position.y - 20, Position.z), glm::quat(), glm::vec3(1,0.8f,0.8f));

		Head->rigidBody->setGravity(btVector3(0,0,0));
		Body->rigidBody->setGravity(btVector3(0,0,0));
		ArmLeftUpper->rigidBody->setGravity(btVector3(0,0,0));
		ArmLeftLower->rigidBody->setGravity(btVector3(0,0,0));
		ArmRightUpper->rigidBody->setGravity(btVector3(0,0,0));
		ArmRightLower->rigidBody->setGravity(btVector3(0,0,0));
		LegLeftUpper->rigidBody->setGravity(btVector3(0,0,0));
		LegLeftLower->rigidBody->setGravity(btVector3(0,0,0));
		LegRightUpper->rigidBody->setGravity(btVector3(0,0,0));
		LegRightLower->rigidBody->setGravity(btVector3(0,0,0));

		btPoint2PointConstraint * Neck = new btPoint2PointConstraint(*Head->rigidBody, *Body->rigidBody, btVector3(0,-2.5f,0),btVector3(0,11,0));
		dynamicsWorld->addConstraint(Neck);

		btPoint2PointConstraint * LeftShouler = new btPoint2PointConstraint(*Body->rigidBody, *ArmLeftUpper->rigidBody, btVector3(-5,9.5f,0),btVector3(1,4,0));
		dynamicsWorld->addConstraint(LeftShouler);

		btPoint2PointConstraint * RightShoulder = new btPoint2PointConstraint(*Body->rigidBody, *ArmRightUpper->rigidBody, btVector3(5,9.5f,0),btVector3(-1,4,0));
		dynamicsWorld->addConstraint(RightShoulder);

		btHingeConstraint * LeftElbow = new btHingeConstraint(*ArmLeftUpper->rigidBody, *ArmLeftLower->rigidBody, btVector3(0,-3.1f,0),btVector3(0,3.1f,0), btVector3(1,0,0), btVector3(1,0,0), true);
		dynamicsWorld->addConstraint(LeftElbow);

		btHingeConstraint * RightElbow = new btHingeConstraint(*ArmRightUpper->rigidBody, *ArmRightLower->rigidBody, btVector3(0,-3.1f,0),btVector3(0,3.1f,0), btVector3(1,0,0), btVector3(1,0,0), true);
		dynamicsWorld->addConstraint(RightElbow);

		btPoint2PointConstraint * LeftHip = new btPoint2PointConstraint(*Body->rigidBody, *LegLeftUpper->rigidBody, btVector3(-2.5f,-8,1),btVector3(0,6,0));
		dynamicsWorld->addConstraint(LeftHip);

		btPoint2PointConstraint * RightHip = new btPoint2PointConstraint(*Body->rigidBody, *LegRightUpper->rigidBody, btVector3(2.5f,-8,0),btVector3(0,6,0));
		dynamicsWorld->addConstraint(RightHip);

		btHingeConstraint * LeftKnee = new btHingeConstraint(*LegLeftUpper->rigidBody, *LegLeftLower->rigidBody, btVector3(0,-3.1f,0),btVector3(0,3.1f,0), btVector3(1,0,0), btVector3(1,0,0), true);
		dynamicsWorld->addConstraint(LeftKnee);

		btHingeConstraint * RightKnee = new btHingeConstraint(*LegRightUpper->rigidBody, *LegRightLower->rigidBody, btVector3(0,-3.1f,0),btVector3(0,3.1,0), btVector3(1,0,0), btVector3(1,0,0), true);
		dynamicsWorld->addConstraint(RightKnee);
	}
}
//************************************************************************************************************************************
// This function is where I create my christmas tree. 
// It takes in the amount of blocks you want for its width and the same for its height. 
// It then loops around the height first so it can lay the bottom bricks. Inside the height loop it does the width for loop that
// places each block. If h == 0 which means its on the first row of blocks so it lays the whole width wide. 
// Then for each other row moving up it takes 2 blocks away from the width so that it gets smaller each row. 
// The last position of the last block placed is recored and stored inside a vector so it can be used to place a sphere on top of the
// tree.
//************************************************************************************************************************************
void PhysicsFactory::CreateChristmasTree(glm::vec3 startAt, float width, float height, float blockWidth, float blockHeight, float blockDepth)
{
	float x = startAt.x;
	glm::vec3 topPosition;
	glm::vec3 UpPosition;
	//int i = 0;
	int Indent = 1;
	for(int h = 0; h < height; h++)
	{
		for(int w = 0; w < width; w++)
		{
			if(h == 0)
			{
				float z = startAt.z - ((blockWidth) * w);
				float y = ((blockHeight) / 2.0f) + ((blockHeight) * (h));
				CreateBox(blockWidth, blockHeight, blockDepth, glm::vec3(x,y,z), glm::quat(), glm::vec3(0.5f,1,0.5f));
			}
			else
			{
				if(w == 0)
				{
					float z = (startAt.z - blockWidth * Indent);
					float y = ((blockHeight) / 2.0f) + ((blockHeight) * (h));
					CreateBox(blockWidth, blockHeight, blockDepth, glm::vec3(x, y, z), glm::quat(), glm::vec3(0.5f,1,0.5f));
					Indent += 1; // So the next row doesnt start at 0
					UpPosition = glm::vec3(x,y,z);
				}
				else
				{
					float z = (UpPosition.z) - ((blockWidth) * w);
					float y = ((blockHeight) / 2.0f) + ((blockHeight) * (h));
					CreateBox(blockWidth, blockHeight, blockDepth, glm::vec3(x, y, z), glm::quat(), glm::vec3(0.5f,1,0.5f));
					topPosition = glm::vec3(x,y,z); // To be used for the sphere(star)
				}	
			}
		}
		//i = 2;
		width = width - 2; // Taking away 2 blocks each time
	}
	CreateSphere(4,glm::vec3(topPosition.x, topPosition.y + (blockHeight/2), topPosition.z + (blockWidth/1.2f)), glm::quat(), glm::vec3(1.0f,1.0f,0));
}
//************************************************************************************************************************************
// In here the ramp for the ball to roll down is created. 
//************************************************************************************************************************************
void PhysicsFactory::CreateRamp(glm::vec3 startAt, float width, float height, float blockWidth, float blockHeight, float blockDepth)
{
	float x = startAt.x;
	float gap = 0;

	for (int w = 0 ; w < width ; w ++)
	{
		for (int h = 0 ; h < height ; h ++)	
		{
			glm::quat RampRotation = glm::angleAxis(60.0f ,glm::vec3(1,0,0)); // Rotating the axis of the ramp
			float z = startAt.z + ((blockWidth + 30.0f) * w);
			float y = ((blockHeight + gap) / 2.0f) + ((blockHeight + gap) * h);
			CreateBox(blockWidth, blockHeight, blockDepth, glm::vec3(x, y, z), RampRotation, glm::vec3(1,1,1)); // Creating the ramp with the new rotation degrees
		}
	}
}
//************************************************************************************************************************************
// Creating the seesaw that is palced at the end of my dominos. 
//************************************************************************************************************************************
void PhysicsFactory::CreateSeeSaw(glm::vec3 startAt, float width, float height, float blockWidth, float blockHeight, float blockDepth)
{
	float z = startAt.z;
	float gap = 0;

	for (int w = 0 ; w < width ; w ++)
	{
		for (int h = 0 ; h < height ; h ++)	
		{
			glm::quat SeeSawRotation = glm::angleAxis(70.0f ,glm::vec3(0,0,1)); // Again rotating the axis of the timber to be placed on the cylinder
			float x = startAt.x + ((blockWidth + 30.0f) * w);
			float y = startAt.y;
			CreateBox(blockWidth, blockHeight, blockDepth, glm::vec3(x, y, z), SeeSawRotation, glm::vec3(1,1,1));
		}
	}
}
//************************************************************************************************************************************
// Here I am creating my dominos stack. 
// The width that the user enters in will determine the amount of dominos created
//************************************************************************************************************************************

void PhysicsFactory::CreateDomino2(glm::vec3 startAt, float width, float height, float blockWidth, float blockHeight, float blockDepth)
{
	float x = startAt.x;

	for (int w = 0 ; w < width ; w ++)
	{
		for (int h = 0 ; h < height ; h ++)	
		{
			float z = startAt.z + ((blockWidth + 20.0f) * w);
			float y = startAt.y;
			CreateBox(blockWidth, blockHeight, blockDepth, glm::vec3(x, y, z), glm::quat(), glm::vec3(239,208,207));
		}
	}
}
//************************************************************************************************************************************
// This is just creating my flat platform that my sphere will be placed on that will roll down and start the domino effect
//************************************************************************************************************************************
void PhysicsFactory::CreateRoof(glm::vec3 startAt, float width, float height, float blockWidth, float blockHeight, float blockDepth)
{
	float z = startAt.z;
	float gap = 0;

	for (int w = 0 ; w < width ; w ++)
	{
		for (int h = 0 ; h < height ; h ++)	
		{
			float x = startAt.x + ((blockWidth) * w);
			float y = ((blockHeight + gap) / 2.0f) + ((blockHeight + gap) * h) + 18;
			CreateBox(blockWidth, blockHeight, blockDepth, glm::vec3(x, y, z), glm::quat(), glm::vec3(1,1,1));
		}
	}
}
//************************************************************************************************************************************
//************************************************************************************************************************************
void PhysicsFactory::CreateWall(glm::vec3 startAt, float width, float height, float blockWidth, float blockHeight, float blockDepth)
{
	float z = startAt.z;
	float gap = 0;

	for (int w = 0 ; w < width ; w ++)
	{
		for (int h = 0 ; h < height ; h ++)	
		{
			float x = startAt.x + ((blockWidth + 2) * w);
			float y = ((blockHeight + gap) / 2.0f) + ((blockHeight + gap) * h);
			CreateBox(blockWidth, blockHeight, blockDepth, glm::vec3(x, y, z), glm::quat(), glm::vec3(1,1,1));
		}
	}
}
//************************************************************************************************************************************
//************************************************************************************************************************************
//Width going along Z Axis
void PhysicsFactory::CreateSecondWall(glm::vec3 startAt, float width, float height, float blockWidth, float blockHeight, float blockDepth)
{
	float x = startAt.x;
	float gap = 0;

	for (int w = 0 ; w < width ; w ++)
	{
		for (int h = 0 ; h < height ; h ++)	
		{
			float z = startAt.z + ((blockWidth + 2) * w);
			float y = ((blockHeight + gap) / 2.0f) + ((blockHeight + gap) * h);
			CreateBox(blockWidth, blockHeight, blockDepth, glm::vec3(x, y, z), glm::quat(), glm::vec3(1,1,1));
		}
	}
}
//************************************************************************************************************************************
//************************************************************************************************************************************
shared_ptr<PhysicsController> PhysicsFactory::CreateFromModel(string name, glm::vec3 pos, glm::quat quat, glm::vec3 scale)
{
	shared_ptr<GameComponent> component = make_shared<GameComponent>();
	component->tag = name;
	component->scale = scale;
	Game::Instance()->Attach(component);
	shared_ptr<Model> model = Content::LoadModel(name);
	component->specular = glm::vec3(1.2f, 1.2f, 1.2f);
	model->Initialise();
	component->Attach(model);

	std::vector<glm::vec3>::iterator it = model->vertices.begin(); 	
	btConvexHullShape * tetraShape = new btConvexHullShape();

	while (it != model->vertices.end())
	{
		glm::vec4 point = glm::vec4(* it, 0) * glm::scale(glm::mat4(1), scale);
		tetraShape->addPoint(GLToBtVector(glm::vec3(point)));
		it ++;
	}
	
	btScalar mass = 1;
	btVector3 inertia(0,0,0);
	
	tetraShape->calculateLocalInertia(mass,inertia);
	btDefaultMotionState * motionState = new btDefaultMotionState(btTransform(GLToBtQuat(quat)
		,GLToBtVector(pos)));	
	
	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(mass,motionState, tetraShape, inertia);
	btRigidBody * body = new btRigidBody(rigidBodyCI);
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	dynamicsWorld->addRigidBody(body);

	shared_ptr<PhysicsController> controller =make_shared<PhysicsController>(tetraShape, body, motionState);	
	body->setUserPointer(controller.get());
	component->Attach(controller);
	
	controller->tag = "Model";	
	return controller;
}
//************************************************************************************************************************************
// What I changed here is to add an extra parameter to be taken in and that is the colour. 
// The rgb value is taken in and is applied ot the shape
//************************************************************************************************************************************
shared_ptr<PhysicsController> PhysicsFactory::CreateSphere(float radius, glm::vec3 pos, glm::quat quat, glm::vec3 Color)
{
	shared_ptr<GameComponent> sphere (new Sphere(radius));
	Game::Instance()->Attach(sphere);
	sphere->diffuse = Color; // Colour applied here.
	btDefaultMotionState * sphereMotionState = new btDefaultMotionState(btTransform(GLToBtQuat(quat)
		,GLToBtVector(pos)));	

	btScalar mass = 2;
	btVector3 sphereInertia(0,0,0);
	btCollisionShape * sphereShape = new btSphereShape(radius);

	sphereShape->calculateLocalInertia(mass,sphereInertia);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass,sphereMotionState, sphereShape, sphereInertia);
	btRigidBody * body = new btRigidBody(fallRigidBodyCI);
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	dynamicsWorld->addRigidBody(body);

	shared_ptr<PhysicsController> sphereController (new PhysicsController(sphereShape, body, sphereMotionState));	
	body->setUserPointer(sphereController.get());
	sphere->Attach(sphereController);
	sphereController->tag = "Sphere";	
	return sphereController;
}
//************************************************************************************************************************************
// Again an extra parameter for colour added in
//************************************************************************************************************************************
shared_ptr<PhysicsController> PhysicsFactory::CreateBox(float width, float height, float depth, glm::vec3 pos, glm::quat quat, glm::vec3 color)
{
	// Create the shape
	btCollisionShape * boxShape = new btBoxShape(btVector3(width, height, depth) * 0.5);
	btScalar mass = 1;
	btVector3 boxInertia(0,0,0);
	boxShape->calculateLocalInertia(mass,boxInertia);

	// This is a container for the box model
	shared_ptr<Box> box = make_shared<Box>(width, height, depth);
	box->diffuse = color;
	box->worldMode = GameComponent::from_child;
	box->position = pos;
	Game::Instance()->Attach(box);

	// Create the rigid body
	btDefaultMotionState * boxMotionState = new btDefaultMotionState(btTransform(GLToBtQuat(quat)
		,GLToBtVector(pos)));			
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass,  boxMotionState, boxShape, boxInertia);
	btRigidBody * body = new btRigidBody(fallRigidBodyCI);
	body->setFriction(567);
	dynamicsWorld->addRigidBody(body);

	// Create the physics component and add it to the box
	shared_ptr<PhysicsController> boxController = make_shared<PhysicsController>(PhysicsController(boxShape, body, boxMotionState));
	boxController->tag = "Box";
	body->setUserPointer(boxController.get());
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	box->Attach(boxController);

	return boxController;
}
//************************************************************************************************************************************
// Again an extra parameter for colour added in
//************************************************************************************************************************************
shared_ptr<PhysicsController> PhysicsFactory::CreateCylinder(float radius, float height, glm::vec3 pos, glm::quat quat, glm::vec3 color)
{
	// Create the shape
	btCollisionShape * shape = new btCylinderShape(btVector3(radius, height * 0.5f, radius));
	btScalar mass = 1;
	btVector3 inertia(0,0,0);
	shape->calculateLocalInertia(mass,inertia);

	// This is a container for the box model
	shared_ptr<GameComponent> cyl = make_shared<GameComponent>(Cylinder(radius, height));
	cyl->position = pos;
	cyl->diffuse = color;
	Game::Instance()->Attach(cyl);

	// Create the rigid body
	btDefaultMotionState * motionState = new btDefaultMotionState(btTransform(GLToBtQuat(quat)
		,GLToBtVector(pos)));			
	btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(mass,  motionState, shape, inertia);
	btRigidBody * body = new btRigidBody(rigidBodyCI);
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	dynamicsWorld->addRigidBody(body);

	// Create the physics component and add it to the box
	shared_ptr<PhysicsController> component = make_shared<PhysicsController>(PhysicsController(shape, body, motionState));
	body->setUserPointer(component.get());
	component->tag = "Cylinder";
	cyl->Attach(component);

	return component;
}
//************************************************************************************************************************************
//************************************************************************************************************************************
shared_ptr<PhysicsController> PhysicsFactory::CreateCameraPhysics()
{
	btVector3 inertia;
	// Now add physics to the camera
	btCollisionShape * cameraCyl = new btCylinderShape(btVector3(0.5f, 5.0f, 2.5f));
	cameraCyl->calculateLocalInertia(1, inertia);
	shared_ptr<PhysicsCamera> physicsCamera = make_shared<PhysicsCamera>(this);

	shared_ptr<Camera> camera = Game::Instance()->camera;
	camera->Attach(physicsCamera);

	btRigidBody::btRigidBodyConstructionInfo cameraCI(10,physicsCamera.get(), cameraCyl, inertia);  
	btRigidBody * body = new btRigidBody(cameraCI);
	physicsCamera->SetPhysicsStuff(cameraCyl, body, physicsCamera.get());
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
	body->setActivationState(DISABLE_DEACTIVATION);

	dynamicsWorld->addRigidBody(body);
	return physicsCamera;
}
//************************************************************************************************************************************
// Created this Kinematic boundry wall
//************************************************************************************************************************************
shared_ptr<PhysicsController> PhysicsFactory::CreateBoundryWall(float width, float height, float depth, glm::vec3 pos, glm::quat quat)
{
	// Create the shape
	btCollisionShape * boxShape = new btBoxShape(btVector3(width, height, depth) * 0.5);
	btScalar mass = 1;
	btVector3 boxInertia(0,0,0);
	
	boxShape->calculateLocalInertia(mass,boxInertia);

	// This is a container for the box model
	shared_ptr<Box> box = make_shared<Box>(width, height, depth);
	box->diffuse = glm::vec3(0,1,0);
	box->worldMode = GameComponent::from_child;
	box->position = pos;
	Game::Instance()->Attach(box);

	// Create the rigid body
	btDefaultMotionState * boxMotionState = new btDefaultMotionState(btTransform(GLToBtQuat(quat)
		,GLToBtVector(pos)));			
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass,  boxMotionState, boxShape, boxInertia);
	btRigidBody * body = new btRigidBody(fallRigidBodyCI);
	body->setFriction(567);
	dynamicsWorld->addRigidBody(body);

	// Create the physics component and add it to the box
	shared_ptr<PhysicsController> boxController = make_shared<PhysicsController>(PhysicsController(boxShape, body, boxMotionState));
	boxController->tag = "Box";
	body->setUserPointer(boxController.get());
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
	box->Attach(boxController);

	return boxController;
}
//************************************************************************************************************************************
// Created kinematic spheres for the snowmans body
//************************************************************************************************************************************
shared_ptr<PhysicsController> PhysicsFactory::Snowman(float radius, glm::vec3 pos, glm::quat quat, glm::vec3 Color)
{
	shared_ptr<GameComponent> sphere (new Sphere(radius));
	Game::Instance()->Attach(sphere);
	sphere->diffuse = Color;
	btDefaultMotionState * sphereMotionState = new btDefaultMotionState(btTransform(GLToBtQuat(quat)
		,GLToBtVector(pos)));	

	btScalar mass = 5;
	btVector3 sphereInertia(0,0,0);
	btCollisionShape * sphereShape = new btSphereShape(radius);

	sphereShape->calculateLocalInertia(mass,sphereInertia);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass,sphereMotionState, sphereShape, sphereInertia);
	btRigidBody * body = new btRigidBody(fallRigidBodyCI);
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
	dynamicsWorld->addRigidBody(body);

	shared_ptr<PhysicsController> sphereController (new PhysicsController(sphereShape, body, sphereMotionState));	
	body->setUserPointer(sphereController.get());
	sphere->Attach(sphereController);
	sphereController->tag = "Sphere";	
	return sphereController;
}
//************************************************************************************************************************************
//************************************************************************************************************************************
shared_ptr<PhysicsController> PhysicsFactory::CreateVehicle(glm::vec3 position)
{
	float width = 15;
	float height = 2;
	float length = 5;
	float wheelWidth = 1;
	float wheelRadius = 2;
	float wheelOffset = 2.0f;
	glm::vec3 colour;
	shared_ptr<PhysicsController> chassis = CreateBox(width, height, length, position, glm::quat(), glm::vec3(1,1,1));
	shared_ptr<PhysicsController> hub; 
	shared_ptr<PhysicsController> chimney; 
	
	shared_ptr<PhysicsController> wheel;
	glm::quat q =  glm::angleAxis(glm::half_pi<float>(), glm::vec3(1, 0, 0));

	glm::vec3 offset;
	btHingeConstraint * hinge;

	offset = glm::vec3(-3.75f, 5, 0);
	chimney = CreateBox(3, 6, 3, glm::vec3(position.x + (width/4),position.y + 50,position.z), q, glm::vec3(1,1,1));
	hinge = new btHingeConstraint(* chassis->rigidBody, * chimney->rigidBody, GLToBtVector(offset),btVector3(0,0,0), btVector3(0,0,1), btVector3(0,1,0), true);
	dynamicsWorld->addConstraint(hinge);

	offset = glm::vec3(3.75f, 5, 0);
	hub = CreateBox(7.5f, 7, length, glm::vec3(position.x + (width/4),position.y + 50,position.z), glm::quat(), glm::vec3(1,1,1));
	hinge = new btHingeConstraint(* chassis->rigidBody, * hub->rigidBody, GLToBtVector(offset),btVector3(0,0,0), btVector3(0,0,1), btVector3(0,1,0), true);
	dynamicsWorld->addConstraint(hinge);

	offset = glm::vec3(- (width / 2 - wheelRadius), 0, - (length / 2 + wheelOffset));
	wheel = CreateCylinder(wheelRadius, wheelWidth, position + offset, q, glm::vec3(1,0.8f,0.8f));	 
	hinge = new btHingeConstraint(* chassis->rigidBody, * wheel->rigidBody, GLToBtVector(offset),btVector3(0,0,0), btVector3(0,0,1), btVector3(0,1,0), true);
	dynamicsWorld->addConstraint(hinge);

	offset = glm::vec3(+ (width / 2 - wheelRadius), 0, - (length / 2 + wheelOffset));
	wheel = CreateCylinder(wheelRadius, wheelWidth, glm::vec3(position.x + (width / 2) - wheelRadius, position.y, position.z - (length / 2) - wheelWidth), q, glm::vec3(1,0.8f,0.8f));
	hinge = new btHingeConstraint(* chassis->rigidBody, * wheel->rigidBody, GLToBtVector(offset),btVector3(0,0, 0), btVector3(0,0,1), btVector3(0,1,0), true);
	dynamicsWorld->addConstraint(hinge);

	offset = glm::vec3(- (width / 2 - wheelRadius), 0, + (length / 2 + wheelOffset));
	wheel = CreateCylinder(wheelRadius, wheelWidth, position + offset, q, glm::vec3(1,0.8f,0.8f));	 
	hinge = new btHingeConstraint(* chassis->rigidBody, * wheel->rigidBody, GLToBtVector(offset),btVector3(0,0, 0), btVector3(0,0,1), btVector3(0,1,0), true);
	dynamicsWorld->addConstraint(hinge);

	offset = glm::vec3(+ (width / 2 - wheelRadius), 0, + (length / 2 + wheelOffset));
	wheel = CreateCylinder(wheelRadius, wheelWidth, position + offset, q, glm::vec3(1,0.8f,0.8f));	 
	hinge = new btHingeConstraint(* chassis->rigidBody, * wheel->rigidBody, GLToBtVector(offset),btVector3(0,0, 0), btVector3(0,0,1), btVector3(0,1,0), true);
	dynamicsWorld->addConstraint(hinge);

	return chassis;
}
//************************************************************************************************************************************
//************************************************************************************************************************************
shared_ptr<PhysicsController> PhysicsFactory::CreateGroundPhysics()
{
	shared_ptr<Ground> ground = make_shared<Ground>();

	btCollisionShape * groundShape = new btStaticPlaneShape(btVector3(0,1,0),1);
	btDefaultMotionState * groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,-1,0)));

	btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0,groundMotionState,groundShape,btVector3(0,0,0));
	btRigidBody* body = new btRigidBody(groundRigidBodyCI);
	body->setFriction(100);
	dynamicsWorld->addRigidBody(body);
	body->setUserPointer(ground.get());
	body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
	shared_ptr<PhysicsController> groundComponent (new PhysicsController(groundShape, body, groundMotionState));
	groundComponent->tag = "Ground";
	ground->Attach(groundComponent);	
	Game::Instance()->SetGround(ground);
	return groundComponent;
}
//************************************************************************************************************************************
//************************************************************************************************************************************
shared_ptr<PhysicsController> PhysicsFactory::CreateRandomObject(glm::vec3 point, glm::quat q)
{
	vector<string> names;
	DIR * dir;
	struct dirent * ent;
	dir = opendir (Content::prefix.c_str());
	if (dir != NULL) 
	{
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL) 
		{
			string fname = string(ent->d_name);
			int fpos = fname.find("objm");
			if (fpos != string::npos)
			{
				if ((fname.find("cube") == string::npos) && (fname.find("cyl") == string::npos) && (fname.find("sphere") == string::npos))
				{
					names.push_back(fname.substr(0, fpos - 1));
				}
			}
		}
		closedir (dir);
	} 
	else 
	{
		throw BGE::Exception("Could not list obj files in content folder");
	}

	int which = rand() % names.size();
	string name = names[which];
	return CreateFromModel(name, point, q, glm::vec3(3,3,3));
}
