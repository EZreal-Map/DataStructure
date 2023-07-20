#include <iostream>
#include "SeqList.h"

using namespace std;


int main(){
	SeqList<int> mylist({1,2,3,4,5});
	mylist.display();
    // 获取元素
	cout << "获取元素：" << mylist.get(3) << endl << endl;
	// 插入元素
	mylist.insert(2, 100);
	mylist.display(); 
	// 删除元素
	mylist.del(5);
	mylist.display();
}