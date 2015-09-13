#include "NodeList.h"

__declspec(dllexport) NodeList::NodeList()
{

}

__declspec(dllexport) NodeList::~NodeList()
{
	
}

__declspec(dllexport) void NodeList::addNPCNode(NPCNode* node)
{
	this->nodes.push_back(node);
}

__declspec(dllexport) std::vector<NPCNode*> NodeList::getAstarPathTo(NPCNode* A,NPCNode* B)
{
std::vector<NPCNode*> nodes2;
nodes2.push_back(A);
return nodes2;
}

__declspec(dllexport) void NodeList::cleanupAllNodes()
{
	std::vector<NPCNode*>::iterator i;
	for (i=nodes.begin();i!=nodes.end();i++)
	{
		NPCNode* n = (*i);
		delete n;
	}
	nodes.clear();
}

__declspec(dllexport) std::vector<NPCNode*> NodeList::getNode()
{
		return nodes;
}