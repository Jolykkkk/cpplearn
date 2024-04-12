//
// Created by zkc on 2024/4/12.
//
#include <iostream>
#include <string>
#include <new>

using namespace std;

const int BUT = 512;

class JustTest{
private:
    string words;
    int number;

public:
    JustTest(const string &s ="JustTesting", int n  = 0){
        words = s;
        number = n;
        cout << words <<endl;
    }

    ~JustTest(){
        cout << words << " destroyed" << endl;
    }

    void Show()const{
        cout << words<< " , " << number << endl;
    }

};

int main(){
//    开辟内存空间
      char * buffer= new char[BUT];
      JustTest *pc1,*pc2;
//定位到刚刚开辟出的内存空间
      pc1 = new(buffer) JustTest;
//
      pc2 = new JustTest("heap1",10);
// 字符串指针若不强制进行类型转换的话 将会打印字符 而不是地址
      cout <<  "buffer:" << (void *)buffer << endl;
      cout <<  "pc2:" << pc2 << endl;
      cout <<  "pc show()" << endl;
      pc1->Show();
      pc2->Show();

      JustTest *pc3,*pc4;
      pc3 =new(buffer+sizeof (JustTest)) JustTest("Bad idea",10);
      pc4 =new JustTest("heap2",10);

      pc3->Show();
      pc4->Show();

      // pc1 和 pc3 可能会起冲突
      delete pc2;
      delete pc4;
//      delete pc1; //错误操作
      // 此时 pc1 变成了 Bad idea
      //pc1的地址 = buffer 如果此处释放了pc1 那么就不能再释放pc3
      //正常操作应该是 delete [] buffer；

      pc3->~JustTest();
      pc1->~JustTest();

      delete [] buffer;

      //
      return 0;
}
