#include <OpenGL3D/Window/OpenGLWindow.h>
#include <Windows.h>
#include <assert.h>

// Procedimiento de ventana personalizado para manejar mensajes de ventana
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    // Obtiene el puntero a la instancia de OpenGLWindow almacenado en los datos de la ventana
    OpenGLWindow* window = (OpenGLWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    if (window) { // Verifica si el puntero es válido
        switch (msg) {
        case WM_DESTROY:
            window->onDestroy(); // Llama al método onDestroy de OpenGLWindow cuando se destruye la ventana
            PostQuitMessage(0); // Envía un mensaje para terminar la aplicación
            return 0;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam); // Maneja otros mensajes con la función de ventana por defecto
        }
    }
    return DefWindowProc(hwnd, msg, wParam, lParam); // Usa la función de ventana por defecto para mensajes no manejados
}

// Constructor de OpenGLWindow
OpenGLWindow::OpenGLWindow() {
    WNDCLASSEX wc = {}; // Estructura para la clase de ventana
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpszClassName = L"OGL3DWindow"; // Nombre de la clase de ventana
    wc.lpfnWndProc = WndProc; // Asigna el procedimiento de ventana personalizado
    wc.hInstance = GetModuleHandle(NULL); // Obtiene el identificador de la instancia del módulo
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Carga el cursor de flecha por defecto

    assert(RegisterClassEx(&wc)); // Registra la clase de ventana y verifica el éxito

    RECT rc = { 0, 0, 1024, 768 }; // Define las dimensiones de la ventana
    AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, FALSE); // Ajusta el tamaño de la ventana con bordes y menú

    // Crea la ventana usando los parámetros definidos
    createWin = CreateWindowEx(0, L"OGL3DWindow", L"Space Survival", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, wc.hInstance, NULL);
    assert(createWin); // Verifica que la ventana se haya creado correctamente

    // Almacena el puntero a la instancia de OpenGLWindow en los datos de la ventana
    SetWindowLongPtr((HWND)createWin, GWLP_USERDATA,
