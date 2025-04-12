#include "stack.hpp"

    /**
     * @brief Constructor por defecto
     */
    template<typename TData> Stack<TData>::Stack()
        : m_top(nullptr)
        , m_size(0)
    {
    }

    /**
     * @brief Destructor: libera todos los nodos
     */
    template<typename TData> Stack<TData>::~Stack()
    {
        while(!isEmpty()){
            pop();
        }
        throw std::underflow_error("Stack is empty");
    }

    /**
     * @brief Agrega un elemento en la cima de la pila
     *
     * @param value Valor a insertar
     */
    template<typename TData> void Stack<TData>::push(const TData& value)
    {
        Node* newNode = new Node(value, m_top);
        m_top = newNode;
        ++m_size;
    }

    /**
     * @brief Elimina el elemento superior de la pila
     *
     * @throws std::underflow_error si la pila está vacía
     */
    template<typename TData> void Stack<TData>::pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack is empty");
        }
        Node* temp = m_top;
        m_top = m_top->next;
        delete temp;
        --m_size;
    }

    /**
     * @brief Devuelve una referencia al elemento superior (mutable)
     *
     * @return TData& referencia al valor
     * @throws std::underflow_error si la pila está vacía
     */
    template<typename TData> TData& Stack<TData>::top()
    {
        if(isEmpty())
        {
            throw std::underflow_error("Stack is empty");
        }
        return m_top->data;
    }

    /**
     * @brief Devuelve una referencia constante al elemento superior
     *
     * @return const TData& referencia constante al valor
     * @throws std::underflow_error si la pila está vacía
     */
    template<typename TData> const TData& Stack<TData>::top() const
    {
        if(isEmpty())
        {
            throw std::underflow_error("Stack is empty");
        }
        return m_top->data;
    }

    /**
     * @brief Verifica si la pila está vacía
     *
     * @return true si no hay elementos
     * @return false si hay al menos un elemento
     */
    template<typename TData> bool Stack<TData>::isEmpty() const
    {
        return m_top == nullptr;
    }

    /**
     * @brief Devuelve la cantidad de elementos en la pila
     *
     * @return size_t tamaño de la pila
     */
    template<typename TData> size_t Stack<TData>::size() const
    {
        return m_size;
    }

      /**
     * @brief Imprime los elementos de la cola
     */
    template<typename TData> void Stack<TData>::print() const
    {
        Node* temp = m_top;
        while (temp != nullptr)
        {
            std::cout << temp->data << ", ";
            temp = temp->next;
        }
    }




