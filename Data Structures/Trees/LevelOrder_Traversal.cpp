#include <bits/stdc++.h>
#include <queue>
using namespace std;


class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};


class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }


    void levelOrder(Node * root) {
        if (root == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* current = q.front();
            cout << current->data << " ";
            q.pop();

            if (current->left != nullptr){
                q.push(current->left);
            }

            if (current->right != nullptr){
                q.push(current->right);
            }
        }
    }

}; //End of Solution