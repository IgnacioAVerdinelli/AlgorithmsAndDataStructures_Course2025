#include "stack.hpp"
#include <iostream>
#include <string>

class History 
{
    private: 

        struct decisiones
        {
            std::string m_decision;
            std::string m_fecha;
        };

    Stack<decisiones> m_historialDecisiones;

    public: 

        void registerDecision(const decisiones& decision) {
        m_historialDecisiones.push(decision);
        }

        void history () {
            std::cout << "Historial de decisiones:" << std::endl;
            m_historialDecisiones.print();
        }
};
