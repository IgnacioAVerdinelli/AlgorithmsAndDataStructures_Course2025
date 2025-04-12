#include "saqueador.hpp"

Saqueador::Saqueador(const std::string& nombre, Estilo estilo, int size)
    : EntidadGenerica(nombre)
    , m_estilo(estilo)
    , m_numMiembros(size)
{
}

void Saqueador::showInfo() const
{
    std::cout << "💀 Saqueadores: " << m_name << "\n"
              << " - Estilo: " << estiloToString(m_estilo) << "\n"
              << " - Miembros: " << m_numMiembros << "\n";
}

void Saqueador::amenazar() const
{
    switch (m_estilo)
    {
        case Estilo::AGRESIVO:
            std::cout << "💬" << m_name << " >>> ¡Entréganos tus recursos o lo pagarán caro!" << std::endl;
            break;
        case Estilo::SIGILOSO:
            std::cout << "💬" << m_name << " >>> Nadie nos vio entrar, nadie los verá salir..." << std::endl;
            break;
        case Estilo::OPORTUNISTA:
            std::cout << "💬" << m_name << " >>> Solo estamos aquí por lo que sobra... si queda algo." << std::endl;
            break;
    }
}

int Saqueador::randomGroupSize() const
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(5, 10);
    return dist(gen);
}

std::string Saqueador::estiloToString(Estilo estilo) const
{
    switch (estilo)
    {
        case Estilo::AGRESIVO: return "Agresivo";
        case Estilo::SIGILOSO: return "Sigiloso";
        case Estilo::OPORTUNISTA: return "Oportunista";
        default: return "Desconocido";
    }
}