/*
TODO:
2) Diagnose inequalities
*/
#include <iostream>
#include <vector>
#include "merkle.h"
using namespace std;
int hashFi(int a,int b){return a+b;}
float hashFf(float a,float b){return a+b;}
void test1(){
    cout<<"*************************Test 1*************************\n";
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    merkelTree<int>mt(v.size(),hashFi);
    mt.createTree(v);
    mt.printData();
    mt.printTree();
}
void test2(){
    cout<<"*************************Test 2*************************\n";
    std::vector<float> v;
    v.push_back(10.1);
    v.push_back(2.12);
    v.push_back(3.1);
    v.push_back(4.3);
    merkelTree<float>mt(v.size(),hashFf);
    mt.createTree(v);
    mt.printData();
    mt.printTree();
}
void test3(){
    cout<<"*************************Test 3*************************\n";
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    merkelTree<int>mt1(v.size(),hashFi);
    merkelTree<int>mt2(v.size(),hashFi);
    mt1.createTree(v);
    mt2.createTree(v);
    cout<<mt1.checkEq(mt2)<<endl;
    v.push_back(50);
    merkelTree<int>mt3(v.size(),hashFi);
    mt3.createTree(v);
    cout<<mt1.checkEq(mt3)<<endl;
}
void init(){
    cout<<"Build done. Starting tests.\n";
    test1();
    test2();
    test3();
}
int main(int argc, char const *argv[]) {
    init();
    return 0;
}
