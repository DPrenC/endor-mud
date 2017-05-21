/****************************************************************************
Fichero: base_civil_crowiano.c
Autor: Kastwey
Fecha: 25/05/2007
Descripción: Fichero base para los pnjs que no son guardias de Crowy
****************************************************************************/


#include "path.h"
#include DOM_SYS "crowiano.h"
#include <gremios.h>

inherit NPC;

private int pEdad, pBorracho;

public int SetEdad(int e) { return pEdad = e; }
public int QueryEdad() { return pEdad; }

public int SetBorracho(int b) { return pBorracho = b; }
public int QueryBorracho() { return pBorracho; }


public int QueryCrowiano() { return 1; }

private status existe_jugador(string jugador)
{
    return find_savefile(jugador)||find_object(lower_case(jugador));
}


public varargs void Die(mixed silent)
{
    object asesino, own;
    string real;

    asesino = QueryKiller();
    if (!asesino = QueryKiller()) return ::Die(silent);
        if (asesino->QueryIsPet() && (own = asesino->QueryOwner())) asesino = own;
    if (!query_once_interactive(asesino)) {return ::Die(silent);}
    if(!existe_jugador((real = NREAL(asesino)))) {return ::Die(silent);}
    ASESINOS->SetAsesino(real,pEdad, QueryGender(), pBorracho, QueryGuild() == GC_GUERREROS);
    return ::Die(silent);
}
