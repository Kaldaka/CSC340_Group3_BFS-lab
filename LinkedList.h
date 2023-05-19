#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

namespace NS_BFS_ALGO {

    template <class T>
    class LinkedList;

    template <class T>
    class Node;

    template <class T>
    class Iterator;

    template <class T>
    class Node{
    private:
        T* value;
        Node<T>* next;
    public: 
        Node(T* value,  Node<T>* next);
        Node(T* value);
        ~Node();
        friend class LinkedList<T>;
        friend class Iterator<T>; 
    };

    template <class T>
    class Iterator {
    private:
        Node<T>* current;
    public:
        Iterator ();
        Iterator(Node<T>* node);
        Iterator(const Iterator &other);

        T* operator*() const;
        T* operator->() const; 
        Iterator& operator++();

        bool hasNext();

    };

    template <class T>
    class LinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;
    public:
        LinkedList();
        LinkedList(const LinkedList<T>& copy);
        ~LinkedList();
        T* getFirstValue();
        int getSize();
        void add(T* value);
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
    inline T* Iterator<T>::operator*() const {
        return current->value;
    }

    template <typename T>
    inline T* Iterator<T>::operator->() const {
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
    inline Node<T>::Node(T* value, Node<T>* next) : value(value), next(next) {}

    template <typename T>
    inline Node<T>::Node(T* value) : value(value), next(nullptr) {}

    template <typename T>
    inline Node<T>::~Node() {
        delete value;
        delete next;
    }
    

    template <typename T>
    inline void LinkedList<T>::add(T* value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    template <typename T>
    inline Iterator<T> LinkedList<T>::begin() {
        Iterator<T> it(head);
        return it;
    }

    template <typename T>
    inline LinkedList<T>::LinkedList() : head(nullptr), size(0), tail(nullptr) {}

    template <typename T>
    inline LinkedList<T>::~LinkedList() {
        // Traverse the list and deallocate each node
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }

        // Set head to nullptr to indicate an empty list
        head = nullptr;
        tail = nullptr;
    }

    template <typename T>
    inline T* LinkedList<T>::getFirstValue() {
        return head->value;
    }

    template <typename T>
    inline int LinkedList<T>::getSize() {
        return size;
    }


    template <typename T>
    LinkedList<T>::LinkedList(const LinkedList<T>& copy) : head(nullptr), tail(nullptr), size(0) {
        // Iterate over the copy list and add each element to the new list
        Node<T>* currentNode = copy.head;
        while (currentNode != nullptr) {
            add(currentNode->value);
            currentNode = currentNode->next;
        }
    }

}

#endif