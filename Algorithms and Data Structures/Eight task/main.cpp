#include <iostream>
#include "fstream"
#include "vector"
struct Student{
    std::string fio = "";
    int year;
    int region;
    std::string phone;
    int group;
};
struct Node{
    Student student;
    int count;
    Node* left = nullptr;
    Node* right = nullptr;
};
bool Compair(std::string a, std::string b){
    int t = a.compare(b);
    if(t >= 1) return true;
    else return false;
}
int height(Node * root){
    if (root == nullptr) return 0;
    return std::max(height(root->right)+1,height(root->left)+1);
}
int balance(Node * root){
    return height(root->right) - height(root->left);
}
void BalancedTreePush (Node** root, Student newP){
    if (*root == nullptr){
        Node *newNode = new Node();
        newNode->student = newP;
        newNode->count = 1;
        newNode->left = nullptr;
        newNode->right = nullptr;
        *root= newNode;
        return;
    }
    if (balance(*root) == 0){
        BalancedTreePush(&((*root)->right), newP);
        return;
    }
    else if (balance(*root) == 1) {
        BalancedTreePush(&((*root)->left), newP);
        return;
    }
    else{
        BalancedTreePush(&((*root)->right), newP);
        return;
    }
}
void BinaryTreePush(Node** root, Student* student){
    if(*root == nullptr){
        Node* newNode = new Node;
        newNode->student = *student;
        newNode->right = nullptr;
        newNode->left = nullptr;
        newNode->count=1;
        (*root) = newNode;
    }
    else{
        if((*root)->student.fio == student->fio) {
            (*root)->count++;
            return;
        }
        if(Compair((*root)->student.fio,student->fio)) {
//        if((*root)->student.region < student->region){
            //right
            BinaryTreePush(&((*root)->right), student);
        }
        else {
            //left
            BinaryTreePush(&((*root)->left), student);
        }
    }
}
void ReadFile(std::string fileName, Node** root,Node** bRoot)
{
    std::ifstream file(fileName);
    std::vector<Student> list;
    while(!file.eof())
    {
        Student student;
        getline(file,student.fio);
        std::string tmp = "";
        getline(file,tmp);
        student.year = std::atoi(tmp.c_str());
        getline(file,tmp);
        student.region = std::atoi(tmp.c_str());
        getline(file,student.phone);
        getline(file,tmp);
        student.group = std::atoi(tmp.c_str());
        list.push_back(student);
        BinaryTreePush(root,&student);
        BalancedTreePush(bRoot,student);
    }

}
void Print(Node** root, int l = 0){
    if(*root != nullptr){
        Print(&(*root)->right,l+1);
        for (int i = 1; i <= l*2; ++i) {
            std::cout<<"    ";
        }
        std::cout << (*root)->student.fio << std::endl;
        Print(&(*root)->left,l+1);
    }
}
int main()
{
    std::cout << "Группа 111:" << std::endl;
    Node* binaryNode = new Node;
    Node* balancedNode = new Node;
    binaryNode = nullptr;
    balancedNode = nullptr;
    ReadFile("111.txt",&binaryNode,&balancedNode);
    std::cout<< "Binary:" <<std::endl;
    Print(&binaryNode);
    std::cout<< "Balanced:" <<std::endl;
    Print(&balancedNode);
    delete(binaryNode);
    delete(balancedNode);
    std::cout<< std::endl;
    std::cout<< std::endl;


    std::cout << "Группа 112:" << std::endl;
    binaryNode = new Node;
    balancedNode = new Node;
    binaryNode = nullptr;
    balancedNode = nullptr;
    ReadFile("112.txt",&binaryNode,&balancedNode);
    std::cout<< "Binary:" <<std::endl;
    Print(&binaryNode);
    std::cout<< "Balanced:" <<std::endl;
    Print(&balancedNode);
    delete(binaryNode);
    delete(balancedNode);
    std::cout<< std::endl;
    std::cout<< std::endl;


    std::cout << "Группа 113:" << std::endl;
    binaryNode = new Node;
    balancedNode = new Node;
    binaryNode = nullptr;
    balancedNode = nullptr;
    ReadFile("113.txt",&binaryNode,&balancedNode);
    std::cout<< "Binary:" <<std::endl;
    Print(&binaryNode);
    std::cout<< "Balanced:" <<std::endl;
    Print(&balancedNode);
    delete(binaryNode);
    delete(balancedNode);
    std::cout<< std::endl;
    std::cout<< std::endl;


    std::cout << "Группа 114:" << std::endl;
    binaryNode = new Node;
    balancedNode = new Node;
    binaryNode = nullptr;
    balancedNode = nullptr;
    ReadFile("114.txt",&binaryNode,&balancedNode);
    std::cout<< "Binary:" <<std::endl;
    Print(&binaryNode);
    std::cout<< "Balanced:" <<std::endl;
    Print(&balancedNode);
    delete(binaryNode);
    delete(balancedNode);
    std::cout<< std::endl;
    std::cout<< std::endl;
    return 0;
}
