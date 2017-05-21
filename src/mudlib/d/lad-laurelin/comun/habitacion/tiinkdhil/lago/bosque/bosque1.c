
#include <rooms.h>

#include <nightday.h>
#include <properties.h>
#include "path.h"
#include <moving.h>

inherit ROOM;
inherit "std/undead";

object obj1, obj2, obj3;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("bosqueDehim");
  SetIntSmell("Hueles a hierba fresca y a flores.\n");
  SetIntNoise("Escuchas el suave crujir de las ramas.\n");
  SetIntShort("el bosque de la Batalla Perdida");
  despertar();
  AddDetail(({"estructura"}),"Parece un cementerio.\n");
  AddDetail(({"rejas"}),"Son las rejas de un cementerio.\n");

  AddExit("este",ALULAGO("bosque/bosque2"));
  AddExit("sur",ALULAGO("bosque/bosque6"));
  AddExit("suroeste",ALULAGO("bosque/bosque5"));
}

public int despertar()  //dependiendo de si es de noche o dia habra batalla o no
{
 	mixed tipodia;
 	tipodia=(mixed *)NIGHTDAY->QueryState();
   	//acciones por la noche:
   	if (tipodia==ND_NIGHT || tipodia==ND_PREDAWN || tipodia == ND_PRENIGHT)
   	{
   		TO->SetIntLong("La atmósfera es opresiva y te encoge "
   		"el corazón. Los árboles que ves ante ti son sólo ilusiones... o "
   		"tal vez imágenes de algo que antaño existió. Hay cuerpos mutilados "
   		"por doquier.\nVes más alante las rejas de una estructura.\n");
   		obj1=clone_object(ALUPNJ("adepto"));
   		obj2=clone_object(ALUPNJ("esquelt"));
   		obj3=clone_object(ALUPNJ("ghoul"));

   		obj1->move(TO,M_SPECIAL);
   		obj2->move(TO,M_SILENT);
   		obj3->move(TO,M_SILENT);

   		obj1->Kill(obj2);  //puedo hacer funcion q dependa del alineamiento de la gente de la habitacion
   		obj2->SetAggressive(0);
   		obj2->AddItem(ALUOBJ("proteccion/casco"),REFRESH_REMOVE,SF(wieldme));
   		obj3->SetAggressive(1);
   		obj1->SetMMsgIn("De la nada aparece la translúcida figura de un monje presto para luchar.\n");
   		write("Es de noche\n");
 	}
 	else
 	{
   		//acciones el resto de periodos diarios:
     		TO->SetIntLong("Aqui termina este desierto paraje. "
     		"Ves más alante las rejas de una estructura.\n");
    		write("No es de noche\n");
 	}
 	return 1;
}

void notify_enter(object oldenv,int method,mixed extra)
{
  if (method==M_SPECIAL) tell_room(TO,"De la nada aparece la translúcida figura de un monje presto para luchar.\n");
}

reset(){
 despertar();
 ::reset();
}
