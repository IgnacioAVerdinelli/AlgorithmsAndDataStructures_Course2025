#ifndef SAQUEADOR_HPP
#define SAQUEADOR_HPP

#include "entidadGenerica.hpp"
#include <iostream>
#include <random>

/**
 * @class Saqueador
 * @brief Representa un grupo de saqueadores en el mundo post-apocalíptico.
 *
 * Los saqueadores pueden presentarse como agresivos, sigilosos u oportunistas.
 * Sus fuerzas varían entre 5 y 10 miembros.
 */
class Saqueador : public EntidadGenerica
{
public:
    enum class Estilo
    {
        AGRESIVO,
        SIGILOSO,
        OPORTUNISTA
    };

private:
    int m_numMiembros; ///< Número de integrantes del grupo
    Estilo m_estilo;   ///< Estilo de saqueo del grupo

public:
    /**
     * @brief Constructor del saqueador
     * @param nombre Nombre del grupo de saqueadores
     * @param estilo Estilo de comportamiento del grupo
     */
    Saqueador(const std::string& nombre, Estilo estilo, int size);

    /**
     * @brief Muestra la información del grupo de saqueadores
     */
    void showInfo() const override;
    
    /**
     * @brief Simula una amenaza del grupo
     */
    void amenazar() const;

private:
    /**
     * @brief Devuelve una cantidad aleatoria de miembros entre 5 y 10
     */
    int randomGroupSize() const;

    /**
     * @brief Convierte el enum de estilo a string
     */
    std::string estiloToString(Estilo estilo) const;

#endif // SAQUEADOR_HPP
};
