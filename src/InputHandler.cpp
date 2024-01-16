#include "InputHandler.h"

/* The function check if a given URL is legal
* Input: the url
* Output: legal or not*/
bool InputHandler::checkURL(string url)
{
    // check that the url has the minimum chars. for example www.a.a
    if (url.length() < 7)
    {
        return false;
    }
    //check the 'www' in the beginning
    if (url[0] != 'w' || url[1] != 'w' || url[2] != 'w')
    {
        return false;
    }
    //check that there is a dot after the 'www' and then the domain start
    if (url[3] != '.' || url[4] == '.')
    {
        return false;
    }
    //We already check that the firs dot appear after the 'www'
    bool dotAppearTwice = false;
    for (int i = 5; i < url.length()-1; ++i)
    {
        if (url[i] == '.') {
            dotAppearTwice = true;
        }
    }
    //check that the url not ending with '.'
    if (url[url.length()-1] == '.')
    {
        return false;
    }
    return dotAppearTwice;
}
