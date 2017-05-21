/****************************************************************************
Fichero: pnj_Base.c
Autor: Riberales
Fecha: 05/02/2006
Descripción: El pnj tanto para guardias como para mineros.
****************************************************************************/


#include "path.h"
#include <moving.h>





inherit NPC;



private static int pScreamHealth;

public int QueryPnjMinasKhaAnnu() { return 1; }

public int SetScreamHealth(int h) { return pScreamHealth = h; }
public int QueryScreamHealth() { return pScreamHealth; }

int cmd_gritar(string str)
{
    "/bin/mortal/_gritar"->main(str);
    return 1;
}

create()
{
    ::create();
    enable_commands();
    SetIds(({"pnj_minas"}));
    add_action("cmd_gritar", "gritar");

}


public int AddEnemy(object en)
{
    int result = ::AddEnemy(en);
    if (result == 1 && (!PO || !PO->id("guardian_minas")))
     // Avisa a sus colegas guardias de la room.
    {
        filter(all_inventory(environment()),(:(   $1->id("guardian_minas")
                                               && $1 != TO ? $1->AddEnemy($2)
                                           : 0):), en);
    }
    return result;
}
// función sobrecargada para que el minero grite cuando está luchando.
// El porcentaje se controla en la función QueryScreamHealth()
public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras)
{
    int res = ::Defend(dam, dam_type, flags, &xtras);
    if (QueryHealth() <= QueryScreamHealth() && d2() == 1)
    // grita
    {
        command_me("gritar ¡SOCORRO! SOCORRO! ¡AYUDAAAAA!");
    }
    return res;
}