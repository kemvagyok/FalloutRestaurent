cmake_minimum_required(VERSION 3.23)
project(FalloutEtterem C)

set(CMAKE_C_STANDARD 99)

add_executable(FalloutEtterem main.c adatokKezelese.c adatokKezelese.h adatokKezelese.h asztalokKezelese.c asztalokKezelese.h alapanyagokKezelese.h alapanyagokKezelese.c etelMenukKezelese.c etelMenukKezelese.h kinezetKezeles.h kinezetKezeles.c)
