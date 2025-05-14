//
// Created by Raoul Kaleba on 4/15/2025.
//
#ifndef MODULE_H
#define MODULE_H

// Imports
#include <string>

namespace MiniECS
{
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

        // Get id
        int getId();

        // Default module update
        virtual void start();

    private:
        ModuleType type;
        std::string moduleTypeName;
        static int moduleId;
    };

}

#endif //MODULE_H
