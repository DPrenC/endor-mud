/*
Fichero: encrucijadasur.c
Autor: Aule
Fecha: 20/10/2012
Descripción: parte sur de la encrucijada
*/
#include "./path.h"
inherit HABITACION+"caminos/base_camino";


create()
{
    ::create();
    	SetIntShort("sur de la encrucijada");
    SetIntLong("En este punto el Camino Verde que recorre las tierras de Bree de norte \n"
    "a sur se abre hacia el norte desembocando en un espacio más o menos circular donde \n"
    "desembocan otras tres vías desde el norte, este y oeste respectivamente.\n");
    AddExit("norte", "./encrucijada");
    AddExit("sur", "./camino_s1");
    AddExit("noroeste", "./encrucijadaoeste");
  AddExit("noreste", "./encrucijadaeste");
}