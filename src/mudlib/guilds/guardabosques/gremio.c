/**
 * SIMAURIA '/gremios/guardabosques/gremio.c'
 */

#include "./path.h"
#include <guild.h>
#include <config.h>
#include <skills.h>
#include <rooms.h>
#include <properties.h>
#include <door.h>
#include <materials.h>
#include<scheduler.h>
#include <sounds.h>
inherit "/std/guild";

/* NO se pueden unir:
	- orcos (no son demasiado naturalistas)
	- demonios (tampoco lo son)
	- troll	(este no sabe ni lo que es la naturaleza...)
	- gigante (un gigante por un bosque... es como soltar un rinoceronte
		en una tienda de porcelanas)
*/


int cmd_join(string str)
{
  switch (TP->QueryRace())
  {
    case "orco":
    case "troll":
    case "gigante":
      return notify_fail("No puedes unirte a este gremio, tu raza no te lo permite.\n"), 0;
  }

  return ::cmd_join(str);
}

create_ob() {
  ::create_ob();

  SetIntShort("el gremio de los Guardabosques");
  SetIntLong(W("Est�s en el Gremio de los Guardabosques. Se compone de "
  	"una habitaci�n central (esta en la que est�s), y hacia el sur ves "
  	"una tienda donde los miembros del gremio pueden comprar y vender "
  	"cosas. Hacia el oeste ves lo que parece una zona de aprendizaje o "
  	"de entrenamiento, y hacia el este, la biblioteca del gremio.\n"));

  SetIntBright(50);
  SetGuildclass(GC_GUARDABOSQUES);
  SetGuildname("Gremio de los Guardabosques");
  SetGuildMaster("Mepher el Guarda");
  SetGuildDomain("lad-laurelin");
  SetCreators(({"Theuzifan"}));
  SetGuildobject(OBJETO("amuleto"));
  AddItem(PNJ("mepher"), REFRESH_DESTRUCT);


/*
  SetGuildSkillLearnMessage(HAB_RASTREAR, W("Mepher te dice: Vas haciendo "
	"progresos. Como sabes, para nosotros es importante conocer nuestro "
	"ambiente, as� que voy a mostrarte c�mo desenvolverte en �l.\n"
	"Aprendes la habilidad '"+HAB_RASTREAR+"'.\n"));
  SetGuildSkillLearnMessage(HAB_VARA, W("Mepher te mira y dice: "
	"Ya est�s preparado para aprender las bases de la pelea con "
	"vara.\n"
	"Aprendes una nueva habilidad.\n"));
  SetGuildSkillLearnMessage(HAB_LANZA, W("Mepher te dice: "
	"Ahora que has aprendido a luchar con una vara, veamos que tal se te "
	"da la lucha con lanzas.\n"
	"Aprendes una nueva habilidad.\n"));
  SetGuildSkillLearnMessage(HAB_ESPADA, W("Mepher te dice: "
	"Ahora que sabes usar un cuchillo, veamos que tal mueves una buena "
	"espada.\n"
	"Aprendes la habilidad '"+HAB_ESPADA+"'.\n"));
  SetGuildSkillLearnMessage(HAB_ESQUIVAR, W("Mepher te dice: "
	"La lucha no se compone s�lo de ataque, tambi�n hay que saber esquivar "
	"los ataques. A ver como te mueves....\n"
	"Aprendes la habilidad '"+HAB_ESQUIVAR+"'.\n"));
  SetGuildSkillLearnMessage(HAB_ARCO, W("Mepher sujeta un arco y dice: "
	"Lo que te voy a ense�ar ahora es la base de la lucha de los guardabosques. "
	"Trata al arco como a un amante y nunca te defraudar�.\n"
	"Aprendes la habilidad '"+HAB_ARCO+"'.\n"));
  SetGuildSkillLearnMessage(HAB_APOSITO, W("Mepher te dice: "
	"Ahora que sabes distinguir las plantas, te voy a ense�ar a escogerlas y "
	"mezclarlas para hacer ap�sitos.\n"
	"Aprendes la habilidad '"+HAB_APOSITO+"'.\n"));

  AddGuildSpell(MAG_CALMAR,1,60,0,8);
  AddGuildSpell(MAG_CONVOCAR,1,60,0,10);
  AddGuildSpell(MAG_CORTEZA,1,60,0,12);
  AddGuildSpell(MAG_SANGRE,1,60,0,15);
  AddGuildSpell(MAG_TRANSMUTAR,1,60,0,20);

  SetGuildSpellLearnMessage(MAG_CALMAR, W("Mepher te dice: Ha llegado el momento "
	"en el que he de ense�arte a controlar la habilidad m�gica '"+MAG_CALMAR+"'.\n"
	"Has aprendido una nueva habilidad.\n"));
  SetGuildSpellLearnMessage(MAG_CORTEZA, W("Mepher te dice: A veces la mejor "
	"manera de sobrevivir es protegi�ndose. Ha llegado la hora de ense�arte la "
	"habilidad m�gica '"+MAG_CORTEZA+"'. Estoy seguro que te ser� de gran "
	"ayuda.\n"
	"Has aprendido una nueva habilidad.\n"));
  SetGuildSpellLearnMessage(MAG_SANGRE, W("Mepher te dice: Con lo que te voy a "
	"ense�ar podr�s regenerarte m�s r�pidamente.\n"
	"Mepher te ense�a la habilidad m�gica '"+MAG_SANGRE+"'.\n"));
  SetGuildSpellLearnMessage(MAG_CONVOCAR, W("Mepher te dice: El bosque es nuestro "
	"aliado. Ahora podr�s convocar a sus habitantes para tu protecci�n.\n"
	"Mepher te ense�a la habilidad m�gica '"+MAG_CONVOCAR+"'.\n"));
  SetGuildSpellLearnMessage(MAG_TRANSMUTAR, W("Tu medall�n de guardabosque empieza "
	"a vibrar. Una tenue luz lo ilumina, y mientras lo miras con asombro, "
	"notas como una fuerza m�stica te invade. Aprendes la habilidad "
	"m�gica '"+MAG_TRANSMUTAR+"'.\n"));
*/
  AddLevelTitles(1, "el aspirante a Guardabosque", "el aspirante a Guardabosque", "la aspirante a Guardabosque");
  AddLevelTitles(5, "el aprendiz de Guardabosque", "el aprendiz de Guardabosque", "la aprendiz Guardabosque");
  AddLevelTitles(12, "el Guardabosque novicio", "el Guardabosque novicio", "la Guardabosque novicio");
  AddLevelTitles(20, "el Guardabosque", "el Guardabosque", "la Guardabosque");
  AddLevelTitles(40, "el maestro Guardabosque", "el maestro Guardabosque", "la maestra Guardabosque");

  AddExit("sur", BASE+"tienda");
  AddExit("salir", "/d/lad-laurelin/comun/habitacion/atbalnin/bosque/bosque00");
  AddExit("oeste", TRAIN "entrenamiento");
  AddExit("este", BASE+"biblioteca");
  AddDoor("sur", "la puerta de la tienda",
          "Es la puerta que comunica esta estancia con la tienda del gremio. "
          "Es una puerta de madera sencilla, adornada con dibujos de hojas "
          "talladas en ella.\n",
          ({"puerta", "puerta de madera", "puerta del gremio", "puerta de la tienda"}),
          GENDER_FEMALE, ([P_MATERIAL:M_MADERA, P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT,
P_DOOR_OPEN_SOUND : SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND : SND_SUCESOS("abrir_puerta_campanillas")]));
}
