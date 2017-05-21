/*=============================================================*
 |             << alcantarillas:Mithondrin [m] Maler >>        |
 *=============================================================*
 |               Creacion............. 01-06-00                |
 |               Ultima Modificacion.. 01-06-00                |
 |                                                             |
 |															   |
 *=============================================================*/
#include "./path.h"
#include <properties.h>
#include <skills.h>
#include <combat.h>
#include <moving.h>
#include <spellmonster.h>
inherit SPELLMONSTER;
public int misil();
public status check_hp();




//funcion de defensa pa no-muertos tomada de la entidad de greywolf//

 Defend(dam, damtype, weapon) {

  string material;


  if (weapon!=0)
  {
   material=weapon->QueryMaterial();
   if (material!="plata")
   {
    dam=1;
    ::Defend(dam,damtype,weapon);
   }
   else {
   dam=dam+weapon->QueryWC();
   ::Defend(dam,damtype,weapon);
   }

  }
  else {
   say("\n... ¡¡NO PARECE QUE LE HAGAS DAÑO!!...\n");
   return 51;
  }

 }










create ()
{
if(::create()) {return;}
SetStandard("espectro de elfo","espectre",20+random(25),GENERO_MASCULINO);
SetShort("un espectro de elfo");
SetLong("Es el espectro de un elfo. Sus ropajes translucidos te inducen a pensar "
"que en su vida fue un hechicero. Puede que fuese poderoso o no, no podrias decirlo "
"con seguridad. Te mira con los ojos rojos del que odia a los vivos.\n");
SetInt(QueryInt()+9);
SetCon(QueryCon()-3);
SetDex(QueryDex()-4);
SetStr(QueryStr()-8);
Set(FOLLOW_NORMAL);
Set(P_SEE_HIDDEN);

SetHP(QueryMaxHP());
SetIds(({"espectro","espectro de elfo","espectro de hechicero","espectro de elfo hechicero"}));
seteuid(getuid());
SetAggressive(2);
SetAlign(-15);
SetSize(P_SIZE_MEDIUM);
 AddItem(ARMA("vara"),REFRESH_REMOVE,SF(wieldme));
AddItem("/d/lad-laurelin/std/usahab");
AddSkill(HAB_VARA,40);
AddSpell("drenar vida",
([
  S_CHECKFUN:SF(check_hp),
  S_FUN:SF(misil),
  S_SP:2,
  S_CHANCE:70,
  S_VICTIMS:1,
  ]));
}

public status check_hp()
{
return QueryHP()<2000;
}

// CREACIÓN DE LA HABILIDAD DER MISÍ MÁXICO //
public int misil()
{
 object *en,ene,bicho;
 int pupa,misiles;
 bicho=TO;
 en=QueryEnemies()||({});
 if(!sizeof(en)) return 0;
 ene=en[random(sizeof(en))];
 if(!ene->QueryIsNpc() && !ene->QueryIsPet())
 {
  misiles=bicho->QueryLevel()/4;
  pupa=(random(10)+1)*misiles;
  ene->AddHP(-pupa);
  //texto//
  tell_room(environment(),"El espectro lanza "+misiles+" proyectiles mágicos contra "+ene->QueryName()+"\n");
 }
return 0;
}

varargs int SetCombatDelay(int i, string str)
{
return 0;
}
