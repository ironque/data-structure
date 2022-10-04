#ifndef MAIN_CPP_LINKLIST_H
#define MAIN_CPP_LINKLIST_H
#include <iostream>
template <typename Type>
class LinkList {
    struct Node{
        Type data;
        Node* next;
        Node():next(nullptr){};
        explicit Node(const Type& data,Node* next= nullptr):data(data),next(next){};
        ~Node()= default;
    };
    Node* head;
    int current_length;
    Node* visit(int);
public:
    LinkList();
    ~LinkList();
    LinkList(const LinkList &linkList);
    void insert(int,const Type&);
    void remove(int);
    void clear();
    int length() const {return current_length;}
    int search( const Type & );
    void traverse() const;
};

template<typename Type>
LinkList<Type>::LinkList() {
    head=new Node;  //头结点不放数据
    current_length=0;
}

template<typename Type>
LinkList<Type>::~LinkList() {
    clear();
    delete head;
}

template<typename Type>
void LinkList<Type>::clear() {
    Node* p=head->next,*q;
    while(p!= nullptr){
        q=p->next;
        delete p;
        p=q;
    }
    head->next= nullptr;
    current_length=0;
}

template<typename Type>
LinkList<Type>::LinkList(const LinkList& linkList) {
    Node* copy=linkList.head->next,*itself=head;
    current_length=linkList.current_length;
    while(copy!= nullptr){
        itself->next=new Node(copy->data);
        itself=itself->next;
        copy=copy->next;
    }
}

template<typename Type>
void LinkList<Type>::insert(int index,const Type & data) {
    if (index>current_length||index<0) throw std::exception();
    Node * begin= visit(index);
    begin->next=new Node(data,begin->next);
    ++current_length;
}

template<typename Type>
void LinkList<Type>::remove(int index) {
    if (index>=current_length||index<0) throw std::exception();
    Node *begin= visit(index),*temp=begin->next;
    begin->next=temp->next;
    delete temp;
    --current_length;
}

template<typename Type>
typename LinkList<Type>::Node *LinkList<Type>::visit(int index) {
//    if (index>=current_length||index<0) throw std::exception();
    Node* ans=head;
    for (int i = 0; i < index; ++i) {
        ans=ans->next;
    }
    return ans;     //ans->next指向a[index]
}

template<typename Type>
int LinkList<Type>::search(const Type &data) {
    int index=0;
    Node* p=head->next;
    while (p->data!=data&&p!= nullptr){
        p=p->next;
        ++index;
    }
    if(p== nullptr) return -1;
    else return index;
}

template<typename Type>
void LinkList<Type>::traverse()const{
    Node* p=head->next;
    while (p!= nullptr){
        std::cout<<p->data<<" ";
        p=p->next;
    }
    std::cout<<std::endl;
}

#endif //MAIN_CPP_LINKLIST_H
