/***************************************************************************************
 ARCHIVO:	camino.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Base para el camino que une Berat y Rhoemas.
 MODIFICACION:  24-04-2003 Repaso de c�digo.
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

public string fcamino() {return TO->QueryIntLong();}

create () {
  ::create();

  SetIndoors(0);
  SetLocate("Camino a Rhoemas");
  SetIntShort("un camino");
  SetIntSmell("Huele a campos, hierbas y otras cosas.\n");
  SetIntNoise("No oyes nada especial, salvo alg�n que otro trinar a lo lejos.\n");

  AddDetail(({"camino"}),SF(fcamino));
  AddDetail(({"tierra","suelo"}),"Es un suelo de tierra lleno de huellas de todo tipo.\n");
  AddDetail(({"huella","huellas"}),"Ves algunas profundas huellas en la tierra del camino. "
  	"parece que por aqu� pasa habitualmente una diligencia. Quiz�s incluso la podr�as "
  	"coger.\n");
  AddDetail(({"hierba","hierbas","peque�a hierba","peque�as hierbas","maleza"}),"Algunas "
  	"hierbas salvajes crecen a los lados del camino.\n");

  switch(random(10))
  {
  	case 0:  SetIntLong("Est�s en el camino que enlaza Berat con el valle de "
  		 "Rhoemas, en el que se encuentra el pueblo de Koek y el Templo de "
  		 "Seri-Solderteg. A los lados del camino ves algunas peque�as hierbas "
  		 "salvajes que le dan mucho colorido y un olor especial.\n");
		 break;
	case 1:  SetIntLong("Caminas por la larga v�a que conecta Koek con el pueblo portuario "
		 " de Berat. Es un bonito paisaje lleno de hierbas a los lados del camino "
		 "y huellas de todo tipo de carromatos y de la diligencia que recorre "
		 "este mismo camino.\n");
		 break;
	case 2:  SetIntLong("Vas progresando en tu andadura por esta ruta que une "
		 "Berat y Rhoemas. Es muy larga y pesada, y quiz�s ser�a mejor que "
		 "te dedicaras a coger la diligencia que cubre este recorrido antes "
		 "de morirte de cansancio andando por este camino sin fin.\n");
		 break;
	case 3:  SetIntLong("Est�s recorriendo el camino de Berat-Rhoemas, un "
		 "tortuoso y largo suplicio que se ameniza con el grato aroma que "
		 "se respira por aqu� y la bonita vista llena de verdor y alegr�a.\n");
		 break;
	case 4:  SetIntLong("Te encuentras en un bonito aunque exageradamente largo "
		 "camino que enlaza el pueblo de Berat con el valle de Rhoemas. Es un "
		 "terreno de tierra con varias huellas de carromatos que te hacen pensar "
		 "que hay un servicio de diligencias que pasa por aqu� habitualmente.\n");
		 break;
	case 5:  SetIntLong("Est�s en un bonito camino lleno de hierbas y maleza a los "
		 "lados. Quiz�s sea un poco peligroso caminar por aqu� as� sin m�s; el "
		 "trinar de los p�jaros y la bonita vista te relajan en demas�a.\n");
		 break;
	case 6:  SetIntLong("Observas con curiosidad que te encuentras en un bello camino "
		 "t�pico de esta zona con algo de maleza a los lados. Por las huellas que "
		 "ves en la tierra jurar�as que hay una diligencia que ofrece el servicio "
		 "de transporte hasta Koek, en el valle de Rhoemas. Dado lo largo "
		 "del camino es muy recomendable que la uses.\n");
		 break;
	case 7:  SetIntLong("Este es un largo camino en el que oyes alg�n trinar de vez "
		 "en cuando. No deber�as andar por aqu� en solitario, podr�as tener alguna "
		 "que otra inesperada compa��a. Quiz�s lo mejor ser�a que cogieras la "
		 "diligencia.\n");
		 break;
	case 8:  SetIntLong("Caminas por la senda que une Berat y Koek, en el valle de "
		 "Rhoemas. Este es un camino algo polvoriento por donde los carromatos "
		 "pasan, aplastando las malas hierbas, pero con una extensa y verde vegetaci�n "
		 "a los lados. De todas formas es tan largo que lo mejor es que utilices "
		 "el servicio de diligencias.\n");
		 break;
	default: SetIntLong("Este camino es eterno. Lo mejor que puedes hacer es usar "
		 "la diligencia para moverte de Berat a Rhoemas. Lo malo es que te perder�as "
		 "la bonita vista. T� decides.\n");
		 break;
  }
    if(d20()==1)
        AddItem(RHOEPNJ("koek/varios/peregrino_camino"),REFRESH_DESTRUCT);
}
