/*****************************************************************************************
 ARCHIVO:       isla_base.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Habitación estándar para el robledal de la isla.
 COMENTARIOS:
*****************************************************************************************/



#include "./path.h"


inherit HAB_VALMAR("hab_bosque.c");


create()
{
    
if(::create()) return 1;


    SetLocate("Isla de los Druidas");

    SetIndoors(0);

}
