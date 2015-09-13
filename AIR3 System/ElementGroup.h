#pragma once

#ifndef __AIELEMENTGROUP_H__
#define __AIELEMENTGROUP_H__
#include <vector>
#include "Ogre.h" 	
#include "OgreVector3.h" 
#include "OgreQuaternion.h" 
#include "Element.h" 
#include "SwarmParams.h" 
using namespace Ogre; 

#define VARIABLES

#ifndef VARIABLES

#define N 10 //N*N SQUARE

#define DIST 5

#define RULE1_BYPASS 1
#define RULE2_DISTANCE 20
#define RULE2_BYPASS 1
#define RULE3_BYPASS 1000
#define XMAX 800
#define YMAX 600
#define XMIN 0
#define YMIN 0

#define RADIUS 1

#define VELOCITY_BYPASS 100

#endif

#ifdef RUN3
#define ELEMENTGROUP_DLL __declspec( dllimport )
#endif

#ifndef ELEMENTGROUP_DLL
#define ELEMENTGROUP_DLL __declspec( dllexport )
#endif

class ELEMENTGROUP_DLL AIElementGroup
{
public:
	AIElementGroup();
	~AIElementGroup();
	void setName(String name);
	String getName(void);
	void addAIElement(AIElement* node);
	void command(String name, int command);
	void command(String name, String command);
	void cleanupAllNodes();
	void setPos(Vector3 pos);
	Vector3 getPos();
	virtual void step(Real evt)=0;
	std::vector<AIElement*> nodes;
private:
	String mName;
	Vector3 mPos;
};

class ELEMENTGROUP_DLL AIElementGroupLeaderShip : public AIElementGroup
{
public:
	AIElementGroupLeaderShip();
	~AIElementGroupLeaderShip();
	void commandLeader(int command);
	void step(Real evt){};
private:
	std::vector<AIElement*> nodes;
};

class ELEMENTGROUP_DLL AIElementGroupSeparate : AIElementGroup
{
public:
	AIElementGroupSeparate();
	~AIElementGroupSeparate();
	void commandAny(int num,int command);
	void commandAny(int num,String command);
	void step(Real evt){};
private:
	std::vector<AIElement*> nodes;
	std::vector<AIElement*> closedset,openset;
};

class ELEMENTGROUP_DLL AIElementGroupSwarm : AIElementGroup
{
public:
	AIElementGroupSwarm();
	~AIElementGroupSwarm();
	void commandAny(int num,int command);
	void commandAny(int num,String command);
	void command(String name, String command);
	void step(Real evt);
	void setParameters(SwarmParams params);
	void tendToPos(Vector3 pos);
	Vector3 rule1(AIElement* b);
	Vector3 rule2(AIElement* b);
	Vector3 rule3(AIElement* b);
private:
	SwarmParams mParams;
	float distanceFunction(float distance);
	//std::vector<AIElement*> nodes;
	//std::vector<AIElement*> closedset,openset;
};

#endif /*__SOUNDMANAGER_H__*/