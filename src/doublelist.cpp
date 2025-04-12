#include "doublelist.hpp"

/// @brief 
/// @tparam TData 
template<typename TData> DoublyLinkedList<TData>::DoublyLinkedList()
        : head(nullptr)
    {
    }

    template<typename TData> DoublyLinkedList<TData>::~DoublyLinkedList()
    {
        while(head != nullptr)
        {
            auto temporalNode = head;
            head = head->next;
            delete temporalNode;
        }
    }

    /**
     * @brief Retorna el primer elemento de la lista
     *
     * @return Primer elemento de la lista
     */
    template<typename TData> DoublyListNode<TData>* DoublyLinkedList<TData>::get_head() const
    {
        return head;
    }

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    template<typename TData> void DoublyLinkedList<TData>::push_front(const TData& value)
    {
        auto nuevo = new DoublyListNode<TData>(value);
        nuevo->next = head;
        head = nuevo;
    }

    /**
     * @brief Inserta un nuevo elemento al final de la lista
     *
     * @param value Valor a insertar
     */
    template<typename TData> void DoublyLinkedList<TData>::push_back(const TData& value)
    {
        auto nuevo = new DoublyListNode<TData>(value);
        // nuevo->next = nullptr; No haria falta pq cuando se crea un DoublyListNode next y prev se inicilizan en nullptr

        // Si la lista esta vacia
        if (!head)
        {
            head = nuevo;
        }
        else
        {
            // Si la lista tiene elementos, recorrer hasta el ultimo nodo
            // DoublyListNode<TData>* temp = get_head();
            auto temp = get_head();
            while (temp->next != nullptr) // Buscamos el ultimo nodo
            {
                temp = temp->next;
            }

            // temp es el ultimo nodo, se conecta con el nuevo ultimo nodo
            temp->next = nuevo;
            nuevo->prev = temp; // El prev de nuevo apunta al antiguo ultimo nodo, osea temp
        }
    }

    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
   template<typename TData> void DoublyLinkedList<TData>::remove_at(size_t position)
    {
        // Si la lista esta vacia no hay nada que eliminar
        if (head == nullptr)
        {
            return;
        }

        // Caso que el nodo a eliminar sea el primero (nodo 0)
        if (position == 0)
        {
            DoublyListNode<TData>* temp = head;
            head = head->next;

            // Si hay mas nodos despues del primero actualizamos el prev del nuevo head
            if (head != nullptr)
            {
                head->prev = nullptr;
            }

            delete temp;
            return;
        }

        // Para cualquier otra posicion recorremos la lista, hacemos un contador para llevar track de
        // la posicion en la lista
        DoublyListNode<TData>* current = head;
        size_t current_position = 0;

        while (current != nullptr && current_position < position)
        {
            current = current->next;
            current_position++;
        }

        // Si current es nullptr quiere decir que la posicion especifica es mas grande que la lista,
        // no se encuentra la posicion
        if (current == nullptr) return;

        // current es el nodo que queremos eliminar, conectamos sus
        // nodos adyacentes
        if (current->prev != nullptr)
        {
            current->prev->next = current->next;
        }

        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }

        delete current;

    }

    /**
    * @brief Copia los elementos de otra lista
    *
    * @param other Lista de la cual copiar los elementos
    */
   template<typename TData> void DoublyLinkedList<TData>::copy_list(const DoublyLinkedList<TData>& other)
    {
        // PREGUNTAR: Borramos los nodos actuales?
        while (head != nullptr)
        {
            auto temporalNode = head;
            head = head->next;
            delete temporalNode;
        }

        // Copiamos los nodos de la otra lista con push_back()
        auto current = other.get_head();
        while (current != nullptr)
        {
            push_back(current->data);
            current = current->next;
        }
    }

    /**
     * @brief Imprime todos los elementos de la lista
     */
    template<typename TData> void DoublyLinkedList<TData>::print() const
    {
        DoublyListNode<TData>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }