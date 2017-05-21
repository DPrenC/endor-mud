/****************************************************************************
Fichero: foso_02.c
Autor: Riberales
		[T] Tagoras
Creación: 4/10/2005
Descripción: Un trozo del foso.
[T] 20/03/2009: Añadidos elementos para poder salir del foso desatornilladno la rejilla y usando el hueco que queda para subir hasta la entrada.
[T] 21/03/2009: Mejorado el mirar_rejilla con una peqeuña pista para salir del foso.
[T] 05/01/2012: Añado destornillar como alias de desatornillar y quito W(). Añado mensaje de error cuando el jugador no tiene un destornillador.
****************************************************************************/

#include "./path.h"
#include <moving.h>

inherit HAB_FOSO_ANNUFAM("foso_base");

#define TREPAR ({"por foso","por el foso","foso","por las paredes del foso",\
"las paredes del foso","paredes del foso","paredes de foso","por las paredes",\
"por la pared","por la pared del foso","por pared","por paredes"})

int pRejilla;
int pRejillaQuitada;
int cmd_retirar();
int cmd_pasar();
private int cmd_desatornillar();
string mirar_pared_sur();
string mirar_rejilla();
private string mirar_hueco();

public void create()
{
    ::create();

    SetIntShort("un foso");
    SetIntLong("Sigues caminando por este foso a los pies de Annufam. Al "
               "oeste ves una construcción de rocas que permiten el paso "
               "del agua pero no el tuyo. No parece que aquí haya mucho "
               "más interesante que ver.\n");
    AddDetail(({"pared","paredes"}),
             "Son paredes de tierra, sin tratar ni nada por el estilo. Los "
             "enanos cavaron el foso y no se preocuparon mucho de "
             "arreglarlo, sino para dejarlo lo más liso posible y que fuera "
             "casi impensable trepar por él. En esta parte del foso hay una "
             "mayor presencia de musgo y algas en la roca.\n");
    AddDetail(({"musgo","alga","algas"}),
             "Son sustancias verdosas que se adhieren a la pared y a "
             "las rocas. Observas que en esta zona están más presentes, y "
             "lo demuestra la pared sur.\n");
    AddDetail("pared sur",SF(mirar_pared_sur));
    AddDetail(({"rejilla","reja"}),SF(mirar_rejilla));
	AddDetail("hueco", SF(mirar_hueco));
    AddDetail("rocas", "Son unas rocas artificiales. Permiten el paso del agua, pero no el de una persona.\n");

    SetIndoors(0);
    AddRoomCmd(({"quitar","mover","retirar"}),SF(cmd_retirar));
	AddRoomCmd(({"desatornillar","destornillar"}), SF(cmd_desatornillar));
    AddExit("este",HAB_FOSO_ANNUFAM("foso_01"));
}

int cmd_trepar(string str)
{
	if (str && (-1 < member(TREPAR,str)) && pRejillaQuitada)
	{
		write("Usando el hueco de la rejilla como punto de apoyo, consigues trepar por la pared del foso y alcanzar la entrada a Annufam.\n");
		say(CAP(TNAME)+" se apoya en el hueco de la rejilla y logra alcanzar la superficie.\n");
		if (!find_object(HAB_CIUDAD_ANNUFAM("entrada")))
			load_object(HAB_CIUDAD_ANNUFAM("entrada"));
		TP->move(HAB_CIUDAD_ANNUFAM("entrada"), M_GO, "arriba");
		return 1;
	}
	else
		return ::cmd_trepar(str);
}

int cmd_retirar(string str)
{
    if (!str || (member(({"algas","musgo","musgo y algas","algas y musgo"}),str) <= -1))
    {
        return notify_fail("¿"+ query_verb() + " qué?\n",NOTIFY_NOT_VALID);
    }
    if (!pRejilla)
    {
        write("Retiras las algas y el musgo de la pared y observas una pequeña rejilla.\n");
        say(CAP(TNAME)+ " retira un poco las algas y el musgo de la pared.\n");
        pRejilla = 1;
        return 1;
    }
    return notify_fail("No hay ningún cúmulo en la pared para "
                       + query_verb()+ ".\n",NOTIFY_NOT_VALID);
}

private int cmd_desatornillar(string str)
{
    if (!pRejilla) return 0;
	if (!present("destornillador", TP)) return notify_fail("¡Pero si no tienes ningún destornillador!", NOTIFY_NOT_VALID);
	if (!str || !strlen(trim(str)) || (-1==member(({"rejilla", "reja"}), str)))
		return notify_fail("¿Desatornillar qué?", NOTIFY_ILL_ARG);
	pRejillaQuitada=1;
	write ("Desatornillas la "+str+" de la pared del foso.\n"
			"Hmmmm! Ha quedado un hueco a la vista.\n");
	say(CAP(TNAME)+" desatornilla la "+str+" de la pared del foso.\n", TP);
	return 1;
}

string mirar_rejilla()
{
    if (!pRejilla) return "No ves nada de eso.\n";
	if (!pRejillaQuitada) return "Es una rejilla que facilita la evacuación del foso cuando llegan las lluvias.\n"
								 "Vaya!!! Parece que los obreros enanos olvidaron cubrir los tornillos que sujetan la rejilla a la pared.\n";
    return "Es una rejilla que facilita la evacuación del foso cuando llegan las lluvias.\n";
}

string mirar_pared_sur()
{
    if (!pRejilla)
    {
        return "Es casi idéntica a la del norte, pero a un metro"
               " y medio del suelo observas algo brillante, tapado por las algas y el musgo.\n";
    }
	if (!pRejillaQuitada)
    	return "Es casi idéntica a la del norte, pero a un metro y medio del suelo observas una rejilla.\n";
	return "Es casi idéntica a la del norte, pero a un metro y medio del suelo observas el hueco que ha dejado la rejilla.\n";
}

private string mirar_hueco()
{
	if (!pRejillaQuitada) return "No ves nada de eso.\n";
	return "Hmmm, el hueco que ocupaba la rejilla no es lo suficientemente ancho para dejarte pasar, pero podrías usarlo para trepar.\n";
}

public void reset()
{
    ::reset();
    pRejilla;
	pRejillaQuitada;
}
