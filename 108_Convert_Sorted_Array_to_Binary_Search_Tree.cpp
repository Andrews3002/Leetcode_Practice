#include<iostream>
using namespace std;

struct BTNode{
    int data;

    BTNode * left;
    BTNode * right;
    BTNode * parent;
};

void printBST(BTNode * root){
    
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

