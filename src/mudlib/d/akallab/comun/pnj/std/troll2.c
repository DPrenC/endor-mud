/*
DESCRIPCION  : un habitante troll de las cuevas
FICHERO      : /d/akallab/comun/pnj/std/troll2.c
MODIFICACION : 19-11-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <combat.h>
#include <gremios.h>


inherit NPC;

#define TROLL_NINYO  0
#define TROLL_JOVEN  1
#define TROLL_ADULTO 2
#define TROLL_VIEJO  3

#define TROLL_PROB_SEXO  40 //40% M, 60% H
#define TROLL_AGRESIVO   25 //25% de agresivos
#define TROLL_MERODEADOR 20 //20% de merodeadores
#define TROLL_PROB ({0,20,50,90,100}) //20%,30%,40%,10%

create() {
  int edad,i,j;
  int *prob;
  string troll;

  ::create();
  Set("pnj_zona",1);  //pnj atrapado en su zona de territorio

  SetName("troll");
  SetRace("troll");
  SetIds(({"troll"}));
  SetAlign(-500);
  SetInt(0);

  SetGender((random(100)<TROLL_PROB_SEXO?GENDER_FEMALE:GENDER_MALE));

  prob=TROLL_PROB;
  i=random(100);
  edad=0;
  do{edad++;
    }while (i>prob[edad]);
  edad--;

  switch(edad){
  case TROLL_NINYO:
          troll=capitalize(ART2)+" niny"+AO2+" troll";
          SetShort(UNA_2+" niny"+AO2+" troll");
          SetLong(
            "Es un"+AO2+" niny"+AO2+" troll de ojos brilantes. No se esta quiet"+AO2+" y "
            "parece bastante revoltos"+AO2+". No te quita la vista de encima.\n");
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
          troll=capitalize(ART2)+" joven troll";
          SetShort(UNA_2+" joven troll");
          SetLong(
            "Es un"+AO2+" joven troll de actitud insolente y descarada. Te mira desafiante.\n");
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

  case TROLL_ADULTO:
          troll=capitalize(ART2)+" troll adult"+AO2;
          SetShort(UNA_2+" troll adult"+AO2);
          SetLong(
            "Es un troll adult"+AO2+". Las cicatrices de su cuerpo son una clara muestra de "
            "su experiencia en combate. Debe ser "+UNA_2+" enemig"+AO2+" dur"+AO2+" de pelar.\n");
          AddId("adult"+AO2);
          SetLevel(10+random(6));
          SetAC(3+random(5));
          SetMaxHP(150);
          SetHP(150);
          SetStr(7+random(7));
          SetDex(1);
          SetCon(15+random(5));
          SetWeight(110000);
          AddItem("/std/weapon",REFRESH_REMOVE,SF(wieldme),
             ([P_SHORT: "una maza",
               P_LONG: "Una tosca maza de madera.\n",
               P_IDS: ({"maza"}),
               P_ADS: ({"tosca"}),
               P_WC: 6,
               P_SIZE:P_SIZE_LARGE,
               P_NUMBER_HANDS: 1,
               P_RESET_QUALITY: 90,
               P_WEIGHT: 5000,
               P_VALUE:  400,
               P_WEAPON_TYPE: CS_MAZA,
               P_DAM_TYPE: DT_BLUDGEON]) );
          break;

  case TROLL_VIEJO:
          troll=capitalize(ART2)+" viej"+AO2+" troll";
          SetShort(UNA_2+" viej"+AO2+" troll");
          SetLong(
            "Es "+UNA_2+" viej"+AO2+" troll. Su cuerpo muestra claramente el paso del tiempo, "
            "pero tiene la sufiente experiencia como para defenderse bien.\n");
          AddId("viej"+AO2);
          SetLevel(8+random(5));
          SetAC(3+random(2));
          SetMaxHP(125);
          SetHP(125);
          SetStr(6+random(5));
          SetDex(1);
          SetCon(12+random(3));
          SetWeight(90000);
          if (random(2)!=0){ //50% de que la tenga
          AddItem("/std/weapon",REFRESH_REMOVE,SF(wieldme),
             ([P_SHORT: "un hueso",
               P_LONG: "Un gran trozo de hueso.\n",
               P_IDS: ({"trozo","hueso"}),
               P_ADS: ({"gran"}),
               P_WC: 4,
               P_SIZE:P_SIZE_LARGE,
               P_NUMBER_HANDS: 1,
               P_RESET_QUALITY: 100,
               P_WEIGHT: 6000,
               P_VALUE:  300,
               P_WEAPON_TYPE: CS_MAZA,
               P_DAM_TYPE: DT_BLUDGEON]) );
               }
          break;
  }
  SetGuild(GC_LUCHADOR);
  SetAggressive(0);
  SetGoChance(0);
  if (random(3)==0){
     InitChats(10,({
        troll+" te mira desconfiad"+AO2+".\n",
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
