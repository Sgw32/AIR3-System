#pragma once

#ifndef __NODELIST_H__
#define __NODELIST_H__
#include <vector>
#include "Ogre.h" 	
#include "OgreVector3.h" 
#include "OgreQuaternion.h" 
#include "NPCNode.h" 
using namespace Ogre; 

class AIR3EXPORT NodeList
{
public:
	NodeList();
	~NodeList();
	void addNPCNode(NPCNode* node);
	std::vector<NPCNode*> getAstarPathTo(NPCNode* A,NPCNode* B);
	std::vector<NPCNode*> getNode();
	void cleanupAllNodes();
private:
	std::vector<NPCNode*> nodes;
	std::vector<NPCNode*> closedset,openset;
};
#endif /*__SOUNDMANAGER_H__*/