/***********************************************************/
//  "vaina"
//  para envainar espadas (y putear a los players)
//  la espada maldita aparecer� en la vaina para poder
//  quitarle la maldici�n ha de ser desenvainada y eso
//  conlleva autoempu�amiento si tienes manos libres...
//  total que se te queda pegada a la mano. }:)
//
//  se puede usar con cualquier espada.
//
//  16-02-02 : Creaci�n -> Kodex
//

virtual inherit CONTAINER;
virtual inherit ARMOUR;
inherit "/std/equipment";

#include <combat.h>
#include <properties.h>
#include <moving.h>
#include <equipment.h>
#include "./path.h"

public int QueryFull();

public int envainar_cmd(string str)
{
  object espada, who;

  if (!sizeof(str)) return notify_fail("�Envainar qu�?\n");

  espada = present(str, TP);

  if (QueryFull())
    return notify_fail("La vaina ya tiene una espada en su interior.\n");
  if (!espada)
    return notify_fail("No tienes "+str+" para envainar.\n");
  if (espada->QueryWeaponType() != WT_ESPADA)
    return notify_fail(capitalize(str)+" no es una espada, por lo tanto no entra en la vaina.\n");
  if (who = espada->QueryEquipped())
  {
    if (who != TP) return notify_fail("T� no tienes la espada.");
    TP->Unequip(espada, (espada->QueryWeaponType()||espada->QueryArmourType()) ? EWF_WEAPON : 0 );
  }
  if (espada->move(TO, M_SILENT) == ME_OK) {
    write("Envainas "+espada->QueryShort()+".\n");
    say(capitalize(TP->QueryRealName())+" envaina "+espada->QueryShort()+".\n");
    return 1;
  }
  return notify_fail("No puedes envainar la espada.\n");
}

public int desenvainar_cmd(string str)
{
  object espada;

  if (!sizeof(str)) return notify_fail("�Desenvainar qu�?\n");

  espada = present(str,TO);
  if (!QueryFull())
    return notify_fail("La vaina est� vac�a, nada que desenvainar.\n");
  if (!espada)
    return notify_fail(capitalize(str)+" no est� en la vaina.\n");
  if (espada->move(TP, M_SILENT) == ME_OK) {
    write("Desenvainas "+espada->QueryShort()+".\n");
    say(capitalize(TP->QueryRealName())+" desenvaina "+espada->QueryShort()+".\n");
    TP->Equip(espada, (espada->QueryWeaponType()||espada->QueryArmourType()) ? EWF_WEAPON : 0);
    return 1;
  }
  return notify_fail("No puedes desenvainar la espada.\n");
}

create()
{
    ::create();
    
    SetStandard(AT_CINTURON, 0, P_SIZE_GENERIC, M_CUERO);
SetShort("un cintur�n con vaina");
    SetLong(W("Es una vaina de cuero adornada con unos "
    "fin�simos hilos de oro, s�mbolo de riqueza. Utilizada "
    "para guardar espadas y tenerlas listas para el combate "
    "est� unida a un cintur�n.\n"));
    SetIds(({"vaina", "cinturon", "cintur�n"}));
    SetWeight(200);
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetMaxIntWeight(6000);
    SetValue(500);
}

public void init()
{
  ::init();

  add_action("envainar_cmd","envainar");
  add_action("desenvainar_cmd","desenvainar");
  add_action("coger_cmd","coger");
}

public int QueryFull()
{
  object *contenido;
  contenido = all_inventory(TO) || ({});
  if (!sizeof(contenido))
    return 0;
  return 1;
}

AddItem(string ruta)
{
  object espada;
  espada = clone_object(ruta);
  espada->move(TO);
  QueryShort("Un cintur�n de cuero con una vaina ("+espada->QueryShort()+" envainada)");
}

string SetShort(string to) {  return "";}
//no hacer nada, para protegerlo del SetProperties al crear el objeto

string QueryShort()
{
  object *contenido;
  contenido = all_inventory(TO) || ({});
  if (!sizeof(contenido))
    return "un cintur�n con una vaina";
  return "un cintur�n con una vaina ("+contenido[0]->QueryShort()+" envainada)";
}

coger_cmd(string strg)
{

  string str;
  if (!strg) return 0;
  if (sscanf(strg,"%s de vaina", str) == 1)
  {
    write("�Lo que quieres es desenvainarla no?\n");
    return 1;
  }
}