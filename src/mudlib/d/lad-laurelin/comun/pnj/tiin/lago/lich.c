/*
Descripción: 	Un Lich
Creado por:	Alura
Fecha:		18/7/2000
Propiedades: 	Es un lich, liche o como se diga

21-11-2001 modificado por cheto para que de el tornillo del quest de la copa.
*/

#include "path.h"
#include <properties.h>
#include <living.h>
#include <combat.h>
#include <spellmonster.h>
#include <materials.h>
#include <magia.h>
#include <colours.h>

inherit "/obj/monster/spellundead";

int turnoPAN,protAN,turnoPM,protM;

//declaracion de hechizos:
public int parar_tiempo();
public int prot_armas_norm();
public int prot_mentalismo();
public int dedo_muerte();
//funciones de chequeo de hechizos:
public int chequeoAN();
public int chequeoM();

Defend(dam, damtype, weapon) {
  //si no llevas armas no le haces daño
  //si lleva el Proteccion contra Armas Normales un arma de este tipo no le afectara
  int magico;
  if (protAN==1){
  	turnoPAN++;
  	if (turnoPAN<8) {
		if (objectp(weapon)){
			magico=weapon->QueryMagic();
			if (magico==0) {
			write(" pero tu arma ahora es inúltil contra él.\n");
			tell_room(environment(),"\nEl arma de "+TP->QueryName()+" ahora no es efectiva contra el lich.\n");}
			else ::Defend(dam, damtype, weapon);
		} else ::Defend(dam, damtype, weapon);
	}
	else {protAN=0; ::Defend(dam, damtype, weapon);}
  }else if (protM==1) {//proteccion contra DT_PSYCHO durante 20 ataques
	turnoPM++;
	 if (turnoPM==20) protM=0;
	 if ((damtype==DT_PSYCHO) && (protM=1)){
		 tell_object(TP,"\n Hechizo ineficaz.\n");
	 } else ::Defend(dam, damtype, weapon);
   	} else ::Defend(dam, damtype, weapon);

 }

public int parar_tiempo(){
//160
 object *en,ene,bicho;
 int danyo;
 mapping hechizos;
 string msg;
 bicho=TO;
 en=QueryEnemies()||({});
 if(!sizeof(en)) return 0;
 for(int i=0;i<sizeof(en);i++){
 ene=en[i];
 if (!ene->QueryIsNpc() && !ene->QueryIsPet())
  {
  	hechizos=bicho->QuerySpells();
  	//if ((int)QuerySP()>hechizos["pararTiempo"][S_SP]) {
		AddSP(-(int)(hechizos["pararTiempo"][S_SP]));
		ene->SetCombatDelay(3,"  Tu TIEMPO se paraliza durante un rato.\n");
		msg=hechizos["pararTiempo"][S_GLOBAL_ENVMSG];
		tell_room(environment(),msg);
	//}
  }//if
 }//for
 return 0;
}


public int prot_armas_norm(){
 //Durante 7 turnos no le afectaran las armas normales
 mapping hechizos;
 string msg;
 object bicho;
  bicho=TO;
  AddSP(-20);
  turnoPAN=0; //Reseteo del turnoPAN
  protAN=1; //Proteccion contra armas normales activo
  hechizos=bicho->QuerySpells();
  msg=hechizos["ProtArmasNormales"][S_GLOBAL_ENVMSG];
  tell_room(environment(),msg);
  return 0;
 }

public int prot_mentalismo(){
 mapping hechizos;
 string msg;
 object bicho;

 bicho=TO;
 turnoPM=0;
 protM=1;
 hechizos=bicho->QuerySpells();
 AddSP(-(int)(hechizos["ProtMentalismo"][S_SP]));
 msg=hechizos["ProtMentalismo"][S_GLOBAL_ENVMSG];
 tell_room(environment(),msg);
 return 0;
 }

public int dedo_muerte(){
 object *en,ene,bicho;
 int danyo;
 int resist;
 mapping hechizos;
 bicho=TO;
 hechizos=bicho->QuerySpells();
 AddSP(-(int)(hechizos["DedoDeMuerte"][S_SP]));
 en=QueryEnemies()||({});
 ene=en[random(sizeof(en))];
 resist=(ene->Resistance(12)/100);
 if (ene->Resistance(12)>(20+random(10)))
	 return 0; //se salva si tiene la resistencia necesaria
 else {
	if (ene->QueryHP()<50) {
		//ene->AddHP(-1*(ene->QueryHP())); //muerto
		ene->SetHP(-1);
		tell_object(ene,hechizos["DedoDeMuerte"][S_VICMSG][MSG_DEAD]);
		tell_room(environment(),hechizos["DedoDeMuerte"][S_GLOBAL_ENVMSG]);
		}
	if (ene->QueryHP()>=120 && ene->QueryHP()<200) {
		danyo=(50+random(50));
		//ene->AddHP(-(int)((float)danyo-(float)danyo*(float)(resist/100)));
		ene->SetHP(danyo-(danyo*resist));
		tell_object(ene,hechizos["DedoDeMuerte"][S_VICMSG][MSG_NORMAL]);
		tell_room(environment(),hechizos["DedoDeMuerte"][S_GLOBAL_ENVMSG]);
		}
	else  { tell_object(ene,"El lich conjura un rayo verde que no te afecta.\n");
		 tell_room(environment(),hechizos["DedoDeMuerte"][S_GLOBAL_ENVMSG]);
		}
 	}
 return 0;
 }

