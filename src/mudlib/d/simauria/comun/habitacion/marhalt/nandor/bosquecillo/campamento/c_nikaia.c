// c_nikaia.c

// Carromato-vivienda de Nikaia y Lattini (quest de Sangor)
// Ocupado por Nikaia, sólo permitirá pasar a quienes le hayan
// devuelto la daga que ha perdido.
/*
// (c) [n] Nemesis@simauria
//
// Creación: 23-Sep-02 14:07:45 CEST
// Modificado:
*/

#include <properties.h>
#include <moving.h>

#include "./path.h"

inherit SIM_ROOM;
// Sólo se permite el paso a quien le haya devuelto la daga a Nikaia

mixed allow_enter(int method, mixed extra) {
/*
 string name;
 string *wq;

 name=PO->QueryName();
 wq = PO->QueryAttr("sangorquest")||({});
 if ( (-1==member(wq,"lattini")) ) {
  // mensaje a la habitación
  say(W(name+" se acerca a la puerta del carromato, pero justo "
      "cuando pone su mano en el pomo de la puerta, aparecen las hojas "
      "de un par de cuchillos a través de ésta y se detiene.\n"));
  // mensaje al jugador
  tell_object(PO,
      W("Cuando intentas entrar en el carromato, una voz femenina grita: "
        "'¡Te he dicho que te quedes fuera hasta que encuentres mi daga!' "
	"De repente, oyes un par de golpes secos en la puerta y a través de "
	"la madera aparecen las relucientes hojas de un par de cuchillos. "
	"Algo te dice que Nikaia no quiere ser molestada en este momento. "
     ));
   return ME_NO_ENTER;
  }

 else // podría dar un mensajillo, pero de momento no
*/
  return ME_OK;
}

// create y demás mandangas...

create() {
 ::create();
 SetLocate("Bosque de Lengor");
 SetPreIntShort("dentro de");
 SetIntShort("el carromato de Lattini y Nikaia");
 SetIntLong(
 W("Te encuentras en un carromato decorado de forma extraña. "
   "Las paredes están cubiertas de panoplias llenas de toda clase "
   "de espadas, así como un par de vitrinas que contienen armas "
   "más cortas, como cuchillos y dagas. También hay un par de baúles, "
   "uno de los cuales está abierto. "
   "Justo detrás de ti hay una puerta que permite salir al exterior. "
 ));
 SetIntBright(30);
 SetIndoors(1);
 AddDetail("carromato",TO->QueryIntLong());
 AddDetail(({"baúles","baules"}),
 "Son bastante grandes y parecen bastante sólidos. Uno de ellos está abierto.\n");
 AddDetail(({"baúl","baul"}),
 "¿Cuál de ellos?.\n");
 AddDetail(({"baúl cerrado","baul cerrado"}),
 W("Es un baúl grande, de los que se usan para guardar cosas. Está "
   "cerrado. Con llave. No es probable que puedas abrirlo.\n"));
 AddDetail(({"baúl abierto","baul abierto"}),
 W("Parece contener ropa como la que un artista de circo usaría en sus "
   "actuaciones. Te gustaría registrarlo, pero por muy agradecida que "
   "esté, no creerás que Nikaia te va a dejar revolver su ropa, ¿verdad?\n"));
 AddDetail(({"vitrinas"}),
 "Contienen toda clase de armas cortas, como cuchillos y dagas.\n");
 AddDetail(({"panoplias"}),
 "En las paredes puedes ver varias panoplias con toda clase de espadas.\n");
 AddDetail(({"cuchillos","dagas"}),
 W("Las vitrinas contienen cuchillos y dagas provenientes de todas las partes "
   "del Mundo Conocido. Te gustaría examinarlos más de cerca, pero la mirada "
   "de Nikaia (o más bien, la manera que tiene de acariciar sus cuchillos) "
   "hace que te reprimas.\n"));
 AddDetail(({"espadas","espadas lujosas","espadas antiguas"}),
 W("Las panoplias contienen toda clase de espadas, algunas parecen muy "
   "antiguas, otras son simplemente muy lujosas. Sin embargo, cada vez "
   "que te acercas demasiado a alguna, notas cómo la mirada de Nikaia "
   "se clava en ti e instintivamente te apartas, no vaya a ser que te "
   "clave alguna otra cosa.\n"));
 AddDetail(({"puerta"}),
 W("Aparte de que está cubierta de muescas, no ves nada anormal, "
   "es una puerta como otra cualquiera.\n"));
 AddDetail(({"muescas","muescas en la puerta","muescas en puerta"}),
 W("Parece que se han producido recientemente. Es como si alguien "
   "hubiera clavado algo en la puerta.\n"));

// AddItem("nikaia",1, REFRESH_REMOVE);
// AddExit("fuera","");

}