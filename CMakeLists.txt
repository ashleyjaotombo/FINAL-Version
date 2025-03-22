cmake_minimum_required(VERSION 3.29)
project(ProjetAutomate_main_3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ProjetAutomate_main_3
    affichage_automateFINAL.c
    Automate.h
    automate_complementaireFINAL.c
    automate_fonctionFINAL.c
    Determinisation.c
    MainFINALE.c
    testReconnaissancev2FINAL.c)
