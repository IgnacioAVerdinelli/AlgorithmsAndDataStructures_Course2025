#ifndef DOUBLELIST_HPP
#define DOUBLELIST_HPP

#include <iostream>

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

    explicit DoublyListNode(const TData& value);
};

/**
 * @brief Clase de lista doblemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
class DoublyLinkedList
{
private:
    DoublyListNode<TData>* head;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    /**
     * @brief Retorna el primer elemento de la lista
     *
     * @return Primer elemento de la lista
     */
    DoublyListNode<TData>* get_head() const;

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    void push_front(const TData& value);

    /**
     * @brief Inserta un nuevo elemento al final de la lista
     *
     * @param value Valor a insertar
     */
    void push_back(const TData& value);

    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
    void remove_at(size_t position);

    /**
    * @brief Copia los elementos de otra lista
    *
    * @param other Lista de la cual copiar los elementos
    */
    void copy_list(const DoublyLinkedList& other);

    /**
     * @brief Imprime todos los elementos de la lista
     */
    void print() const;

#endif
};