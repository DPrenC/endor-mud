/************************************************************************/
/*                                                                      */
/*  Tortuga Gigante del Lago                                            */
/*                                                                      */
/*  [k] Kintups (jobarmar@eui.upv.es)                                   */
/*                                                                      */
/*  03-05-99: Creacion [k]                                              */
/*                                                                      */
/************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>

inherit NPC;

create()
{
    ::create();
    SetStandard("una tortuga gigante","tortuga",25+random(5),GENERO_FEMENINO);
    SetIVision(-40);
    SetSize(P_SIZE_LARGE);
    SetShort("una Tortuga gigante");
    SetLong("Puedes ver una tortuga gigante, mide poco más de un metro. Su caparazón, "
    "en forma de cúpula, parece extremadamente duro.\n");
    AddId(({"tortuga","Tortuga","tortuga gigante"}));
    SetWeight(160000);
    AddWalkZones(CAOSHAB);
  SetGoChance(1);
    SetMsgIn("viene lentamente");
    SetMsgOut("se va lentamente");

    SetHands( ({ ({"pata derecha",0,8}),({"pata izquierda",0,8}),({"boca",0,8}) }) );
    AddDefence(DT_NOAIR,100);
}
