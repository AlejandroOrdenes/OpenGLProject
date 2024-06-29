#pragma once

#include <memory> // Incluye la librería <memory> para utilizar std::unique_ptr

class OpenGLWindow; // Declaración adelantada de la clase OpenGLWindow

class OGame
{
public:
    OGame(); // Constructor de la clase OGame
    ~OGame(); // Destructor de la clase OGame

    void run(); // Método para ejecutar el ciclo principal del juego
    void quit(); // Método para finalizar el juego

protected:
    bool isRunning = true; // Bandera que indica si el juego está en ejecución
    std::unique_ptr<OpenGLWindow> winDisplay; // Puntero único que maneja la ventana OpenGL del juego
};

