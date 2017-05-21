/****************************************************************************
Fichero: salon_recepcion.c
Autor: Ratwor
Fecha: 01/01/2008
Descripción: Un salón de recepciones.
****************************************************************************/

#include "./path.h"
#include <sounds.h>
inherit SIM_ROOM;

create(){
    ::create();
    SetIntBright(40);
    SetIntShort("un salón de recepciones");
    SetIntLong("El amplio salón en el que te encuentras está situado en el corazón de "
    "la torre del homenaje. Es el lugar donde el señor de Nandor recibe a emisarios de "
    "Ishtria y otras tierras lejanas, donde en determinados días al año atiende las "
    "quejas y peticiones de los plebeyos y administra justicia. A juzgar por el "
    "número de caballetes y mesas apoyadas contra las paredes, también es aquí donde se "
    "celebran los grandes banquetes.  La enorme chimenea sostenida por pilares en la "
    "que cabrían varios hombres puestos en pie alberga el fuego que arde día y noche "
    "caldeando la estancia y sirviendo a veces para asar animales enteros, sobretodo "
    "jabalíes, venados y otras piezas cobradas por los varones de la familia Dhes-Bláin "
    "en los bosques de la región. Algunos tapices algo ajados por el paso del tiempo, "
    "aunque no por ello menos espléndidos cuelgan de las paredes tratando de dar un "
    "aire distinguido a la sala, pero detalles como las cabezas disecadas de osos y "
    "lobos, y el enorme cuerno que cuelga junto a la chimenea no hacen mucho a tal efecto.\n"
    "Del techo sostenido por pulidos pilares de piedra cuelga una araña de cristal con "
    "multitud de velas que sólo en muy raras ocasiones se encienden. El suelo está "
    "recubierto por una capa de juncos.\n"
    "Al este unas puertas de roble conducen al amplio vestíbulo de la torre, y al oeste "
    "se extiende el salón donde se yergue un estrado elevado con un pesado sillón de "
    "madera tallada.\n");
    AddDetail("tapices", "Tres tapices  bordados con distintas escenas de caza cuelgan en "
    "esta parte del salón.\n");
    AddDetail(({"tapiz 1", "tapiz uno"}),
    "Representa a un jóven cazador de porte gallardo y vestido de "
    "verde montado en un corcel negro disponiéndose a atravesar con su lanza de parte "
    "a parte un jabalí de gran tamaño al que rodean varios perros de caza.\n");
    AddDetail(({"tapiz 2", "tapiz dos"}),
    "Muestra a un cazador vestido con prendas de cuero blando que "
    "empuña una daga larga mientras se enfrenta a un oso negro incorporado en dos patas "
    "con el mango roto de una lanza sobresaliendole del costado, las fauces abiertas y "
    "las zarpas delanteras tintas en sangre alzadas en posición de ataque. A los pies "
    "de la fiera yacen los cuerpos de dos sabuesos.\n");
    AddDetail(({"tapiz 3", "tapiz tres"}),
    "El tapiz que miras es el mas grande de esta parte del salón.\n"
    "En el se muestra una cacería en el bosque con jinetes armados de lanzas y "
    "jabalinas, secundados por numerosos sirvientes que sujetan a los perros de una "
    "jauría por medio de traíllas. Algunos monteros provistos de cuernos y garrotes "
    "espantan a dos ciervos y un jabalí hacia la comitiva, al frente de la cual un "
    "noble jinete que cabalga sobre un corcel negro sopla un cuerno de caza de gran "
    "tamaño, similar al que cuelga junto a la chimenea.\n");
    AddDetail(({"suelo", "juncos"}), "Una capa de juncos cubre el suelo de piedra y, "
    "a pesar de que suelen cambiarse a menudo, algún que otro excremento de perro  o "
    "hueso roído se ve aquí y allí.\n");
    AddDetail("pilares", "Sencillos pilares de piedra sin talla alguna que sostienen el "
    "techo del salón.\n");
    AddDetail("cuerno", "Un cuerno de caza grande y curvo con guarniciones de plata que "
    "parece ser bastante antiguo.\n");
    AddDetail("cabezas", "Varias cabezas de animales cuelgan de las paredes. Hay "
    "muchas de lobo, dos de oso y una de ciervo de magnífica cornamenta.\n");
    AddDetail("estrado", "Un estrado de madera. Acercándote podrías ver mas detalles.\n");
    AddDetail("sillón", "Un alto sillón de madera sobre el estrado. Acercándote podrías "
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

