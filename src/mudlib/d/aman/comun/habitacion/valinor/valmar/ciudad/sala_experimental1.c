/*
Fichero: sala_experimental1.c
Autor: Orome
Fecha: 01/10/2014
Descripción: sala 1 para experimentaciones.
*/
#include "./path.h"
#include <xp.h>
inherit STD_VALINOR("hab_valinor");
create()
{
    ::create();
    	SetLocate("Valmar");
    SetIntShort("sala experimental 1");
    SetIntLong("Esta es la sala 1 para experimentos, diseñada para incorporar a ella algunos códigos y comprovar como se comportan.\n Ahora mismo, entre otras cosas, sirve para aumentarse los xp.\n");

     SetIntBright(20);
     SetIntSmell("Huele a madera húmeda, humus y hojas muertas.\n");
     SetIntNoise("Crees oír el leve susurrar secreto de las ramas movidas por una brisa intangible.\n");


AddRoomCmd("experiencia","cmd_experiencia");
     }

public int cmd_experiencia(){
    TP->exp(5);
    return 1;
    }
