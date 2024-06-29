#pragma once

// La directiva `#pragma once` asegura que el archivo de cabecera se incluye solo una vez en cada archivo de traducción durante la compilación, evitando errores de redefinición.
class OpenGLWindow {
public:
    // Constructor de la clase OpenGLWindow.
    // Se utiliza para inicializar la instancia de la ventana OpenGL.
    OpenGLWindow();

    // Destructor de la clase OpenGLWindow.
    // Se utiliza para liberar los recursos asociados a la ventana cuando se destruye la instancia de la clase.
    ~OpenGLWindow();

    // Método que se llama cuando la ventana se destruye.
    // Realiza tareas de limpieza y actualización del estado de la ventana.
    void onDestroy();

    // Método que verifica si la ventana está cerrada.
    // Retorna true si la ventana está cerrada, de lo contrario retorna false.
    bool isClosed();

private:
    // Puntero a la ventana creada.
    // Se utiliza para almacenar el identificador de la ventana y administrar su ciclo de vida.
    void* createWin = nullptr;
};
