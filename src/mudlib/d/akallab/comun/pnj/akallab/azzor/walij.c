/****************************************************************************
Fichero: /d/akallab/comun/pnj/akallab/azzor/walij.c
Autor: Yalin
Fecha: 20/01/2008 13:27
Descripci�n: Tabernero de la fonda Cr�neo de Elfo.
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
    SetLong("Walij es un orco extra�o. Es un viejo malhumorado, del que se dice que nadie ha "
        "visto sonre�r jam�s.\nCirculan rumores de que, en sus a�os j�venes y maduros, fu� un "
        "mercenario sin escr�pulos, asesino a sueldo de quien pudiera y quisiera pagar sus "
        "servicios, sin importar a qui�n o a cu�ntos tuviera que matar, hombres o mujeres, "
        "viejos o ni�os.\nHoy, ya viejo y cansado, pasa el tiempo en este olvidado local, "
        "esperando a los pocos valientes o locos que se aventuran a vagar solitarios por estos "
        "peligrosos lugares.\n");
    AddId(({"walij","Walij","orco","viejo","siniestro"}));
    AddItem(ARMA("daga"),REFRESH_REMOVE,1,SF(wieldme));
    InitChats(5,({
        "Walij te mira mientras acaricia melanc�licamente la empu�adura de su daga.\n",
        "Walij te dice: �Vas a tomar algo, o has venido a saludar?\n",
        "Walij refunfu�a: �ste no es un buen negocio, pero es un sitio tranquilo.\n",
        "Walij te dice: �Por qu� me miras, amigo? �Hay alg�n problema?\n"}));
}
    