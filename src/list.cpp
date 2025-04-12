#include "list.hpp"

template<typename TData> LinkedList<TData>::LinkedList()
        : head(nullptr)
    {
    }

    template<typename TData> LinkedList<TData>::~LinkedList()
    {
        while(head != nullptr)
        {
            auto temporalNode = head;
            head = head->next;
            delete temporalNode;
        }
    }

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    template<typename TData> void LinkedList<TData>::push_front(const TData& value)
    {
        auto nuevo = new ListNode<TData>(value);
        nuevo->next = head;
        head = nuevo;
    }

    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
   template<typename TData> void LinkedList<TData>::remove_at(size_t position)
    {
        if (head == nullptr)
        {
            return;
        }

        if (position == 0)
        {
            auto temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Para cualquier otra posicion necesitamos mantener un puntero al nodo anterior
        auto prev = head;
        auto current = head->next;
        size_t current_position = 1;

        // Avanzamos hasta encontrar la posicion o llegar al final de la lista
        while (current != nullptr && current_position < position)
        {
            prev = current;
            current = current->next;
            current_position++;
        }

        // Si current es nullptr quiere decir que la posicion especifica es mas grande que la lista,
        // no se encuentra la posicion
        if (current == nullptr) return;

        // Hacemos que el nodo anterior apunte al nodo siguiente actual
        prev->next = current->next;

        delete current;
    }

    /**
    * @brief Crea una lista nueva de n elementos a partir de una posición dada
    *
    */
   template<typename TData> ListNode<TData>* LinkedList<TData>::take(size_t startPosition, size_t nElements)
    {
        // Si la lista esta vacia retornamos nullptr
        if (head == nullptr)
        {
            return nullptr;
        }

        // Buscamos el nodo de inicio
        ListNode<TData>* current = head;
        size_t current_position = 0;

        // Avanzamos hasta la posicion de inicio
        while (current != nullptr && current_position < startPosition)
        {
            current = current->next;
            current_position++;
        }

        // Si current es nullptr, la posicion esta fuera de rango
        if (current == nullptr) return nullptr;

        // Creamos el primer nodo de la nueva lista
        ListNode<TData>* new_head = new ListNode<TData>(current->data);
        ListNode<TData>* new_current = new_head;

        // Avanzamos al siguiente nodo en la lista original
        current = current->next;

        // Copiamos los siguientes mElements-1 nodos (ya copiamos 1)
        for (size_t i = 1; i < nElements && current != nullptr; i++)
        {
            // Creamos un nuevo nodo con el valor actual
            new_current->next = new ListNode<TData>(current->data);

            // Avanzamos en ambas listas
            new_current = new_current->next;
            current = current->next;
        }

        return new_head;
    }

    /**
     * @brief Imprime todos los elementos de la lista
     */
    template<typename TData> void LinkedList<TData>::print() const
    {
        ListNode<TData>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }


/**
 * @brief Nodo de lista doblemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
struct DoublyListNode
{
    TData data;
    DoublyListNode* next;
    DoublyListNode* prev;

    template<typename TData> explicit DoublyLinkedList<TData>::DoublyListNode(const TData& value)
        : data(value)
        , next(nullptr)
        , prev(nullptr)
    {
    }
};
