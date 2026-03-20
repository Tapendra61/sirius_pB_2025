#!/usr/bin/env bash
cd build || { echo "build dir not found"; exit 1; }
cmake --build .
echo "Build done"
