#!/bin/bash
g++ --std=c++11 "${1}.cpp" && cat "${1}.dat" | ./a.out