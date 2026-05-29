#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int value;
    Node(int val = 0) : left(nullptr), right(nullptr), value(val){}
};

class Tree{
private:
    int uPoint;
    int checkHeight(Node* node){
        if(node == nullptr)return 0;
        int leftHeight = checkHeight(node->left);
        if(leftHeight == -1)return -1;
        int rightHeight = checkHeight(node->right);
        if(rightHeight == -1)return -1;
        if(abs(leftHeight - rightHeight) > 1){
            uPoint = node->value;
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }
public:
    void free(Node* node){
        if(node == nullptr)return;
        free(node->left);
        free(node->right);
        delete node;
    }
    bool isBalance(Node* node){
        uPoint = -1;
        return checkHeight(node) != -1;
    }
    Node* insert(Node* current, int digit){
        if(current == nullptr){
            return new Node(digit);
        }
        if(digit <= current->value){
            current->left = insert(current->left, digit);
        }
        else if(digit > current->value){
            current->right = insert(current->right, digit);
        }
        return current;
    }

    void levelorder(Node* root){
        if(root == nullptr)return;
        queue<Node*> q;
        cout << root->value;
        if(root->left != nullptr)q.push(root->left);
        if(root->right != nullptr)q.push(root->right);

        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            cout << "," << cur->value;

            if(cur->left != nullptr)
                q.push(cur->left);
            if(cur->right != nullptr)
                q.push(cur->right);
        }

    }
    int unbalancePoint(){
        return uPoint;
    }

};

int main(){
    fstream File("hw3_input.txt", ios::in);
    if(!File)return 0;
    int T;
    File >> T;
    File.ignore();
    string line;
    while (T--)
    {
        getline(File, line);
        std::replace(line.begin(), line.end(), ',', ' ');
        vector<int> vec;
        stringstream ss(line);
        int num;
        while(ss >> num){
            vec.push_back(num);
        }

        Node* root = nullptr;
        Tree tree;
        for(int x : vec){
            root = tree.insert(root, x);
        }

        if(tree.isBalance(root)){
            cout << "BALANCED\n";
        }
        else{
            cout << "UNBALANCED:" << tree.unbalancePoint() << "\n";
        }
         cout << "LEVEL-ORDER:";
        tree.levelorder(root);
        cout << "\n";
        
        tree.free(root);
    }
    
}
