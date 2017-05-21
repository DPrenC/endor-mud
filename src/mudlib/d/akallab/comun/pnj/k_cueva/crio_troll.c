/*
DESCRIPCION  : un crio troll de la guarderia
FICHERO      : /d/akallab/comun/pnj/k_cueva/crio_troll.c
MODIFICACION :
24-11-99 [Angor@Simauria] Creacion
29-11-99 [Angor@Simauria] En caso de ser agredido, pide ayuda a cualquier otro
         troll que haya en los alrededores.
30-11-99 [Angor@Simauria] De vez en cuando te lanzan craneos... y eso duele...
--------------------------------------------------------------------------------
*/

//#include <living.h>
#include <combat.h>
#include <properties.h>

#include "path.h"
#include AK_MACRO
inherit NPC;

#define TROLL_NINYO      0
#define TROLL_JOVEN      1
#define PROB_NINYO       70 //70% ninyos, el resto jovenzuelos
#define TROLL_PROB_SEXO  40 //40% M, 60% H
#define TROLL_AGRESIVO   50 //50% de agresivos

#define PROB_LANZAR      10 //10% de las veces te tiraran algo...
#define TIEMPO_LANZAR    20

int ataque(){
  object room,ob;

  while (remove_call_out("ataque") >=0);
  if (random(100)<PROB_LANZAR){
     room=environment(TO);
     for(ob=first_inventory(room);ob;ob=next_inventory(ob))
        {
	    if (ob->QueryIsPlayer() && ob->QueryRace()!=TO->QueryRace())
 	       {
		   write("El troll te lanza un craneo que y te hace algo de daño.\n");
		   ob->Defend(3+random(4), DEFEND_F_NOMSG);
		   }
	    }
     }
  call_out("ataque",TIEMPO_LANZAR);
  return 1;
}

create() {
  int sexo,edad;
  int i,j;
  string troll;

  ::create();
  sexo=(random(100)<TROLL_PROB_SEXO?GENDER_FEMALE:GENDER_MALE);
  edad=(random(100)<PROB_NINYO?TROLL_NINYO:TROLL_JOVEN);
  SetName("troll");
  SetRace("troll");
  SetIds(({"troll","niny"+(sexo==2?"a":"o")}));
  SetAlign(-500);
  SetInt(0);
  SetGender(sexo);
  switch(edad){

  case TROLL_NINYO:
       troll=capitalize(ART2)+" niny"+AO2+" troll";
       SetShort(UNA_2+" niny"+AO2+" troll");
       SetLong(
          "Es un"+AO2+" niny"+AO2+" troll de ojos brilantes. No se esta "
		    "quiet"+AO2+" y parece bastante revoltos"+AO2+". No te quita "
			"la vista de encima.\n");
       AddId("niny"+AO2);
       SetLevel(1+random(4));
       SetAC(1+random(3));
       SetMaxHP(50);
       SetHP(50);
       SetStr(3+random(3));
       SetDex(3);
       SetCon(10);
       SetWeight(40000);
       AddItem("/std/weapon",REFRESH_REMOVE,SF(wieldme),
             ([P_SHORT: "un trozo de roca",
               P_LONG: "Un vulgar trozo de roca.\n",
               P_IDS: ({"trozo","roca"}),
               P_ADS: ({"trozo","vulgar"}),
               P_WC: 2,
               P_SIZE:P_SIZE_LARGE,
               P_NUMBER_HANDS: 1,
               P_RESET_QUALITY: 70,
               P_WEIGHT: 1000,
               P_VALUE:  10,
               P_WEAPON_TYPE: CS_MAZA,
               P_DAM_TYPE: DT_BLUDGEON]) );
       break;

  case TROLL_JOVEN:
       troll=capitalize(ART2)+" niny"+AO2+" troll";
       SetShort(UNA_2+" joven troll");
       SetLong("Es un"+AO2+" joven troll de actitud insolente y "
                 "descarada. Te mira desafiante.\n");
       AddId("joven");
       SetLevel(5+random(5));
       SetAC(2+random(5));
       SetMaxHP(100);
       SetHP(100);
       SetStr(5+random(5));
       SetDex(2);
       SetCon(13+random(4));
       SetWeight(80000);
       if (random(3)!=0){ //66% de que la tenga
       AddItem("/std/weapon",REFRESH_REMOVE,SF(wieldme),
             ([P_SHORT: "una maza",
               P_LONG: "Una tosca maza de madera.\n",
               P_IDS: ({"maza"}),
               P_ADS: ({"tosca"}),
               P_WC: 5,
               P_SIZE:P_SIZE_LARGE,
               P_NUMBER_HANDS: 1,
               P_RESET_QUALITY: 100,
               P_WEIGHT: 4000,
               P_VALUE:  300,
               P_WEAPON_TYPE: CS_MAZA,
               P_DAM_TYPE: DT_BLUDGEON]) );
               }
       break;

  }

  SetAggressive(1);
  SetAttackChance(100);
  if (random(2)==0){//50% charlatanes
     InitChats(8,({
		capitalize(QueryShort())+" te lanza un palo.\n",
	    "Alguien grita enloquecid"+AO2+".\n",
	    troll+" se contonea delante de ti de forma burlona.\n",
	    troll+" te mira de mala manera al tiempo que juguetea con un trozo de roca...\n",
        troll+" da vueltas a tu alrededor.\n",
        capitalize(QueryShort())+" te mira desconfiad"+AO2+".\n",
        troll+" te observa con una mirada agresiva.\n",
        troll+" se limpia el pelaje de parasitos.\n",
        troll+" saca algo de comida de alguna parte y se pone a comersela.\n",
        troll+" te mira fijamente. Resulta inquietante.\n"
        }));
     }

 InitAChats(10,({
    troll+" te grita:'Largate de aqui miserable!'\n",
    troll+" grita enloquecid"+AO2+":'te dice:'Vas a morir!!'\n",
    troll+" grita:'Aaaahhhhhhh!!'\n",
    troll+" tiene una mirada sedienta de sangre.\n",
    troll+" exclama:'Me comere tu corazon y tu sangre tenyira este suelo!'\n",
    troll+" grita:'Hij"+AO+" de mil padres, preparate a dejar la piel'.\n"
    }));
}

init() {
  call_out("ataque",TIEMPO_LANZAR/2+random(TIEMPO_LANZAR));
  ::init();
  return;
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras) {
  object room,ob;
  string str;

  room=environment(TO);
  for(ob=first_inventory(room);ob;ob=next_inventory(ob)) {
	 if (ob && living(ob) && ob!=TO
	    && (ob->QueryRace()=="troll") && !(ob->QueryIsPlayer())
	    && member(ob->QueryEnemies(), TP)==-1)
	    {
	       str=capitalize(ART2)+" troll chilla pidiendo ayuda a "+
		       lower_case(ob->QueryShort())+"\n";
               tell_room(environment(TO),str);
               ob->AddEnemies(TO->QueryEnemies());
	    }
     }
  return ::DoDamage (damage, type, gentle, xtras);
}
