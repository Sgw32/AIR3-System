#pragma once
#ifndef __NPCNode_H__
#define __NPCNode_H__
#define AIR3EXPORT __declspec(dllimport)
#include "Ogre.h" 	
#include "OgreVector3.h" 
#include "OgreQuaternion.h" 
using namespace Ogre; 


class AIR3EXPORT NPCNode
{
public:
	NPCNode(SceneManager* mSceneMgr,Vector3 pos);
	~NPCNode();
	Vector3 getPosition();
	void setType(int typ){type=typ;}
	Real getDistanceTo(NPCNode* second);
    /*NPCNode& operator = ( const NPCNode& sNode)
    {
            x = rkVector.x;
            y = rkVector.y;
            z = rkVector.z;

            return *this;
    }*/
private:
	int type;
	Vector3 mPos;
	SceneManager* mSceneMgr;
};

#endif /*__SOUNDMANAGER_H__*/
