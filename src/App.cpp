#include "App.h"

void App::run()
{
    bool atStart = true;
    while (true) {
        string line;
        getline(std::cin,line);
        if (atStart)
        {
            if (!InputHandler::checkLineValidation(line,0))
                continue;
            atStart = false;
            ///TODO: create bf object.
        }
        else
        {
            int type = InputHandler::getType(line);
            if (type == ERROR || !InputHandler::checkLineValidation(line,type))
            {
                continue;
            }
            ///TODO: bf.execute(InputHandler::getURL(line))
        }
    }
}
