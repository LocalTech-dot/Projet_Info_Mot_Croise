cmake_minimum_required(VERSION 4.1.2)
project(Mot_croise C)

set(CMAKE_C_STANDARD 99)

add_executable(Mot_croise main.c
        header.h
        moteur.c
        plateau.h
        plateau.c
        dictionnaire.c
        dictionnaire.h)
