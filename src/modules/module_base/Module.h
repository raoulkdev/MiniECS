//
// Created by Raoul Kaleba on 4/15/2025.
//
#ifndef MODULE_H
#define MODULE_H

// Imports
#include <string>

namespace MiniECS
{
    class Module {
    public:
        // Constructor & Destructor
        Module(const std::string& type);
        virtual ~Module();

        // Get id
        int getId();

        // Default module update
        virtual void start();

    private:
        std::string moduleType;
        static int moduleId;
    };

}

#endif //MODULE_H
