/****************************************************************************
Fichero: salon_recepcion.c
Autor: Ratwor
Fecha: 01/01/2008
Descripci�n: Un sal�n de recepciones.
****************************************************************************/

#include "./path.h"
#include <sounds.h>
inherit SIM_ROOM;

create(){
    ::create();
    SetIntBright(40);
    SetIntShort("un sal�n de recepciones");
    SetIntLong("El amplio sal�n en el que te encuentras est� situado en el coraz�n de "
    "la torre del homenaje. Es el lugar donde el se�or de Nandor recibe a emisarios de "
    "Ishtria y otras tierras lejanas, donde en determinados d�as al a�o atiende las "
    "quejas y peticiones de los plebeyos y administra justicia. A juzgar por el "
    "n�mero de caballetes y mesas apoyadas contra las paredes, tambi�n es aqu� donde se "
    "celebran los grandes banquetes.  La enorme chimenea sostenida por pilares en la "
    "que cabr�an varios hombres puestos en pie alberga el fuego que arde d�a y noche "
    "caldeando la estancia y sirviendo a veces para asar animales enteros, sobretodo "
    "jabal�es, venados y otras piezas cobradas por los varones de la familia Dhes-Bl�in "
    "en los bosques de la regi�n. Algunos tapices algo ajados por el paso del tiempo, "
    "aunque no por ello menos espl�ndidos cuelgan de las paredes tratando de dar un "
    "aire distinguido a la sala, pero detalles como las cabezas disecadas de osos y "
    "lobos, y el enorme cuerno que cuelga junto a la chimenea no hacen mucho a tal efecto.\n"
    "Del techo sostenido por pulidos pilares de piedra cuelga una ara�a de cristal con "
    "multitud de velas que s�lo en muy raras ocasiones se encienden. El suelo est� "
    "recubierto por una capa de juncos.\n"
    "Al este unas puertas de roble conducen al amplio vest�bulo de la torre, y al oeste "
    "se extiende el sal�n donde se yergue un estrado elevado con un pesado sill�n de "
    "madera tallada.\n");
    AddDetail("tapices", "Tres tapices  bordados con distintas escenas de caza cuelgan en "
    "esta parte del sal�n.\n");
    AddDetail(({"tapiz 1", "tapiz uno"}),
    "Representa a un j�ven cazador de porte gallardo y vestido de "
    "verde montado en un corcel negro disponi�ndose a atravesar con su lanza de parte "
    "a parte un jabal� de gran tama�o al que rodean varios perros de caza.\n");
    AddDetail(({"tapiz 2", "tapiz dos"}),
    "Muestra a un cazador vestido con prendas de cuero blando que "
    "empu�a una daga larga mientras se enfrenta a un oso negro incorporado en dos patas "
    "con el mango roto de una lanza sobresaliendole del costado, las fauces abiertas y "
    "las zarpas delanteras tintas en sangre alzadas en posici�n de ataque. A los pies "
    "de la fiera yacen los cuerpos de dos sabuesos.\n");
    AddDetail(({"tapiz 3", "tapiz tres"}),
    "El tapiz que miras es el mas grande de esta parte del sal�n.\n"
    "En el se muestra una cacer�a en el bosque con jinetes armados de lanzas y "
    "jabalinas, secundados por numerosos sirvientes que sujetan a los perros de una "
    "jaur�a por medio de tra�llas. Algunos monteros provistos de cuernos y garrotes "
    "espantan a dos ciervos y un jabal� hacia la comitiva, al frente de la cual un "
    "noble jinete que cabalga sobre un corcel negro sopla un cuerno de caza de gran "
    "tama�o, similar al que cuelga junto a la chimenea.\n");
    AddDetail(({"suelo", "juncos"}), "Una capa de juncos cubre el suelo de piedra y, "
    "a pesar de que suelen cambiarse a menudo, alg�n que otro excremento de perro  o "
    "hueso ro�do se ve aqu� y all�.\n");
    AddDetail("pilares", "Sencillos pilares de piedra sin talla alguna que sostienen el "
    "techo del sal�n.\n");
    AddDetail("cuerno", "Un cuerno de caza grande y curvo con guarniciones de plata que "
    "parece ser bastante antiguo.\n");
    AddDetail("cabezas", "Varias cabezas de animales cuelgan de las paredes. Hay "
    "muchas de lobo, dos de oso y una de ciervo de magn�fica cornamenta.\n");
    AddDetail("estrado", "Un estrado de madera. Acerc�ndote podr�as ver mas detalles.\n");
    AddDetail("sill�n", "Un alto sill�n de madera sobre el estrado. Acerc�ndote podr�as "
    "verlo con mas detalle.\n");
    AddDetail(({"puertas", "puerta"}), "Unas altas puertas de roble pulido sin ninguna "
    "insignia ni adorno, casi siempre abiertas de par en par. Sobre la parte alta del "
    "arco que las alberga, hay tallado un yelmo alado.\n");
    AddExit("oeste", "./gran_salon");
    AddExit("este", "./vestibulo");
    SetLocate("el castillo de Nandor");
    SetSoundEnvironment(SND_AMBIENTES("chimenea"));
    AddItem(PNJCASTILLO("perro_caza"), REFRESH_DESTRUCT, 2);
}

