/*******
Non-player-character 
Player following
Basic AI - creature
********/
#pragma once

#ifndef __NPC_BPLAY_H__

#define __NPC_BPLAY_H__

#include <Ogre.h>
#include <OgreNewt.h>
#include "NPCNode.h"
#include "Defs.h"
#include <OIS/OIS.h>
#include <vector>


#define NPC_BPLAY_MESH "ninja.mesh"
#define NPC_BPLAY_SCALE Ogre::Vector3(1,1,1)
#define AIR3EXPORT __declspec(dllimport)

//class AIR3EXPORT npc_pfollow_nai:public FrameListener
class AIR3EXPORT npc_bplay
{
public:
	npc_bplay();
	~npc_bplay();
	void init(Ogre::Root* root,String name,Real time,Vector3 spawn,Real velocity);
	String getName(){return mName;};
	void start();
	void setPlayerPosition(Vector3 pos);
	void suspend();
	void resume();
	void step(const Ogre::FrameEvent &evt);
	void processEvent(int flag,String param1,String param2);
	bool frameStarted(const Ogre::FrameEvent &evt);
private:
	Real mTime,mRealTime,mVel;
	NPCNode* pPos;
	Vector3 direction,pPosit,mSpawn;
	int i,iter;
	bool ttcomplete;
	bool started;
	String mName;
	Ogre::Root* mRoot;
	Ogre::SceneNode* mHeliNode;
	Ogre::SceneManager* mSceneMgr;
};

#endif /*__NPC_BPLAY_H__*/