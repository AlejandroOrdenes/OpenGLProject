#include "OpenGL3D/Game/OGame.h"        // Incluye la declaraci�n de la clase OGame
#include "OpenGL3D/Window/OpenGLWindow.h" // Incluye la declaraci�n de la clase OpenGLWindow
#include <Windows.h>                   // Incluye la API de Windows

OGame::OGame()
{
    winDisplay = std::unique_ptr<OpenGLWindow>(new OpenGLWindow); // Crea una instancia �nica de OpenGLWindow y la asigna a winDisplay; std::unique_ptr garantiza que solo un �nico objeto pueda poseer la propiedad de liberar la memoria asociada a un objeto din�mico.
    //No se puede copiar un std::unique_ptr directamente, lo que significa que siempre habr� una �nica instancia que gestione la liberaci�n del recurso.
}

OGame::~OGame()
{
    // El destructor por defecto es suficiente para la clase OGame.
    // No se necesita liberar expl�citamente winDisplay, ya que std::unique_ptr lo maneja autom�ticamente.
}

void OGame::run()
{
    MSG msg; // Estructura para almacenar mensajes de ventana
    while (isRunning && !winDisplay->isClosed()) {
        // Mientras el juego est� corriendo y la ventana de OpenGL est� abierta
        if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) // Verifica si hay mensajes en la cola de mensajes
        {
            TranslateMessage(&msg); // Traduce los mensajes de teclado y rat�n
            DispatchMessage(&msg); // Env�a el mensaje a la funci�n de ventana adecuada (WndProc)
        }

        Sleep(1); // Duerme el hilo principal durante 1 milisegundo
    }
}

void OGame::quit()
{
    isRunning = false; // Establece la bandera isRunning a false para salir del bucle en run()
}
