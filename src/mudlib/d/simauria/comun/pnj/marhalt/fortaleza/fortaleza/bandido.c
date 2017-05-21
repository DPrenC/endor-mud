/*=============================================================*
 |             << Fortaleza:Simauria [m] Maler >> 		       |
 *=============================================================*
 |               Creacion............. 03-07-00                |
 |               Ultima Modificacion.. 11-09-00                |
 |                                                             |
 | [Nyh] Cachondo, si usas el DoDamage, al menos mira como se usa |
 *=============================================================*/
//Bandido q apuñala en el primer ataque
#include "./path.h"
#include <spellmonster.h>
#include <gremios.h>
#include <properties.h>
#include <combat.h>


inherit SPELLMONSTER;

int estad,apu;
public status check_hp();
public int apu();
create ()
{
  ::create();
seteuid(getuid());
SetStandard("bandido","humano",([GC_LUCHADOR:25+random(5)]),GENERO_MASCULINO);
SetSpellChance(100);
SetShort("un bandido humano");
SetLong(W("Es un bandido humano. Lleva los ropajes negros típicos de la profesión. "
"Parece dispuesto a atacarte en cualquier momento.\n"));
SetIds(({"humano","bandido"}));
SetAggressive(1);
SetAlign(-150);
SetSize(P_SIZE_MEDIUM);
InitChats(3,"El bandido te mira amenazadoramente.\n");
AddItem(ARMA("daga2"),REFRESH_REMOVE,SF(wieldme));
AddItem(ARMA("daga2"),REFRESH_REMOVE,SF(wieldme));
estad=0;
AddSpell("apunyalar",
([
  S_CHECKFUN:SF(check_hp),
  S_FUN:SF(apu),
  S_SP:2,
  S_CHANCE:100,
  S_VICTIMS:1,
  ]));
}

public status check_hp()
{
return QueryHP()<2000;
}

public int apu()
{
 object *en,ene,bicho;
 int pupa,mult;
 bicho=TO;
 en=QueryEnemies()||({});
 if(!sizeof(en)) return 0;
 ene=en[random(sizeof(en))];
 if(!ene->QueryIsNpc() && !ene->QueryIsPet())
 {
  if(estad==0)
  {
  //crujo//
  mult=bicho->QueryLevel()/6;
  pupa=random(20)+1;
  pupa=pupa*mult;
  ene->AddHP(-pupa);
  //texto//
  tell_room(environment(),"El bandido apuñala  por la espalda a "+ene->QueryName()+".\n",(({ene})));
  tell_object(ene,"El bandido te apuñala por la espalda.\n");
  estad=1;
  }
  return 0;
 }
return 0;
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras)
{
    estad=1;
    return ::DoDamage(damage, type, gentle, &xtras);
}
