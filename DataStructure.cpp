#include <iostream>

using namespace std;

const int MAXSIZE = 100;

template<typename ElemType>
class SeqList {
private:
	ElemType datas[MAXSIZE]; /*数组 存储数据元素*/
	int length;				 /*线性表当前长度*/
public:
	/*构造函数*/
	SeqList(std::initializer_list<ElemType> datas) {
		/*std::initializer_list 是 C++ 中的一个模板类，
		它提供了一种方便的方式来创建初始化列表，允许在构造函数或函数参数中传递一组值。*/
		this->length = 0;
		for (ElemType data : datas) {
			this->datas[this->length++] = data;
		}
	}
	/*1、获取元素*/
	ElemType get(int num) {
		if (num<1 || num>this->length) {
			cout << "超过线性表" << endl;
			return 0;
		}
		else {
			return this->datas[num - 1];
		}

	}

	/*2、插入元素*/
	void insert(int num, ElemType data) {
		if (num<1 || num>this->length + 1) {
			cout << "超过线性表" << endl;
		}
		else {
			++(this->length);
			--num;
			for (int i = this->length; i > num; --i) {
				this->datas[i] = this->datas[i - 1];
			}
			this->datas[num] = data;
		}
	}

	/*3、 删除元素*/
	void del(int num) {
		if (num<1 || num>this->length) {
			cout << "超过线性表" << endl;
		}
		else {
			--(this->length);
			--num;
			for (int i = num; i < this->length; ++i) {
				this->datas[i] = this->datas[i + 1];
			}
		}
	}

	/*4、 遍历显示元素*/
	void display() {
		for (int i = 0; i < this->length; ++i) {
			cout << "顺序线性表长度为["<<this->length<<"], 其中第["<<i+1<<"]个元素为："<<datas[i]<<endl;
		}
		cout << endl;
	}
};

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