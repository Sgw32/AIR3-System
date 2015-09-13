#pragma once
#include "Air3Prerequisties.h"

#include "ElementGroup.h"
#include "Ogre.h" 	

using namespace Ogre; 
using namespace std; 

class AIR3EXPORT ElementGroupGenerator
{
public:
	ElementGroupGenerator();
	~ElementGroupGenerator();
	AIElementGroup* createGroup(int type);
};