#include "PhysicSystem.h"

using namespace Demo;

namespace Demo
{
	void PhysicSystem::initialize()
	{
		collisionConfig = new btDefaultCollisionConfiguration();
		dispatcher = new btCollisionDispatcher(collisionConfig);
		broadphase = new btDbvtBroadphase();
		solver = new btSequentialImpulseConstraintSolver();

		dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfig);
		dynamicsWorld->setGravity(btVector3(0, -9.81f, 0));
	}

	void PhysicSystem::deinitialize()
	{
	}

	void PhysicSystem::update(float timeSinceLast)
	{
		dynamicsWorld->stepSimulation(timeSinceLast);

		// Do something with collisions, or triggers or whatever here
	}
}