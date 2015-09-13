// NodeList macro-s
#define NODELIST_SPAWN NodeList* nList;
#define NODELIST_NEW nList = new NodeList();
#define PRIVATE_NODELIST NodeList* mNodeList;
#define STORE_NODELIST mNodeList=nList;
#define NODELIST_USABLE mNodeList;
#define GET_NODELIST return mNodeList;
#define ADD(x) nList->addNPCNode(x);
#define NPCNODES nList->getNode()


#define RUN3_AI_STORE global::getSingleton().setNodeList(nList);
#define RUN3_AI_GET mNodeList=global::getSingleton().getNodeList();

#define AINODE(p) NPCNode* n=new NPCNode;nList->addNPCNode(n);