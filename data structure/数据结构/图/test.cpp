# include <iostream>
# include <queue>
using namespace std;

struct ArcNode{
	int adjvex;
	ArcNode * next;
};

typedef struct VNode{
	char vertex;
	ArcNode * firstarc;
}AdjList[20];

struct ALGraph{
	AdjList adjList;
	int vexNum;
	int arcNum;
};

bool visited[20];

void CreatGraph(ALGraph & graph);
void PritnGraph(ALGraph & graph);
void DFSTraverse(ALGraph & graph);
void BFSTraverse(ALGraph & graph);


void CreatGraph(ALGraph & graph){
	cout <<" input the vexNum:";
	cin>> graph.vertex;
	cout << "input arcNum:";
	cin>> graph.arcNum;

	cout<< "input the information of" << graph.vexNum  << "vertexes:";
	for (int i =0; i < graph.vexNum; i++)
	{
		cin >> graph.adjList[i].vertex;
		graph.adjList[i].firstarc = nullptr;
	}

	cout<< "input the information of" << graph.arcNum  << "arcs:";
	int h1, h2;
	ArcNode* temp;
	for (int i = 0; i < graph.arcNum; i++)
	{
		cin >> h1 >> h2;
		temp = new ArcNode;
		temp->adjvex = h2;
		temp->next = graph.adjList[h1].firstarc;
		graph.adjList[h1].firstarc = temp;

		temp = new ArcNode;
		temp->adjvex = h1;
		temp->next = graph.adjList[h2].firstarc;
		graph.adjList[h2].firstarc = temp;


	}
}


void PritnGraph( ALGraph & graph ){
	for(int i = 0; i < graph.vexNum; i++)
	{
		
		ArcNode* p = graph.adjList[i];
		while(p)
		{
			cout << p->vertex<<ends;
			p
		}
	}
}


