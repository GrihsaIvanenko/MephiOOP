//
// Created by grigorijivanenko on 13.12.22.
//

#include "MyList.h"

template<class T>
MyList<T>::Node::Node()
    : Data_(nullptr)
    , Next_(nullptr)
{ }

template<class T>
MyList<T>::Node::Node(const T& data)
        : Data_(data)
        , Next_(nullptr)
{ }

template<class T>
MyList<T>::Node::Node(const T& data, Node* next)
        : Data_(data)
        , Next_(next)
{ }

template<class T>
MyList<T>::Node::~Node() {
    if (Data_)
        delete Data_;
}

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
}

template<class T>
T& MyList<T>::iterator::operator *() const {
    return *Data_;
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
MyList<T>::MyList()
    : Size_(0)
    , Head_(new Node(nullptr))
{ }

template<class T>
MyList<T>::~MyList() {
    while (Head_) {
        Node* next = Head_->GetNext();
        delete Head_;
        Head_ = next;
    }
}

template<class T>
void MyList<T>::insert(const T& what,  typename MyList<T>::iterator beforeWho) {
    ++Size_;
    Node* nw = new Node(what, beforeWho.Node_);
    beforeWho.Node_ = nw;
    swap(nw->Data_, beforeWho.Data_);

}

template<class T>
void MyList<T>::erase(MyList<T>::iterator who) {
    --Size_;
    Node* toDelete = who.Data_->Next_;
    who.Data_->Next_ = toDelete->Next_;
    swap(who.Data_->Data_, toDelete->Data_);
    delete toDelete;
}
