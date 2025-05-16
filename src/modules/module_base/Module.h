#ifndef MODULE_H
#define MODULE_H

// Imports
#include <string>

namespace MiniECS
{
    // Module types enum
    enum class ModuleType
    {
        ModuleBase = 0,
        Transform = 1,
        Renderer = 2
    };

    class Module {
    public:
        // Constructor & Destructor
        Module(const ModuleType setType);
        virtual ~Module();

        // Get type name;
        std::string getTypeName();
        ModuleType getType();

        // Default module update
        virtual void start();

    private:
        // Module type
        ModuleType type;
        // String name of module type
        std::string moduleTypeName;
    };

}

#endif //MODULE_H
