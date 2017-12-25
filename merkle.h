/*
TODO: 1) Add more advance maths operations (=,+)
*/
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
template <typename T>
class merkelTree{
    std::vector<T> treeH;
    int size;
public:
    typedef T (*hash_)(T,T);
    typedef T (*bhash_)(T);
    hash_ myhash;
    bhash_ basehash;
    merkelTree(int sz,T hashF(T,T), T bhashF(T)){
        this->basehash=bhashF;
        this->myhash=hashF;
        this->size=sz;
        this->treeH=std::vector<T>((sz*2));
        for(int i=1;i<(sz*2);i++) treeH[i]=1;
    }
    merkelTree(int sz,T hashF(T,T)){
        this->basehash=NULL;
        this->myhash=hashF;
        this->size=sz;
        this->treeH=std::vector<T>((sz*2));
        for(int i=1;i<(sz*2);i++) treeH[i]=1;
    }
    void createTree(std::vector<T> &data);
    void printData();
    void printTree();
    bool checkEq(const merkelTree<T> &mT);
    pair<int,T> issueRes(const merkelTree<T> &mT);
    bool checkHashF(const merkelTree<T> &mT);
    bool operator==(const merkelTree<T> &mT);
};
template <typename T>
void merkelTree<T>::createTree(vector<T> &data){
    int j=0;
    if(this->basehash){
        for(int i=data.size();j!=data.size();i++,j++){
            treeH[i]=this->basehash(data[j]);
        }
    }else{
        for(int i=data.size();j!=data.size();i++,j++){
            treeH[i]=data[j];
        }
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
template <typename T>
pair<int,T> merkelTree<T>::issueRes(const merkelTree<T> &mT){
    if(this->checkEq(mT)){
        return make_pair(-1,NULL);
    }
    int currIndex=1;
    while(currIndex<(2*this->size)){
        if(this->treeH[currIndex]!=mT.treeH[currIndex]){
        }else if(this->treeH[currIndex+1]!=mT.treeH[currIndex]){
            currIndex++;
        }
        currIndex*=2;
    }
    return make_pair(currIndex/2,treeH[(currIndex)/2]);
}
template <typename T>
bool merkelTree<T>::checkHashF(const merkelTree<T> &mT){
    return this->myhash==mT.myhash;
}
template <typename T>
bool merkelTree<T>::operator==(const merkelTree<T> &mT){
    return this->checkEq(mT);
}
