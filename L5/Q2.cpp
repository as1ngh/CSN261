#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long int ll;

struct edge{
    int src;
    int dest;
    int weight;
};

struct Set{
    int rank;
    int parent;
};

int find(Set * s, int i){
    if(s[i].parent!=i){
        s[i].parent=find(s,s[i].parent);
    }
    return s[i].parent;
}
void Union(Set * s,int v1,int v2){
    int v1_root=find(s,v1);
    int v2_root=find(s,v2);
    if(s[v1_root].rank<s[v2_root].rank){
        s[v1_root].parent=s[v2_root].parent;
    }
    else if(s[v1_root].rank>s[v2_root].rank){
        s[v2_root].parent=s[v1_root].parent;
    }
    else{
        s[v1_root].parent=s[v2_root].parent;
        s[v2_root].rank++;
    }
}

bool comparator(edge a,edge b){
    return a.weight<b.weight;
}


void kruskal(edge * input,int n,int e){
    sort(input,input+e,comparator);
    edge * output=new edge[n-1];
    Set * s=new Set[n];
    for(int i=0;i<n;i++){
        s[i].rank=0;
        s[i].parent=i;
    }
    int counter=0,i=0;
    while(counter!=n-1){
        edge currEdge=input[i];
        int srcParent=find(s,currEdge.src);
        int desParent=find(s,currEdge.dest);
        if(srcParent!=desParent){
            output[counter]=currEdge;
            Union(s,srcParent,desParent);
            counter++;
        }
        i++;
    }

    ofstream file;
    file.open("Q2Kruskal.dot");

    if(file.is_open())
    {
        file << "graph MST { " << endl;
        file << "   graph [ dpi = 1200 ] ; " << endl;
        for(int i=0;i<n-1;i++){
        file << "   " << (char)(output[i].src+'A')
             << " -- " << (char)(output[i].dest+'A')
             <<"[label = " << output[i].weight << "];"
             << endl;
        }

        file << " } " << endl;
        file.close();
    }

    for(int i=0;i<n-1;i++){
        cout<<(char)(output[i].src+'A')<<
        "---"<<(char)(output[i].dest+'A')<<"---"<<output[i].weight<<endl;
    }
}



int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ifstream file;
    file.open("2019_CSN_261_L5_P2.csv");
    int n,e=0;
    edge * input=new edge[100000];
    map<int,int>cnt;
    string temp;
    while(getline(file , temp))
    {
        char ch1 , ch2 , com;
        int wt;
        stringstream s(temp);
        s >> ch1;
        s >> com;
        s >> ch2;
        s >> com;
        s >> wt;
        input[e].src=ch1-'A';
        input[e].dest=ch2-'A';
        cnt[input[e].src]=1;
        cnt[input[e].dest]=1;
        input[e].weight=wt;
        e++;
    }
    file.close();
    kruskal(input, cnt.size(), e);


    return 0;
}
/*
   SAMPLE INPUT
   6 8
   A B 4
   A C 4
   B C 2
   C D 3
   C F 2
   C E 4
   D E 3
   F E 3
*/
