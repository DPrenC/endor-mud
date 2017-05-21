/*
DESCRIPCION  : huesped de una posada
FICHERO      : /d/akallab/comun/pnj/std/huesped.c
MODIFICACION : 17-10-98 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <combat.h>
#include <gremios.h>


inherit NPC;

#define ARMADO 40 //probabilidad de que este armado al despertarse

int despierto;    //esta el huesped despierto? no[0], si[1]

void dormir();
void despertar();
int  hay_ladron(string s);

int SetEstado(int i){despierto=i; (i==0?dormir():despertar()); return 1;}

create() {
  ::create();
 SetName("huesped");
  SetGender(random(2)==0?GENDER_MALE:GENDER_FEMALE);
  SetShort(UNA_2+" huesped dormid"+AO2);

  SetRace("orco");
  AddId(({"huesped","orco"}));
  SetLevel(6+random(5));
  SetAlign(-500);
  SetAC(0+random(3));
  SetMaxHP(100+random(20));
  SetHP(QueryMaxHP());
  SetStr(8+random(5)); SetDex(2+random(3)); SetInt(2); SetCon(10+random(5));

  if (random(100)<=ARMADO){
     AddItem("/std/weapon",REFRESH_REMOVE,SF(wieldme),
        ([P_SHORT: "una larga daga",
          P_LONG: "Una larga daga que parece peligrosa.\n",
          P_IDS: ({"daga",}),
          P_ADS: ({"larga","una"}),
          P_WC: 3,
          P_SIZE:P_SIZE_SMALL,
          P_NUMBER_HANDS: 1,
          P_RESET_QUALITY: 95,
          P_WEIGHT: 750,
          P_VALUE:  400,
          P_WEAPON_TYPE: CS_CUCHILLO,
          P_DAM_TYPE: DT_PIERCE]) );
     }
  SetGuild(GC_LUCHADOR);

   dormir();
}


void dormir(){
  despierto=0;
  SetShort(UNA_2+" huesped dormid"+AO2);
  SetLong(
     "Es un"+AO2+" de los huespedes alojados en esta posada. En este momento está "
     "durmiendo placidamente en la cama de la habitacion.\n");

  InitChats(12,({
    "'Zzzzzz..... Zzzzzz...'.\n",
    capitalize(ART2)+" huesped da media vuelta en la cama.\n",
    "'Zzzz....Zzzz.....Zzzz....'.\n",
    capitalize(ART2)+" huesped esta a punto de despertarse por el ruido que haces.\n",
    }));
  return;
}

a_dormir() {
  object ob;
  ob=present(TP,environment(TO));
  if (!ob) dormir();
  else call_out("a_dormir",60);
}

void despertar(){
  object ob;
  despierto=1;
  SetShort(UNA_2+" huesped");
  SetLong(
     "Es un"+AO2+" de los huespedes alojados en esta posada. En este momento esta\n"
     "despiert"+AO2+" y de muy mal humor ya que tu estas en su habitacion.\n");

  write(MAY(ART2)+" huesped se despierta debido al ruido que haces.\n");
  say(
  MAY(ART2)+" huesped se despierta debido al ruido que hace "+NOMBRE+" en la habitacion.\n",TP);

  ob=present("cofre",environment(TO));
  if (ob) {
      if (ob->QueryEstado()==1) hay_ladron("cofre");
      }

  ob=present("armario",environment(TO));
  if (ob) {
      if (ob->QueryEstado()==1) hay_ladron("armario");
      }

  //object present(mixed str, object ob)

  InitChats(20,({
    MAY(ART2)+" huesped te dice:'Se puede saber que demonios haces tu en mi habitacion?'.\n",
    MAY(ART2)+" huesped te dice:'Largate de mi habitacion antes de que me enfade.'\n",
    MAY(ART2)+" huesped exclama:'Llamare a los guardias si no te vas de aqui!'\n"
    }));
 call_out("a_dormir",60);
 return;
}

int hay_ladron(string s){
  write(MAY(ART2)+" huesped te dice:' Que hace mi "+s+" abierto? Maldit"+AO+" ladron"+A_+"!'\n");
  Kill(TP);
  //aparece guardia??
  //apuntar como ladron
  return 1;
}