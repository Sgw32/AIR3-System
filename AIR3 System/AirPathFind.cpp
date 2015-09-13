#include "AirPathFind.h"

__declspec(dllexport) AirPathFind::AirPathFind()
{
dFound=false;
}

__declspec(dllexport) AirPathFind::~AirPathFind()
{

}

__declspec(dllexport) void AirPathFind::setNodes(std::vector<NPCNode*> nodes)
{
	mNodesStartup=nodes;
}

__declspec(dllexport) void AirPathFind::setWorld(OgreNewt::World* world)
{
mWorld=world;
}

__declspec(dllexport) OgreNewt::Body* AirPathFind::ray(Ogre::Vector3 pos,Ogre::Vector3 end)
{
	OgreNewt::BasicRaycast shootRay(mWorld,pos,end);
	return shootRay.getFirstHit().mBody;
}

__declspec(dllexport) vector<NPCNode*> AirPathFind::search(int type,NPCNode* pos,NPCNode* end)
{
	path.clear();
	dFound=false;
	firstNode=pos;
	mNodes=mNodesStartup;
	mNodesMarked.clear();
	if (type==DEPTH_FIRST_SEARCH) 
		processDFSearch(pos,end);
	/*if (type==2) n
		processAIR3Search(pos,end);*/
	/*int i = path.size();
	i=i+1;*/
	return path;
}

__declspec(dllexport) void AirPathFind::processDFSearch(NPCNode* pos,NPCNode* end)
{
	LogManager::getSingleton().logMessage("Depth-first search iteration.pos="+StringConverter::toString(pos->getPosition())+"end="+StringConverter::toString(end->getPosition()));
	NPCNode* s;
	vector<NPCNode*>::iterator i;
	if (firstNode==pos)
	{
		LogManager::getSingleton().logMessage("Iteration one, passing first node.");
		path.push_back(pos);
		mNodesMarked.push_back(pos);
	}
	if (pos==end)
	{
		LogManager::getSingleton().logMessage("The destination is equal from the start. Not a mistake in definition?");
		path.push_back(end);
		dFound=true;
		return;
	}
	OgreNewt::Body* bod;
	bod=ray(pos->getPosition(),end->getPosition());
	if (!bod || bod->getName()=="PLAYER1" )
	{
		LogManager::getSingleton().logMessage("The pass is free to the end, or the pass collides PLAYER!pos="+StringConverter::toString(pos->getPosition())+"end="+StringConverter::toString(end->getPosition()));
		path.push_back(end);
		dFound=true;
		return;
	}
	/*if ((pos!=firstNode)&&bod)
		return;*/
	//int i;
	LogManager::getSingleton().logMessage("Finding a free pass...Found a path="+StringConverter::toString(dFound));
	for (i=mNodes.begin();i!=mNodes.end();i++)
	{
		
		bod=ray(pos->getPosition(),(*i)->getPosition());
		int j;
		bool n;
		n=false;
		LogManager::getSingleton().logMessage(StringConverter::toString(mNodesMarked.size()));
		for (j=0;j!=mNodesMarked.size();j++)
		{
			if ((*i)==mNodesMarked[j])
			{
				n=true;
				break;
			}
		}
		if ((!dFound)&&!bod&&!n)
		{
			
			path.push_back((*i));
			s=*i;
			mNodesMarked.push_back(*i);
			LogManager::getSingleton().logMessage(StringConverter::toString(s->getPosition()));
			processDFSearch(s,end);
			
		}
	}
	LogManager::getSingleton().logMessage("Path not found. Sorry!");
}

__declspec(dllexport) void AirPathFind::processAIR3Search(Ogre::Vector3 pos,Ogre::Vector3 end)
{

}