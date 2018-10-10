#include <cstdint>

class GameInput
{
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    bool button = false;
};

class Image
{
public:
    double x = 0.0;
    double y = 0.0;
    double width = 0.0;
    double height = 0.0;
    
};

class Actor
{
public:
    /**
     * This method will be called periodically by the engine.
     * The time value is the time in milliseconds.
     * The time value is garanteed to never run backwards.
     */
    virtual void act(int64_t time, const GameInput& input) = 0;
};

class GameLoop
{
public:
    GameLoop();



private:

};