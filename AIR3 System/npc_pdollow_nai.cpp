#include "npc_pfollow_nai.h"


__declspec(dllexport) npc_pfollow_nai::npc_pfollow_nai()
{

}

__declspec(dllexport) npc_pfollow_nai::~npc_pfollow_nai()
{

}

__declspec(dllexport) void npc_pfollow_nai::init(Ogre::Root* root,String name,Real time)
{
			//mSpawn=spawn;
			mRoot=root;
			started=false;
			//mRoot->addFrameListener(this);
			mSceneMgr=root->getSceneManagerIterator().getNext();
			mName=name;
			ttcomplete=false;
			i=1;
			iter=0;
			mTime=time;
			mRealTime=0;
 }

__declspec(dllexport) void npc_pfollow_nai::addPoint(NPCNode* a)
{
	mPath.push_back(a);
}
__declspec(dllexport) void npc_pfollow_nai::start()
{
started=true;
}

__declspec(dllexport) void npc_pfollow_nai::suspend()
{

}

__declspec(dllexport) void npc_pfollow_nai::resume()
{

}

__declspec(dllexport) void npc_pfollow_nai::processEvent(int flag,String param1,String param2)
{
	if (flag==SPAWN_NPC)
	{
		mHeliNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mPath[0]->getPosition());
		Entity* heliEnt = mSceneMgr->createEntity(mName,NPC_PFOLLOW_MESH);
		mHeliNode->attachObject(heliEnt);
		mHeliNode->setScale(NPC_PFOLLOW_SCALE);
	}
	if (flag==RUNTO_NPC)
	{
		start();
	}
}

__declspec(dllexport) void npc_pfollow_nai::step(const Ogre::FrameEvent &evt)
{
	if (started)
	{
		Vector3 dest = mPath[i]->getPosition();
		if (!(mHeliNode->getPosition().distance(mPath[i-1]->getPosition())>dest.distance(mPath[i-1]->getPosition())))
		{
		Vector3 myPos = mPath[i-1]->getPosition();
		Real dist = myPos.distance(dest); 
		Vector3 dir = dest-myPos;
		if (evt.timeSinceLastFrame!=0)
		{
			Vector3 step = dir/mTime*evt.timeSinceLastFrame;
			mHeliNode->translate(step);
		}
		}
		if (mHeliNode->getPosition().distance(mPath[i-1]->getPosition())>dest.distance(mPath[i-1]->getPosition()))
		{
			int b;
			b = i+1;
		if (!(b>mPath.size()))
      			i++;
		if ((i)==mPath.size())
			started=false;
		}
	}
}

bool npc_pfollow_nai::frameStarted(const Ogre::FrameEvent &evt)
{
	step(evt);
	return true;
}