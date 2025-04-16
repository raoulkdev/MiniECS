# MiniECS (Mini Entity Component System)

<p align="left">
  <img src="https://img.shields.io/github/last-commit/raoulkdev/MiniECS?style=flat&logo=git" />
  <img src="https://img.shields.io/github/languages/top/raoulkdev/MiniECS?style=flat&logo=c%2B%2B" />
  <img src="https://img.shields.io/github/languages/count/raoulkdev/MiniECS?style=flat&logo=github" />
   <img src="https://img.shields.io/github/contributors/raoulkdev/MiniECS?style=flat&logo=github" />
</p>

## Terminology Context
MiniECS is an ECS-inspired framework, where the terminology has been customized to Unit Module System (UMS).

In this system:
- **Unit** = Entity
- **Module** = Component

## Table of Contents

- [Overview](#overview)  
- [Getting Started](#getting-started)  
- [Installation](#installation)  
- [Usage](#usage)  
- [Testing](#testing)

## Overview

**MiniECS** is a lightweight C++ framework built to explore and understand the principles of the Entity-Component-System (ECS) architecture. Inspired by Unity’s design, it demonstrates how Units (Entities) and Modules (Components) can interact in a minimalist setup.

While this project isn't intended for full-scale game development or engine creation, it offers a simple foundation that can be expanded with significant adjustments to suit more complex use cases.

## Getting Started

### Prerequisites

Before getting started, ensure you have the following dependencies installed:

- **Programming Language**: C++
- **Package Manager**: CMake

## Installation

To install MiniECS from source, follow these steps:

1. **Clone the repository:**

    ```bash
    git clone https://github.com/raoulkdev/MiniECS.git
    ```

2. **Navigate to the project directory:**

    ```bash
    cd MiniECS
    ```

3. **Install the dependencies using CMake:**

    ```bash
    cmake .
    ```

## Usage

To run the project, simply execute:

```bash
./MiniECS
