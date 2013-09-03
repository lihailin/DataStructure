enum Blacne{LH=-1,TIE,RH};
enum posType{link=1,thread};
struct tnode {
	int data;
	struct tnode *lchild;
	struct tnode *rchild;
	//////////////////////////////////////////////////////////////////////////
	Blacne bw;

	//////////////////////////////////////////////////////////////////////////
	posType ltype;
	posType rtype;
};

typedef struct tnode TNode;
typedef struct tnode *Tree;
typedef struct tnode *NodePos;