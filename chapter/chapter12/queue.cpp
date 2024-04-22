//
// Created by zkc on 2024/4/22.
//
#include "queue.h"
#include <cstdlib>
////构造函数
//Queue(int qs=Q_SIZE); //
////判空
//bool isempty() const;
//bool isfull() const;
//int queuecount() const;         //队列元素
//bool enqueue(const Item &item); //入队
//bool dequeue(Item &item);
Queue::Queue(int qs):qsize(qs) {
    front = rear = nullptr;
    items = 0;

}
Queue::~Queue() {
    Node* temp;
    while (front != nullptr){
        temp = front;
        front = front ->next;
        delete temp;
    }
}

bool Queue::isempty() const {
    return  items == 0;
}

bool Queue::isfull() const {
    return items == qsize;
}

int Queue::queuecount() const {
    return items;
}

bool Queue::enqueue(const Item &item) {
    if(isfull())
        return false;
    Node *add = new Node;
    add->item = item;
    add->next = nullptr;
    items ++ ;
    //更新尾节点和头节点
    if(front == nullptr)
        front = add;
    else{
        rear->next = add;
    }
    rear = add;


    return true;
}

bool Queue::dequeue(Item &item) {
    if(isempty())
        return false;
    item = front->item;
    items--;
    Node *temp;
    temp = front;
    front = front->next;
    delete temp;

    //更新头尾节点
    if(items == 0){
        rear == nullptr;
    }
    return true;
}

void Customer::set(long when) {
    arrive = when;
    processtime = rand() % 3 + 1 ;
}
