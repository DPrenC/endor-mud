// c_museo1.c

/*
 Primera habitaci�n del "Museo de las Cosas Imposibles"
 Ser� necesario pagar para entrar (2 Ag)
 Mira por d�nde, adem�s va a haber un bonito punto de
 exploraci�n por mirar todos los objetos del museo.
 Eso va a suponer complicar un poquito m�s la cosa,
 pero lo que importa no es la complejidad, sino que
 quede bonito...
 (c) [n] nemesis@simauria
 Creaci�n:  06-Oct-2002 00:32:26 CEST [n]
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
           W("Por desgracia, est�s m�s pelad"+
           ((who->QueryGender()==GENERO_MASCULINO)?"o":"a")+" que una rata, "
           "as� que tendr�s que dejar la visita para otra ocasi�n. L�stima, "
           "parec�a interesante...\n" ));
   // mensaje a la habitaci�n
   say(W("Como"+name+"es m�s pobre que las ratas, no puede entrar en el "
      "Museo. La verdad es que lo suyo es pat�tico: ni siquiera tiene dos "
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
 W("Te encuentras en un carromato amplio, si bien est� atestado de toda "
   "clase de objetos extra�os, colocados en vitrinas o pedestales. Sobre "
   "cada uno de ellos puedes ver un cartel. El museo contin�a hacia el este "
   "y una puerta te conducir� fuera de este mundo de magia e ilusi�n.\n"));
 SetIndoors(1);
 SetIntBright(60);

// AddDetails: DEBE haber al menos 8-10 'objetos imposibles'
// con sus correspondientes subdetalles si fuera necesario.
// Esto deber�a dar no menos de 15-20 llamadas a AddDetail.
// Bueno, eso sin contar los otros detalles, lo que dar� un
// total de unos 20-25 detalles. No est� nada mal.
 AddDetail("carromato",TO->QueryIntLong());
 AddDetail(({"vitrinas"}),
 W("Los objetos m�s peque�os est�n situados en vitrinas. Sobre cada "
   "una de ellas hay un cartel.\n"));
 AddDetail(({"pedestales"}),
 W("Los objetos m�s grandes est�n colocados encima de unos pedestales "
   "de madera en los que hay clavado un cartel.\n"));
 AddDetail(({"carteles","cartel"}),
 "Explican la funcionalidad del objeto con una frase alusiva al mismo.\n");
 AddDetail(({"puerta"}),
 W("Un extra�o artilugio de forma cuadrada, sujeto a la pared por "
   "unos pedazos de metal, de tal forma que puede girar sobre s� mismo "
   "y �zas! De pronto ya es posible pasar al otro lado. Ciertamente es "
   "todo un prodigio de ingenier�a.\n"));

// AddExit("este", "c_museo2");
// AddExit("salir", "fuera");

}
