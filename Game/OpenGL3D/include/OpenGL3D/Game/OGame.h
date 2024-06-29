#pragma once

#include <memory> // Incluye la librer�a <memory> para utilizar std::unique_ptr

class OpenGLWindow; // Declaraci�n adelantada de la clase OpenGLWindow

class OGame
{
public:
    OGame(); // Constructor de la clase OGame
    ~OGame(); // Destructor de la clase OGame

    void run(); // M�todo para ejecutar el ciclo principal del juego
    void quit(); // M�todo para finalizar el juego

protected:
    bool isRunning = true; // Bandera que indica si el juego est� en ejecuci�n
    std::unique_ptr<OpenGLWindow> winDisplay; // Puntero �nico que maneja la ventana OpenGL del juego
};

