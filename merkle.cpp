#include <iostream>
#include <vector>
#include <utility>
#include "merkle.h"
using namespace std;
int hashFi(int a,int b){return a+b;}
int hashFib(int a,int b){return a-b;}
float hashFf(float a,float b){return a+b;}
int hashF1(int a){return a/10;}
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
    cout<<(mt1==mt3)<<endl;
    cout<<endl;
}
void test4(){
    cout<<"*************************Test 4*************************\n";
    std::vector<int> v1,v2;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(51);
    merkelTree<int>mt1(v1.size(),hashFi);
    mt1.createTree(v1);
    merkelTree<int>mt2(v2.size(),hashFi);
    mt2.createTree(v2);
    pair<int,int> pAns=mt1.issueRes(mt2);
    cout<<pAns.first<<" "<<pAns.second<<endl;
    cout<<endl;
}
void test5(){
    cout<<"*************************Test 5*************************\n";
    std::vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    merkelTree<int> mt(v1.size(),hashFi,hashF1);
    mt.createTree(v1);
    mt.printTree();
}
void test6(){
    cout<<"*************************Test 6*************************\n";
    std::vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    merkelTree<int> mt1(v1.size(),hashFi,hashF1);
    merkelTree<int> mt2(v1.size(),hashFib);
    cout<<mt1.checkHashF(mt2)<<endl;
}
void init(){
    cout<<"Build done. Starting tests.\n";
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}
int main(int argc, char const *argv[]) {
    init();
    return 0;
}
