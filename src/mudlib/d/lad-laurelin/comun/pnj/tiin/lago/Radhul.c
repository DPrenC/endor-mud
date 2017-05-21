/*
Descripción: 	Radhul el Maestro Vampiro (personaje de Quest)
Creado por:	Alura
Fecha:		12/6/2000
Propiedades: 	Es un vampiro en toda regla
*/

#include "path.h"
#include <properties.h>
#include <living.h>
#include <combat.h>
#include <spellmonster.h>
#include <materials.h>
#include <colours.h>
#include <nightday.h>
#include <magicd.h>

inherit "/obj/monster/spellundead";

public int drenar();
public int despertar();
int torpeza();

Defend(dam, damtype, weapon) {

   string material;
   string msgcruz,msgcollar;
   object cruces,collarajos;
   cruces=present("cruz",TP)||({});
   collarajos=present("collar de ajos",TP)||({});

  // Las cruces le haran daño siempre:
   if (cruces!=({}))
            if (cruces->QueryEquipped()==TP)
	 {
	    TO->SetDex(15);
	    TO->SetStr(15);
	    msgcruz="\n"+"Radhul esquiva la mirada de la cruz y parece que le cuesta atacarte.\n"TC_NORMAL;
	    tell_object(TP, TC_YELLOW+msgcruz+TC_NORMAL);
       	 }
    // Si lleva collar de ajos el bicho regenera la vida mas lentamente y no piensa con claridad:
     if (collarajos!=({}))
             if (collarajos->QueryEquipped()==TP)
     {
	TO->SetInt(20);
	TO->SetRegHP(1);
	 msgcollar="\n"+"Radhul gruñe cuando huele tu collar y se tambalea por momentos.\n"TC_NORMAL;
	tell_object(TP, TC_YELLOW+msgcollar+TC_NORMAL);
     }
   ::Defend(dam, damtype, weapon);
} //end Defend


public varargs void Die (mixed silent) {
  tell_object(TP,"El antiquísimo hechicero grita de dolor y rabia mientras ve como se le acerca\n"
"la verdadera muerte. El cuerpo de Radhul se retuerce y se convierte en polvo\n"
"y lo único que queda de él es la medalla que llevaba en el cuello.\n");
  //destruct(TO);
  ::Die(silent);
}


int puedeParalizar(string str){
//funcion temporal
//quiero modificarla para q segun el tipo de hechizo funcione el setDelaycombat (o nada)
if (upper_case(str)=="'FRIO INTENSO' CONTRA RADHUL"){
	tell_object(TP,TC_BLUE"Radhul se quita el HIELO de encima sin problemas!\n"TC_NORMAL);
	return 1;
 }
 else {return 0;}
}

init(){
   ::init();
   add_action("puedeParalizar","magia");
}

