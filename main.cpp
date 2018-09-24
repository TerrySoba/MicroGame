#include "SDL.h"

// #include "chaiscript/chaiscript.hpp"

#include <tclap/CmdLine.h>

#include <boost/scope_exit.hpp>

#include <exception>
#include <iostream>
#include <sstream>


struct GameConfig
{
    int screenWidth;
    int screenHeight;
    bool fullscreen;
};


int toInt(const std::string& str)
{
    std::stringstream ss;
    ss << str;
    int val;
    ss >> val;

    return val;
}


GameConfig parseCommandline(int argc, char *argv[])
{
    TCLAP::CmdLine cmd("MicroGame options", ' ', "0.1");
    TCLAP::ValueArg<std::string> nameArg("r", "resolution", "screen resolution", false, "1280x720", "string");
    cmd.add(nameArg);
    TCLAP::SwitchArg fullscreenSwitch("f", "fullscreen", "run game in fullscreen mode", false);
    cmd.add(fullscreenSwitch);

    // Parse the argv array.
    cmd.parse(argc, argv);

    auto resString = nameArg.getValue();

    auto xPos = resString.find("x");
    if (xPos == std::string::npos)
    {
        throw std::runtime_error("Could not find 'x' in resolution string.");
    }

    auto x = toInt(resString.substr(0, xPos));
    auto y = toInt(resString.substr(xPos + 1));

    std::cout << "x:" << x << " y:" << y << std::endl;

    auto fullscreen = fullscreenSwitch.getValue();

    return {x,y,fullscreen};
}

int main(int argc, char *argv[])
{
    try
    {
        GameConfig config = parseCommandline(argc, argv);


        std::cout << "MicroGame 0.1" << std::endl;

        // chaiscript::ChaiScript chai;

        // chai.eval(R"(
        //     puts("gnaa");
        //     unknown(1,2,3,4);
        // )");

        if (SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            std::stringstream message;
            message << "SDL_Init Error: " << SDL_GetError();
            throw std::runtime_error(message.str());
        }

        BOOST_SCOPE_EXIT_ALL(&)
        {
            SDL_Quit();
        };

        SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, config.screenWidth, config.screenHeight, SDL_WINDOW_SHOWN);
        if (!win)
        {
            std::stringstream message;
            message << "SDL_CreateWindow Error: " << SDL_GetError();
            throw std::runtime_error(message.str());
        }

        BOOST_SCOPE_EXIT_ALL(&)
        {
            SDL_DestroyWindow(win);
        };

        SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!ren)
        {
            std::stringstream message;
            message << "SDL_CreateRenderer Error: " << SDL_GetError();
            throw std::runtime_error(message.str());
        }

        BOOST_SCOPE_EXIT_ALL(&)
        {
            SDL_DestroyRenderer(ren);
        };

        std::string imagePath = "rgb.bmp";
        SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
        if (!bmp)
        {
            std::stringstream message;
            message << "SDL_LoadBMP Error: " << SDL_GetError();
            throw std::runtime_error(message.str());
        }

        SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
        SDL_FreeSurface(bmp);

        if (!tex)
        {
            std::stringstream message;
            message << "SDL_CreateTextureFromSurface Error: " << SDL_GetError();
            throw std::runtime_error(message.str());
        }

        BOOST_SCOPE_EXIT_ALL(&)
        {
            SDL_DestroyTexture(tex);
        };

        //A sleepy rendering loop, wait for 3 seconds and render and present the screen each time
        for (int i = 0; i < 3; ++i)
        {
            //First clear the renderer
            SDL_RenderClear(ren);
            //Draw the texture
            SDL_RenderCopy(ren, tex, NULL, NULL);
            //Update the screen
            SDL_RenderPresent(ren);
            //Take a quick break after all that hard work
            SDL_Delay(1000);
        }

        return EXIT_SUCCESS;
    }
    catch (std::exception &ex)
    {
        std::cerr << "Caught std::exception. what() \"" << ex.what() << "\"" << std::endl;
    }
    catch (...)
    {
        std::cerr << "Caught unknown exception." << std::endl;
    }

    return EXIT_FAILURE;
}
