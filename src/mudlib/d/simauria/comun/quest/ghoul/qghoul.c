/* (c) Nemesis 1997                                        *
* Version 3.3b [Diciembre'98]                             *
* Tercera version para el quest del cementerio de Nandor  *
* Modificacion: Subido a nivel 10 y aumentados los stats  *
*               en consecuencia.                          *
*               Ahora, si ya has resuelto el quest ni te  *
*               da la cabeza ni na                        *
*               Bajado el alineamiento                    *
               [n] Castellanizado. (Oct'02)               *
         [n] Añadido un SetOwner para que no sea    *
             posible robar la cabeza y resolver el  *
       quest                                  *
         [z] En la comprobacion del quest cambio    *
             pl=PO por pl=TP         *
             porque PO era el combatmaster y no     *
             se sacaba el nombre del que lo mata.
[n] ¿Razón por la que se usaba previous_object? Sencillo:
    this_player es el ghoul. Y como previous_object no sé
    lo que da (bueno, sí, por culo), pues creo que el quest
    se desactiva de momento...

* POR HACER:                                              *
*        - Heredar el std/undead.c                        *
*        - Cambiar ligeramente el Die()                   *
*        - Meter algun otro hechicillo o algo asi         *
* NOTAS:                                                  *
*     - Esto sigue siendo version beta, aunque el quest   *
*       este rulando.                                     *


   14-07-2004 [kastwey@simauria]
         Ahora es necesario un cuchillo especial para cortarle la cabeza al Ghoul.
         Si se intenta con otro arma cortante: espadas, hachas, otro cuchillo que no sea el apropiado, Etc,
         esta quedará dañada :)
         14/01/2005: [kastwey@simauria]: Repaso el código, simplifico un montón
         y sangro lo que no había sangrado...

*/

#include <spellmonster.h>
#include <magia.h>
#include <properties.h>
#include <materials.h>
#include "path.h"

inherit "/obj/monster/spellmonster";

object armadura;
string Asesino;

init()
{
  add_action("cmd_cortar","cortar");
  ::init();
}


create() {
  ::create();
 seteuid(getuid());
  SetStandard("un ghoul","no-muerto",10,GENERO_MASCULINO);
  AddId(({"ghoul","q_ghoul"}));
  SetShort("un feo ghoul");
  SetLong(
    "Es un horrible ghoul. Su piel está totalmente seca, y su cara está\n"
    "horriblemente desfigurada. Sus puntiagudos dientes amarillos sobresalen por\n"
    "fuera de la boca. Un escalofrío te recorre el cuerpo al verlo.\n");
  SetAggressive(1);
  SetAlign(-1100);
  SetWhimpy(-1);
  SetAC(6);
  // [n] 14-Jul-04 Quito el SetGoChance porque no me mola. Ale.
  //  SetGoChance(45);
  SetCastChance(25);
  AddSpell("frio",
    ([
    S_CHANCE:20,
    S_COMBAT_DELAY:2,
    S_SIMULT:0,
  S_VICTIMS:1,
  S_DELAY:5,
    S_DAMTYPE:DT_COLD,
    S_MINDAM:10,
    S_MAXDAM:30,
    S_SP:0,
    S_GLOBAL_ENVMSG:({"El ghoul te toca!",""}),
    S_ENVMSG:([
      MSG_NORMAL:
      ({"@@MyName|1@ toca a @@VicName@@ y ves a @@VicName@@ empezar a temblar.\n"
      "@@VicName@@ tiembla de frío mientras es congelado.\n",
      "Notas un frío intenso rozar tu piel.\n"}),
  MSG_DEAD:
    ({"@@MyName@@|1@@ ha matado a @@VicName@@ y comienza a devorarlo.\n",
      "El cuerpo sin vida de @@VicName@@ cae al suelo.\n"}),
      ]),
  S_VICMSG:([
    MSG_NORMAL:
      ({"@@MyName|1@ te toca. Sientes un frío intensísimo llegar hasta tu alma.\n",
      "De pronto notas que hace demasiado frío...\n"}),
    MSG_DEAD:
      ({"@@MyName|1@@ te toca y caes al suelo sin vida.\n",
      "Sientes un frío tan intenso que el alma te abandona.\nDe repente ves "
      "un túnel sobre ti con una luz al fondo...\n" })
  ])
  ])
  );

  armadura=clone_object("/std/armour");
  armadura->SetStandard(AT_PANTALONES, 0, P_SIZE_MEDIUM, M_TELA);
  armadura->Set(P_SHORT, "unos pantalones bastante sucios");
  armadura->Set(P_LONG, "Unos pantalones sucios y medio podridos.\n");
  armadura->AddId(({"pantalones podridos y sucios","sucios pantalones","pantalones podridos"}));
  armadura->SetResetQuality(25);
  armadura->SetQuality(25);
  AddItem(armadura, REFRESH_REMOVE,SF(wearme));

  /* Resistencia: El NPC resistente a algo es tan resistente en porcentaje
  como el numero entre 0 y 100 indique. En el caso de hechizos, el hechizo
  sera repelido, llegando incluso a volverse contra su lanzador. */

  AddResistance(ST_COLD,100);
  AddResistance(DT_COLD, 100);
  AddResistance(ST_GAS,100);
  AddResistance(ST_POISON,100);
  AddResistance(ST_PSYCHO,60);
  AddResistance(DT_POISON,100);
  AddResistance(DT_NOAIR,100);

  /* Defensa: Simplemente significa que el NPC esta mas protegido contra
  un determinado tipo de danyo. En el caso de hechizos, estos NUNCA
  se volveran contra su lanzador ni seran repelidos. El danyo que
  haga un ataque del tipo contra el que esta protegido sera reducido
  en tantos HP como se indique. */

  AddDefence(DT_SLASH,3);    // 3 puntos de reduccion en todos los golpes de armas cortantes...
  AddDefence(DT_BLUDGEON,2); // 2 puntos menos en todos los golpes de armas romas...
  AddDefence(DT_PIERCE,1);   // y 1 punto menos en todos los golpes de armas punzantes.

  SetHands(({({"la garra izquierda",0,6}),({"la garra derecha",0,6})}));
  SetAds(({"un","feo","peludo"}));
  SetCorpse(QUEST + "ghoul/cadaver_ghoul");
  InitAChats(8,({ "El ghoul ruge siniestramente.\n" }));

}


int cmd_cortar(string str)
{
  str = lower_case(str);
  if (!str)
  {
    write ("¿Cortar qué a quien?\n");
    return 1;
  }
  else if (str == "cabeza a ghoul" || str == "cabeza al ghoul" || str == "la cabeza al ghoul")
  {
    write("Mejor será que lo mates antes de cortarle la cabeza...\n");
    return 1;
  }
  else
  {
    write ("Cortar qué a quién?\n");
    return 1;
  }
}

public object LeaveCorpse()
{
	object cadaver, asesino;
	cadaver = ::LeaveCorpse();
	if (!asesino = QueryKiller()) return cadaver;
	if (asesino->QueryIsPet() && asesino->QueryOwner())
	// es un familiar con dueño, así que el asesino es el dueño
	{
		cadaver->SetKiller(asesino->QueryOwner()->QueryRealName());
	}
	else
	{
		cadaver->SetKiller(asesino->QueryRealName());
	}
	return cadaver;
}

