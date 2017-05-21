/**************************************************************************
fichero: elearca.c
Autor: kastwey
Creación: 20/07/2005
Descripción: La enana elearca, tendera de la tienda de armas
**************************************************************************/
#include <combat.h>
#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;

public void create()
{
    ::create();
    SetStandard("Elearca","enano",10,GENDER_FEMALE);
    SetLong(W("Es una enana de constitución recia, aunque con la cara ya "
              "mostrando unas arrugas de vejez y cansancio. Parece que está "
              "algo malhumorada. Va de aquí para allá ordenando cosas y no "
              "te presta mucha atención.\n"));
    Set(P_CANT_STEAL,"Sería más sencillo robarle al mismísimo Belthain que "
                     "a esta enfurecida enana.\n");
/* CANT_FIGHT solo acepta 0 o 1
    Set(P_CANT_FIGHT,W("EHMMM. Con lo enfadada que parece, no crees que sea "
                       "muy aconsejable iniciar un combate... Piensas que mejor "
                       "intentarlo con alguien que parezca menos intimidante.\n"));
*/
	Set(P_CANT_FIGHT, 1);
}


int cmd_lanzar(string str)
{
    object que;
    string a, b, short, genero;
    int peso;
    if (!str) return 0;
    if (sscanf(str,"%s contra %s",a,b) < 2) return 0;
    if (!(que = present(a,TP))) return 0;
    if (present(b,environment()) != TO) return 0;
    if (que->Query(P_NOGIVE) || que->Query(P_NODROP)) return 0;
    short = que->QueryShort() || que->QueryName() || "algo";
    genero = (que->Query(P_GENDER) == GENDER_FEMALE?"la":"lo");
    write("Intentas lanzar " + short + " contra Elearca.\n");
    say(W(CAP(TNAME) + " intenta lanzar " + short + " contra Elearca."),TP);
    write(W("Con un ágil movimiento, Elearca agarra " + short + " y te " +
    genero + " arroja.\n"));
    say(W("Con un ágil movimiento, Elearca atrapa " + short + " y se " +
          genero + " arroja.\n"),TP);
    peso = que->QueryWeight();
    TP->Defend((peso / 100?peso / 100:15),DT_PIERCE,DEFEND_NOMSG);

    que->move(environment(),M_SILENT);
    return notify_fail("Visto lo visto, desistes en tu ataque.\n",
                       NOTIFY_NOT_VALID);
}



public void init()
{
    ::init();
    add_action("cmd_lanzar","lanzar");
}