create() {
  ::create();
 seteuid(getuid());
  SetStandard("Radhul el Maestro Vampiro","Radhul",30,GENERO_MASCULINO);
  SetIds(({"Radhul"}));
  //SetShort("Radhul el Maestro Vampiro");
  SetLong(
 "  Tienes ante ti a un antiguo  mago y  ahora  poderoso  vampiro  ataviado\n"
 "soverbiamente, de mirada penetrante y abrumadora. El aura de grandeza que\n"
 "desprende hace que te sientas poca cosa.\n"
 "En su cuello lleva un hermoso medallón que no concuerda con su vestimenta .\n");

  SetRace("no-muerto","vampiro");
  despertar();
  SetWeight(80000);
  SetGoChance(0);
  SetWhimpy(20);

  //SetLevel(45);
  SetAlign(-1500);
  SetCastChance(70);

  SetStr(30);
  SetDex(33);
  SetCon(27);
  SetInt(30);

  AddItem("/d/lad-laurelin/comun/objeto/magico/medal");

  AddResistance(DT_COLD, 100);

  AddResistance(DT_POISON, 100);

  AddResistance(DT_NOAIR, 80);

  AddDefence(DT_BLUDGEON, 5);
  AddDefence(DT_PIERCE, 5);
  AddDefence(DT_SLASH, 7);
  AddDefence(DT_MAGIC,-1);
  AddDefence(DT_FIRE, 1);
  AddDefence(DT_ACID, 3);
  AddDefence(DT_ELECTRO, 6);

  SetHands(({({"mano derecha",0,12}),({"mano izquierda",0,12}),({"colmillos",0,6})}));

  AddSpell("drenar_vida",
           ([
             S_CHANCE:70,
             S_COMBAT_DELAY:1,
             S_DELAY:2,
             S_SIMULT:1,
             S_VICTIMS:1,
             S_DAMTYPE:DT_MAGIC,
             S_MINDAM:10,
             S_MAXDAM:20,
             S_FUN:SF(drenar),
             S_GLOBAL_ENVMSG:(TC_RED"Lod ojos de Radhul se vuelven rojos.\n"TC_NORMAL),
             S_ENVMSG:([
                       MSG_NORMAL:
                       ({"Radhul el vampiro muerde con ansia  a @@VicName@@ y ves como sus ojos se vuelven rojos\n"
                       ".\n","@@VicName@@ palidece y grita de dolor.\n"}),

                       MSG_DEAD:
                       ({"@@VicName@@ se agita con temblores de muerte y cae al suelo totalmente desangrado.\n"
                       "Oyes como un cuerpo cae al suelo seguido de una maliciosa y estridente risa.\n"})
                       ]),

            S_VICMSG:([
                      MSG_NORMAL:
                      (" Radhul te clava sus grandes colmillos con ahínco y notas cómo se te escapa "
                      "la vida.\n"),

                      MSG_DEAD:
                      ({"Estás tan mareado que caes al suelo inconsciente. Mientras, Radhul acaba con\n"
                      "la última gota de tu sangre.\n"
                      })
           ]),


          ])
  );

 AddSpell("torpeza",
           ([
             S_CHANCE:70,
             S_COMBAT_DELAY:1,
             S_DELAY:2,
             S_SIMULT:1,
             S_VICTIMS:1,
             S_DAMTYPE:DT_PSYCHO,
             S_MINDAM:0,
             S_MAXDAM:0,
             S_FUN:SF(torpeza),
             S_GLOBAL_ENVMSG:(TC_PURPLE"Radhul torna sus ojos en blanco.\n"TC_NORMAL),
             S_ENVMSG:([
                       MSG_NORMAL:
                       ("Radhul apunta en dirección a @@VicName@@ y pronuncia : - Torpe .\n")]),

             S_VICMSG:([
                      MSG_NORMAL:
                      (" Radhul te apunta con un largo y huesudo dedo y pronuncia: - Torpe. "
                      "Y de repente te cuesta más moverte.\n")
           ]),


          ])
  );
}

drenar(mapping sp, object *vic) {
 object *en,ene,bicho;
 int danyo;

 bicho=TO;
 en=QueryEnemies()||({});
 if(!sizeof(en)) return 0;
 ene=en[random(sizeof(en))];
 if (!ene->QueryIsNpc() && !ene->QueryIsPet()) {
   danyo=25+random(15);
   ene->AddHp(-danyo);
   bicho->AddHp(danyo);
   vic=({ene});
  // tell_object(ene,TC_RED"El Vampiro te clava sus grandes colmillos con ahínco y notas cómo se te escapa la vida.\n"TC_NORMAL);
  // tell_room(environment(),TC_RED"El poderoso Radhul clava sus grandes colmillos en "+ene->QueryName()+" y empieza a sorber.\n"TC_NORMAL);
  }
 return sp;
}

torpeza(mapping sp, object *vic){
   object *en,ene;
   en=QueryEnemies()||({});
   if (sizeof(en)) {
     ene=en[random(sizeof(en))];
     ene->SetDexBonus(-1);
     vic=({ene});
    // tell_room(environment(),TC_GREEN"El Vampiro apunta con su esquelético dedo a "+ene->QueryName()+" y pronuncia : - Masss torpe...\n"TC_NORMAL);
     //tell_object(ene,TC_GREEN" Te sientes menos diestro.\n"TC_NORMAL);
   }
   return sp;
}

public int despertar()  //dependiendo de si es de noche o dia sera agresivo o no
{
 mixed tipodia;
 tipodia=(mixed *)NIGHTDAY->QueryState();

 if (tipodia==ND_NIGHT || tipodia==ND_PREDAWN || tipodia == ND_PRENIGHT)
    SetAggressive(1);   //esta despierto
 else
    SetAggressive(0); //esta durmiendo
 return 1;
}

