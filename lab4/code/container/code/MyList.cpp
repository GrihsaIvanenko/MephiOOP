//
// Created by grigorijivanenko on 13.12.22.
//

#include "MyList.h"
#include "../../ships/code/TWarShip.h"

template class MyList<TWarShip>;

template<class T>
MyList<T>::Node::Node()
    : Data_()
    , Next_(nullptr)
{ }

template<class T>
MyList<T>::Node::Node(const T& data)
        : Data_(std::make_unique<T>(data))
        , Next_(nullptr)
{ }

template<class T>
MyList<T>::Node::Node(const T& data, Node* next)
        : Data_(std::make_unique<T>(data))
        , Next_(next)
{ }


template<class T>
T& MyList<T>::Node::operator *() const {
    return *Data_;
}

/////////////////////////////////////////////////////////////////

template<class T>
MyList<T>::iterator::iterator(Node* data)
    : Data_(data)
{ }

template<class T>
typename MyList<T>::iterator& MyList<T>::iterator::operator ++() {
    Data_ = Data_->Next_;
    return *this;
}

template<class T>
T& MyList<T>::iterator::operator *() const {
    return *(Data_->Data_);
}

template<class T>
bool MyList<T>::iterator::operator == (const MyList<T>::iterator& other) {
    return Data_ == other.Data_;
}

template<class T>
bool MyList<T>::iterator::operator != (const MyList<T>::iterator& other) {
    return Data_ != other.Data_;
}

/////////////////////////////////////////////////////////////////

template<class T>
void MyList<T>::Clear() {
    while (Head_) {
        Node* next = Head_->Next_;
        delete Head_;
        Head_ = next;
    }
    Size_ = 0;
}

template<class T>
MyList<T>::MyList()
    : Size_(0)
    , Head_(new Node())
    , Tail_(Head_)
{ }

template<class T>
MyList<T>::~MyList() {
    Clear();
}

template<class T>
MyList<T>::MyList(const MyList<T>& other)
        : Size_(0)
        , Head_(new Node())
        , Tail_(Head_)
{
    for (const auto& elem : other)
        insert(elem, end());
}

template<class T>
MyList<T>::MyList(MyList&& other)
    : Size_(other.Size_)
    , Head_(other.Head_)
    , Tail_(other.Tail_)
{
    other.Size_ = 0;
    other.Head_ = nullptr;
    other.Tail_ = nullptr;
}


template<class T>
MyList<T>& MyList<T>::operator =(const MyList& other) {
    Clear();
    Tail_ = Head_ = new Node();
    for (const auto& elem : other)
        insert(elem, end());
    return *this;
}

template<class T>
MyList<T>& MyList<T>::operator =(MyList&& other) {
    std::swap(Head_, other.Head_);
    std::swap(Tail_, other.Tail_);
    std::swap(Size_, other.Size_);
    return *this;
}

template<class T>
int MyList<T>::size() const {
    return Size_;
}

template<class T>
typename MyList<T>::iterator MyList<T>::begin() const {
    return MyList<T>::iterator(Head_);
}

template<class T>
typename MyList<T>::iterator MyList<T>::end() const {
    return MyList<T>::iterator(Tail_);
}

template<class T>
void MyList<T>::insert(const T& what,  typename MyList<T>::iterator beforeWho) {
    ++Size_;
    Node* nw = new Node(what, beforeWho.Data_->Next_);
    if (Tail_ == beforeWho.Data_)
        Tail_ = nw;
    beforeWho.Data_->Next_ = nw;
    std::swap(nw->Data_, beforeWho.Data_->Data_);
}

template<class T>
void MyList<T>::erase(MyList<T>::iterator who) {
    --Size_;
    Node* toDelete = who.Data_->Next_;
    if (toDelete == Tail_)
        Tail_ = who.Data_;
    who.Data_->Next_ = toDelete->Next_;
    std::swap(who.Data_->Data_, toDelete->Data_);
    delete toDelete;
}
