#include "App.h"
#include "Factory.h"
#include "Server.h"

int main(){
    /*Factory factory = Factory::getInstance();
    IMenu* menu = factory.createMenu(CONSOLE_MENU);
    App::run(menu);*/
    Server::startServer();

    return 0;
}
