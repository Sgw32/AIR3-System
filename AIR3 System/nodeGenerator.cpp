#include "nodeGenerator.h"



__declspec(dllexport) nodeGenerator::nodeGenerator(Vector3 size,SceneManager* scene,int spacing,bool nodeListFeedback)
{
mSize=size;
mSceneMgr=scene;
mSpacing=spacing;
feedback=nodeListFeedback;
}

__declspec(dllexport) nodeGenerator::~nodeGenerator()
{
	
}

void nodeGenerator::setNodeList(NodeList* nList)
{
	nodeList=nList;
}

__declspec(dllexport) vector<NPCNode*> nodeGenerator::generate_nodes()
{
	int i,j,k;
	Real minx = mSize.x/2;
	Real miny = mSize.y/2;
	Real minz = mSize.z/2;
	vector<NPCNode*> res;
	int i1 = floor(mSize.x/mSpacing);
	int j1 = floor(mSize.y/mSpacing);
	int k1 = floor(mSize.z/mSpacing);
	for (i=0;i!=i1;i++)
	{
			for (j=0;j!=j1;j++)
			{
					for (k=0;k!=k1;k++)
					{
						NPCNode* n = new NPCNode(mSceneMgr,Vector3(minx-i*300,miny-j*300,minz-k*300));
						if (feedback)
							nodeList->addNPCNode(n);
						res.push_back(n);
					}
			}
	}
	return res;
}