#include "./path.h"
#include <properties.h>

inherit GUILD;

/*
public varargs mapping QuerySkills(object pl)
{
  switch(pl?pl->QueryRace():0)
    {
     case "enano":
      return ([SK_FIGHT:25;0,
               SK_PARRY:20;0,
               SK_CRITICAL:10;0,
               SK_THROW:5;0,
               SK_SHOOT:5;0,
               SK_AIM:5;0,
               SK_MULTIPLE:10;0,
               SK_AXE:25;0,
               SK_SWORD:15;0,
               SK_CLUB:20;0,
               SK_WEAPONLESS:20;0,
               SK_SPEAR:10;0]);
               break;
     case "default":
      return ([SK_FIGHT:25;0,
               SK_PARRY:20;0,
               SK_CRITICAL:10;0,
               SK_THROW:7;0,
               SK_SHOOT:7;0,
               SK_AIM:7;0,
               SK_MULTIPLE:10;0,
               SK_AXE:15;0,
               SK_SWORD:20;0,
               SK_CLUB:10;0,
               SK_WEAPONLESS:20;0,
               SK_SPEAR:20;0]);
               break;
    }
}
*/


/*
public void kick_out( object pl )
{
  if (!pl) return;

  tell_object( pl, "Algo golpea tu cabeza y pierdes el conocimiento...\n"
);
  pl->move(CIUDAD+"entrada",M_SILENT);
  tell_object( pl, "Te recuperas del golpe algo despues.\n");
  pl->LookAfterMove();
}

// stuff moved from guildmaster
public void notify_enter(mixed from,int method,mixed extra)
{
  object po;

  po = PO;

  if ( ! po->QueryIsPlayer() )
    return (::notify_enter(from,method,extra));

  if ( (po->QueryGuild()=="Guerreros") ||
       (po->QueryGuild()=="Guerreros") )
    po->SetGuild("guerreros");

/* Omitido el denegar la entrada si se es de alineamiento malvado...

if ( ( ! IS_LEARNER( po ) ) && ( po->QueryAlign()<-59 ) )
  {
    tell_room( environment(po),
"Oyes una voz en tu mente: '¡Rapido! ¡Un ser oscuro a entrado a nuestro gremio! "
"¡Devolvamoslo al infierno o de donde provenga! ¡Pero HAGAMOSLO! ¡Estas "
"criaturas son incomprensibles!'\n");
	 );

    call_out( SF(kick_out), 1, po );
  }
  else
      tell_object( po, "Entras en tu gremio.\n");

  return (::notify_enter(from,method,extra));
*/
/*
}
*/

public create()
{
  ::create();
  SetIntShort("el salón del Gremio de los Guerreros de Kha-annu");
  SetIntLong(
"Has llegado al gremio de Clerigos de Kha-annu. Es un enorme salon de "
"marmol, en cuyo centro se encuentra una estrella de siete puntas, y unas "
"escenas de algunas de las batallas mas importantes de Simauria. Tus pies "
"representando a los dioses rodean la sala. Justo en el centro de la estrella "
"emerge un negro altar de madera.\n");

AddDetail( ({"hall","salon"}),
"El salon es muy espacioso, con algunos sillones hechos de piel dedicados "
"al descanso tras los arduos entrenamientos. El unico defecto es que huele "
"un poco a sudor, pero te reconfortas al saber que es el fruto del trabajo "
"que realizan los guerreros de este gremio.\n");
AddDetail( ({"suelo","alfombra"}),
"Sobre el suelo puedes ver la lujosa alfombra que mide unos cuatro metros "
"de largo.\n");
AddDetail( ({"cartel"}),
"Es un simple cartel que cuelga de la pared oeste. Podrias leerlo.\n");

  SetGuildname("Clerigos");
/*
  SetGuildclass(GC_WARRIOR);
*/
  AddMinStat(P_INT,1); AddMaxStat(P_INT,15); AddMaxHLPStat(P_INT,20);
  AddMinStat(P_DEX,1); AddMaxStat(P_DEX,25); AddMaxHLPStat(P_DEX,40);
  AddMinStat(P_CON,1); AddMaxStat(P_CON,25); AddMaxHLPStat(P_CON,40);
  AddMinStat(P_STR,1); AddMaxStat(P_STR,25); AddMaxHLPStat(P_STR,40);
  SetCreators(({"Izet"}));
  SetIndoors(1);
/*
  AddLevelTitles( 1,
                    "la Aprendiz de Soldado",
                    "el Aprendiz de Soldado",
                    "el Aprendiz de Soldado");
  AddLevelTitles( 2,
                    "la nueva Soldado",
                    "el nuevo Soldado",
                    "el nuevo Soldado");
  AddLevelTitles( 3,
                    "la Soldado",
                    "el Soldado",
                    "el Soldado");
  AddLevelTitles( 4,
                    "la Soldado experimentada",
                    "el Soldado experimentado",
                    "el Soldado experimentado");
  AddLevelTitles( 5,
                    "la nueva Guardia",
                    "el nuevo Guardia",
                    "el nuevo Guardia");
  AddLevelTitles( 6,
                    "la Guardia",
                    "el Guardia",
                    "el Guardia");
  AddLevelTitles( 7,
                    "la Guardia Experimentada",
                    "el Guardia Experimentado",
                    "el Guardia Experimentado");
  AddLevelTitles( 8,
                    "la Oficial de la Guardia",
                    "el Oficial de la Guardia",
                    "el Oficial de la Guardia");
  AddLevelTitles( 9,
                    "la Capitana de la Guardia",
                    "el Capitan de la Guardia",
                    "el Capitan de la Guardia");
  AddLevelTitles(10,
                    "la Guerrera",
                    "el Guerrera",
                    "el Guerrero");
  AddLevelTitles(11,
                    "la Guerrera experimentada",
                    "el Guerrero experimentado",
                    "el Guerrero experimentado");
  AddLevelTitles(12,
                    "la Guerrera profesional",
                    "el Guerrero profesional",
                    "el Guerrero profesional");
  AddLevelTitles(13,
                    "la Estratega",
                    "el Estratega",
                    "el Estratega");
  AddLevelTitles(14,
                    "la Maestra Estratega",
                    "el Maestro Estratega",
                    "el Maestro Estratega");
  AddLevelTitles(15,
                    "la mano izquierda del Maestro Guerrero",
                    "la mano izquierda del Maestro Guerrero",
                    "la mano izquierda del Maestro Guerrero");
  AddLevelTitles(16,
                    "la Maestra guerrero",
                    "el Maestro guerrera",
                    "el Maestro guerrero");
  AddLevelTitles(17,
                    "la Gran Maestra de la guerra",
                    "el Gran Maestra de la guerra",
                    "el Gran Maestro de la guerra");
  AddLevelTitles(18,
                    "la General Guerrera",
                    "el General Guerrero",
                    "el General Guerrero");
  AddLevelTitles(19,"la Conquistadora",
                    "el Conquistador",
                    "el Conquistador");
  AddLevelTitles(20,"la enviada del Dios Dulkar",
                    "el enviado del Dios Dulkar",
                    "el enviado del Dios Dulkar");
  AddItem(MONS+"thualin", REFRESH_HOME);
*/
  AddExit("norte",CIUDAD+"grimly8");
  AddExit("sur",CIUDAD+"baldur8");
}