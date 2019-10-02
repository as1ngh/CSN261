#include<bits/stdc++.h>
#include "fibo_heap.h"

using namespace std;

struct Graph{
	int adj_list[26][26];
	int vertices;
	Graph(){
		for (int i = 0; i < 26; ++i){
			for (int j = 0; i < 26; ++i){
				adj_list[i][j] = 0;
			}
		}
	}
	void readFromFile(){
		ifstream file;
		file.open("2019_CSN_261_L5_P2.csv");
		if (file.is_open()){
			string temp;
			while(getline(file,temp)){
				char vertex1,vertex2,comma;
				int weight;
				stringstream s(temp);
				s >> vertex1;
				s >> comma;
				s >> vertex2;
				s >> comma;
				s >> weight;
				this->addEdge(vertex1,vertex2,weight);
			}
			file.close();
		}
	}
	void addEdge(char v1, char v2, int weight){
		adj_list[v1%65][v2%65] = weight;
		adj_list[v2%65][v1%65] = weight;
		this->vertices = countVertices();
	}
	int countVertices(){
		int initialmax = -1;
		for (int i = 0; i < 26; ++i){
			int count = 0;
			for (int j = 0; j < 26; ++j){
				if (adj_list[i][j] > 0){
					count = j+1;
				}
			}
			if (count > initialmax){
				initialmax = count;
			}
		}
		return initialmax;
	}
	void prt(){
		int vertices = countVertices();
		for (int i = 0; i < vertices; ++i){
			for (int j = i; j < vertices; ++j){
				if (adj_list[i][j] > 0){
					cout << (char)(i+65) 
					<< ',' << (char)(j+65) 
					<< ',' << adj_list[i][j] << endl;
				}	
			}
		}
	}
};
void graph_nw(vector<string>** String,Graph* mst, char* parent,char v){
	for (int i=0; i < mst->vertices; ++i){
		if ((char)(parent[i]+65) == v){
			graph_nw(String,mst,parent,(char)(i+65));
			string s = "";
			if (!String[i]->empty()){
				s += "(";
				for (auto it = String[i]->begin(); it != String[i]->end(); ++it){
					s += *it;
					if (*it != String[i]->back()){
						s+= ",";
					}
				}
				s+= ")";
			}
			s+= (char)(i+65);
			s+= ':';
			s+= to_string(mst->adj_list[i][v%65]);
			String[v%65]->push_back(s);
		}
	}
}

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

	Graph* graph = new Graph();
	graph->readFromFile();
	Heap* fibo_Heap = new Heap();
	bool* mstSet = new bool[graph->vertices];
	char* parent = new char[graph->vertices];
	for (int i = 0; i < graph->vertices; ++i){
		mstSet[i] = false;
		parent[i] = -1;
	}
	fibo_Heap->insert((char)65,0);
	for (int i = 1; i < graph->vertices; ++i){
		fibo_Heap->insert((char)(i+65),INT_MAX);
	}
	for (int i = 0; i < graph->vertices - 1; ++i){
		HeapNode* min = fibo_Heap->extractMin();
		mstSet[min->v1 % 65] = true;
		for (int i = 0; i < graph->vertices; ++i){
			HeapNode* node = fibo_Heap->find(fibo_Heap->minimum,i+65);
			if (node != nullptr && graph->adj_list[min->v1 % 65][i] != 0 && 
				mstSet[i] == false && graph->adj_list[min->v1 % 65][i] < node->key ){
				parent[i] = min->v1 % 65;
				fibo_Heap->decreaseKey(node,graph->adj_list[min->v1 % 65][i]);
			}
		}
	}
	Graph* min_tree = new Graph();
	int total_weight = 0;
	for (int i = 0; i < graph->vertices; ++i){
		int curr_weight = graph->adj_list[i][parent[i]];
		total_weight += curr_weight;
		min_tree->addEdge((char)(parent[i]+'A'), (char)(i+'A'), curr_weight);
	}
	min_tree->prt();
	cout << endl;
	cout << "Weight of the MST: " << total_weight << endl;
	vector<string>** String = new vector<string>*[min_tree->vertices];
	for (int i = 0; i < min_tree->vertices; ++i){
		String[i] = new vector<string>();
	}
	graph_nw(String,min_tree,parent,'A');
	string str = "";
	if (!String[0]->empty()){
		str += "(";
		for (auto it = String[0]->begin(); it != String[0]->end(); ++it){
			str += *it;
			if (*it != String[0]->back()){
				str+= ",";
			}
		}
		str+= ")";
	}
	str+="A;";
	ofstream file;
	file.open("Q3_graph.nw");
	if (file.is_open()){
		file << str << endl;
		file.close();
	}
	return 0;
}