#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    T m_data;
    Node* m_next;

public:

    //default constructor
    Node();

    //constructor for only value
    Node(const T& other);

    //copy constructor
    Node(const Node<T>& other)=default;

    //destructor
    ~Node();

    //assignment operator
    Node<T>& operator=(const Node<T>& other)=default;

    //returns a pointer to the next node
    Node<T>* getNext() const;

    //returns a refrence to the data of the node
    T& getData();

    //returns a refrence to the data of the node
    const T& getData() const;

    //set the node that this node points to
    void setNext(Node<T>*next);
};


template<class T>
Node<T>::Node(): m_data(), m_next(nullptr)
{

}

template<class T>
Node<T>::Node(const T& other): m_data(other), m_next(nullptr)
{

}

template<class T>
Node<T>::~Node()
{

}

template<class T>
Node<T>* Node<T>::getNext() const
{
    return m_next;
}

template<class T>
T& Node<T>::getData()
{
    return m_data;
}

template<class T>
const T& Node<T>::getData() const
{
    return m_data;
}

template<class T>
void Node<T>::setNext(Node<T>*next)
{
    m_next=next;
}
#endif // NODE_H
