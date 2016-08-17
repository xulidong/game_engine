#include "AppDelegate.h"
#include "Application.h"

int main() {
    AppDelegate app;
    return Application::getInstance()->run();
}
