/*
DESCRIPCION  : Donde les kitan el alijo
FICHERO      : aduanase.c
MODIFICACION :

[Chs] Chaos@Simauria.upv.es

18-04-00 [Chs]  Creacion
13-11-01 [Chs]  Modificacion para a�adir en un futuro un impuesto sobre materiales
		de contrabando.
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <moving.h>



inherit SIM_ROOM;

#define NOMBRE capitalize(TP->QueryPresay()+TP->QueryName())
#define AO     (TP->QueryGenderEndString())
#define S2     (TP->QueryGender()==2?"a":"e")

int ir_bosque_se(){
	object prohibido;
	/*object contrabando; 	 esto estara para en la aduana cobrar un porcentaje
			 mas de su valor y cu�arlo*/
	status found;
		// recorre el inventario y destruye los alijos
	while (prohibido = present("prohibido", TP) ){
	  prohibido->remove();
	  found = 1 ;
	  }
    if (found)   {
	      write(W("Avanzas por el camino hacia el oeste pero de repente eres "
	        "detenid"+AO+" por unos guardias.\nEl Capit�n te requisa la mercanc�a"
	        " diciendo: 'No puedes pasar llevando esa mercanc�a'.\n"));
	      say(W(NOMBRE+" avanza por el camino hacia el oeste y es retenid"+AO+
	        " por unos guardias.\nEl Capit�n le requisa la mercanc�a a "+NOMBRE+" y "
		    "dice: "+NOMBRE+" no puedes pasar llevando esa mercanc�a.\n"),TP);
    }
    say(NOMBRE+" se va hacia el norte.\n");
    TP->move(BOSQUE_NYN("bosque176"),M_SILENT);
    say(NOMBRE+" llega del sur.\n");
    tell_object(TP,
         "El Capit�n te dice: '�Que tenga un buen dia!'\n");
    TP->LookAfterMove();
	return 1;
}
int salir_bosque_se(){
	 object prohibido;
	 /*object contrabando; 	 esto estara para en la aduana cobrar un porcentaje
			 mas de su valor y cu�arlo*/
	 status found;

	 found =0;
	 while (prohibido = present("prohibido",TP))  {
     prohibido->remove();
     found = 1;
	 }
	 if( found)  {
		write(W("Avanzas por el camino hacia el sur pero de repente eres "
		  "detenid"+AO+" por unos guardias.\nEl Capit�n te requisa la mercanc�a"
		  " diciendo: 'No puedes pasar llevando esa mercanc�a'.\n"));
		say(W(NOMBRE+" avanza por el camino hacia el oeste y es retenid"+AO+
		  " por unos guardias.\nEl Capit�n le requisa la mercanc�a a "+NOMBRE+" y "
		  "dice: "+NOMBRE+" no puedes pasar llevando esa mercanc�a.\n"),TP);
	 }
	 say(NOMBRE+" se va hacia el sur.\n");
     TP->move(CNYNEBERAT("cam01"),M_SILENT);
     say(NOMBRE+" llega del norte.\n");
     tell_object(TP,
		"El Capit�n te dice: '�Que tenga un buen d�a!'\n");
	 TP->LookAfterMove();

	 return 1;
}


create() {
	::create();
	  SetIntShort("un puesto de guardia");
	  SetIntLong(W("En un lateral del desfiladero ves un puesto de guardia. "
	               "Es una peque�a construcci�n donde los guardias se turnan "
	               "para vigilar la entrada al bosque de Nyne. Al lado de la "
	               "casa ves un cartel. Hacia el norte puedes observar un bosque "
	               "bastante frondoso, en el que se interna el camino.\n"));
	  AddDetail(({ "cartel" , "letrero" }),"ADUANA.\n");
	  AddDetail(({"casa","construcci�n","construccion"}),
		   W("Es una peque�a casa hecha de madera. Dentro ves algunos guardias "
		     "que vigilan la entrada al bosque de posibles ataques de bandidos. "
		     "Tambi�n impiden el paso a los contrabandistas.\n"));
	  AddDetail(({"camino","sendero"}),
		  "Es un camino que se interna en el bosque");
	  SetIntNoise("Oyes el susurro del viento a trav�s de las rocas.\n");
	  SetIntSmell("Hueles a comida frita.\n");
	  SetLocate("Nyne");
	  SetIndoors(0);

	  AddExit("sur",SF(salir_bosque_se));
	  AddExit("norte",SF(ir_bosque_se));
}
