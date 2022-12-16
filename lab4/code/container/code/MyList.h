//
// Created by grigorijivanenko on 13.12.22.
//

#ifndef LAB4_MYLIST_H
#define LAB4_MYLIST_H

#include <memory>

template<class T>
class MyList {
private:
    int Size_;

    class Node {
        friend class MyList;
    private:
        std::unique_ptr<T> Data_;
        Node* Next_;
    public:
        Node();
        Node(const T& data);
        Node(const T& data, Node* next);
        T& operator *() const;
    };
    Node* Head_;
    Node* Tail_;

    void Clear();

public:
    MyList();
    ~MyList();

    MyList(const MyList& other);
    MyList(MyList&& other);
    MyList& operator =(const MyList& other);
    MyList& operator =(MyList&& other);

    class iterator {
        friend class MyList;
    private:
        Node* Data_;
    public:
        iterator(Node* data);
        iterator& operator ++();
        T& operator *() const;
        bool operator != (const iterator& other);
        bool operator == (const iterator& other);
    };

    int size() const;
    iterator begin() const;
    iterator end() const;
    void insert(const T& what, iterator beforeWho);//iterator will look at new Node
    void erase(iterator what); //iterator will look at next Node
};

#endif //LAB4_MYLIST_H
