#pragma once
#include <iostream>
using namespace std;

//结点类（class Node）声明
template<typename Elemtype>
class Node {
public:
    Elemtype data;        // 存放数据
    Node<Elemtype>* next; // 定义一个指向Node数据类型的指针

    Node() :next(nullptr) {} //创建头结点的时候，没有参数，需要一个data为空的构造函数
    Node(Elemtype data) :data(data), next(nullptr) {} // Node的构造函数
};

//单链表类（class LinkList）声明
template<typename Elemtype>
class LinkList {
private:
    Node<Elemtype>* head;
public:
    // Elemtype构造函数 
    // 这种是不带头结点的LinkList结构
    // LinkList() :head(nullptr) {} 
    // 带头结点的LinkList结构
    LinkList() {
        this->head = new Node<Elemtype>();
    }
    ~LinkList() {
        Node<Elemtype>* ptr = head, * temp;
        while (ptr) {
            temp = ptr;
            ptr = ptr->next;
            delete(temp);
        }
    }
    // 1、链表的增加
    void append(Elemtype value);

    // 2.1、链表的插入
    void insert(int num, Elemtype value);

    //2.2、 重载链表的插入，末位插入 和1、链表的增加 append方法一样 (可删除)
    void insert(Elemtype value);

    // 3.1、链表的删除
    void remove(int num);

    // 3.2、重载链表的末位删除
    void remove();
    // 4、链表查或改 运算符operator[]重载
    Elemtype& operator[](int num);

    // 5、链表的显示
    void display();
};


// 1、链表的增加
template<typename Elemtype>
void LinkList<Elemtype>::append(Elemtype value) {
    Node<Elemtype>* newNode = new Node<Elemtype>(value);
    Node<Elemtype>* ptr = head;
    while (ptr->next != nullptr) {
        // 这里使用(*ptr).next更好理解，
        // 先把指针解引用，得到Node，然后取得Node.next
        ptr = ptr->next; // 前进
    }
    // 找到ptr->next 为nullptr后，就是找到链表的末尾
    ptr->next = newNode;
}

// 2.1、链表的插入
template<typename Elemtype>
void LinkList<Elemtype>::insert(int num, Elemtype value) {
    Node<Elemtype>* ptr = head;
    for (int i = 0; i < num - 1; ++i) {
        ptr = ptr->next;
        if (ptr->next == nullptr) // 检查超过边界，在单链表最后插入一个元素
        {
            break;
        }
    }
    Node<Elemtype>* temp = ptr->next;
    ptr->next = new Node<Elemtype>(value);
    ptr = ptr->next;
    ptr->next = temp;
}

//2.2、 重载链表的插入，末位插入 和1、链表的增加 append方法一样 (可删除)
template<typename Elemtype>
void LinkList<Elemtype>::insert(Elemtype value) {
    Node<Elemtype>* ptr = head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = new Node<Elemtype>(value);
}

// 3.1、链表的删除
template<typename Elemtype>
void LinkList<Elemtype>::remove(int num) {
    Node<Elemtype>* ptr = head;
    for (int i = 0; i < num - 1; ++i) {
        ptr = ptr->next;
        if (ptr == nullptr) // 检查超过边界
        {
            cout << "删除链表的第[" << num << "]个元素失败，链表一共有[" << i << "]个元素" << endl;
            return;
        }
    }
    Node<Elemtype>* temp = ptr->next;
    ptr->next = temp->next;
    delete(temp); // 别忘了跳过要删除的Node后，清空Node
}

// 3.2、重载链表的末位删除
// 问题出在你只删除了节点本身，但没有更新倒数第二个节点的next指针。
// 这样，倒数第二个节点仍然指向被删除的末位节点，导致无法正确遍历链表，
// 且被删除的节点内存没有被释放。 
// 虽然通过 while (ptr->next != nullptr) 找到末尾，
// 此时ptr与导数第二个Node.next是指向相同的地址的2份拷贝。
template<typename Elemtype>
void LinkList<Elemtype>::remove() {
    Node<Elemtype>* ptr = head;
    Node<Elemtype>* prev = nullptr;
    while (ptr->next != nullptr) {
        prev = ptr; // 增加记录上一个结点
        ptr = ptr->next;
    }

    // 现在ptr指向末位节点,prev指向倒数第二个节点
    if (prev != nullptr) {
        delete(prev->next);
        prev->next = nullptr;
    }
    else {
        // 如果链表为空或只有一个节点
        // 删除头结点
        // delete head->next;
        // head->next = nullptr;
    }
}

// 4、链表查或改 运算符operator[]重载
template<typename Elemtype>
Elemtype& LinkList<Elemtype>::operator[](int num) {
    Node<Elemtype>* ptr = head;
    for (int i = 0; i < num; ++i) {
        ptr = ptr->next;
    }
    return ptr->data;
}

// 5、链表的显示
template<typename Elemtype>
void LinkList<Elemtype>::display() {
    Node<Elemtype>* ptr = head;
    int i = 1;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
        cout << "单链表的第[" << i << "]个元素为：" << ptr->data << endl;
        ++i;
    }
    cout << endl;
}