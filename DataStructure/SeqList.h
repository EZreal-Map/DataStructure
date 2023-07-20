// SeqList.cpp
#ifndef SEQLIST_H
#define SEQLIST_H
#include <iostream>
using namespace std;
const int MAXSIZE = 100;

template<typename ElemType>
class SeqList {
private:
	ElemType datas[MAXSIZE]; /*���� �洢����Ԫ��*/
	int length;				 /*���Ա�ǰ����*/
public:
	/*���캯��*/
	SeqList(std::initializer_list<ElemType> datas);
	/*1����ȡԪ��*/
	ElemType get(int num);

	/*2������Ԫ��*/
	void insert(int num, ElemType data);

	/*3�� ɾ��Ԫ��*/
	void del(int num);

	/*4�� ������ʾԪ��*/
	void display();
};


template<typename ElemType>
SeqList<ElemType>::SeqList(std::initializer_list<ElemType> datas) {
	/*std::initializer_list �� C++ �е�һ��ģ���࣬
		���ṩ��һ�ַ���ķ�ʽ��������ʼ���б������ڹ��캯�����������д���һ��ֵ��*/
	this->length = 0;
	for (ElemType data : datas) {
		this->datas[this->length++] = data;
	}
}
/*1����ȡԪ��*/
template<typename ElemType>
ElemType SeqList<ElemType>::get(int num) {
	if (num<1 || num>this->length) {
		cout << "�������Ա�" << endl;
		return 0;
	}
	else {
		return this->datas[num - 1];
	}

}

/*2������Ԫ��*/
template<typename ElemType>
void SeqList<ElemType>::insert(int num, ElemType data) {
	if (num<1 || num>this->length + 1) {
		cout << "�������Ա�" << endl;
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

/*3�� ɾ��Ԫ��*/
template<typename ElemType>
void SeqList<ElemType>::del(int num) {
	if (num<1 || num>this->length) {
		cout << "�������Ա�" << endl;
	}
	else {
		--(this->length);
		--num;
		for (int i = num; i < this->length; ++i) {
			this->datas[i] = this->datas[i + 1];
		}
	}
}

/*4�� ������ʾԪ��*/
template<typename ElemType>
void SeqList<ElemType>::display() {
	for (int i = 0; i < this->length; ++i) {
		cout << "˳�����Ա���Ϊ[" << this->length << "], ���е�[" << i + 1 << "]��Ԫ��Ϊ��" << datas[i] << endl;
	}
	cout << endl;
}
#endif // SEQLIST_H