#include "Element.h"



__declspec(dllexport) AIElement::AIElement(SceneManager* sceneMgr,Vector3 pos,String name)
{
	mName=name;
if (sceneMgr)
	mSceneMgr = sceneMgr;
mPos = pos;
mVel=Vector3::ZERO;
}

__declspec(dllexport) AIElement::~AIElement()
{
	
}

__declspec(dllexport) void AIElement::sendCommand1(String command)
{
	mCommand1=command;
}

__declspec(dllexport) void AIElement::sendCommand2(String command)
{
	mCommand2=command;
}
__declspec(dllexport) String AIElement::getName()
{
	return mName;
}
__declspec(dllexport) String AIElement::getCommand1()
{
	return mCommand1;
}
__declspec(dllexport) String AIElement::getCommand2()
{
	return mCommand2;
}

__declspec(dllexport) Vector3 AIElement::getPosition()
{
	return mPos;
}

__declspec(dllexport) Vector3 AIElement::getVelocity()
{
	return mVel;
}

__declspec(dllexport) void AIElement::setPosition(Vector3 pos)
{
	mPos=pos;
}

__declspec(dllexport) void AIElement::setVelocity(Vector3 vel)
{
	mVel=vel;
}


__declspec(dllexport) Real AIElement::getDistanceTo(AIElement* second)
{
	return mPos.distance(second->getPosition());
}