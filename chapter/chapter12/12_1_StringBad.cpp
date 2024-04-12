//
// Created by zkc on 2024/3/27.
//
#include "stringbad.h"
#include <iostream>
#include <cstring>

int StringBad::number_strings = 0; //静态的对象成员是单独存储的
StringBad::StringBad(const char *s) {
    len = strlen(s);
//    new 开辟出的内存空间返回的是首字母的地址
    str = new char[len + 1];
    strcpy(str,s);
    number_strings ++;
    cout << number_strings << ":\"" << str << ".\"" << endl;
}

StringBad::StringBad() {
    len =4;
    str = new char[4];
    strcpy(str,"c++");
    number_strings ++;
    cout << number_strings << ":\"" << str << ".\"" << endl;
}

StringBad::StringBad(const StringBad &st){
    len = st.len;
    str = new char[len+1];
    strcpy(str,st.str);
    number_strings++;
}

StringBad &StringBad::operator=(const StringBad &st) {
    if (this == &st){

        return *this;
    }
    delete [] str;
    len = st.len;
    str = new char[len+1];
    strcpy(str,st.str);
//    number_strings++;

    return *this;
}





StringBad::~StringBad() {
    cout << "\"" << str << "\""  << " object delete " << number_strings << " left " << endl;
    number_strings --;
    delete  []str;

}

ostream  &operator<<(ostream&os,const StringBad &st){
    os << st.str;
    return os;
}