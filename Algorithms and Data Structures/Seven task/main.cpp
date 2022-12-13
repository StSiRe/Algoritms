#include <iostream>

struct ListNode{
    ListNode* next;
    int value = 0;
};
void ListNodeCreate(ListNode** listNode){
    (*listNode)->next = *listNode;
}
void ListNodePush(ListNode** listNode,int value){

    ListNode* newNode = new ListNode;
    newNode->value = value;
    auto v = (*listNode)->value;
    if((*listNode)->next == (*listNode) && (*listNode)->value == 0){ // Если лист пустой
        *listNode = newNode;
        (*listNode)->next = newNode;
    }
    else{
        auto test = *listNode;
        while(test->next != *listNode) test = test->next;//Прокручиваем список до конца

        auto prevAddr = test;
        auto nextAddr = *listNode;
        newNode->next = nextAddr;
        prevAddr->next = newNode;
    }
}
void ListNodeDeleteByCount(ListNode** listNode, int counts){
    auto currentAddr = *listNode;
    auto prevAddr = *listNode;
    for (int i = 1; i < counts; ++i) {
        prevAddr = currentAddr;
        currentAddr = currentAddr->next;
    }
    prevAddr->next = currentAddr->next;
    *listNode = currentAddr->next;
    delete(currentAddr);
}
void ListNodePrint(ListNode * listNode){

    std::cout << "Current list: " << (listNode)->value <<" ";
    auto curr = (listNode)->next;
    while(curr != listNode){
        std::cout << curr->value << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}
int ListNodeLen(ListNode * listNode){
    if(listNode == listNode->next) return 0;
    int result = 1;
    auto curr = listNode->next;
    while(curr != listNode){
        result++;
        curr = curr->next;
    }
    return result;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    for (int i = 2; i <= 20; ++i) {
        ListNode* listNode = new ListNode;
        ListNodeCreate(&listNode);
        for (int j = 1; j <= 20; ++j) {
            ListNodePush(&listNode,j);
        }
        std::cout << "Starting task with param " << i << "..." << std::endl;
        while(ListNodeLen(listNode) >= 1){
            ListNodeDeleteByCount(&listNode,i);
        }
        ListNodePrint(listNode);
        std::cout<< std::endl;
        delete(listNode);
    }
    return 0;
}
