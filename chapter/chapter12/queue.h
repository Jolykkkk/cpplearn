//
// Created by zkc on 2024/4/22.
//

#ifndef _QUEUE_H
#define _QUEUE_H


#include<iostream>


using namespace std;

class Customer{
private:
    //存储顾客信息
    long arrive; //到达时间
    int processtime; //处理时间

public:
    Customer(){arrive = processtime = 0 ;}
    void set(long when);
    long when() const{return arrive;} //几点开始操作
    int ptime() const{return processtime;} //操作时间

};

typedef Customer Item;

class Queue{
private:
    enum{Q_SIZE = 10};
    struct Node{
        Item item;
        struct Node* next;
    };
    Node* front; //队头指针
    Node* rear; //队尾指针
    int items;  //当前元素数量
    const int qsize; //队列空间  常量，队列一旦初始化其空间不能被修改
public:
    //构造函数
    Queue(int qs=Q_SIZE); //
    ~Queue();
    //判空
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;         //队列元素
    bool enqueue(const Item &item); //入队
    bool dequeue(Item &item);       //出队
};
#endif //CPP_TEST1_QUEUE_H
