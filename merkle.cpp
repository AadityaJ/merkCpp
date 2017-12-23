#include <iostream>
#include <vector>
#include "merkle.h"
using namespace std;
int hashF(int a,int b){return a+b;}
void test1(){
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    merkelTree mt(v.size(),hashF);
    mt.createTree(v);
    mt.printData();
}
int main(int argc, char const *argv[]) {
    test1();
    return 0;
}
