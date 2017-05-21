/****************************************************************************
Fichero: /d/akallab/comun/pnj/akallab/azzor/walij.c
Autor: Yalin
Fecha: 20/01/2008 13:27
Descripción: Tabernero de la fonda Cráneo de Elfo.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Walij","orco",([ GC_ASESINO:40 ]),GENERO_MASCULINO);
    SetName("Walij");
    SetShort("Walij el siniestro");
    SetLong("Walij es un orco extraño. Es un viejo malhumorado, del que se dice que nadie ha "
        "visto sonreír jamás.\nCirculan rumores de que, en sus años jóvenes y maduros, fué un "
        "mercenario sin escrúpulos, asesino a sueldo de quien pudiera y quisiera pagar sus "
        "servicios, sin importar a quién o a cuántos tuviera que matar, hombres o mujeres, "
        "viejos o niños.\nHoy, ya viejo y cansado, pasa el tiempo en este olvidado local, "
        "esperando a los pocos valientes o locos que se aventuran a vagar solitarios por estos "
        "peligrosos lugares.\n");
    AddId(({"walij","Walij","orco","viejo","siniestro"}));
    AddItem(ARMA("daga"),REFRESH_REMOVE,1,SF(wieldme));
    InitChats(5,({
        "Walij te mira mientras acaricia melancólicamente la empuñadura de su daga.\n",
        "Walij te dice: ¿Vas a tomar algo, o has venido a saludar?\n",
        "Walij refunfuña: Éste no es un buen negocio, pero es un sitio tranquilo.\n",
        "Walij te dice: ¿Por qué me miras, amigo? ¿Hay algún problema?\n"}));
}
    