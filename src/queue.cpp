#include "queue.hpp"

    /**
     * @brief Constructor por defecto
     */
    template<typename TData> Queue<TData>::Queue()
        : m_front(nullptr)
        , m_rear(nullptr)
        , m_size(0)
    {
    }

    /**
     * @brief Destructor: libera todos los nodos de la cola
     */
    template<typename TData> Queue<TData>::~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    /**
     * @brief Inserta un elemento al final de la cola
     *
     * @param value Valor a insertar
     */
    template<typename TData> void Queue<TData>::enqueue(const TData& value)
    {
        Node* newNode = new Node(value);
        if (isEmpty())
        {
            m_front = m_rear = newNode;
        }
        else
        {
            m_rear->next = newNode;
            m_rear = newNode;
        }
        ++m_size;
    }

    /**
     * @brief Elimina el primer elemento de la cola
     *
     * @throws std::underflow_error si la cola está vacía
     */
    template<typename TData> void Queue<TData>::dequeue()
    {
        if(isEmpty())
        {
            throw std::underflow_error("Queue is empty");
        }
        Node* temp = m_front;
        m_front = m_front->next;
        if(m_front==nullptr){
            m_rear=nullptr;
        }
        delete temp;
        --m_size;
    }

    /**
     * @brief Devuelve el primer elemento sin eliminarlo
     *
     * @return TData Primer valor en la cola
     * @throws std::underflow_error si la cola está vacía
     */
    template<typename TData> TData Queue<TData>::front() const
    {
        Node* temp = m_front;
        if (temp != nullptr)
        {
            return temp->data;
        }
        throw std::underflow_error("Queue is empty");
    }

    /**
     * @brief Verifica si la cola está vacía
     *
     * @return true si no hay elementos
     * @return false si hay al menos un elemento
     */
    template<typename TData> bool Queue<TData>::isEmpty() const
    {
        return m_size == 0;
    }

    /**
     * @brief Devuelve la cantidad de elementos en la cola
     *
     * @return size_t tamaño de la cola
     */
    template<typename TData> size_t Queue<TData>::getSize() const
    {
        return m_size;
    }

    /**
     * @brief Imprime los elementos de la cola
     */
    template<typename TData> void Queue<TData>::print() const
    {
        Node* temp = m_front;
        while (temp != nullptr)
        {
            std::cout << temp->data << ", ";
            temp = temp->next;
        }
    }

