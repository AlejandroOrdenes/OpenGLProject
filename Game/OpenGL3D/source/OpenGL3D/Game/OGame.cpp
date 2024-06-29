#include "OpenGL3D/Game/OGame.h"        // Incluye la declaración de la clase OGame
#include "OpenGL3D/Window/OpenGLWindow.h" // Incluye la declaración de la clase OpenGLWindow
#include <Windows.h>                   // Incluye la API de Windows

OGame::OGame()
{
    winDisplay = std::unique_ptr<OpenGLWindow>(new OpenGLWindow); // Crea una instancia única de OpenGLWindow y la asigna a winDisplay; std::unique_ptr garantiza que solo un único objeto pueda poseer la propiedad de liberar la memoria asociada a un objeto dinámico.
    //No se puede copiar un std::unique_ptr directamente, lo que significa que siempre habrá una única instancia que gestione la liberación del recurso.
}

OGame::~OGame()
{
    // El destructor por defecto es suficiente para la clase OGame.
    // No se necesita liberar explícitamente winDisplay, ya que std::unique_ptr lo maneja automáticamente.
}

void OGame::run()
{
    MSG msg; // Estructura para almacenar mensajes de ventana
    while (isRunning && !winDisplay->isClosed()) {
        // Mientras el juego esté corriendo y la ventana de OpenGL esté abierta
        if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) // Verifica si hay mensajes en la cola de mensajes
        {
            TranslateMessage(&msg); // Traduce los mensajes de teclado y ratón
            DispatchMessage(&msg); // Envía el mensaje a la función de ventana adecuada (WndProc)
        }

        Sleep(1); // Duerme el hilo principal durante 1 milisegundo
    }
}

void OGame::quit()
{
    isRunning = false; // Establece la bandera isRunning a false para salir del bucle en run()
}
