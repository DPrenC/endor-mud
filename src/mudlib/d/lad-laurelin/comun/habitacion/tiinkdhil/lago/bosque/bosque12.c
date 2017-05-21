
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

  AddExit("oeste",ALULAGO("bosque/bosque11"));
  AddExit("norte",ALULAGO("bosque/bosque6"));

}

public int despertar()  //dependiendo de si es de noche o dia habra batalla o no
{
 	mixed tipodia;
 	tipodia=(mixed *)NIGHTDAY->QueryState();
	//acciones por la noche:
   	if (tipodia==ND_NIGHT || tipodia==ND_PREDAWN || tipodia == ND_PRENIGHT)
   	{
   		TO->SetIntLong("Im�genes de luchas se superponen. "
    		"Est�s viviendo en tu propia piel cruentas peleas entre seres "
    		"vivos y muertos vivientes.\n");
   		TO->SetIntNoise("Escuchas el suave crujir de las ramas.\n");
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
 	//acciones el resto de periodos diarios:
 	else
 	{
    		TO->SetIntLong("Al oeste descubres monta�a. Por aqui "
    		"aparte de maleza hay dos feos �rboles.\n");
    		TO->AddDetail(({"�rboles","arboles"}),"Tienen parte "
    		"de la corteza seriamente quemada. Posiblemente el incendio que "
    		"lo provoc� se produjo hace a�os.\n");
    		TO->AddDetail(({"imagenes","im�genes"}),"Los moribundos "
    		"se retuercen de dolor, pocos monjes y peregrinos quedan en pie.\n");
    		write("No es de noche\n");
 	}
 	return 1;
}

reset(){
 despertar();
 ::reset();
}
