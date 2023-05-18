#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

namespace NS_BFS_ALGO {

    template <typename T>
    class Node{
    private:
        T value;
        Node<T>* next;
    public: 
        Node(T value,  Node<T>* next);
        Node(T value);
        friend class LinkedList;
    };

     template <typename T>
    class Iterator {
    private:
        Node<T>* current;
    public:
        Iterator ();
        Iterator(Node<T>* node);
        Iterator(const Iterator &other);

        T& operator*() const;

        Iterator& operator++();

        bool hasNext();

    };

    template <typename T>
    class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
    public:
        void add(T value);
        Iterator<T> begin();
        friend class Iterator<T>; 
    };


    

    template <typename T>
    inline Iterator<T>::Iterator() : current(nullptr) {}

    template <typename T>
    inline Iterator<T>::Iterator(Node<T>* node) : current(node) {}

    template <typename T>
    inline Iterator<T>::Iterator(const Iterator &other) : current(other.current) {}

    template <typename T>
    inline T& Iterator<T>::operator*() const {
        return current->value;
    }

    template <typename T>
    inline Iterator<T>& Iterator<T>::operator++() {
        current = current->next;
        return *this;
    }

    template <typename T>
    inline bool Iterator<T>::hasNext() {
        return current->next != nullptr;
    }
  

    template <typename T>
    inline Node<T>::Node(T value, Node<T>* next) : value(value), next(next) {}

    template <typename T>
    inline Node<T>::Node(T value) : value(value), next(nullptr) {}

    template <typename T>
    inline void LinkedList<T>::add(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    template <typename T>
    inline Iterator<T> LinkedList<T>::begin() {
        Iterator<T> it(head);
        return it;
    }
   
}

#endif