#ifndef _Demo_PhysicSystem_H_
#define _Demo_PhysicSystem_H_

#include <btBulletDynamicsCommon.h>

namespace Demo
{
	class PhysicSystem
	{
	public:
		void initialize();
		void deinitialize();
		void update(float timeSinceLast);

	private:
		btDefaultCollisionConfiguration* collisionConfig;
		btCollisionDispatcher* dispatcher;
		btBroadphaseInterface* broadphase;
		btSequentialImpulseConstraintSolver* solver;
		btDiscreteDynamicsWorld* dynamicsWorld;
	};
}  // namespace Demo

#endif
