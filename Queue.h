#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "exception"
template<class T>
class Queue{

class Node//nested class
{
    T m_data;
    Node* m_next;

public:

    //default constructor
    Node();

    //constructor for only value
    Node(const T& other);

    //copy constructor
    Node(const Node& other)=default;

    //destructor
    ~Node();

    //assignment operator
    Node& operator=(const Node& other)=default;

    //returns a pointer to the next node
    Node* getNext() const;

    //returns a refrence to the data of the node
    T& getData();

    //returns a refrence to the data of the node
    const T& getData() const;

    //set the node that this node points to
    void setNext(Node*next);
};

    Node* m_first;
    Node* m_last;

public:

    //creates an empty queue
    explicit Queue();

    //copy constructor
    Queue(const Queue<T>& other);

    //destroies the current queue
    ~Queue();

    //operation =
    Queue<T>& operator=(const Queue<T>& other);

    //pushes the value to the end of the queue
    //throws std::bad_aloc if cannot give more memory
    void pushBack(const T& value);

    //returns the element in the front of the queue
    //throws EmptyQueue if the queue is enpty
    T& front();

    //returns the element in the front of the queue
    //throws EmptyQueue if the queue is enpty
    //for const queue
    const T& front() const;

    //removes the first element of the queue
    //throws EmptyQueue if the queue is enpty
    void popFront();

    //returns the size of the queue
    int size() const;

    //exception class in case the queue is empty
    class EmptyQueue{};

    //regular iterator
    class Iterator
    {
        Node* m_ptrToNode;
    public:
        //constructor
        Iterator(Node*ptr);

        //copy constructor
        Iterator(const Iterator& other)=default;

        //destructor
        ~Iterator()=default;

        //assignment operator
        Iterator& operator=(const Iterator& other)=default;

        /*
        note that they are defalut since we only need the pointer value
        */

        //* operator for value
        //throws InvalidOperation if tries to do it for the end
        T& operator*() const;

        //++ operator to to foward the iterator
        //throws InvalidOperation if tries to do it for the end
        Iterator& operator++();

        //comparison operator
        bool operator!=(const Iterator& other) const;

        //exception class for invalid operations on an iterator
        //like ++ of an end iterator
        class InvalidOperation{};
    };
    //const iterator
    class ConstIterator
    {
        Node* m_ptrToNode;
    public:
        //constructor
        ConstIterator(Node*ptr);

        //copy constructor
        ConstIterator(const ConstIterator& other)=default;

        //destructor
        ~ConstIterator()=default;

        //assignment operator
        ConstIterator& operator=(const ConstIterator& other)=default;

        /*
        note that they are defalut since we only need the pointer value
        */

        //* operator for value
        //throws InvalidOperation if tries to do it for the end
        const T& operator*() const;

        //++ operator to to foward the iterator
        //throws InvalidOperation if tries to do it for the end
        ConstIterator& operator++();

        //comparison operator
        bool operator!=(const ConstIterator& other) const;

        //exception class for invalid operations on an constiterator
        //like ++ of an end constiterator
        class InvalidOperation{};
    };
    //returns an iterator to the start of the queue
    Iterator begin();

    //returns an iterator to the element after the end of the queue
    Iterator end();

    //returns an iterator to the start of the queue
    ConstIterator begin() const;

        //returns an iterator to the element after the end of the queue

    ConstIterator end() const;
};


/*
 implementation of queue
*/
template<class T>
Queue<T> :: Queue(): m_first(nullptr),m_last(nullptr)
{

}

template<class T>
Queue<T>::Queue(const Queue<T>& other): m_first(nullptr),m_last(nullptr)
{
    Queue<T>temp;//temporary queue
    /*
    if pushBack fails, the queue will remain the same
    */
    for(Queue<T>::ConstIterator i=other.begin(); i!=other.end(); ++i)
    {
        temp.pushBack(*i);
    }
    m_first=temp.m_first;//updating the values
    m_last=temp.m_last;
    temp.m_first=nullptr;
    temp.m_last=nullptr;
}
template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if(this==&other)//no self assignment
    {
        return *this;
    }
    Queue<T>temp;//temporary queue
    /*
    if pushBack fails, the queue will remain the same
    */
    for(Queue<T>::ConstIterator i=other.begin(); i!=other.end(); ++i)
    {
        temp.pushBack(*i);
    }
    while(m_first!=nullptr)//deleting the value
    {
        Node*temp=m_first->getNext();
        delete m_first;
        m_first=temp;
    }
    m_first=temp.m_first;//updating the values
    m_last=temp.m_last;
    temp.m_first=nullptr;
    temp.m_last=nullptr;
    return *this;
}
template<class T>
Queue<T>::~Queue()
{
    while(m_first!=nullptr)
    {
        Node*temp=m_first->getNext();
        delete m_first;
        m_first=temp;
    }
}

