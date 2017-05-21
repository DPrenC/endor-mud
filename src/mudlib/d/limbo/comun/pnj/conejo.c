/*
DESCRIPCION  : conejo para el parque de novatos
FICHERO      : /d/limbo/comun/pnj/conejo.c
MODIFICACION : 08-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit NPC;

create() {
    ::create();
    SetStandard("un conejo","conejo",([ GC_TORPE: 2]),GENDER_MALE);
    SetShort("un pequeño conejo");
    SetLong(
    "Es un pequeño y encantador conejito blanco. Te mira con sus ojos curiosos.\n");
    AddId("conejo");
    AddId("conejito");
    SetAds(({"pequeño","pequenyo","blanco","encantador"}));
    SetSize(P_SIZE_SMALL);
  SetMaxHP(10+(QueryLevel()-1)*5);
  SetHP(QueryMaxHP());
    SetStr(QueryStr()-1);
    SetDex(QueryDex()+1);
    SetInt(1);
    SetHands( ({ ({"mordisco",TD_PENETRACION,2}) }) );
    SetWeight(2000);
    SetGoChance(30);
    SetNoGet("El conejo da un salto y se aleja de ti.\n");
    InitChats(3,({"El pequeño conejo mordisquea un poco de hierba.\n",
                  "El pequeño conejo olisquea el aire como si presintiera algún peligro.\n",
                  "El pequeño conejo mira temeroso a su alrededor.\n"}));
    SetDesmembrableEn(({CABEZA,PATA_PEQUENYA,PATA_PEQUENYA,PATA_PEQUENYA,PATA_PEQUENYA}));
}

