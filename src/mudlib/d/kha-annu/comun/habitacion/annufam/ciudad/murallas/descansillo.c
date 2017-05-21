/****************************************************************************
Fichero: escalera_01.c
Autor: Riberales
Creación: 7/10/2005
Descripción: Plaza de Annufam
****************************************************************************/

#include "./path.h"
#include <moving.h>


inherit HAB_MURALLAS_ANNUFAM("escalera_base");

int subir()
{
    write("Comienzas a subir las escaleras.\n");
    say(W(CAP(TNAME) + " se va subiendo las escaleras.\n"));
    TP->move(HAB_MURALLAS_ANNUFAM("descansillo_a_murallas"),M_SILENT,"arriba");
    return 1;
}

int bajar()
{
    write("Comienzas a bajar las escaleras.\n");
    say(W(CAP(TNAME) + " se va bajando las escaleras.\n"));
    TP->move(HAB_MURALLAS_ANNUFAM("ab_a_descansillo"),M_SILENT,"abajo");
    return 1;
}


public void create()
{
    ::create();
    SetIntShort("un descansillo en la torre de Annufam");
    SetIntLong(W("Estás en el descansillo que hay en la torre que comunica "
                 "las murallas de Annufam con la ciudad en sí. Esta parte es "
                 "bastante pobre en decoración, simplemente el estandarte "
                 "que ya has visto en varios lugares, y las interminables "
                 "escaleras, que te llevan arriba o abajo.\n"));

    AddExit("arriba",SF(subir));
    AddExit("abajo",SF(bajar));
}