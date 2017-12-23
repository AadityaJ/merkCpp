/*
TODO:
1) write tests properly
2) Diagnose inequalities
*/
#include <iostream>
#include <vector>
#include "merkle.h"
using namespace std;
int hashF(int a,int b){return a+b;}
void test1(){
    std::vector<int> v,v1;
    v1.push_back(100);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    merkelTree<int>mt(v.size(),hashF);
    merkelTree<int>mt2(v1.size(),hashF);
    mt.createTree(v);
    mt.printData();
    cout<<endl;
    mt.printTree();
    mt2.createTree(v1);
    cout<<mt.checkEq(mt2);
}
/*void test1(){
    cout<<"starting "
}
void init(){
    cout<<""
}*/
int main(int argc, char const *argv[]) {
    init();
    test1();
    return 0;
}
