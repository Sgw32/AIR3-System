#pragma once
#ifndef __nodeGenerator_H__
#define __nodeGenerator_H__
#include "Air3Prerequisties.h"
#include "NPCNode.h"
#include "NodeList.h"
#include "Ogre.h" 	
#include "OgreVector3.h" 
#include "OgreQuaternion.h" 
using namespace Ogre; 
using namespace std; 

class AIR3EXPORT nodeGenerator
{
public:
	nodeGenerator(Vector3 size,SceneManager* scene,int spacing,bool nodeListFeedback);
	~nodeGenerator();
	void setNodeList(NodeList* nList);
	vector<NPCNode*> generate_nodes(void);
private:
	NodeList* nodeList;
	int mSpacing;
	bool feedback;
	SceneManager* mSceneMgr;
	Vector3 mSize;
};

#endif /*__SOUNDMANAGER_H__*/
