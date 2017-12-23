#include <iostream>
#include <vector>
using namespace std;
class merkelTree{
    std::vector<int> treeH;
    int size;
public:
    typedef int (*hash_)(int,int);
    hash_ myhash;
    merkelTree(int sz,int hashF(int,int)){
        this->myhash=hashF;
        this->size=sz;
        this->treeH=std::vector<int>((sz*2));
        for(int i=1;i<(sz*2);i++) treeH[i]=1;
    }
    void createTree(std::vector<int> &data);
    void printData();
    void printTree();
};
void merkelTree::createTree(vector<int> &data){
    int j=0;
    for(int i=data.size();j!=data.size();i++,j++){
        treeH[i]=data[j];
    }
    for(int i=data.size()-1;i>=1;i--){
        treeH[i]=this->myhash(treeH[i*2],treeH[(i*2)+1]);
    }
}
void merkelTree::printData(){
    for(int i=1;i<(2*this->size);i++) cout<<treeH[i]<<" ";
}
void merkelTree::printTree(){
    // overall number of nodes is 2*size-1
    
}