create() {
  ::create();
 seteuid(getuid());
  protAN=0;
  protM=0;
  SetStandard("DheSarf","no-muerto",33,GENERO_MASCULINO);
  SetIds(({"lich","DheSarf"}));
  //SetShort("DheSarf");
  SetLong(
 "  Por su estatura jurarias que era humano antes de morir, aunque ahora no es\n"
 "más que piel y huesos. Está vestido galantemente con las ropas de un antiguo\n"
 "mago. En su no vida, sirve fielmente a su señor y benefactor Radhul, el odiado\n"
 "amo de los vampiros.\n");

  SetWeight(60000);
  SetAggressive(1);
  SetWhimpy(20);
  Set(P_CANT_STEAL,1);
  SetAlign(-100);
  SetCastChance(80);

  AddDefence(DT_BLUDGEON, 2);
  AddDefence(DT_PIERCE, 2);
  AddDefence(DT_SLASH, 2);
  AddDefence(DT_MAGIC,-2);
  AddDefence(DT_FIRE, 2);

  SetHands(({({"mano derecha",0,12}),({"mano izquierda",0,12}),({"colmillos",0,6})}));

  AddSpell("pararTiempo",
           ([
             S_SP:20,
             S_CHANCE:30,
             S_COMBAT_DELAY:0,
             S_DELAY:80,
             S_SIMULT:0,
             S_VICTIMS:-1,
             S_DAMTYPE:ST_OTHER,
             S_MINDAM:0,
             S_MAXDAM:0,
             S_FUN:SF(parar_tiempo),
             S_GLOBAL_ENVMSG:(TC_PURPLE"\n El licht para el tiempo.\n"TC_NORMAL),
             S_VICMSG:([
                      MSG_NORMAL:
                      (" Tu TIEMPO se paraliza durante un rato.\n")])
          ,])
  );//100

 AddSpell("ProtArmasNormales",
           ([
             S_SP:15,
             S_CHANCE:20,
             S_COMBAT_DELAY:1,
             S_DELAY:80,
             S_SIMULT:0,
             S_VICTIMS:0,
             S_DAMTYPE:ST_PROTECT,
             S_MINDAM:0,
             S_MAXDAM:0,
             S_CHECKFUN :SF(chequeoAN),
             S_FUN:SF(prot_armas_norm),
             S_GLOBAL_ENVMSG:(TC_GREEN"  El licht conjura un Protección Contra Armas Normales.\n"TC_NORMAL)
	,])
  );

AddSpell("ProtMentalismo",
           ([
             S_SP:30,
             S_CHANCE:20,
             S_COMBAT_DELAY:0,
             S_DELAY:60,
             S_SIMULT:0,
             S_VICTIMS:0,
             S_DAMTYPE:ST_PROTECT,
             S_MINDAM:0,
             S_MAXDAM:0,
	     S_CHECKFUN :SF(chequeoM),
             S_FUN:SF(prot_mentalismo),
             S_GLOBAL_ENVMSG:(TC_YELLOW"  El licht conjura un Protección Mental.\n"TC_NORMAL),])
  );

AddSpell("DedoDeMuerte",
           ([
             S_SP:20,
             S_CHANCE:30,
             S_COMBAT_DELAY:1,
             S_DELAY:30,
             S_SIMULT:0,
             S_VICTIMS:1,
             S_DAMTYPE:ST_PSYCHO,
             S_FUN:SF(dedo_muerte),
             S_GLOBAL_ENVMSG:(TC_GREEN"\n  EL licht lanza el DEDO DE MUERTE.\n"TC_NORMAL),
		 S_VICMSG:([
                      MSG_NORMAL:
                      (" El licht te señala y de su dedo sale un rayo verde que te inflinge\n"+
				" mucho dolor...\n"),
                      MSG_DEAD:
                      ("El licht te señala y de su dedo sale un rayo verde que te fulmina..\n"
                      )]),
		])
 );
 AddItem("/d/lad-laurelin/comun/objeto/magico/diadema");
}//fin create

public int chequeoAN() { return !protAN;}

public int chequeoM()  { return !protM;}

public varargs void Die (mixed silent) {
object ob;
ob=clone_object("/d/simauria/comun/objeto/otro/tornillo");
ob->move(environment(TO));
write("Al matar al lich se le cae el tornillo que le sujetaba la cadera.\n");
return ::Die(silent);
}



