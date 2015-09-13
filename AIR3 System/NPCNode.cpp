#include "NPCNode.h"



__declspec(dllexport) NPCNode::NPCNode(SceneManager* sceneMgr,Vector3 pos)
{
if (sceneMgr)
	mSceneMgr = sceneMgr;
mPos = pos;
}

__declspec(dllexport) NPCNode::~NPCNode()
{
	
}

__declspec(dllexport) Vector3 NPCNode::getPosition()
{
	return mPos;
}


__declspec(dllexport) Real NPCNode::getDistanceTo(NPCNode* second)
{
	return mPos.distance(second->getPosition());
}