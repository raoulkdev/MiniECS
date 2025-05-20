# MiniECS (Mini Entity Component System)

[![Last Commit](https://img.shields.io/github/last-commit/raoulkdev/MiniECS?style=flat&logo=git)](https://github.com/raoulkdev/MiniECS/commits)
[![Top Language](https://img.shields.io/github/languages/top/raoulkdev/MiniECS?style=flat&logo=c%2B%2B)](https://github.com/raoulkdev/MiniECS)
[![Languages Count](https://img.shields.io/github/languages/count/raoulkdev/MiniECS?style=flat&logo=github)](https://github.com/raoulkdev/MiniECS)
[![Contributors](https://img.shields.io/github/contributors/raoulkdev/MiniECS?style=flat&logo=github)](https://github.com/raoulkdev/MiniECS/graphs/contributors)

> **MiniECS** is a simple C++ ECS-style framework built for learning purposes. Inspired by Unity’s architecture, it shows how Units and Modules (akin to GameObjects and Components) can work together in a minimal setup.

[Read my article on starting this project](https://medium.com/@nkumba/building-a-lightweight-ecs-1-units-modules-0d66c764e263)

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Getting Started](#getting-started)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Architecture](#architecture)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

**MiniECS** is a lightweight C++ framework designed to help you understand the principles of the Entity-Component-System (ECS) architecture.

- **Units** represent entities (like GameObjects).
- **Modules** represent components (like Transform, Renderer, etc).

This project is best suited for educational exploration and prototyping, rather than production-level game development.

---

## Features

- Minimal and readable C++ codebase.
- Simple ECS architecture with Units and Modules.
- Extensible: Add your own modules (components) easily.
- Inspired by Unity, but minimal and dependency-light.
- MIT-licensed for open learning and extension.

---

## Getting Started

### Prerequisites

- C++20 compatible compiler (e.g. GCC, Clang, MSVC).
- [CMake](https://cmake.org/) for build configuration.
- [GLM](https://github.com/g-truc/glm) (header-only math library) for Transform module.
    - Make sure to adjust the include path for GLM in `TransformModule.h` as needed.

---

## Installation

Clone and build the project:

```bash
git clone https://github.com/raoulkdev/MiniECS.git
cd MiniECS
cmake .
make
```

---

## Usage

After building, run the executable:

```bash
./MiniECS
```

You can modify `src/main.cpp` to experiment with the ECS framework.

---

## Examples

Here’s a minimal example (see `src/main.cpp`):

```cpp
#include "unit/Unit.h"
#include "world/World.h"
#include "modules/transform/TransformModule.h"

int main() {
    // Create a world (scene)
    MiniECS::World scene("Scene");

    // Add a unit (entity)
    scene.createUnit("u1");

    // Add modules/components to the unit
    scene.getUnitByName("u1")->addModule(MiniECS::ModuleType::Renderer);
    scene.getUnitByName("u1")->addModule(MiniECS::ModuleType::Transform);

    // Access and modify a module
    auto* transform = scene.getUnitByName("u1")->getModule<MiniECS::TransformModule>();
    if (transform) {
        transform->position = {22.5f, 33.4f};
    }

    // Start the main loop
    scene.play();
}
```

---

## Architecture

- **World**: Container for all Units.
    - `createUnit(name)`: Add new Unit by name.
    - `getUnitByName(name)`: Get a Unit pointer.
    - `play()`: Starts the main loop for all Units/Modules.

- **Unit**: An entity (like a GameObject).
    - Holds a vector of Modules.
    - Methods: `addModule`, `removeModule`, `getModule<T>`, etc.

- **Module**: Base class for all components.
    - Extendable for custom components.
    - Built-in: `TransformModule`, `RendererModule`.

- **Extending**: Add your own Modules by inheriting from `Module`, then register and add them to Units.

---

## Contributing

Pull requests, suggestions, and improvements are welcome! For larger changes, please open an issue to discuss your ideas.

---

## License

This project is licensed under the [MIT License](LICENSE).
