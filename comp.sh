#!/bin/bash

g++ -c battleship_main.cpp
g++ -o battle battleship_main.o battleship.o -lcurses
