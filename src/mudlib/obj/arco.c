/* SIMAURIA '/obj/arco.c'
   ======================
     21-10-99 [w] Este archivo habrá que heredarlo en caso de que se quiera
            crear un arco, porque este usa las habilidades y es el estandar.
                           1.- Tienes que tener el arco 'empuñado'
               2.- Tienes que tener flechas en tu inventario
               3.- Tienes que apuntar hacia alguna salida.
               4.- Tienes que 'disparar <flecha> contra <objetivo>'
                            No puedes si:
               a.- Estás en un lugar cerrado QueryIndoors.
               b.- No puedes ver nada.
               c.- No existe esa salida.
               d.- No tienes flechas, por supuesto.
 El arco puede actuar como arma improvisada si lo tiienes empuñado.
            Puedes disparar otras cosas que no sean flechas, siempre y
            cuando tengan un QueryIsArrow() que devuelva 1.
              28-10-99 [w] Ahora la flecha se mueve al environment de la victima si
            fallas y cambiado algún textillo... Además para apuntar en una
            dirección es indispensable tener el arco empuñado. Y las flechas
            se rompen.. como máximo puedes usar 5 veces una flecha.
               del todo bien.
      */

#include <properties.h>
#include <combat.h>
#include <search.h>
#include <moving.h>
#include <messages.h>
#include <skills.h>
#include <colours.h>
inherit WEAPON;

create() {
 ::create();
 SetStandard(WT_IMPROVISADA,5,P_SIZE_GENERIC,M_MADERA);
 SetIds(({"arco","arco de madera"}));
 SetNumberHands(1);
 SetValue(1000);
 Set(P_GENDER,GENDER_MALE);
 Set(P_NUMBER,NUMBER_SINGULAR);
 SetShort("un arco de madera");
 SetLong("Es un arco hecho de una madera muy flexible. Con él podrás apuntar\n"
 "y disparar a alguien que se encuentre en una habitación contigua.\n");
}

init() {
 ::init();
 add_action("cmd_apuntar","apuntar");
 add_action("cmd_disparar","disparar");
}

cmd_apuntar(string str)
{
 string direccion,fichero,intshort;
 mapping salidas;
 object destino,aqui;
int atisbar,bonus_gremio=0;
 if (!TP||!str||!(aqui = environment(TP)))
   return notify_fail("¿En que dirección quieres apuntar?\n"),0;
 if (sscanf(str,"en direccion %s",direccion)!=1 && sscanf(str,"direccion %s",direccion)!=1 &&
     sscanf(str,"en dirección %s",direccion)!=1 && sscanf(str,"dirección %s",direccion)!=1)
    direccion = str;

 salidas = (["ar":"arriba",
             "ab":"abajo",
             "n":"norte",
             "ne":"noreste",
             "e":"este",
             "se":"sureste",
             "s":"sur",
             "so":"suroeste",
             "o":"oeste",
             "no":"noroeste"]);
  str = lower_case(str);
  if (member(salidas,str))
    str = salidas[str];

  if (TO->QueryEquipped()!=TP)
    return notify_fail("Debes de tener el arco empuñado para poder apuntar.\n"),0;
  if (!member(salidas = aqui->QueryPlainExits()||([]),str))
    return notify_fail("No puedes apuntar en esa dirección.\n"),0;
  if (!stringp(fichero = salidas[str]))
    return notify_fail("No puedes apuntar en esa dirección.\n"),0;
  if (TP->CantSee())
    return notify_fail("No puedes ver nada.\n"),0;
  if (TP->QueryCombatDelay())
    return notify_fail(TP->QueryCombatDelayMsg()),0;
  if (!destino=load_object(fichero))
    return notify_fail("No puedes apuntar en esa dirección.\n"),0;
  if (str=="norte" || str=="sur" || str=="este" || str=="oeste" ||
      str=="noreste" || str=="noroeste" || str=="sureste" || str=="suroeste")
  {
    write("Apuntas hacia el "+str+"...");
    say(capitalize(TP->QueryName())+" apunta con su arco hacia el "+str+".\n");
  }
  else
  {
    write("Apuntas hacia "+str+" y puedes ver:\n");
    say(capitalize(TP->QueryName())+" apunta con su arco hacia "+str+".\n");
  }
    atisbar = TP->UseSkill(HAB_ATISBAR, bonus_gremio);
  intshort=destino->QueryIntShort()+".\n"+TC_NORMAL;

  switch(atisbar){
    case -10..20:
write(("\n"+intshort) ||"Una espesa niebla expontánea te impide reconocer algo.\n");
break;
        case 21..45:
write(("\n"+intshort+destino->QueryIntLong())
||"Una espesa niebla expontánea te impide reconocer algo.\n");
break;
            case 46..70:
                write(("\n"+intshort+destino->QueryIntLong()+destino->Content())
                ||"Una espesa niebla expontánea te impide reconocer algo.\n");
                break;
            case 71..300:
  write(("\n"+destino->GetIntDesc()) || "Una espesa niebla expontánea te impide reconocer algo.\n");
  break;
  default:
    write(" pero no consigues distinguir gran cosa.\n");
            }

  //write(destino->GetIntDesc()||"Algo te impide ver con claridad.\n");
  TP->Set("Apuntardesde",environment(TP));
  TP->Set("Apuntardonde",destino);
  TP->SetCombatDelay(1,"Estás concentrándote en apuntar.\n");
  return 1;
}

