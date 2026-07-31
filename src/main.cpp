#include "steamfix/app.hpp"

#include <windows.h>

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PWSTR, _In_ int) {
    return steamfix::app::entry();
}
