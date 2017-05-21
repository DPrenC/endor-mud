/*
DESCRIPCION  : una ardilla
FICHERO      : /d/akallab/comun/pnj/animal/ardilla.c
MODIFICACION : 29-10-98 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/

inherit NPC;

#include <properties.h>  //por el PSIZE
#include <living.h>      //por el GENDER

create() {
  ::create();
  SetName("ardilla");
  SetShort("una ardilla");
  SetLong(
    "Ves a una alegre ardilla que juega tranquilamente subiendo y bajando de los "
    "arboles. Es un pequenyo animal pacifico que tan solo se preocupa de buscar su "
    "comida y sobrevivir a sus depredadores.\n");

  SetRace("ardilla");
  SetGender(GENDER_FEMALE);
  SetWeight(500);
  SetIds(({"ardilla"}));
  SetAds(({"alegre","simpatica"}));
  SetLevel(2);
  SetGoChance(25);
  SetMaxHP(15);
  SetHP(13);
  SetDex(3);
  SetStr(1);
  SetInt(1);
  SetCon(1);
  SetAlign(20);
  SetAC(1);
  SetHands(({({"un mordisco",0,1})}));
  InitChats(10,({
     "Una ardilla te mira con una tierna cara.\n",
     "Una ardilla se te acerca, e intuyes que tiene ganas de jugar.\n",
     "Una ardilla trepa por los arboles, rebosando alegria.\n"  }));

  InitAChats(10,({
     "La ardilla te mira con los ojos llorosos.\n",
     "La ardilla no comprende como puedes pegarle sin haber hecho nada malo.\n",
     "Notas un extranyo sentimiento al observar a la magullada ardilla.\n" }));
}
