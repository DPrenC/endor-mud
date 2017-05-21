// c_nikaia.c

// Carromato-vivienda de Nikaia y Lattini (quest de Sangor)
// Ocupado por Nikaia, s�lo permitir� pasar a quienes le hayan
// devuelto la daga que ha perdido.
/*
// (c) [n] Nemesis@simauria
//
// Creaci�n: 23-Sep-02 14:07:45 CEST
// Modificado:
*/

#include <properties.h>
#include <moving.h>

#include "./path.h"

inherit SIM_ROOM;
// S�lo se permite el paso a quien le haya devuelto la daga a Nikaia

mixed allow_enter(int method, mixed extra) {
/*
 string name;
 string *wq;

 name=PO->QueryName();
 wq = PO->QueryAttr("sangorquest")||({});
 if ( (-1==member(wq,"lattini")) ) {
  // mensaje a la habitaci�n
  say(W(name+" se acerca a la puerta del carromato, pero justo "
      "cuando pone su mano en el pomo de la puerta, aparecen las hojas "
      "de un par de cuchillos a trav�s de �sta y se detiene.\n"));
  // mensaje al jugador
  tell_object(PO,
      W("Cuando intentas entrar en el carromato, una voz femenina grita: "
        "'�Te he dicho que te quedes fuera hasta que encuentres mi daga!' "
	"De repente, oyes un par de golpes secos en la puerta y a trav�s de "
	"la madera aparecen las relucientes hojas de un par de cuchillos. "
	"Algo te dice que Nikaia no quiere ser molestada en este momento. "
     ));
   return ME_NO_ENTER;
  }

 else // podr�a dar un mensajillo, pero de momento no
*/
  return ME_OK;
}

// create y dem�s mandangas...

create() {
 ::create();
 SetLocate("Bosque de Lengor");
 SetPreIntShort("dentro de");
 SetIntShort("el carromato de Lattini y Nikaia");
 SetIntLong(
 W("Te encuentras en un carromato decorado de forma extra�a. "
   "Las paredes est�n cubiertas de panoplias llenas de toda clase "
   "de espadas, as� como un par de vitrinas que contienen armas "
   "m�s cortas, como cuchillos y dagas. Tambi�n hay un par de ba�les, "
   "uno de los cuales est� abierto. "
   "Justo detr�s de ti hay una puerta que permite salir al exterior. "
 ));
 SetIntBright(30);
 SetIndoors(1);
 AddDetail("carromato",TO->QueryIntLong());
 AddDetail(({"ba�les","baules"}),
 "Son bastante grandes y parecen bastante s�lidos. Uno de ellos est� abierto.\n");
 AddDetail(({"ba�l","baul"}),
 "�Cu�l de ellos?.\n");
 AddDetail(({"ba�l cerrado","baul cerrado"}),
 W("Es un ba�l grande, de los que se usan para guardar cosas. Est� "
   "cerrado. Con llave. No es probable que puedas abrirlo.\n"));
 AddDetail(({"ba�l abierto","baul abierto"}),
 W("Parece contener ropa como la que un artista de circo usar�a en sus "
   "actuaciones. Te gustar�a registrarlo, pero por muy agradecida que "
   "est�, no creer�s que Nikaia te va a dejar revolver su ropa, �verdad?\n"));
 AddDetail(({"vitrinas"}),
 "Contienen toda clase de armas cortas, como cuchillos y dagas.\n");
 AddDetail(({"panoplias"}),
 "En las paredes puedes ver varias panoplias con toda clase de espadas.\n");
 AddDetail(({"cuchillos","dagas"}),
 W("Las vitrinas contienen cuchillos y dagas provenientes de todas las partes "
   "del Mundo Conocido. Te gustar�a examinarlos m�s de cerca, pero la mirada "
   "de Nikaia (o m�s bien, la manera que tiene de acariciar sus cuchillos) "
   "hace que te reprimas.\n"));
 AddDetail(({"espadas","espadas lujosas","espadas antiguas"}),
 W("Las panoplias contienen toda clase de espadas, algunas parecen muy "
   "antiguas, otras son simplemente muy lujosas. Sin embargo, cada vez "
   "que te acercas demasiado a alguna, notas c�mo la mirada de Nikaia "
   "se clava en ti e instintivamente te apartas, no vaya a ser que te "
   "clave alguna otra cosa.\n"));
 AddDetail(({"puerta"}),
 W("Aparte de que est� cubierta de muescas, no ves nada anormal, "
   "es una puerta como otra cualquiera.\n"));
 AddDetail(({"muescas","muescas en la puerta","muescas en puerta"}),
 W("Parece que se han producido recientemente. Es como si alguien "
   "hubiera clavado algo en la puerta.\n"));

// AddItem("nikaia",1, REFRESH_REMOVE);
// AddExit("fuera","");

}