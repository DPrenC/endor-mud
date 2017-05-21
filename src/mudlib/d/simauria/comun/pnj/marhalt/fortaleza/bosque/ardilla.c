/*
DESCRIPCION  : una ardilla
FICHERO      : /d/simauria/comun/pnj/simauria/fortaleza/bosque/ardilla.c
MODIFICACION : 29-10-98 [Maler]Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <properties.h>

inherit NPC;

create() {
    ::create();
    SetStandard("una ardilla","ardilla",2,GENDER_FEMALE);
    SetShort("una ardilla");
    SetLong(
      "Ves a una alegre ardilla que juega tranquilamente subiendo y bajando de los "
      "árboles. Es un pequeño animal pacífico que tan solo se preocupa de buscar su "
      "comida y sobrevivir a sus depredadores.\n");

    SetWeight(500);
    SetIds(({"ardilla"}));
    SetAds(({"alegre","simpatica","simpática"}));
    SetGoChance(25);
    SetDex(3);
    SetStr(1);
    SetInt(1);
    SetCon(1);
    SetMaxHP(15);
    SetHP(QueryMaxHP());
    SetAC(1);
    SetHands(({({"un mordisco",0,1})}));
    InitChats(10,({
       "Una ardilla te mira con una tierna cara.\n",
       "Una ardilla se te acerca, e intuyes que tiene ganas de jugar.\n",
       "Una ardilla trepa por los arboles, rebosando alegria.\n"
       }));

    InitAChats(10,({
       "La ardilla te mira con los ojos llorosos.\n",
       "La ardilla no comprende como puedes pegarle sin haber hecho nada malo.\n",
       "Notas un extranyo sentimiento al observar a la magullada ardilla.\n"
       }));
    AddWalkZones(ROOMFB(""));
}
