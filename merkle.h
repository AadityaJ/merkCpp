#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class merkelTree{
    std::vector<T> treeH;
    int size;
public:
    typedef T (*hash_)(T,T);
    hash_ myhash;
    merkelTree(int sz,T hashF(T,T)){
        this->myhash=hashF;
        this->size=sz;
        this->treeH=std::vector<T>((sz*2));
        for(int i=1;i<(sz*2);i++) treeH[i]=1;
    }
    void createTree(std::vector<T> &data);
    void printData();
    void printTree();
    bool checkEq(const merkelTree<T> &mT);
};
template <typename T>
void merkelTree<T>::createTree(vector<T> &data){
    int j=0;
    for(int i=data.size();j!=data.size();i++,j++){
        treeH[i]=data[j];
    }
    for(int i=data.size()-1;i>=1;i--){
        treeH[i]=this->myhash(treeH[i*2],treeH[(i*2)+1]);
    }
}
template <typename T>
void merkelTree<T>::printData(){
    for(int i=1;i<(2*this->size);i++) cout<<treeH[i]<<" ";
    cout<<endl;
}
template <typename T>
void merkelTree<T>::printTree(){
    // BFS strategy for printing. O(n).
        int x=1,mult=1;
        while(x!=(2*this->size)){
            int sz=mult;
            mult*=2;
            for(int i=0;i<sz && x!=(2*this->size);i++,x++){
                cout<<treeH[x]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
}
template <typename T>
bool merkelTree<T>::checkEq(const merkelTree<T> &mT){
    if(this->size!=mT.size){
        return 0;
    }
    return this->treeH[1]==mT.treeH[1];
}
