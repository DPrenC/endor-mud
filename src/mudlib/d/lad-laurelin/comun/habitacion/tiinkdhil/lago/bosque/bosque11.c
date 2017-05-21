
#include <rooms.h>

#include <nightday.h>
#include <properties.h>
#include "path.h"
#include <moving.h>

inherit ROOM;
inherit NPC;

object obj1, obj2, obj3, obj4;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("bosqueDehim");
  SetIntShort("el bosque de la Batalla Perdida");
  despertar();
  AddDetail(({"ladera","montaña","montanya","cordillera"}),"Es muy alta y "
  		"escarpada. No hay vegetación que la pueble.\n");

  AddExit("norte",ALULAGO("bosque/bosque5"));
  AddExit("este",ALULAGO("bosque/bosque12"));
}

public int despertar()  //dependiendo de si es de noche o dia habra batalla o no
{
	mixed tipodia;
 	tipodia=(mixed *)NIGHTDAY->QueryState();
   	//acciones por la noche:
   	if (tipodia==ND_NIGHT || tipodia==ND_PREDAWN || tipodia == ND_PRENIGHT)
   	{
   		TO->SetIntLong("El paisaje no varia, no crece ni "
   		"una brizna de hierba. No ves animales ni signos de vida por ningún "
   		"lado\n");
   		TO->SetIntNoise("Escuchas el vaivén del viento.\n");
   		obj1=clone_object(ALUPNJ("adepto"));
   		obj2=clone_object(ALUPNJ("monjef"));
   		obj3=clone_object(ALUPNJ("vampiro"));
   		obj4=clone_object(ALUPNJ("vampiro"));
   		obj1->move(TO,M_SILENT);
   		obj2->move(TO,M_SILENT);
   		obj3->move(TO,M_SILENT);
   		obj4->move(TO,M_SILENT);
   		obj1->Kill(obj3);
   		obj2->Kill(obj4);
   		obj3->SetAggressive(1);
   		obj4->SetAggressive(0);
   		obj1->AddItem(ALUOBJ("proteccion/tunica"),REFRESH_REMOVE,SF(wieldme));
   		obj1->AddItem(ALUOBJ("arma/espada-corta-acero"),REFRESH_REMOVE,SF(wearme));
   		write("Es de noche\n");
 	}
 	//acciones el resto de periodos diarios:
 	else
 	{
   		TO->SetIntLong("La tierra yerma termina en la ladera "
   		"de la cordillera que bordea este valle. Hay cascotes y trozos de "
   		"enormes troncos dispersos pero son escasos. Aqui la tierra está "
   		"seca y no crece de ella ni una brizna de hierba. Tan sólo las "
   		"piedras y rocas desmoronadas de la motaña habitan este lugar... "
   		"y las imágenes que ves.\n");
    		TO->AddDetail(({"imagenes","imágenes"}),"Monjes y "
    		"peregrinos luchan por sus vidas contra horribles criaturas.\n");
    		write("No es de noche\n");
 	}
 	return 1;
}

reset(){
 despertar();
 ::reset();
}
