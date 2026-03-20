# Sirius Engine

Sirius Engine is a 2D platformer-focused game engine built in C++23 on top of [Raylib](https://www.raylib.com/). It provides a component-based entity system and a simple scene/engine loop to get a game up and running quickly.

## Requirements

- CMake 4.0+
- A C++23-compatible compiler (MSVC, GCC, Clang)
- [Raylib](https://www.raylib.com/)

## Building

### Configure

```bash
cmake -S . -B build
```

### Build

```bash
cmake --build build
```

Or use the provided script:

```bash
./build.ps1
```

> Note: `build.ps1` assumes the `build/` directory already exists from a prior configure step.

## Project Structure

```
sirius_pB_2025/
├── core/       # Engine library (ECS, Engine loop, Scene management)
├── game/       # Game executable using the engine
└── CMakeLists.txt
```
