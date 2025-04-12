#include <string>
#include <iostream>
#include "queue.hpp"

class Evento 
{
    private:

struct Event 
{
    std::string m_date;
    std::string m_type;
};

    Queue<Event> m_eventosPendientes;
    Queue<Event> m_eventosRealizados;
    
    public:    
    
    void NewEvent(const Event& Evento) 
        {
            m_eventosPendientes.enqueue(Evento);
        }

    void DeleteEvent(const Event& Evento)
        {
            m_eventosPendientes.dequeue();
        }
    
    void check ()
    {
        if (m_eventosPendientes.isEmpty ())
        {
            std::cout << "No hay eventos pendientes." << std::endl;
        }
        else
        {
            std::cout << "Eventos pendientes:" << std::endl;
            return m_eventosPendientes.print();
            }
        }
    };