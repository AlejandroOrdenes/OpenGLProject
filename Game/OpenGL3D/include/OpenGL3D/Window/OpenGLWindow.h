#pragma once

// La directiva `#pragma once` asegura que el archivo de cabecera se incluye solo una vez en cada archivo de traducci�n durante la compilaci�n, evitando errores de redefinici�n.
class OpenGLWindow {
public:
    // Constructor de la clase OpenGLWindow.
    // Se utiliza para inicializar la instancia de la ventana OpenGL.
    OpenGLWindow();

    // Destructor de la clase OpenGLWindow.
    // Se utiliza para liberar los recursos asociados a la ventana cuando se destruye la instancia de la clase.
    ~OpenGLWindow();

    // M�todo que se llama cuando la ventana se destruye.
    // Realiza tareas de limpieza y actualizaci�n del estado de la ventana.
    void onDestroy();

    // M�todo que verifica si la ventana est� cerrada.
    // Retorna true si la ventana est� cerrada, de lo contrario retorna false.
    bool isClosed();

private:
    // Puntero a la ventana creada.
    // Se utiliza para almacenar el identificador de la ventana y administrar su ciclo de vida.
    void* createWin = nullptr;
};
