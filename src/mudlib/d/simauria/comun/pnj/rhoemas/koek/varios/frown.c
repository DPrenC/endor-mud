/***************************************************************************************
 ARCHIVO:	frown.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Frown, el conserje
 MODIFICACION:  21-03-2003 Añado cosillas para el quest de Draego.
 		09-04-2003 Añado cosillas para el quest de Draego. (Toma 2)
 		17-04-2003 Añado cosillas para el quest de Draego. (Toma 3)
 		20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 		24-04-2003 Repaso código para que quede más ordenado y claro.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

public int leyendo;

public string farchivos(string str)
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"copa"))
	{
		if (quest["copa",0]==1) quest+=(["copa":2]);
		if (quest["copa",0]>1 && quest["copa",0]<4)
		{
			return W("Frown te dice: Vaya vaya... ¿asi que necesitas con "
			"urgencia echarle un vistazo a mis preciados archivos?. Pues "
			"siento decirte que ahora está cerrado. Necesito relajarme, "
			"¿sabes?. Esto es muy monótono, tanto papel para leer pero "
			"ninguno interesante... Lo que daría porque algo entretenido "
			"cayera en mis manos...\n");
		}
		else if (quest["copa",0]==4)
		{
			return W("Frown está demasiado entretenido leyendo un libro. "
			"De repente te mira y te dice: Los archivos están abiertos, "
			"mira lo que quieras.\n");
		}
		else
		{
			return W("Frown te mira y dice: ¿Los archivos? ¡Pero si ya los "
			"has visto! No me molestes más, que estoy ocupado.\n");
		}
	}
	else
	{
		return W("Frown te mira y dice: ¿Los archivos? Están cerrados. De todas "
		"formas no creo que te sirvieran de nada, así que vete o llamo a la guardia. "
		"Tengo mucho trabajo.\n");
	}
}

create(){
  ::create();
  SetStandard("Frown el conserje","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Frown");
  SetIds(({"humano","frown","Frown","conserje"}));
  SetShort("Frown el conserje");
  SetLong("Frown es un amable viejecito que trabaja como conserje en la alcaldía.\n");
  AddQuestion(({"alcalde"}),W("Frown te dice: El alcalde trabaja todo el día. La verdad, no se como "
  	"lo consigue.\n"),1);
  AddQuestion(({"guardia","guardias","patrullero","patrulleros"}),W("Frown te dice: La guardia de "
  	"Koek, junto con los patrulleros, son unos esforzados funcionarios que "
  	"protegen a cualquier persona que pase o resida en el valle. Sin duda se "
  	"merecen nuestra admiración.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Frown te dice: Koek es un sitio bastante tranquilo, aunque ultimamente se está masificando algo. "
	"tengo más trabajo que nunca.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Frown te dice: Un consejo... no vayas a verlo nunca... y si piensas en ir, mejor pásate por "
	"aquí antes a ver si te podemos convencer.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W(
	"Frown te dice: El templo es nuestra fuente de ingresos. Además nos protege del bosque.\n"),1);
  AddQuestion(({"archivo","archivos"}),SF(farchivos),1);

  InitChats(5,({"Frown bosteza aburrido y somnoliento.\n",
  		"Frown te dice: ¿Has visto que protegido que estoy? jeje.\n",
		"Frown empieza a impacientarse.\n",
		"Frown dice: Ahora no estoy de humor para trabajar.\n",
		"Frown dice: AAAAAAAAAHhhhhhhhhhhhhh... ZZZZzzzzz...zz..zz...\nParece que se ha quedado dormido.\n",
		"Frown te mira como si fueras a hacer algo malo.\n"}));
  InitAChats(5,({"Frown grita: [52m ¡Guardias! ¡Guardias![0m.\n"}));
  SetLeyendo(0);
}

reset(){
  ::reset();
  SetLeyendo(0);
}

public int SetLeyendo(int num) 	{return leyendo=num;}
public int QueryLeyendo()	{return leyendo;}
