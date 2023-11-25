#include<iostream>
using namespace std;

struct BTNode{
    int data;

    BTNode * left;
    BTNode * right;
    BTNode * parent;
};

struct Node{
    BTNode node;
    Node *next;
};

struct Queue{
    Node *front;
    Node *end;
};

Queue * initializeQ(){
    Queue *q = new Queue;
    q->front = NULL;
    q->end = NULL;
    return q;
}

void enqueue(Queue *q, BTNode *node){
    if(q->front == NULL){
        Node *newnode = new Node;
        newnode->node = node;
        newnode->next = NULL;
        q->front = newnode;
        q->end->node->dat = value;
        return;
    }
    else{
        Node *newnode = new Node;
        newnode->data = value;
        newnode->next = NULL;
        q->end->next = newnode;
        q->end = newnode;
        return;
    }
}

int dequeue(Queue *q){
    if (q->front == q->end){
        int val = q->front->data;
        q->front = NULL;
        q->end = NULL;
        return val;
    }
    else{
        int val = q->front->data;
        q->front = q->front->next;
        return val;
    }
}

void printBST(BTNode * root){
    Queue *q1 = initializeQ();
    Queue *q2 = initializeQ();

    if((root->left != NULL) && (root->right != NULL)){
        enqueue(q1, root->left->data);
        enqueue(q1, root->right->data);
    }



    
}

BTNode * initializeBST(int value){
    BTNode * newnode = new BTNode;

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;

    return newnode;
}

void insertIntoBSt(BTNode * root, int value){
    cout << endl;
    if (value < root->data){
        if(root->left == NULL){
            root->left = initializeBST(value);
            root->left->parent = root;
            return;
        }
        else{
            insertIntoBSt(root->left, value);
        }
    }

    if (value > root->data){
        if (root->right == NULL){
            root->right = initializeBST(value);
            root->right->parent = root;
            return;
        }
        else{
            insertIntoBSt(root->right, value);
        }
    }

    return;
}

BTNode * sortedArrayToBST(int nums[]){
    int length = sizeof(nums)+1;

    int mid = nums[(length/2)-1];

    BTNode * root = initializeBST(nums[mid]);

    for (int i = 0; i < length; i++){
        if (i == mid){
            continue;
        }
        else{
            insertIntoBSt(root, nums[i]);
        }
        
    }

    return root;
}

int main(){

    // int arr[5] = {1,2,3,4,5};

    // BTNode * root = sortedArrayToBST(arr);
    
    // cout << "root: " << root->data << endl;
    // cout << "l: " << root->left->data << "    " << "r: " << root->right->data << endl;
    // cout << "lr: " << root->left->right->data << "    " << "rr: " << root->right->right->data << endl;

    cout << "Hello World" << endl;

    return 0;
}

