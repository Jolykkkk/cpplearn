//
// Created by zkc on 2023/12/14.
//
#include <iostream>
#include "stock.h"

int main(){
    using namespace std;
//    类的初始化
    Stock stock1 = Stock("HUBU",10,3.5);
    Stock stock2 = Stock();
    stock1.show();
    stock2.show();
//类的对象之间可以互相拷贝  但是数组不可以
    cout << "stock2 = stock1 " << endl;
    stock2 = stock1;
    stock2.show();
    cout << "Using a construct to reset an object:\n";
//可以用显示构造函数重新对类进行重构
    stock1 = Stock("wuhan",10,50.0);
    cout << "Revised stock1:\n";
    stock1.show();

    const Stock land = Stock("sova",2,1.2);
    land.show();  //会报错，因为land是常量，但是show函数没有保护常量的机制 需要在show函数后+const关键字
    return 0;

}