template<class T>
void Queue<T>::pushBack(const T& value)
{
    Node*temp;
    try
    {
        temp=new Node(value);
    }
    catch(const std::bad_alloc& e)
    {
        throw std::bad_alloc();
    }
    if(m_first==nullptr)//queue is empty
    {
        m_first=temp;
        m_last=m_first;
        return;
    }
    //queue is not empty
    m_last->setNext(temp);
    m_last=m_last->getNext();
}

template<class T>
T& Queue<T>::front()
{
    if(m_first==nullptr)
    {
        throw Queue<T>::EmptyQueue();
    }
    return m_first->getData();
}
template<class T>
const T& Queue<T>:: front() const
{
    if(m_first==nullptr)
    {
        throw Queue<T>::EmptyQueue();
    }
    return m_first->getData();
}
template<class T>
void Queue<T>::popFront()
{
    if(m_first==nullptr)
    {
        throw Queue<T>::EmptyQueue();
    }
    Node*temp=m_first->getNext();
    delete m_first;
    m_first=temp;
    if(m_last==nullptr)//now there is one value in queue
    {
        m_last=m_first;
    }
}

template<class T>
int Queue<T>::size() const
{
    int counter=0;
    Node*temp=m_first;
    while(temp!=nullptr)
    {
        counter++;
        temp=temp->getNext();
    }
    return counter;
}

/*
  implementation of iterator
*/
template<class T>
Queue<T>::Iterator::Iterator(Node*ptr): m_ptrToNode(ptr)
{

}
template<class T>
T& Queue<T>::Iterator::operator*() const
{
    if(m_ptrToNode ==nullptr)
    {
        throw Queue<T>::Iterator::InvalidOperation();
    }
    return m_ptrToNode->getData();
}

template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if(m_ptrToNode ==nullptr)
    {
        throw Queue<T>::Iterator::InvalidOperation();
    }
    m_ptrToNode = m_ptrToNode->getNext();
    return *this;
}

template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& other) const
{
    return m_ptrToNode !=other.m_ptrToNode;
}
template<class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    return Queue<T>::Iterator(m_first);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end()
{
    if(m_first==nullptr)
    {
        return Queue<T>::Iterator(m_first);
    }
    return Queue<T>::Iterator(m_last->getNext());
}

/*
  implementation of const iterator
*/
template<class T>
Queue<T>::ConstIterator::ConstIterator(Node*ptr): m_ptrToNode(ptr)
{

}
template<class T>
const T& Queue<T>::ConstIterator::operator*() const
{
    if(m_ptrToNode ==nullptr)
    {
        throw Queue<T>::ConstIterator::InvalidOperation();
    }
    return m_ptrToNode->getData();
}

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
    if(m_ptrToNode ==nullptr)
    {
        throw Queue<T>::ConstIterator::InvalidOperation();
    }
    m_ptrToNode = m_ptrToNode->getNext();
    return *this;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& other) const
{
    return m_ptrToNode !=other.m_ptrToNode;
}
template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    return Queue<T>::ConstIterator(m_first);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    if(m_first==nullptr)
    {
        return Queue<T>::ConstIterator(m_first);
    }
    return Queue<T>::ConstIterator(m_last->getNext());
}


//the function gets a queue and a condition (object with () operator or a function for example)
//returns a queue of all the elements in the original queue that fit the condition
template<class Condition,class T>
Queue<T> filter(const Queue<T>&queue,Condition condition)
{
    Queue<T>queueToInsert;
    for(typename Queue<T>::ConstIterator i=queue.begin(); i!=queue.end(); ++i)
    {
        if(condition(*i))
        {
            queueToInsert.pushBack(*i);
        }
    }
    return queueToInsert;
}


//the function gets a queue and an operation (object with () operator or a function for example)
//changes the queue so every element went under the change of operation
template<class Operation,class T>
void transform(Queue<T>&queue,Operation operation)
{
    for(typename Queue<T>::Iterator i=queue.begin(); i!=queue.end(); ++i)
    {
        operation(*i);
    }
}





template<class T>
Queue<T>::Node::Node(): m_data(), m_next(nullptr)
{

}

template<class T>
Queue<T>::Node::Node(const T& other): m_data(other), m_next(nullptr)
{

}

template<class T>
Queue<T>::Node::~Node()
{

}

template<class T>
typename Queue<T>::Node* Queue<T>::Node::getNext() const
{
    return m_next;
}

template<class T>
T& Queue<T>::Node::getData()
{
    return m_data;
}

template<class T>
const T& Queue<T>::Node::getData() const
{
    return m_data;
}

template<class T>
void Queue<T>::Node::setNext(Node*next)
{
    m_next=next;
}


#endif // QUEUE_H
