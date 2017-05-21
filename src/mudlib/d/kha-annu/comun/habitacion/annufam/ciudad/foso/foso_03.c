/****************************************************************************
Fichero: foso_03.c
Autor: Riberales
Creaci�n: 5/10/2005
Descripci�n: Un trozo del foso.
****************************************************************************/

#include "./path.h"
inherit HAB_FOSO_ANNUFAM("foso_base");
int cmd_abrir();
int cmd_retirar();
int pRejilla;
string mirar_pared_sur();
string mirar_rejilla();



public void create()
{
    ::create();

    SetPreIntShort("dentro de");
    SetIntShort("un foso");
    SetIntLong(W("Sigues por el oscuro foso, lleno de agua y barro. Al este "
                 "ves un mont�n de piedras que te impiden ir m�s para all�. "
                 "A simple vista la �nica salida viable que observas es "
                 "volver al oeste.\n"));


    AddDetail(({"pared","paredes"}),
             W("Son paredes de tierra, sin tratar ni nada por el estilo. Los "
               "enanos cavaron el foso y no se preocuparon mucho de "
               "arreglarlo. Parece que s�mplemente intentaron dejar las "
               "paredes lo m�s lisas posible para evitar que nadie pudiese "
               "trepar por ellas. En esta parte del foso observas gran "
               "cantidad de musgo adherido a las rocas.\n"));


    AddDetail(({"musgo","alga","algas"}),
             W("Son sustancias verdosas que se adhieren a la pared y a "
               "las rocas. Observas que en esta zona est�n m�s presentes, y "
               "lo demuestra la pared sur.\n"));


    AddDetail("pared sur",SF(mirar_pared_sur));


    AddDetail(({"rejilla","reja"}),SF(mirar_rejilla));


    AddDetail("rocas",
            W("Son unas rocas artificiales. Permiten el paso del agua, pero "
              "no el de una persona.\n"));


    SetIndoors(0);
    AddRoomCmd(({"quitar","mover","retirar"}),SF(cmd_retirar));
    AddRoomCmd(({"abrir","arrancar"}),SF(cmd_abrir));
    AddExit("oeste",HAB_FOSO_ANNUFAM("foso_01"));
}


int cmd_retirar(string str)
{
    if (!str) return 0;
    if (member(({"algas","musgo","musgo y algas","algas y musgo"}),str) <= -1)
    {
        return notify_fail("�" + query_verb() + " qu�?\n",NOTIFY_NOT_VALID);
    }
    if (!pRejilla)
    {
        write("Retiras las algas y el musgo de la pared y observas una peque�a"
              " rejilla.\n");
        say(W(CAP(TNAME)+ " retira un poco las algas y el musgo de la "
              "pared.\n"));
        pRejilla = 1;
        return 1;
    }
    return notify_fail(W("No hay ning�n c�mulo en la pared "
                         "para " + query_verb() + ".\n"),NOTIFY_NOT_VALID);
}


string mirar_rejilla()
{
    if (!pRejilla) return 0;
    return W("Es una rejilla que facilita la evacuaci�n del foso cuando "
             "llegan las lluvias.\n");
}

string mirar_pared_sur()
{
    if (!pRejilla)
    {
        return W("Es casi id�ntica a la del norte, pero a un metro"
                 " y medio del suelo observas algo brillante, "
                 "tapado por las algas y el musgo.\n");
    }
    return W("Es casi id�ntica a la del norte, pero a un metro y medio del "
             "suelo observas una rejilla.\n");
}


public void reset()
{
    ::reset();
    pRejilla;
}

int cmd_abrir(string str)
{
    if (!pRejilla || !str || member(({"rejilla","reja"}),str) <= -1) return 0;
    return notify_fail(W("Esta rejilla est� bien sujeta a la pared, y no "
                         "podr�s abrirla.\n"),NOTIFY_NOT_VALID);
}
