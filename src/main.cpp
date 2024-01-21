#include "App.h"
#include "Factory.h"

int main(){
    Factory factory;
    IMenu* menu = factory.createMenu(CONSOLE_MENU);
    App app;
    app.run(menu);

    return 0;
}
