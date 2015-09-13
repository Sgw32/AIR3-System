#include "ElementGroupGenerator.h"

ElementGroupGenerator::ElementGroupGenerator()
{
}

ElementGroupGenerator::~ElementGroupGenerator()
{
}

AIElementGroup* ElementGroupGenerator::createGroup(int type)
{
		AIElementGroup* grp;
		switch (type)
		{
		case 0:
			grp = (AIElementGroup*) new AIElementGroupLeaderShip();
			LogManager::getSingleton().logMessage("Generating leadership group...");
			break;
		case 1:
			grp = (AIElementGroup*) new AIElementGroupSeparate();
			LogManager::getSingleton().logMessage("Generating group separate...");
			break;
		case 2:
			grp = (AIElementGroup*) new AIElementGroupSwarm();
			LogManager::getSingleton().logMessage("Generating swarm...");
			break;
		default:
//			grp = (AIElementGroup*) new AIElementGroup();
			LogManager::getSingleton().logMessage("Generating common type...");
			break;
		}
		return grp;
}