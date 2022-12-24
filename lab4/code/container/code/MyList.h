//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_MYLIST_H
#define LAB4_MYLIST_H

#include <memory>
#include "../../ships/code/TShip.h"

template<class T>
class MyList {
private:
    class Node {
        friend class MyList;
    private:
        std::unique_ptr<T> Data_;
        Node* Next_;
    public:
        Node() : Data_(), Next_(nullptr) { }
        Node(T&& data): Data_(std::make_unique<T>(std::move(data))), Next_(nullptr) { }
        Node(T&& data, Node* next) : Data_(std::make_unique<T>(std::move(data))) , Next_(next) { }
        T& operator *() const{ return *Data_; }
    };

public:
    class iterator {
        friend class MyList;
    private:
        Node* Data_;
    public:
        iterator(Node* data) : Data_(data) { }
        iterator& operator ++() {
            Data_ = Data_->Next_;
            return *this;
    }
        T& operator *() const { return *(Data_->Data_); }
        bool operator != (const iterator& other) { return Data_ != other.Data_; }
        bool operator == (const iterator& other) { return Data_ == other.Data_; }
    };

private:
    int Size_;
    Node* Head_;
    Node* Tail_;
    void Clear(){
        while (Head_) {
            Node* next = Head_->Next_;
            delete Head_;
            Head_ = next;
        }
        Size_ = 0;
    }

public:
    MyList() : Size_(0), Head_(new Node()), Tail_(Head_) { }
    ~MyList(){
        Clear();
    }
    MyList(MyList&& other) : Size_(other.Size_), Head_(other.Head_), Tail_(other.Tail_) {
        other.Size_ = 0;
        other.Head_ = nullptr;
        other.Tail_ = nullptr;
    }
    MyList& operator =(MyList&& other){
        Clear();
        std::swap(Head_, other.Head_);
        std::swap(Tail_, other.Tail_);
        std::swap(Size_, other.Size_);
        return *this;
    }
    bool operator ==(const MyList& other) const {
        if (Size_ != other.size())
            return false;
        auto it_o = other.begin();
        auto it_me = begin();
        while (it_me != end()) {
            if (!(*it_o == *it_me))
                return false;
            ++it_o;
            ++it_me;
        }
        return true;
    }
    int size() const {
        return Size_;
    }
    iterator begin() const {
        return MyList<T>::iterator(Head_);
    }
    iterator end() const {
        return MyList<T>::iterator(Tail_);
    }
    void insert(T&& what, iterator beforeWho) {
        ++Size_;
        Node* nw = new Node(std::move(what), beforeWho.Data_->Next_);
        if (Tail_ == beforeWho.Data_)
            Tail_ = nw;
        beforeWho.Data_->Next_ = nw;
        std::swap(nw->Data_, beforeWho.Data_->Data_);
    }//iterator will look at new Node
    void erase(iterator who){
        --Size_;
        Node* toDelete = who.Data_->Next_;
        if (toDelete == Tail_)
            Tail_ = who.Data_;
        who.Data_->Next_ = toDelete->Next_;
        std::swap(who.Data_->Data_, toDelete->Data_);
        delete toDelete;
    } //iterator will look at next Node
    const T& getById(int id) const {
        if (id < 0 || id >= Size_) {
            std::string ex = "Bad id = " + std::to_string(id) + " in range [0, " + std::to_string(Size_) + ")";
            throw ex;
        }
        for (const auto& item : *this)
            if (id-- == 0)
                return item;
        throw "228";
    }

    T& getById(int id) {
        if (id < 0 || id >= Size_) {
            std::string ex = "Bad id = " + std::to_string(id) + " in range [0, " + std::to_string(Size_) + ")";
            throw ex;
        }
        for (auto& item : *this)
            if (id-- == 0)
                return item;
        throw "228";
    }
};

#endif //LAB4_MYLIST_H
