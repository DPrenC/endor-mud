/***************************************************************************************
 ARCHIVO:	muelle.c
 AUTOR:		[z] Zomax
 FECHA:		18-12-2001
 COMENTARIOS:	Muelles Standard.
 MODIFICACION:  24-04-2003 Repaso de código.
 ***************************************************************************************/

#include <weather.h>
#include <nightday.h>
#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

mapping map;

public int QueryEntrarPatrullero()	{return 1;}
public int QueryEntrarGato()		{return 1;}
public int fmuelle()			{return TO->QueryIntLong();}

create () {
  ::create();

  SetIndoors(0);
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddDetail(({"muelle"}),SF(fmuelle));
  map = ([]);
  map += ([neu:des;sme;noi]);
  map += ([inv:des;sme;noi]);
  map += ([pri:des;sme;noi]);
  map += ([ver:des;sme;noi]);
  map += ([oto:des;sme;noi]);

  map[neu,sme]="No hueles nada en especial.\n";
  map[inv,sme]="Tienes la nariz tan fría que no hueles nada.\n";
  map[pri,sme]="Huele a primavera... las flores y plantas de todo el "
  		"valle dejan un aroma embriagador. Sería perfecto si "
  		"no fuera porque también hace un olor a pescado insoportable.\n";
  map[ver,sme]="Aspiras el aire... demasiado caliente para tu gusto.\n";
  map[oto,sme]="El olor a tierra mojada y pescado no muy fresco invade el ambiente.\n";

  map[neu,noi]="Te concentras... No oyes nada en especial.\n";
  map[inv,noi]="Oyes los silbidos del aire gélido al chocar con tus orejas.\n";
  map[pri,noi]="Apenas oyes el sonido del viento acariciando cuanto toca.\n";
  map[ver,noi]="El aire está tan parado que no oyes nada en absoluto.\n";
  map[oto,noi]="Oyes el sonido del viento que empieza a soplar con algo de fuerza.\n";

  switch(random(5))
  {
 	case 0: map[inv,des]="El muelle está cubierto de una capa de nieve muy compacta.\n";
 		map[pri,des]="Hay un agradable ambiente de primavera.\n";
 		map[ver,des]="Hace bastante calor.\n";
 		map[oto,des]="Las lluvias han dejado el suelo muy resbaladizo.\n";
 		break;
 	
 	case 1: map[inv,des]="Hace bastante frío y hay una gran capa de nieve en el suelo.\n";
 		map[pri,des]="La nieve ya se derritió hace tiempo, dejando al descubierto el suelo de madera.\n";
 		map[ver,des]="Con este calor no piensas más que lanzarte al lago.\n";
 		map[oto,des]="Las lluvias han dejado el lago muy crecido.\n";
 		break;
 		
 	case 2: map[inv,des]="Todo el muelle está cubierto por la nieve.\n";
 		map[pri,des]="La nieve ya se ha derretido y notas una suave brisa en la cara.\n";
 		map[ver,des]="Hace mucho calor, demasiado para tu gusto.\n";
 		map[oto,des]="La lluvia entorpece el caminar, haciendo muy resbaladizo el suelo.\n";
 		break;
 		
 	case 3: map[inv,des]="Está todo nevado y te cuesta andar.\n";
 		map[pri,des]="Se respira un ambiente muy bueno.\n";
 		map[ver,des]="El aire se ha parado de golpe y tienes mucho calor.\n";
 		map[oto,des]="Las lluvias han dejado el suelo brillante y resbaladizo.\n";
 		break;
 		 	
 	case 4: map[inv,des]="En este momento la nieve ha invadido casi todo.\n";
 		map[pri,des]="Al derretirse la nieve se descrubre el suelo.\n";
 		map[ver,des]="Hace mucho calor.\n";
 		map[oto,des]="Andas con cuidado para no caerte de un resbalón.\n";
 		break;
 		 		
 	default:map[inv,des]="Hace bastante frío y todo está cubierto por la nieve.\n";
 		map[pri,des]="Se está muy bien aquí.\n";
 		map[ver,des]="Notas un agobiante calor.\n";
 		map[oto,des]="El suelo está brillante y resbaladizo por la lluvia.\n";
 		break;
  }
}

init(){
  ::init();

  switch (CHRONOS->QueryEstacion())
  {
 	case 1:	SetIntLong(W(to_string(map[neu,des])+to_string(map[inv,des])));
 		SetIntSmell(W(to_string(map[inv,sme])));
 		SetIntNoise(W(to_string(map[inv,noi])));
 		AddDetail(({"nieve"}),W(
		"El duro invierno del valle de Rhoemas hace que la nieve se amontone "+
		"sin cesar por donde cae, formando todo un manto nevado que cubre "+
		"prácticamente todo a su paso.\n"));
		AddDetail(({"suelo","tablón","tablon","tablones","madera"}),W(
		"La nieve tapa casi por completo el suelo de madera.\n"));
 		AddDetail(({"lago"}),W(
		"Desde aquí puedes ver el lago. Está completamente helado, pero no "
		"consigues adivinar el grosor de la capa de hielo. Mejor no andar "
		"sobre el hielo, puede ser peligroso.\n"));
		break;
 		
 	case 2:	SetIntLong(W(to_string(map[neu,des])+to_string(map[pri,des])));
 		SetIntSmell(W(to_string(map[pri,sme])));
 		SetIntNoise(W(to_string(map[pri,noi])));
 		AddDetail(({"suelo","tablón","tablon","tablones","madera"}),W(
		"El suelo del muelle está hecho de tablones de madera.\n"));
		AddDetail(({"lago"}),W(
		"Desde aquí puedes ver el lago. Ahora está muy lleno, gracias a los "
		"deshielos de la zona.\n"));
		break;
 		
 	case 3: SetIntLong(W(to_string(map[neu,des])+to_string(map[ver,des])));
 		SetIntSmell(W(to_string(map[ver,sme])));
 		SetIntNoise(W(to_string(map[ver,noi])));
 		AddDetail(({"suelo","tablón","tablon","tablones","madera"}),W(
		"La madera de la que está hecha el suelo aisla el agobiante calor.\n"));
		AddDetail(({"lago"}),W(
		"Desde aquí puedes ver el lago. Tiene mucha agua, pero no está en "
		"su mejor momento. Hace demasiado calor y se ha secado algo.\n"));
		break;
 		
 	case 4:	SetIntLong(W(to_string(map[neu,des])+to_string(map[oto,des])));
 		SetIntSmell(W(to_string(map[oto,sme])));
 		SetIntNoise(W(to_string(map[oto,noi])));
 		AddDetail(({"suelo","tablón","tablon","tablones","madera"}),W(
		"La madera del suelo se ha mojado por completo a causa de las lluvias.\n"));
		AddDetail(({"lago"}),W(
		"Desde aquí puedes ver el lago. Ahora está rebosante de vida. Con las "
		"lluvias del otoño se ha conseguido llenar hasta sobrepasar la media.\n"));
		break;
 		
 	default:SetIntLong(W(to_string(map[neu,des])));
 		SetIntSmell(W(to_string(map[neu,sme])));
 		SetIntNoise(W(to_string(map[neu,noi])));
 		break;
  }
}

public int fcoger(string str)
{
	object cosa;
	if(str=="nieve" && CHRONOS->QueryEstacion()==1)
	{
		cosa=clone_object(RHOEVAR("cylin/nieve"));
		cosa->move(TP,M_SILENT);
		write("Coges algo de nieve del suelo.\n");
		say(W(CATP+
		"coge un poco de nieve.\n"),TP);
		return 1;
	}
}