cmd_disparar(string str)
{
  string flecha,objetivo;
  object ob_flecha,victima;
  int libre,i,inte,des,EsJug,acierto;
  mixed *manos;

  if (!str)
    return notify_fail("¿Disparar qué contra quién?.\n"),0;
  if (sscanf(str,"%s contra %s",flecha,objetivo)!=2)
    return notify_fail("¿Disparar qué contra quién?.\n"),0;
  if (TP->CantSee())
    return notify_fail("No puedes ver.\n"),0;
  if (TP->QueryCombatDelay())
    return notify_fail(TP->QueryCombatDelayMsg()),0;
  if (!TO->QueryEquipped())
    return notify_fail("Primero deberias empuñar el arco.\n"),0;
  if (!ob_flecha = search(TP,flecha,SM_OBJECT|SEARCH_INV))
    return notify_fail("No tienes nada que se llame "+flecha+" que puedas disparar.\n"),0;
  if (!ob_flecha->QueryIsArrow())
    return notify_fail("Eso seria muy dificil que lo pudieses disparar con un arco.\n"),0;
  if (ob_flecha->QueryQuality()<30)
    return notify_fail(capitalize(ob_flecha->QueryShort())+" está en muy mal estado para usarse.\n"),0;
  if (!environment(TP)||environment(TP)->QueryIndoors())
    return notify_fail("Estás en un lugar cerrado y no tienes suficiente espacio para disparar.\n"),0;
  if (environment(TP)!=TP->Query("Apuntardesde")||!TP->Query("Apuntardonde"))
    return notify_fail("Tienes que apuntar primero en alguna dirección.\n"),0;
  if (!victima = locate(TP->Query("Apuntardonde"),objetivo,SM_OBJECT))
    return notify_fail("No ves a tu victima allí.\n"),0;
  if (!victima->QueryIsNPC() && !victima->QueryIsPlayer() && !victima->QueryIsPet() && !victima->QueryGhost())
    return notify_fail("Mejor apunta a algo que esté vivo.\n"),0;

  // Comprueba que tenga una mano libre.
  manos=TP->QueryHands();
  for (libre = i = 0; i < sizeof(manos); i++)
	 if (!manos[i][HAND_WEAPON]) libre++;


  if (!libre)
    return notify_fail("No te quedan manos libres con la que coger la flecha.\n"),0;
  EsJug=victima->QueryIsPlayer();
  // Está tu victima, la ves, tienes la flecha, etc...
  // Si es un jugador y además tiene la habilidad "tiro con arco" hace una cosa..
  if (TP->QueryIsPlayer() && TP->HasSkill("tiro con arco"))
  {
    if (acierto=TP->UseSkill("tiro con arco",15))
    {
      write("Disparas "+ob_flecha->QueryShort()+" contra "+victima->QueryName()+" y le das de lleno.\n");
      say(W(capitalize(TP->QueryName())+" dispara "+ob_flecha->QueryShort()+" contra "+victima->QueryName()+" y le da de lleno.\n"));
      tell_room(environment(victima),({MSG_SEE, W(capitalize(TP->QueryName())+" dispara "+ob_flecha->QueryShort()+" contra "+victima->QueryName()+" y le da de lleno.\n")}), ({victima}));
      if (victima->QueryIsNPC()) TP->StartHunting(victima);
      if (victima->QueryGoChance() && victima->QueryIsNPC()) victima->move(environment(TP),M_GO);
      if (ob_flecha->move(victima,M_SILENT)!=ME_OK)
        ob_flecha->move(environment(victima),M_SILENT);
      ob_flecha->SetQuality(ob_flecha->QueryQuality()-15);
      write(capitalize(victima->Short()||"alguien")+" te ha reconocido.\n");
      if (EsJug) tell_object(victima,capitalize(TP->QueryName())+" te dispara una flecha y te da de lleno.\n");
      if (acierto<10)
        victima->Defend(random(10),DT_PIERCE,DEFEND_NOMSG);
      else
        victima->Defend(random(10)+acierto/5,DT_PIERCE,DEFEND_NOMSG);
    }
    else
    {
      write("Disparas "+ob_flecha->QueryShort()+" contra "+victima->QueryName()+" pero fallas.\n");
      say(W(capitalize(TP->QueryName())+" dispara "+ob_flecha->QueryShort()+" contra "+victima->QueryName()+" pero falla.\n"));
      tell_room(environment(victima),({MSG_SEE, W(capitalize(TP->QueryName())+" dispara "+ob_flecha->QueryShort()+" contra "+victima->QueryName()+" pero falla.\n")}),({victima}));
      if (EsJug) tell_object(victima,capitalize(TP->QueryName())+" te dispara una flecha pero falla.\n");
      ob_flecha->move(environment(victima),M_SILENT);
      ob_flecha->SetQuality(ob_flecha->QueryQuality()-15);
    }
  }
  // Si no tienes la habilidad mira la inteligencia y la destreza.
  else
  {
    if ((inte=TP->QueryInt())>30) inte=30;
    if ((des=TP->QueryDex())>30) des=30;

    // Si no tienes la habilidad lo tienes un pelin más complicao.
    if (random(100-inte-des)<20)
    {
      // Aquí habrá que hacerlo tb más bonito..
      write("Disparas "+ob_flecha->QueryShort()+" contra "+victima->QueryName()+" y le das de lleno.\n");
      say(W(capitalize(TP->QueryName())+" dispara "+ob_flecha->QueryShort()+" contra "+victima->QueryName()+" y le da de lleno.\n"));
      tell_room(environment(victima),({MSG_SEE, W(capitalize(TP->QueryName())+" dispara "+ob_flecha->QueryShort()+" contra "+victima->QueryName()+" y le da de lleno.\n")}),({victima}));
      if (victima->QueryIsNPC()) TP->StartHunting(victima);
      if (victima->QueryGoChance() && victima->QueryIsNPC()) victima->move(environment(TP),M_GO);
      if (ob_flecha->move(victima,M_SILENT)!=ME_OK)
        ob_flecha->move(environment(victima),M_SILENT);
      ob_flecha->SetQuality(ob_flecha->QueryQuality()-15);
      if (EsJug) tell_object(victima,capitalize(TP->QueryName())+" te dispara una flecha y te da de lleno.\n");
      write(capitalize(victima->Short()||"alguien")+" te ha reconocido.\n");
      victima->Defend((inte+des+random(10)),DT_PIERCE,DEFEND_NOMSG); // le quito el /8 que tenía el daño producido por la flecha.
    }
    else
    {
      write("Disparas "+ob_flecha->QueryShort()+" contra "+victima->QueryName()+" pero fallas.\n");
      say(W(capitalize(TP->QueryName())+" dispara "+ob_flecha->QueryShort()+" contra "+victima->QueryName()+" pero falla.\n"));
      tell_room(environment(victima),({MSG_SEE, W(capitalize(TP->QueryName())+" dispara "+ob_flecha->QueryShort()+" contra "+victima->QueryName()+" pero falla.\n")}),({victima}));
      if (EsJug) tell_object(victima,capitalize(TP->QueryName())+" te dispara una flecha pero falla.\n");
      ob_flecha->move(environment(victima),M_SILENT);
      ob_flecha->SetQuality(ob_flecha->QueryQuality()-15);
    }
  }
  if (!random(10))
  {
	TP->Set("Apuntardesde",0);
	TP->Set("Apuntardonde",0);
	write("Dejas de apuntar hacia tu objetivo.\n");
  }
  if (TP->QueryGender()==2)
    TP->SetCombatDelay(2,"Estás concentrada disparando con el arco.\n");
  else
    TP->SetCombatDelay(2,"Estás concentrado disparando con el arco.\n");
  return 1;
}
