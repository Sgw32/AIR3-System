/*******
Non-player-character 
Path following
No ai - creature
Just follows path and can do specific thing mentioned in LUA script
********/
#ifndef __NPC_PFOLLOW_NAI_H__
#define __NPC_PFOLLOW_NAI_H__
#pragma once

#include <Ogre.h>
#include <OgreNewt.h>
#include "NPCNode.h"
#include "Defs.h"
#include <OIS/OIS.h>
#include <vector>


#define NPC_PFOLLOW_MESH "box.mesh"
#define NPC_PFOLLOW_SCALE Ogre::Vector3(500,700,1000)
#define AIR3EXPORT __declspec(dllimport)

//class AIR3EXPORT npc_pfollow_nai:public FrameListener
class AIR3EXPORT npc_pfollow_nai
{
public:
	npc_pfollow_nai();
	~npc_pfollow_nai();
	void init(Ogre::Root* root,String name,Real time);
	String getName(){return mName;};
	void start();
	void addPoint(NPCNode* a);
	void suspend();
	void resume();
	void step(const Ogre::FrameEvent &evt);
	void processEvent(int flag,String param1,String param2);
	bool frameStarted(const Ogre::FrameEvent &evt);
private:
	Real mTime,mRealTime;
	std::vector<NPCNode*> path;
	int i,iter;
	bool ttcomplete;
	bool started;
	Real thisdist;
	String mName;
	Ogre::Root* mRoot;
	Ogre::SceneNode* mHeliNode;
	Ogre::SceneManager* mSceneMgr;
	std::vector<NPCNode*> mPath;
};

#endif /*__NPC_PFOLLOW_NAI_H__*/