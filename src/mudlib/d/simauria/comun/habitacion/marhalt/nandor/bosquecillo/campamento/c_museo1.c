// c_museo1.c

/*
 Primera habitación del "Museo de las Cosas Imposibles"
 Será necesario pagar para entrar (2 Ag)
 Mira por dónde, además va a haber un bonito punto de
 exploración por mirar todos los objetos del museo.
 Eso va a suponer complicar un poquito más la cosa,
 pero lo que importa no es la complejidad, sino que
 quede bonito...
 (c) [n] nemesis@simauria
 Creación:  06-Oct-2002 00:32:26 CEST [n]
 Modificado:

*/

#include <moving.h>
#include <properties.h>
#include <money.h>
#include "./path.h"

// inherit "/lib/money"; // Funciones del dinero
inherit SIM_ROOM;

// Antes de nada: si no pagan, no entran
public int allow_enter(int method, mixed extra) {

 string name;
 object who;

 name=PO->QueryName();
 who = PO;
 write(W("Baskari aparece de la nada, se planta ante la puerta y dice: "
         "'Dos de plata por favor.' Al mismo tiempo, alarga su manaza "
         "para recibir el dinero.\n"));
 if (MONEY_LIB->QuerySomeonesValue(PO) < 20) {
   tell_object(who,
           W("Por desgracia, estás más pelad"+
           ((who->QueryGender()==GENERO_MASCULINO)?"o":"a")+" que una rata, "
           "así que tendrás que dejar la visita para otra ocasión. Lástima, "
           "parecía interesante...\n" ));
   // mensaje a la habitación
   say(W("Como"+name+"es más pobre que las ratas, no puede entrar en el "
      "Museo. La verdad es que lo suyo es patético: ni siquiera tiene dos "
      "miserables monedas de plata.\n"));
    return ME_NO_ENTER;
  }

 else {
  MONEY_LIB->PayValue(who, 20);
  return ME_OK;
 }
}


create() {
 ::create();

 SetLocate("Bosque de Lengor");
 SetIntShort("el 'Museo de las Cosas Imposibles'");
 SetIntLong(
 W("Te encuentras en un carromato amplio, si bien está atestado de toda "
   "clase de objetos extraños, colocados en vitrinas o pedestales. Sobre "
   "cada uno de ellos puedes ver un cartel. El museo continúa hacia el este "
   "y una puerta te conducirá fuera de este mundo de magia e ilusión.\n"));
 SetIndoors(1);
 SetIntBright(60);

// AddDetails: DEBE haber al menos 8-10 'objetos imposibles'
// con sus correspondientes subdetalles si fuera necesario.
// Esto debería dar no menos de 15-20 llamadas a AddDetail.
// Bueno, eso sin contar los otros detalles, lo que dará un
// total de unos 20-25 detalles. No está nada mal.
 AddDetail("carromato",TO->QueryIntLong());
 AddDetail(({"vitrinas"}),
 W("Los objetos más pequeños están situados en vitrinas. Sobre cada "
   "una de ellas hay un cartel.\n"));
 AddDetail(({"pedestales"}),
 W("Los objetos más grandes están colocados encima de unos pedestales "
   "de madera en los que hay clavado un cartel.\n"));
 AddDetail(({"carteles","cartel"}),
 "Explican la funcionalidad del objeto con una frase alusiva al mismo.\n");
 AddDetail(({"puerta"}),
 W("Un extraño artilugio de forma cuadrada, sujeto a la pared por "
   "unos pedazos de metal, de tal forma que puede girar sobre sí mismo "
   "y ¡zas! De pronto ya es posible pasar al otro lado. Ciertamente es "
   "todo un prodigio de ingeniería.\n"));

// AddExit("este", "c_museo2");
// AddExit("salir", "fuera");

}
