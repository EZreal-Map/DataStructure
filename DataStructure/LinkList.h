#pragma once
#include <iostream>
using namespace std;

//����ࣨclass Node������
template<typename Elemtype>
class Node {
public:
    Elemtype data;        // �������
    Node<Elemtype>* next; // ����һ��ָ��Node�������͵�ָ��

    Node() :next(nullptr) {} //����ͷ����ʱ��û�в�������Ҫһ��dataΪ�յĹ��캯��
    Node(Elemtype data) :data(data), next(nullptr) {} // Node�Ĺ��캯��
};

//�������ࣨclass LinkList������
template<typename Elemtype>
class LinkList {
private:
    Node<Elemtype>* head;
public:
    // Elemtype���캯�� 
    // �����ǲ���ͷ����LinkList�ṹ
    // LinkList() :head(nullptr) {} 
    // ��ͷ����LinkList�ṹ
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
    // 1�����������
    void append(Elemtype value);

    // 2.1������Ĳ���
    void insert(int num, Elemtype value);

    //2.2�� ��������Ĳ��룬ĩλ���� ��1����������� append����һ�� (��ɾ��)
    void insert(Elemtype value);

    // 3.1�������ɾ��
    void remove(int num);

    // 3.2�����������ĩλɾ��
    void remove();
    // 4��������� �����operator[]����
    Elemtype& operator[](int num);

    // 5���������ʾ
    void display();
};


// 1�����������
template<typename Elemtype>
void LinkList<Elemtype>::append(Elemtype value) {
    Node<Elemtype>* newNode = new Node<Elemtype>(value);
    Node<Elemtype>* ptr = head;
    while (ptr->next != nullptr) {
        // ����ʹ��(*ptr).next������⣬
        // �Ȱ�ָ������ã��õ�Node��Ȼ��ȡ��Node.next
        ptr = ptr->next; // ǰ��
    }
    // �ҵ�ptr->next Ϊnullptr�󣬾����ҵ������ĩβ
    ptr->next = newNode;
}

// 2.1������Ĳ���
template<typename Elemtype>
void LinkList<Elemtype>::insert(int num, Elemtype value) {
    Node<Elemtype>* ptr = head;
    for (int i = 0; i < num - 1; ++i) {
        ptr = ptr->next;
        if (ptr->next == nullptr) // ��鳬���߽磬�ڵ�����������һ��Ԫ��
        {
            break;
        }
    }
    Node<Elemtype>* temp = ptr->next;
    ptr->next = new Node<Elemtype>(value);
    ptr = ptr->next;
    ptr->next = temp;
}

//2.2�� ��������Ĳ��룬ĩλ���� ��1����������� append����һ�� (��ɾ��)
template<typename Elemtype>
void LinkList<Elemtype>::insert(Elemtype value) {
    Node<Elemtype>* ptr = head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = new Node<Elemtype>(value);
}

// 3.1�������ɾ��
template<typename Elemtype>
void LinkList<Elemtype>::remove(int num) {
    Node<Elemtype>* ptr = head;
    for (int i = 0; i < num - 1; ++i) {
        ptr = ptr->next;
        if (ptr == nullptr) // ��鳬���߽�
        {
            cout << "ɾ������ĵ�[" << num << "]��Ԫ��ʧ�ܣ�����һ����[" << i << "]��Ԫ��" << endl;
            return;
        }
    }
    Node<Elemtype>* temp = ptr->next;
    ptr->next = temp->next;
    delete(temp); // ����������Ҫɾ����Node�����Node
}

// 3.2�����������ĩλɾ��
// ���������ֻɾ���˽ڵ㱾����û�и��µ����ڶ����ڵ��nextָ�롣
// �����������ڶ����ڵ���Ȼָ��ɾ����ĩλ�ڵ㣬�����޷���ȷ��������
// �ұ�ɾ���Ľڵ��ڴ�û�б��ͷš� 
// ��Ȼͨ�� while (ptr->next != nullptr) �ҵ�ĩβ��
// ��ʱptr�뵼���ڶ���Node.next��ָ����ͬ�ĵ�ַ��2�ݿ�����
template<typename Elemtype>
void LinkList<Elemtype>::remove() {
    Node<Elemtype>* ptr = head;
    Node<Elemtype>* prev = nullptr;
    while (ptr->next != nullptr) {
        prev = ptr; // ���Ӽ�¼��һ�����
        ptr = ptr->next;
    }

    // ����ptrָ��ĩλ�ڵ�,prevָ�����ڶ����ڵ�
    if (prev != nullptr) {
        delete(prev->next);
        prev->next = nullptr;
    }
    else {
        // �������Ϊ�ջ�ֻ��һ���ڵ�
        // ɾ��ͷ���
        // delete head->next;
        // head->next = nullptr;
    }
}

// 4��������� �����operator[]����
template<typename Elemtype>
Elemtype& LinkList<Elemtype>::operator[](int num) {
    Node<Elemtype>* ptr = head;
    for (int i = 0; i < num; ++i) {
        ptr = ptr->next;
    }
    return ptr->data;
}

// 5���������ʾ
template<typename Elemtype>
void LinkList<Elemtype>::display() {
    Node<Elemtype>* ptr = head;
    int i = 1;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
        cout << "������ĵ�[" << i << "]��Ԫ��Ϊ��" << ptr->data << endl;
        ++i;
    }
    cout << endl;
}