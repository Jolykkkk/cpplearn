//
// Created by zkc on 2024/3/27.
//
#include <iostream>

using namespace std;

#ifndef _STRINGBAD_H
#define _STRINGBAD_H


class StringBad {
private:
    char *str;  //存放字符串的内存地址
    int len;
    static int number_strings;//所有对象共享一个number_strings  通过这个了解创建了多少个对象
public:
    StringBad(const char *s);
//    在构造函数中new 开辟内存 在析构函数的中 delete
    StringBad();
    StringBad(const StringBad &st);

    ~StringBad();
    StringBad &operator=(const StringBad &st);
    friend ostream &operator<<(ostream &os,const StringBad &st);


};


#endif //CPP_TEST1_STRINGBAD_H
