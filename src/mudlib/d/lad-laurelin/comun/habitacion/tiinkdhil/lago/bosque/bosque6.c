
#include <colours.h>
#include <rooms.h>

#include <nightday.h>
#include <properties.h>
#include "path.h"

#define TEXTO	ALULAGO("bosque/batalla.txt")

inherit ROOM;

int linea;
int puedeNarrar;
void mostrar_mensaje();

create(){
  ::create();
  linea=0;
  puedeNarrar=1;
  despertar();
  SetIndoors(0);
  SetLocate("bosqueDehim");
  SetIntNoise("El viento golpea en tu cara salvajemente.\n");
  SetIntShort("el bosque de la Batalla Perdida");
  AddDetail(({"tierra oscura","tierra oscurecida","zona"}),"No sabes lo que es, "
  		"pero te produce escalofrios.\n");

  AddItem(ALUPNJ("guerPereg"),REFRESH_DESTRUCT,1);

  AddExit("norte",ALULAGO("bosque/bosque1"));
  AddExit("sur",ALULAGO("bosque/bosque12"));
  AddExit("este",ALULAGO("bosque/bosque7"));
  AddExit("oeste",ALULAGO("bosque/bosque5"));
  AddExit("nordeste",ALULAGO("bosque/bosque2"));
}

reset(){
 despertar();
 linea=0;
 puedeNarrar=1;
 historia();
 ::reset();
}

public int despertar()  //dependiendo de si es de noche o dia habra batalla o no
{
 	//Aqui se encuentran el fantasma de Radhul y del Guardian dandose lexes
 	//nadie puede tocarlos ni intentar matarlos
 	//muere el guardian (siempre)
 	//ademas habran un lich (mas flojito y sin diadema qel otro q tengo)
 	//y un peregrino cañero
 	mixed tipodia;
 	tipodia=(mixed *)NIGHTDAY->QueryState();
  	//acciones por la noche:
 	if (tipodia==ND_NIGHT || tipodia==ND_PREDAWN || tipodia == ND_PRENIGHT)
 	{
   		TO->SetIntLong("Estás en el centro de una gran batalla. "
   		"Aqui, representantes del bien y el mal lucharon ferozmente por el "
   		"lugar. Moran en este paraje espectros por doquier en lucha encarnizada, "
   		"imágenes de antiguas luchas aparecen y desaparecen anti ti.\n"
    		"Ves más alante las rejas de una estructura.\n");
 	}
 	//acciones el resto de periodos diarios:
 	else
 	{
     		TO->SetIntLong("Aquí la tierra está desierta. No hay ni "
     		"piedras ni animales ni nada. La única presencia que notas es el fuerte "
     		"mecer del viento. Observas que la tierra se oscurece en una zona.\n");
 	}
 	return 1;
}

int matar_com(string quien)
{
	if (quien=="Radhul" || quien="guardian")
	{
		tell_object(TP,"No puedes matarlo, es solo una ilusión.\n");
		return 1;
	}
	else return 0;
}

init(){
  add_action("matar_com","matar");
  historia();
  ::init();
}

void linea_batalla()
{
	string bat;
	bat=read_file(TEXTO,linea,1);
	if (bat!=0) tell_room(TO,TC_CYAN+"Ilusión: "+TC_NORMAL+bat); else tell_room(TO,"\n");
	mostrar_mensaje();
}

void mostrar_mensaje()
{
	linea=linea+1;
	if(linea<=13) call_out("linea_batalla",4);
	else puedeNarrar=1; // si se acaba, da permiso para que recomience

}

int historia()
{
	if (puedeNarrar)
	{
		linea=0;
	   	puedeNarrar=0;
	   	mostrar_mensaje();// comienza la paranoia
	 };
  	return 1;
}
