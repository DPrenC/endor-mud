/*
DESCRIPCION    : Monje fantasma
FICHERO        : /d/lad-laurelin/pnj/lago/monjef.c
CREACION       : 24-11-98 [Alura]
U.MODIFICACION :
*/

#include <rooms.h> // solo para que pueda perseguir
#include <properties.h>
#include <magia.h>
#include "path.h"
inherit "std/undead";

private string mensaje;

string accion_monje(){
string msg;
int num;

num=random(7);
    switch(num) {
      case 0: msg  =
"Ves un monje putrefacto limpiando afanosamente la habitacion con una escoba.\n";
              break;
      case 1: msg =
"Un monje muerto te mira y vuelve a su faena, como si no le importaras.\n";
              break;
      case 2: msg =
"Un tipo que huele mal con sotana esta leyendo un libro. No te presta atencion\n";
              break;
      case 3: msg =
"Es un humano bastante demacrado que lleva un habito hecho jirones.\n";
			  break;
	  case 4: msg =
"El tiempo lo ha tratado mal, esta hecho un asco. Parece mas muerto que vivo.\n";
			  break;
	  case 5: msg =
"Alguien lo debio traer de la muerte para continuar su vida anterior.\n";
			  break;
	  default: return "Es un muerto viviente.\n";
 }
return msg;
}



create() {
  ::create();
  mensaje=accion_monje();
  SetName("Monje fantasma");
  SetShort("un monje\n");
  SetLong(mensaje);
  SetRace("no-muerto");
  SetIds(({"fantasma","muerto","monje"}));   //identificativos
  SetAds(({"el","un","demacrado"}));   //adjetivos feo, alto...
  SetLevel(9);
  SetAlign(10);
  SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
  SetAC(1);   //armadura de piel
  SetGender(GENDER_MALE);
  SetHands(({({"mano izquierda",0,1}),({"mano derecha",0,1})}));
  SetDex(7);
  SetInt(7);
  SetCon(11);
  SetStr(10);
  SetAggressive(0);  // agresivo 1=si, 0=no
  SetHP(100);
  SetMaxHP(100);

  /*                        Resistencias y Defensas                           */
  /* Resistencias: El pnj resistente a algo lo es en el porcentaje que marque
                  el AddResistance(). En el caso de hechizos, el hechizo puede
                  ser repelido o devuelto contra el lanzador. Consecuencia: los
                  no-muertos son una putada si no tienes hechizos de fuego o
                  magia pura.
  */

  // Inmunes al frio (estos monjes nop)
   AddResistance(ST_COLD, 90);
   AddResistance(DT_COLD, 90);

  // Tambien a todo veneno (estan muertos, que caray!)
   AddResistance(ST_POISON, 100);
   AddResistance(DT_POISON, 100);

  // Tambien lo son a la asfixia (por gas o por ahogamiento)
  AddResistance(ST_GAS, 100);
  AddResistance(DT_NOAIR, 100);

  // Resistencia parcial a los ataques psiquicos
  // NOTESE que esta puede variar dependiendo del tipo de no-muerto
  AddResistance(ST_PSYCHO,60);

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
  AddDefence(DT_FIRE, -25); // El fuego les hace danyo
  AddDefence(DT_ACID, -15); // Para permitir que el agua bendita o las armas
                            // bendecidas les hagan ESTE tipo de danyo
AddDefence(DT_ELECTRO, -25); // Una especie de fuego cutre

}
