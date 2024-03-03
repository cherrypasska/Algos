#include <iostream>

using namespace std;

struct Trunk{
    Trunk *prev;
    string str;
    Trunk(Trunk *prev, string str){
        this->prev = prev;
        this->str = str;
    }
};
class Node{
private:
    int key;
    Node* right;
    Node* left;
    int height;
public:
    Node(){
        key = 0;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
    int Height(Node* root){
        if (root == nullptr) return 0;
        return root->height;
    }
    void setbalance(Node* root){
        if (root != nullptr){
            root->height = max(Height(root->left), Height(root->right)) + 1;
        }
    }
    int Balance(Node* root) {
        if(root == nullptr){
            return 0;
        }
        return Height(root->left) - Height(root->right);
    }
    Node* R_rot(Node* root){
        Node* leftnode = root->left;
        Node* leftrightnode = leftnode->right;
        leftnode->right = root;
        root->left = leftrightnode;
        setbalance(root);
        setbalance(leftnode);
        return leftnode;
    }
    Node* L_rot(Node* root){
        Node* rightnode = root->right;
        Node* rightleftnode = rightnode->left;
        rightnode->left = root;
        root->right = rightleftnode;
        setbalance(root);
        setbalance(rightnode);
        return rightnode;
    }
    Node* insert(Node* root, int value){
        if (root == nullptr){
            root = new Node;
            root->key = value;
        }
        else{
            if (value > root->key){
                root->right = insert(root->right, value);
            }
            else if (value < root->key){
                root->left = insert(root->left, value);
            }
            else{
                cout << "Element already exists\n";
            }
            setbalance(root);
            if(Height(root->left) - Height(root->right) > 1){
                if (value < root->left->key){
                    return R_rot(root);
                }else{
                    root->left = L_rot(root->left);
                    return R_rot(root);
                }
            }
            if(Height(root->right) - Height(root->left) > 1){
                if(value > root->right->key){
                    return L_rot(root);
                }
                else{
                    root->right = R_rot(root->right);
                    return L_rot(root);
                }
            }
        }
        return root;
    }
    Node* minValueNode(Node* node){
        Node* current = node;
        while(current->left != nullptr){
            current = current->left;
        }
        return current;
    }
    Node* deleteNode(Node* root, int key){
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } 
                else {
                    *root = *temp;
                }
                delete temp;
            } 
            else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr) {
            return root;
        }

        setbalance(root);

        int balance = Balance(root);
        if (balance > 1) {
            if (Balance(root->left) >= 0) {
                return R_rot(root);
            } 
            else {
                root->left = L_rot(root->left);
                return R_rot(root);
            }
        }
        if (balance < -1) {
            if (Balance(root->right) <= 0) {
                return L_rot(root);
            } 
            else {
                root->right = R_rot(root->right);
                return L_rot(root);
            }
        }
        printTree(root, nullptr, false);
        return root;
    }
    Node* search(Node* root, int key){
        if(root == nullptr || root->key == key){
            return root;
        }
        if(key < root->key){
            return search(root->left, key);
        }
        return search(root->right, key);
    }
    void postOrderTravers(Node* root){
        if(root){
            postOrderTravers(root->left);
            postOrderTravers(root->right);
            printf("%d ", root->key);
        }
    }
    void showTrunks(Trunk *p){
        if(p == nullptr){
            return;
        }
        showTrunks(p->prev);
        cout << p->str;
    }
    void printTree(Node* root, Trunk *prev, bool isLeft){
        if(root == nullptr){
            return;
        }
        string prev_str = "    ";
        Trunk *trunk = new Trunk(prev, prev_str);
    
        printTree(root->right, trunk, true);
        if (!prev){
                trunk->str = "";
            }
            else if(isLeft){
                trunk->str = "---";
                prev_str = "   |";
            }
            else{
                trunk->str = "---";
                prev->str = prev_str;
            }
            showTrunks(trunk);
            cout << " " << root->key << endl;
            if(prev){
                prev->str = prev_str;
            }
        trunk->str = "   |";
        printTree(root->left, trunk, false);
    }
    void cycleDeleteOddNodes(Node* &root) {
        bool oddExists = true;

        while (oddExists && root != nullptr) {
            oddExists = false;
            root = recursiveCycleDeleteOddNodes(root, oddExists);
            if (root != nullptr) {
                printTree(root, nullptr, false);
            }
        }
    }
    Node* recursiveCycleDeleteOddNodes(Node* root, bool &oddExists) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->key % 2 != 0) {
            oddExists = true;
            cout << "Deleting odd node: " << root->key << endl;
            return deleteNode(root, root->key);
        }
        root->left = recursiveCycleDeleteOddNodes(root->left, oddExists);
        root->right = recursiveCycleDeleteOddNodes(root->right, oddExists);
        setbalance(root);
        int balance = Balance(root);
        if (balance > 1) {
            if (Balance(root->left) >= 0) {
                return R_rot(root);
            } else {
                root->left = L_rot(root->left);
                return R_rot(root);
            }
        }
        if (balance < -1) {
            if (Balance(root->right) <= 0) {
                return L_rot(root);
            } else {
                root->right = R_rot(root->right);
                return L_rot(root);
            }
        }

        return root;
    }

};

int main(){
    int n = 0;
    Node* root = nullptr;
    Node tree;
    do{
        cout << "Enter 1 if you want to add a new element\n";
        cout << "Enter 2 if you want to delete an element\n";
        cout << "Enter 3 if you want to find an element\n";
        cout << "Enter 4 if you want to display your tree\n";
        cout << "Enter 5 if you want to output a list corresponding to vertex traversal\n";
        cout << "Enter 6 if you want to cyclically delete each odd node of the tree\n";
        cout << "Enter 7 if you want to exit the program\n";
        cin >> n;
        switch (n){
            case 1:{
                int numero;
                cout << "Enter an element\n";
                cin >> numero;
                root = tree.insert(root, numero);
                break;
            }
            case 2:{
                int numero;
                cout << "Enter an element to delete\n";
                cin >> numero;
                root = tree.deleteNode(root, numero);
                break;
            }
            case 3:{
                int numero;
                cout << "Enter an element to search\n";
                cin >> numero;
                Node* result = tree.search(root, numero);
                if (result != nullptr) {
                    cout << "Element found\n";
                } 
                else{
                    cout << "Element not found\n";
                }
                break;
            }
            case 4:{
                tree.printTree(root, nullptr, false);
                break;
            }
            case 5:{
                tree.postOrderTravers(root);
                cout << '\n';
                break;
            }
            case 6: {
                tree.cycleDeleteOddNodes(root);
                break;
            }
            case 7:{
                cout << "End of programm \n";
                break;
            }
            default:
                break;
        }
    }while (n != 7);
    return 0;
}