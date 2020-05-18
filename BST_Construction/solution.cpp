#include <bits/stdc++.h>
using namespace std;

class BST {
    private:
        int data;
        BST *left = NULL;
        BST *right = NULL;

    public:
        BST(): data(0), left(NULL), right(NULL){}
        
        BST (const int tempdata){
            data = tempdata;
            left = right = NULL;
        }

        BST *insert(const int data){
            BST *currentNode = this;
            while(true){
                if (data < currentNode->data){
                    if (currentNode->left == NULL)
                        currentNode->left = new BST(data);
                    else 
                        currentNode = currentNode->left;
                }
                else {
                    if (currentNode->right == NULL)
                        currentNode->right = new BST(data);
                    else    
                        currentNode = currentNode->right;
                }
            }
            return this;
        }
};