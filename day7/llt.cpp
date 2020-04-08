#include <iostream>

template <class T>
class LinkedList {

    struct Node {
        T data;
        Node* next;
    };

public:
    LinkedList();
    ~LinkedList();

    void pushBack(T data);
    void pushFront(T data);
    void print();
    void reverse();

    void removeIndex(size_t index);
    void removeHead();
    void removeTail();

private:
    Node* createNode(int value);
    Node* m_pHead;
    uint8_t m_length;
};

template <class T>
LinkedList<T>::LinkedList()
    : m_pHead(nullptr)
    , m_length(0)
{
}

template <class T>
LinkedList<T>::~LinkedList()
{
    while (m_pHead != nullptr) {
        Node* pCurrent = m_pHead;
        m_pHead = m_pHead->next;
        delete pCurrent;
    }
}

template <class T>
void LinkedList<T>::pushBack(T data)
{
    if (m_pHead == nullptr) {
        m_pHead = createNode(data);
        return;
    }

    Node* pCurrent = m_pHead;

    while (pCurrent->next != nullptr) {
        pCurrent = pCurrent->next;
    }

    pCurrent->next = createNode(data);
}

template <class T>
void LinkedList<T>::pushFront(T data)
{
    if (m_pHead == nullptr) {
        m_pHead = createNode(data);
        return;
    }

    Node* pCurrent = m_pHead;
    m_pHead = createNode(data);
    m_pHead->next = pCurrent;
}

template <class T>
void LinkedList<T>::print()
{
    Node* pCurrent = m_pHead;

    while (pCurrent) {
        std::cout << +pCurrent->data << " ";
        pCurrent = pCurrent->next;
    }
    std::cout << "\n";
}

template <class T>
void LinkedList<T>::reverse()
{

    Node* pCurrent = m_pHead;
    Node* prev = nullptr;
    Node* next = nullptr;

    while (pCurrent != nullptr) {
        next = pCurrent->next;
        pCurrent->next = prev;
        prev = pCurrent;
        pCurrent = next;
    }
    m_pHead = prev;
}

template <class T>
void LinkedList<T>::removeIndex(size_t index)
{
    Node* pCurrent = m_pHead;

    if (pCurrent == nullptr) {
        return;
    }

    if (index == 0) {
        removeHead();
        return;
    }

    if (index == m_length - 1) {
        removeTail();
        return;
    }

    for (uint8_t i = 1; i < index; i++) {
        pCurrent = pCurrent->next;
    }

    Node* pCurrentDelete = pCurrent->next;
    pCurrent->next = pCurrent->next->next;
    delete pCurrentDelete;
    m_length--;
}

template <class T>
void LinkedList<T>::removeHead()
{
    if (m_pHead == nullptr) {
        return;
    }

    Node* pCurrent = m_pHead;
    m_pHead = pCurrent->next;
    delete pCurrent;
    m_length--;
}

template <class T>
void LinkedList<T>::removeTail()
{
    if (m_pHead == nullptr) {
        return;
    }

    Node* pCurrent = m_pHead;

    while (pCurrent->next->next != nullptr) {
        pCurrent = pCurrent->next;
    }

    Node* pCurrentDelete = pCurrent->next;
    pCurrent->next = pCurrent->next->next;
    delete pCurrentDelete;
    m_length--;
}

template <class T>
class LinkedList<T>::Node* LinkedList<T>::createNode(int value) {
    Node* node = new Node();
    node->data = value;
    m_length++;
    return node;
}

int
main()
{
    LinkedList<uint8_t> ll;

    for (size_t i = 0; i < 200; i++) {
        ll.pushBack(i);
    }
    ll.removeIndex(2);
    ll.reverse();
    ll.print();

    return 0;
}
