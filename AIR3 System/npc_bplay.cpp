#include "npc_bplay.h"


__declspec(dllexport) npc_bplay::npc_bplay()
{

}

__declspec(dllexport) npc_bplay::~npc_bplay()
{

}

__declspec(dllexport) void npc_bplay::init(Ogre::Root* root,String name,Real time,Vector3 spawn,Real velocity)
{
			mRoot=root;
			started=false;
			mSceneMgr=root->getSceneManagerIterator().getNext();
			mName=name;
			ttcomplete=false;
			i=1;
			iter=0;
			mTime=time;
			mRealTime=0;
			mVel=velocity;
			mSpawn=spawn;
 }

__declspec(dllexport) void npc_bplay::setPlayerPosition(Vector3 pos)
{
pPosit=pos;
}

__declspec(dllexport) void npc_bplay::start()
{
started=true;
}

__declspec(dllexport) void npc_bplay::suspend()
{
started=false;
}

__declspec(dllexport) void npc_bplay::resume()
{

}

__declspec(dllexport) void npc_bplay::processEvent(int flag,String param1,String param2)
{
	if (flag==SPAWN_NPC)
	{
		mHeliNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mSpawn);
		Entity* heliEnt = mSceneMgr->createEntity(mName,NPC_BPLAY_MESH);
		mHeliNode->attachObject(heliEnt);
		mHeliNode->setScale(NPC_BPLAY_SCALE);
	}
	if (flag==RUNTO_NPC)
	{
		start();
	}
	if (flag==STOP_NPC)
	{
		suspend();
	}
}

__declspec(dllexport) void npc_bplay::step(const Ogre::FrameEvent &evt)
{
	if (started)
	{
		Vector3 dir3 = pPosit-mHeliNode->getPosition();
		Vector3 dir = Vector3(pPosit.x,mHeliNode->getPosition().y,pPosit.z);-mHeliNode->getPosition();
		Vector3 step = dir3/pPosit.distance(mHeliNode->getPosition())*evt.timeSinceLastFrame*mVel;
		Vector3 dir2(dir.x,mHeliNode->getPosition().y,dir.z);
		mHeliNode->lookAt(dir2,Node::TS_WORLD);
		mHeliNode->translate(step);
		//mHeliNode->roll(Radian(0),Node::TS_WORLD);
		//mHeliNode->setOrientation(Quaternion(Radian(0),Vector3::UNIT_Y));
		//mHeliNode->lookAt(pPosit,Node::TS_WORLD);
		//mHeliNode->roll(Radian(180));
	}
}

bool npc_bplay::frameStarted(const Ogre::FrameEvent &evt)
{
	step(evt);
	return true;
}