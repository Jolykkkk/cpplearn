//
// Created by zkc on 2023/10/31.
//

#ifndef CPP_TEST1_STOCK_H
#define CPP_TEST1_STOCK_H

#include <iostream>
#include <string>
using namespace std;

class Stock{
private:

    std::string company;
    long shares;
    double  share_val;
    double total_val;
    void total();
   // void total(){ total_val = share_val * shares; }
public:
//    Stock(const std::string &co = "None",int share = 0,double  pr = 0.0);
    Stock(const std::string &co,int share ,double pr);
    Stock();
    void buy(long num , double price);
    void sell(long num , double price);
    void update( double price);
    void show() const;
    ~Stock();

};

inline void Stock::total(){ total_val = share_val * shares; }
#endif //CPP_TEST1_STOCK_H
