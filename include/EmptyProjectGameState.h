#ifndef _Demo_EmptyProjectGameState_H_
#define _Demo_EmptyProjectGameState_H_

#include "OgrePrerequisites.h"
#include "TutorialGameState.h"
#include "PhysicSystem.h"
#include "GameState.h"


namespace Demo
{
    class EmptyProjectGameState : public TutorialGameState
    {
        Ogre::SceneNode* pItemSceneNode;
        float time = 0.f;

        PhysicSystem* pPhysicSystem;

        void generateDebugText( float timeSinceLast, Ogre::String &outText ) override;

    public:
        EmptyProjectGameState( const Ogre::String &helpDescription );
        ~EmptyProjectGameState();

        void createScene01() override;

        void update( float timeSinceLast ) override;

        void keyReleased( const SDL_KeyboardEvent &arg ) override;
    };
}  // namespace Demo

#endif
