#include <functional>

class MyScopeExit
{
public:
    MyScopeExit(std::function<void(void)> atExit) : m_atExit(atExit) {}
    ~MyScopeExit()
    {
        m_atExit();
    }

private:
    std::function<void(void)> m_atExit;
};

#define CONCAT_IMPL( x, y ) x##y
#define MACRO_CONCAT( x, y ) CONCAT_IMPL( x, y )

#define SCOPE_EXIT(func) MyScopeExit MACRO_CONCAT( exitThing, __COUNTER__) (func)
