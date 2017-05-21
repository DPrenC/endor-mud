/*
DESCRIPCION    :
FICHERO        :
CREACION       :
U.MODIFICACION :
*/

#include <rooms.h> // solo para que pueda perseguir
#include <properties.h>
#include <materials.h>
#include "path.h"
#include <magia.h>

inherit "std/undead";
int car;


create() {
  car=random(10);
  ::create();
  SetName("un esqueleto");
  SetShort("Un esqueleto vagabundea por la zona y te mira");
  SetLong("Es todo huesos, no lleva armas.\n");
  SetRace("no-muerto");
  SetIds(({"esqueleto","muerto"}));   //identificativos
  SetAds(({"el","un","tenebroso"}));   //adjetivos feo, alto...
  SetLevel(1+car);   //nivel
  SetAlign(-500);   //alineamiento mas de cero bueno
  SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
  SetAC(1);   //armadura de piel
  SetGender(GENDER_MALE);// male , female, ?neutral? ...
  SetHands(({({"mano izquierda",0,1}),({"mano derecha",0,1})}));  //manos o garras o ...
  SetDex(2+car);
  SetInt(1+car);
  SetCon(2+car);
  SetStr(3+car);
  SetAggressive(1);  // agresivo 1=si, 0=no
  SetHP(50+car*8);  //puntos de vida.
  SetMaxHP(30+car*8);

 // Inmunes al frio
  AddResistance(ST_COLD, 100);
  AddResistance(DT_COLD, 100);

 // Tambien a todo veneno (estan muertos, que caray!)
  AddResistance(ST_POISON, 100);
  AddResistance(DT_POISON, 100);

 // Tambien lo son a la asfixia (por gas o por ahogamiento)
 AddResistance(ST_GAS, 100);
 AddResistance(DT_NOAIR, 100);

 // Resistencia total a los ataques psiquicos
 // NOTESE que esta puede variar dependiendo del tipo de no-muerto
 AddResistance(ST_PSYCHO, 100);

 /* Defensas: El pnj tiene una bonificacion de n en el danyo que recibe con el
             tipo de danyo X definido con AddDefence(X,n). Al ser golpeado con
             el tipo de danyo X, se le restaran n puntos de danyo al danyo pro-
             ducido. Notese que esto permite definir "debilidades" sin mas que
             definir una defensa negativa contra un tipo de danyo particular.
 */

 // Defensas contra los ataques fisicos
 AddDefence(DT_BLUDGEON, random(QueryLevel())/2); // Los golpes le hacen mas danyo
 AddDefence(DT_PIERCE, random(QueryLevel())+11);  // que los pinchazos (que le vas a pinchar!!)
 AddDefence(DT_SLASH, random(QueryLevel())+4);    // o que los cortes...

 /*                              Debilidades                                 */

 AddDefence(DT_MAGIC,-20); // Al ser criaturas magicas, la magia les afecta mucho
 AddDefence(DT_FIRE, -15); // El fuego les hace danyo
 AddDefence(DT_ACID, -10); // Para permitir que el agua bendita o las armas
                           // bendecidas les hagan ESTE tipo de danyo
AddDefence(DT_ELECTRO, -5); // Una especie de fuego cutre



  InitChats(2,({
  "Jejejeeeeee ...\n",
  "moriraaaaaaaaassssss jajajajajaaaaa\n"}));

  InitAChats(2,({
  "no entraras a la issslaaa!!!\n","mueeereee\n"}));

}