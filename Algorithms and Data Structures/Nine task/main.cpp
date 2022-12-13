#include <iostream>
#include "vector"
using namespace std;
struct Path{
    int len;
    string path="";
};
void Deikstra(vector<vector<int>>* graph, vector<int> used,int len, vector<Path>* path){
    if(used.size() == 5)
    {
        int outPoint = used[used.size()-1];
        auto array = (*graph)[outPoint];
        len+=array[0];
        used.push_back(0);
        Path* p = new Path;
        p->len = len;

        string path_h = "";
        for (int i = 0; i < 6; ++i) {
            path_h+=(to_string(used[i]));
            if(i!=5) path_h+=" -> ";
        }
        p->path = path_h;
        path->push_back(*p);
        return;
    }
    int outPoint = used[used.size()-1];
    auto array = (*graph)[outPoint];
    for (int i = 0; i < 5; ++i) {
        bool propusk = false;
        for (int j = 0; j < used.size(); ++j) {
            if(used[j] == i)
            {propusk=true;break;}
        }
        if(array[i] != 0 && !propusk)
        {
            auto add = used;
            add.push_back(i);
            Deikstra(graph,add,len+array[i],path);
        }
    }
}

int main() {
    vector<vector<int>>graph;
    vector<int> l0 = {0,5,3,4,4};
    vector<int> l1 = {5,0,3,5,6};
    vector<int> l2 = {3,3,0,4,7};
    vector<int> l3 = {4,5,4,0,7};
    vector<int> l4 = {4,6,7,7,0};
    graph.push_back(l0);
    graph.push_back(l1);
    graph.push_back(l2);
    graph.push_back(l3);
    graph.push_back(l4);
    vector<Path> paths;

    Deikstra(&graph,vector<int> {0},0,&paths);
    std::cout << "Hello, World! This is 9-th lab work! So..." << std::endl;
    int minLen = 99999;

    for (int i = 0; i < paths.size(); ++i) {
        if(paths[i].len < minLen) minLen = paths[i].len;
    }
    for (int i = 0; i < paths.size(); ++i) {
        if(paths[i].len == minLen)
            cout << "Path: " << paths[i].path << "  Summary len of path: " << paths[i].len << endl;
    }

    graph.clear();
    return 0;
}
