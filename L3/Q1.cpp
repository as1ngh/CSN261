#include<bits/stdc++.h>
using namespace std;
enum Color {RED, BLACK};
struct Node{
  int data;
  Node* left;
  Node* right;
  Node* parent;
  int height;
  bool color;
  Node(int data)
    {
       this->data = data;
       left = right = parent = NULL;
       this->color = RED;
    }
};

Node* BSTInsert(Node* root, Node *pt){
    if (root == NULL)
       return pt;
    if (pt->data < root->data){
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data){
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }
    return root;
}



void rotateLeft(Node * &root, Node *&pt){
    Node *parentRight = pt->right;
    pt->right = parentRight->left;
    if (pt->right != NULL)
        pt->right->parent = pt;
    parentRight->parent = pt->parent;
    if (pt->parent == NULL)
        root = parentRight;
    else if (pt == pt->parent->left)
        pt->parent->left = parentRight;
    else
        pt->parent->right = parentRight;
    parentRight->left = pt;
    pt->parent = parentRight;
}

void rotateRight(Node * &root, Node *&pt){
    Node *parentLeft = pt->left;
    pt->left = parentLeft->right;
    if (pt->left != NULL)
        pt->left->parent = pt;
    parentLeft->parent = pt->parent;
    if (pt->parent == NULL)
        root = parentLeft;
    else if (pt == pt->parent->left)
        pt->parent->left = parentLeft;
    else
        pt->parent->right = parentLeft;
    parentLeft->right = pt;
    pt->parent = parentLeft;
}

void insertREDBLACK(Node * &root, int data){
    Node *pt = new Node(data);
    root = BSTInsert(root, pt);
    Node *parentNode = NULL;
    Node *grandNode = NULL;
    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)){
        parentNode = pt->parent;
        grandNode = pt->parent->parent;
        if (parentNode == grandNode->left){
            Node *uncle_pt = grandNode->right;
            if (uncle_pt != NULL && uncle_pt->color == RED){
                grandNode->color = RED;
                parentNode->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grandNode;
            }
            else{
                if (pt == parentNode->right){
                    rotateLeft(root, parentNode);
                    pt = parentNode;
                    parentNode = pt->parent;
                }
                rotateRight(root, grandNode);
                swap(parentNode->color, grandNode->color);
                pt = parentNode;
            }
        }
        else{
            Node *uncle_pt = grandNode->left;
            if ((uncle_pt != NULL) && (uncle_pt->color == RED)){
                grandNode->color = RED;
                parentNode->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grandNode;
            }
            else{
                if (pt == parentNode->left){
                    rotateRight(root, parentNode);
                    pt = parentNode;
                    parentNode = pt->parent;
                }
                rotateLeft(root, grandNode);
                swap(parentNode->color, grandNode->color);
                pt = parentNode;
            }
        }
    }
    root->color = BLACK;
}
vector<int>inorder;
int height;
int h(Node *root){
  if(root==0)
    return 0;
  int temp=max(h(root->left),h(root->right));
  return temp+1;
}
Node * BuildFromInorder(int start,int end){
  if(start>end){
     return 0;
  }
  int mid=(start+end)/2;
  Node*root=new Node(inorder[mid]);
  root->left=BuildFromInorder(start,mid-1);
  root->right=BuildFromInorder(mid+1,end);
  return root;
}


void fillinorder(Node*root){
   if(root==0)
     return;
   fillinorder(root->left);
   inorder.push_back(root->data);
   fillinorder(root->right);
   return;
}

void print(Node * root){
  if(root==0){
     return;
  }
  print(root->left);
   cout<<root->data<<endl;
  print(root->right);
  return;
}
void printtree(Node*root,int pos,bool temp){
  if(root==0)
    return;
  for(int i=0;i<pos;i++)
    cout<<"\t";
  cout<<root->data<<" ";
  if(temp)
    cout<<root->color<<endl;
  else
    cout<<height-pos<<endl;
  printtree(root->left,pos+1,temp);
  printtree(root->right,pos+1,temp);
}
Node* createAVL(Node*rootBST){
   inorder.clear();
   fillinorder(rootBST);
   Node*root=BuildFromInorder(0,inorder.size()-1);
   return root;
}
int main(){
     Node*rootBST=0;
     Node*rootREDBLACK=0;
     Node*rootAVL=0;
     bool temp=true;
     while(temp){
        cout<<"ENTER CHOICE:"<<endl;
        cout<<"1:INSERTION IN BST AND RED BLACK TREE:"<<endl;
        cout<<"2:CREATE AVL FROM INORDER:"<<endl;
        cout<<"3:PRINT IN ORDER OF BST AVL AND RED BLACK TREE:"<<endl;
        cout<<"4:LEVEL PRINT OF ALL:"<<endl;
        cout<<"-1:EXIT:"<<endl;
        int choice;
        cin>>choice;
        if(choice==1){
           int data;
           cout<<"DATA:";
           cin>>data;
           rootBST=BSTInsert(rootBST,new Node(data));
           insertREDBLACK(rootREDBLACK,data);
           rootAVL=createAVL(rootBST);
        }
        if(choice==2){
          cout<<"TREE CREATED.."<<endl;
        }
        if(choice==3){
          cout<<"BST"<<endl;
          print(rootBST);
          cout<<endl;
          cout<<"AVL"<<endl;
          print(rootAVL);
          cout<<endl;
          cout<<"RED BLACK"<<endl;
          print(rootREDBLACK);
          cout<<endl;
        }
        if(choice==4){
          cout<<"BST"<<endl;
          height=h(rootBST);
          printtree(rootBST,0,false);
          cout<<endl;
          cout<<"AVL"<<endl;
          height=h(rootAVL);
          printtree(rootAVL,0,false);
          cout<<endl;
          cout<<"RED BLACK"<<endl;
          printtree(rootREDBLACK,0,true);
          cout<<endl;
        }
        if(choice==-1){
          temp=false;
        }
     }
}
