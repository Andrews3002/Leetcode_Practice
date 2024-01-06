#include <iostream>

using namespace std;

struct BSTNode{
    int data;

    BSTNode * left;
    BSTNode * right;
    BSTNode * parent;
};

struct Node{
    BSTNode *node;
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

void enqueue(Queue *q, BSTNode *node){
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

void printBST(BSTNode * root){
    Queue *q1 = initializeQ();
    Queue *q2 = initializeQ();

    enqueue(q1,root);

    BSTNode *clone = root;

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

BSTNode * initializeBST(int value){
    BSTNode * newnode = new BSTNode;
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;

    return newnode;
}

void insertIntoBSt(BSTNode * root, int value){
    
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

BSTNode * sortedArrayToBST(int nums[], int length){
    int mid;

    if (length%2 == 0){
        mid = (length/2)-1;
    }
    else{
        mid = (length/2); 
    }

    BSTNode * root = initializeBST(nums[mid]);

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

        int arr[8] = {1,3,5,7,9,10,11,12};

    int length = sizeof(arr)/sizeof(int);

    BSTNode * root = sortedArrayToBST(arr,length);

    printBST(root);

    return 0;
}

