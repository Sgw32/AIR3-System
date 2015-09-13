#pragma once
#ifndef __AI_ELEMENT_H__
#define __AI_ELEMENT_H__
#define AIR3EXPORT __declspec(dllimport)
#include "Ogre.h" 	
#include "Defs.h" 	
#include "OgreVector3.h" 
#include "OgreQuaternion.h" 
using namespace Ogre; 


class AIR3EXPORT AIElement
{
public:
	AIElement(SceneManager* mSceneMgr,Vector3 pos,String name);
	~AIElement();
	void setPosition(Vector3 pos);
	void setVelocity(Vector3 pos);
	void sendCommand1(String command);
	void sendCommand2(String command);
	String getName();
	String getCommand1();
	String getCommand2();
	Vector3 getPosition();
	Vector3 getVelocity();
	void setElementType(int typ){type=typ;}
	Real getDistanceTo(AIElement* second);
private:
	String mName;
	String mCommand1,mCommand2;
	int type;
	Vector3 mPos,mVel;
	SceneManager* mSceneMgr;
};

#endif /*__SOUNDMANAGER_H__*/
