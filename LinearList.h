#ifndef MAIN_CPP_LINEARLIST_H
#define MAIN_CPP_LINEARLIST_H

#include <iostream>

template <typename Type>
class LinearList {  //a[0]存数据
    Type* a;
    int current_length;
    int space;
    void doubleSpace();

public:
    explicit LinearList(int initSpace=10);
    ~LinearList();
    LinearList(const LinearList &linearList);
    void insert(int,const Type&);
    void remove(int);
    Type& visit(int)const;
    void clear(){current_length=0;}
    int length() const {return current_length;}
    int search( const Type & );
    void traverse() const;
    Type& operator[](int index);

};

template<typename Type>
LinearList<Type>::LinearList(int initSpace) {
    a=new Type [initSpace];
    space=initSpace;
    current_length=0;
}

template<typename Type>
LinearList<Type>::~LinearList() {
    delete []a;
    current_length=0;
}

template<typename Type>
LinearList<Type>::LinearList(const LinearList &linearList) {
    space=linearList.space;
    a=new Type [space];
    current_length=linearList.length();
    for (int i = 0; i < current_length; ++i) {
        a[i]=linearList.a[i];
    }
}

template<typename Type>
void LinearList<Type>::doubleSpace() {
    Type* temp=a;
    space*=2;
    a=new Type [space];
    for (int i = 0; i < current_length; ++i) {
        a[i]=temp[i];
    }
    delete []temp;
}

template<typename Type>
void LinearList<Type>::insert(int index,const Type & data) {
    if(current_length==space) doubleSpace();
    for (int i=current_length;i>index;--i){
        a[i]=a[i-1];
    }
    a[index]=data;
    ++current_length;
}

template<typename Type>
void LinearList<Type>::remove(int index) {
    for (int i=index;i<current_length-1;++i){
        a[i]=a[i+1];
    }
    --current_length;
}

template<typename Type>
Type& LinearList<Type>::visit(int index)const{
    return a[index];
}

template<typename Type>
int LinearList<Type>::search(const Type &data) {
    if(space==current_length) doubleSpace();
    a[current_length]=data;
    int i=0;
    while(a[i]!=data) ++i;
    if(i==current_length) i=-1;
    return i;
}

template<typename Type>
void LinearList<Type>::traverse()const{
    for (int i = 0; i < current_length; ++i) {
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
}

template<typename Type>
Type &LinearList<Type>::operator[](int index) {
    if(index<0||index>=current_length) throw std::exception();
    return a[index];
}

#endif //MAIN_CPP_LINEARLIST_H
