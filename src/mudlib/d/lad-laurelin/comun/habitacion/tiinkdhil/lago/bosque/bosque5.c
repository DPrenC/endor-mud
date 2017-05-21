
#include <rooms.h>

#include <nightday.h>
#include <properties.h>
#include "path.h"
#include <moving.h>

inherit ROOM;
inherit NPC;

object obj1, obj2, obj3;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("bosqueDehim");
  SetIntShort("el bosque de la Batalla Perdida");
  despertar();
  AddDetail(({"ladera","montaña","montanya","cordillera"}),"Es muy alta y "
  		"escarpada. No hay vegetación que la pueble.\n");

  AddExit("este",ALULAGO("bosque/bosque6"));
  AddExit("sur",ALULAGO("bosque/bosque11"));
  AddExit("nordeste",ALULAGO("bosque/bosque1"));
}

public int despertar()  //dependiendo de si es de noche o dia habra batalla o no
{
 	mixed tipodia;
 	tipodia=(mixed *)NIGHTDAY->QueryState();
	//acciones por la noche:
   	if (tipodia==ND_NIGHT || tipodia==ND_PREDAWN || tipodia == ND_PRENIGHT)
   	{
   		TO->SetIntLong("Un aura de malignidad pulula por "
   		"esta zona. No oyes los gritos de los pájaros ni ves nada sólido"
   		"... pero vislumbras imágenes de hechos pasados.\n");
   		obj1=clone_object(ALUPNJ("monjef"));
   		obj2=clone_object(ALUPNJ("monjer"));
   		obj3=clone_object(ALUPNJ("espectro"));
   		obj1->move(TO,M_SILENT);
   		obj2->move(TO,M_SILENT);
   		obj3->move(TO,M_SILENT);
   		obj1->Kill(obj3);  //puedo hacer funcion q dependa del alineamiento de la gente de la habitacion
   		obj3->SetAggressive(1);
   		obj2->Kill(obj2);
   		obj1->AddItem(ALUOBJ("proteccion/capa"),REFRESH_REMOVE,SF(wieldme));
   		write("Es de noche\n");
 	}
 	else
 	{
   		//acciones el resto de periodos diarios:
     		TO->SetIntLong("Estás en el bosque encantado que antaño "
     		"se convirtió en lugar de una cruenta batalla. Hay restos de algunos "
     		"arbustos por aquí.\n");
    		TO->AddDetail(({"imagenes","imágenes"}),"Una mujer llora "
    		"por su  hijo que llace entre sus brazos mientras un espectro se cierne "
    		"sobre ella. Unos monjes acuden en su auxilio.\n");
    		write("No es de noche\n");
 	}
 	return 1;
}

reset(){
 despertar();
 ::reset();
}
