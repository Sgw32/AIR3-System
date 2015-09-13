#pragma once

#ifndef __AIR3PATHFIND_H__
#define __AIR3PATHFIND_H__
#define AIR3SINGLETON __declspec(dllimport)
#include <vector>
#include "Ogre.h" 	
#include "OgreNewt.h" 	
#include "OgreVector3.h" 
#include "OgreQuaternion.h" 
#include "NodeList.h" 
#include "Defs.h" 
using namespace Ogre; 
using namespace std;

class AIR3SINGLETON AirPathFind
{
public:
	AirPathFind();
	~AirPathFind();
	void setWorld(OgreNewt::World* world);
	void setNodes(std::vector<NPCNode*> nodes);
	OgreNewt::Body* ray(Ogre::Vector3 pos,Ogre::Vector3 end);
	vector<NPCNode*> search(int type,NPCNode* pos,NPCNode* end);
	void processDFSearch(NPCNode* pos,NPCNode* end); //depth-first search
	void processAIR3Search(Ogre::Vector3 pos,Ogre::Vector3 end); //special AIR3 search
private:
	OgreNewt::World* mWorld;
	bool dFound;
	NPCNode* firstNode;
	std::vector<NPCNode*> path;
	std::vector<NPCNode*> mNodes;
	std::vector<NPCNode*> mNodesStartup;
	std::vector<NPCNode*> mNodesMarked;
};

#endif /*__SOUNDMANAGER_H__*/