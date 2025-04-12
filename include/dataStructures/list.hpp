#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

/**
 * @brief Nodo de lista simplemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
struct ListNode
{
    TData data;
    ListNode* next;

    explicit ListNode(const TData& value)
        : data(value)
        , next(nullptr)
    {
    }
};

/**
 * @brief Implementación de una lista simplemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
class LinkedList
{
private:
    ListNode<TData>* head;

public:
    LinkedList();

    ~LinkedList();

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    void push_front(const TData& value);

    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
    void remove_at(size_t position);

    /**
    * @brief Crea una lista nueva de n elementos a partir de una posición dada
    *
    */
    ListNode<TData>* take(size_t startPosition, size_t nElements);

    /**
     * @brief Imprime todos los elementos de la lista
     */
    void print() const;

#endif
};