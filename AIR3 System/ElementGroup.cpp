#include "ElementGroup.h"

ELEMENTGROUP_DLL AIElementGroup::AIElementGroup()
{
	mPos=0;
}

ELEMENTGROUP_DLL AIElementGroup::~AIElementGroup()
{
}

ELEMENTGROUP_DLL AIElementGroupSeparate::AIElementGroupSeparate()
{

}

ELEMENTGROUP_DLL AIElementGroupSeparate::~AIElementGroupSeparate()
{

}

ELEMENTGROUP_DLL AIElementGroupSwarm::AIElementGroupSwarm()
{
	mParams.N=10;
	mParams.DIST=200;

	mParams.RULE1_BYPASS=1;
	mParams.RULE2_DISTANCE=200;
	mParams.RULE2_BYPASS=0.05;
	mParams.RULE3_BYPASS=1;
	mParams.XMAX=800;
	mParams.YMAX=600;
	mParams.XMIN=0;
	mParams.YMIN=0;

	mParams.RADIUS=1;

	mParams.VELOCITY_BYPASS=10000;
}

ELEMENTGROUP_DLL AIElementGroupSwarm::~AIElementGroupSwarm()
{

}

ELEMENTGROUP_DLL void AIElementGroupSeparate::commandAny(int num,int command)
{
	
}


ELEMENTGROUP_DLL void AIElementGroupSeparate::commandAny(int num,String command)
{
	if (command=="gather")
	{
	AIElement* n = nodes[num];
	n->sendCommand1(StringConverter::toString(GOTO_NPC));
	n->sendCommand2(StringConverter::toString(n->getPosition()));
	}
}

ELEMENTGROUP_DLL void AIElementGroup::addAIElement(AIElement* node)
{
	nodes.push_back(node);
	
}

ELEMENTGROUP_DLL void AIElementGroup::setName(String name)
{
	mName=name;
}

ELEMENTGROUP_DLL String AIElementGroup::getName(void)
{
	return mName;
}

ELEMENTGROUP_DLL void AIElementGroup::command(String name, int command)
{
	
}

void AIElementGroup::command(String name, String command)
{
	if ((name=="")&&(command=="gather"))
	{
		//Send "message" to leader to gather group to position.
		std::vector<AIElement*>::iterator i;
		for (i=nodes.begin();i!=nodes.end();i++)
		{
			AIElement* n = (*i);
			n->sendCommand1(StringConverter::toString(GOTO_NPC));
			n->sendCommand2(StringConverter::toString(n->getPosition()));
		}
	}
	if ((name=="")&&(command=="activate"))
	{
		//Send "message" to leader to gather group to position.
		std::vector<AIElement*>::iterator i;
		for (i=nodes.begin();i!=nodes.end();i++)
		{
			AIElement* n = (*i);
			n->sendCommand1(StringConverter::toString(SETAI_NPC));
			n->sendCommand2("group_behavior");
		}
	}
	if ((command=="tend_to_pos"))
	{
		LogManager::getSingleton().logMessage("Tend to position:");
		//Send "message" to leader to gather group to position.
		mPos=StringConverter::parseVector3(name);
		LogManager::getSingleton().logMessage(StringConverter::toString(mPos));
	}
	if ((command=="calculate_center"))
	{
		mPos=0;
		//Send "message" to leader to gather group to position.
		std::vector<AIElement*>::iterator i;
		for (i=nodes.begin();i!=nodes.end();i++)
		{
			AIElement* n = (*i);
			mPos+=n->getPosition();
		}
		mPos/=nodes.size();
	}
}

void AIElementGroup::setPos(Vector3 pos)
{
	mPos=pos;
}

Vector3 AIElementGroup::getPos()
{
	return mPos;
}

void AIElementGroup::cleanupAllNodes()
{
	std::vector<AIElement*>::iterator i;
	for (i=nodes.begin();i!=nodes.end();i++)
	{
		AIElement* n = (*i);
		delete n;
	}
	nodes.clear();
}

AIElementGroupLeaderShip::AIElementGroupLeaderShip()
{
}

AIElementGroupLeaderShip::~AIElementGroupLeaderShip()
{
}

void AIElementGroupLeaderShip::commandLeader(int command)
{
}

float AIElementGroupSwarm::distanceFunction(float distance)
{
	if (distance<mParams.RULE2_DISTANCE)
	{
		return distance/mParams.RULE2_DISTANCE;
	}
	else
	{
		return (mParams.RULE2_DISTANCE*mParams.RULE2_DISTANCE/distance/distance);
	}
}

//
void AIElementGroup::step(Real evt)
{
	LogManager::getSingleton().logMessage("Obsolete step.");
}

//
void AIElementGroupSwarm::step(Real evt)
{
	//LogManager::getSingleton().logMessage("Swarm step.");
	int i;
		Vector3 v1,v2,v3,mVel;
		for (i=0;i!=nodes.size();i++)
		{
			AIElement* n = nodes[i];
			v1=rule1(n);
			v2=rule2(n);
			v3=rule3(n);
			mVel=n->getVelocity();
			mVel+=v1+v2+v3;
			//LogManager::getSingleton().logMessage(StringConverter::toString(nodes.size()));
		//	LogManager::getSingleton().logMessage(StringConverter::toString(v2));
		//	LogManager::getSingleton().logMessage(StringConverter::toString(v3));
			//boundPosition(nodes[i]);
			//tend_to_pos(nodes[i]);
			//n->setPosition(n->getPosition()+mVel/(100000)*evt);
			n->setVelocity(mVel*0.0001);
			tendToPos(getPos());
			n->sendCommand1(StringConverter::toString(GOTO_NPC));
			n->sendCommand2(StringConverter::toString(n->getPosition()));
		}
}

void AIElementGroupSwarm::setParameters(SwarmParams params)
{
	mParams=params;
}

Vector3 AIElementGroupSwarm::rule1(AIElement* b)
{
		Vector3 res=Vector3::ZERO;
		int i;
		for (i=0;i!=nodes.size();i++)
		{
			if (nodes[i]!=b)
			{
				res+=(nodes[i]->getPosition());
			}
		}
		res/=nodes.size()-1;
		return (res - b->getPosition())/mParams.RULE1_BYPASS;
}

Vector3 AIElementGroupSwarm::rule2(AIElement* b)
{
	//LogManager::getSingleton().logMessage("Swarm step.");
	Vector3 res=Vector3::ZERO;
		int i;
		for (i=0;i!=nodes.size();i++)
		{
			if (nodes[i]!=b)
			{
				Vector3 dist = nodes[i]->getPosition() - b->getPosition();

				float force = distanceFunction(dist.length());
				res-=(nodes[i]->getPosition() - b->getPosition())*(force);
				
			}
		}
		return res/mParams.RULE2_BYPASS;
}

Vector3 AIElementGroupSwarm::rule3(AIElement* b)
{
	Vector3 res=Vector3::ZERO;

		int i;
		for (i=0;i!=nodes.size();i++)
		{
			if (nodes[i]!=b)
			{
					res+=nodes[i]->getVelocity();
			}
		}

		res/=nodes.size()-1;

		return (res - b->getVelocity()) / mParams.RULE3_BYPASS;
}

void AIElementGroupSwarm::tendToPos(Vector3 pos)
{
	int i;
	for (i=0;i!=nodes.size();i++)
		{
			Vector3 res=Vector3::ZERO;
			res=nodes[i]->getVelocity()+(pos-nodes[i]->getPosition())/mParams.VELOCITY_BYPASS;
			nodes[i]->setVelocity(res);
		}
}
