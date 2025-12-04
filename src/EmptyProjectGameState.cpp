
#include "EmptyProjectGameState.h"
#include "CameraController.h"
#include "GraphicsSystem.h"

#include "OgreItem.h"
#include "OgreSceneManager.h"

#include "OgreMesh2.h"
#include "OgreMeshManager.h"
#include "OgreMeshManager2.h"

#include "OgreCamera.h"
#include "OgreWindow.h"

#include "OgreHlmsPbsDatablock.h"
#include "OgreHlmsSamplerblock.h"

#include "OgreHlmsManager.h"
#include "OgreHlmsPbs.h"
#include "OgreRoot.h"

#include "PhysicSystem.h"

using namespace Demo;

namespace Demo
{
    // EmptyProjectGameState is the may system of my Arena Shooter. From there, the rest of the Engine is like an API to me.
	// Those are tools that I can use to build the game.
    // I build from there, and will only extend when I need to.
    EmptyProjectGameState::EmptyProjectGameState( const Ogre::String &helpDescription ) :
        TutorialGameState( helpDescription )
    {
		pItemSceneNode = nullptr;

        pPhysicSystem = new PhysicSystem();
        pPhysicSystem->initialize();
    }
    EmptyProjectGameState::~EmptyProjectGameState()
    {
        pPhysicSystem->deinitialize();
        delete pPhysicSystem;
    }
    //-----------------------------------------------------------------------------------
    void EmptyProjectGameState::createScene01()
    {
        // I let this alone, as I for now, I want it to handle the debug text.
		TutorialGameState::createScene01();

        // This was already here. This is a bit weird that it is not created directly in the base class. This sample is dumb ! Isn't it ?
		mCameraController = new CameraController(mGraphicsSystem, false);

        // I get the scene manager, it has already been created in the graphic system. I will use it to instantiate things in it.
		Ogre::SceneManager* sceneManager = mGraphicsSystem->getSceneManager();
		// I get the root node of the scene. I create a child node to attach my objects to it, just because it was like this in Forward3DGameState,
        // and I don't want to change things up while I don't have something working.
        Ogre::SceneNode* root = sceneManager->getRootSceneNode(Ogre::SCENE_DYNAMIC)->createChildSceneNode(Ogre::SCENE_DYNAMIC);

		// I create an item from a mesh. The mesh must be in the resource path that has been set in the graphic system.
        Ogre::Item* item = sceneManager->createItem(
            "CubeFromMedia_d.mesh", Ogre::ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME,
            Ogre::SCENE_DYNAMIC);

		// I create a scene node to attach the item to it.
        pItemSceneNode = root->createChildSceneNode(Ogre::SCENE_DYNAMIC);
        pItemSceneNode->attachObject(item);
    }
    //-----------------------------------------------------------------------------------
    void EmptyProjectGameState::update( float timeSinceLast )
    {
        TutorialGameState::update( timeSinceLast );

		pPhysicSystem->update(timeSinceLast);

        // Self made accumulated time.
		time += timeSinceLast;

        // I am being fancy with my cube
        pItemSceneNode->setPosition(0, Ogre::Math::Sin(time) * 2.0f, 0);
    }
    //-----------------------------------------------------------------------------------
    void EmptyProjectGameState::generateDebugText( float timeSinceLast, Ogre::String &outText )
    {
        TutorialGameState::generateDebugText( timeSinceLast, outText );
    }
    //-----------------------------------------------------------------------------------
    void EmptyProjectGameState::keyReleased( const SDL_KeyboardEvent &arg )
    {
        if( ( arg.keysym.mod & ~( KMOD_NUM | KMOD_CAPS ) ) != 0 )
        {
            TutorialGameState::keyReleased( arg );
            return;
        }

        TutorialGameState::keyReleased( arg );
    }
}  // namespace Demo
