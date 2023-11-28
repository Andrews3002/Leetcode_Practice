#include<iostream>
using namespace std;

struct BTNode{
    int data;

    BTNode * left;
    BTNode * right;
    BTNode * parent;
};

struct Node{
    BTNode *node;
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
        q->end = q->front;
        return;
    }
    else{
        Node *newnode = new Node;
        newnode->node = node;
        newnode->next = NULL;
        q->end->next = newnode;
        q->end = newnode;
        return;
    }
}

void dequeue(Queue *q){
    if (q->front == NULL){
        return;
    }
    if (q->front == q->end){
        int val = q->front->node->data;
        cout << val << " ";
        q->front = NULL;
        q->end = NULL;
        return;
    }
    else{
        int val = q->front->node->data;
        Node *temp = q->front;
        q->front = q->front->next;
        delete(temp);
        cout << val << " ";
        return;
    }
}

void printBST(BTNode * root){
    Queue *q1 = initializeQ();
    Queue *q2 = initializeQ();

    enqueue(q1,root);

    BTNode *clone = root;

    while ((q1->front != NULL) || (q2->front != NULL)){
        while(q1->front != NULL){
            if(q1->front->node->left != NULL){
                enqueue(q2,q1->front->node->left);
            }
            if(q1->front->node->right != NULL){
                enqueue(q2,q1->front->node->right);
            }
            dequeue(q1);
        }

        cout << endl;

        while(q2->front != NULL){
            if(q2->front->node->left != NULL){
                enqueue(q1,q2->front->node->left);
            }
            if(q2->front->node->right != NULL){
                enqueue(q1,q2->front->node->right);
            }
            dequeue(q2);
        }
        cout << endl;
    }

    return;  
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

    int arr[9] = {1,3,4,7,9};

    BTNode * root = sortedArrayToBST(arr);

    printBST(root);

    return 0;
}

