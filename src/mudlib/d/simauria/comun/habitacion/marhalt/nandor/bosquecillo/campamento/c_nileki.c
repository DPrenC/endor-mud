// c_nileki.c

/*
 Carromato-vivienda de Nileki y Baskari.
 (c) [n] nemesis@simauria
 Creación:  29-sep-2002 17:04:15 CEST [n]
 Modificado:

*/

#include <moving.h>

#include "./path.h"

inherit SIM_ROOM;

string exa_pelos() {
 if(!TI->Query("know_hair"))
  return "No ves ese ingrediente en particular.\n";
 else return
  W("En una esquina de la estantería ves un pequeño tarro etiquetado "
    "como: 'Pelos de Pantera'. Por desgracia, está totalmente vacío, "
    "de forma que la única solución será conseguir que Lady Morkobva "
    "te dé algunos...\n");
}

create() {
 ::create();

 SetLocate("Bosque de Lengor");
 SetIntShort("el carromato de Madamme Nileki");
 SetIntLong(
 W("Te encuentras en un carromato tenuemente iluminado por la luz de "
   "varios candelabros. En el fondo de la estancia hay una mesa sobre la "
   "que puedes ver diversos artefactos utilizados en el arte de la adivinación. "
   "Junto a ella, un enorme espejo negro llama tu atención. Las paredes "
   "están cubiertas por estanterías atestadas de toda clase de frascos y "
   "recipientes. A pesar de todo, no parece un lugar tan siniestro como "
   "pudiera pensarse. Hay una puerta que conduce fuera.\n"));
 SetIndoors(1);
 SetIntBright(45);
 SetIntSmell("Hay un extraño olor en el aire, como de hierbas exóticas o incienso.\n");

 AddDetail("carromato",TO->QueryIntLong());
 AddDetail(({"candelabros"}),
 W("Una serie de candelabros iluminan tenuemente la estancia. Curiosamente, "
   "las velas no parecen sufrir desgaste alguno.\n"));
 AddDetail(({"velas","velas de los candelabros","velas de candelabros"}),
 "Curiosamente, no parecen gastadas. Tal vez sean mágicas.\n");
 AddDetail(({"artefactos","artefactos de adivinación","artefactos de adivinacion"}),
 W("Hay una bola de cristal, un par de barajas, un plato con sangre,... "
   "En fin, de todo un poco.\n"));
 AddDetail(({"bola de cristal","bola"}),
 W("Una esfera de cristal translúcido. Es probable que Madamme Nileki "
   "la utilice para predecir el futuro.\n"));
 AddDetail(({"barajas","cartas","baraja"}),
 W("Un montón de láminas con extraños dibujos que la pitonisa extiende sobre "
   "la mesa para intentar predecir el futuro de los incaut... estooo... de sus "
   "clientes.\n"));
 AddDetail(({"tarot","cartas del tarot","barajas de tarot","baraja de tarot"}),
 W("¿Te has parado a pensar que en un mundo de fantasía es posible que "
   "las cosas no se llamen exactamente como en el nuestro? Pues éste es el caso. "
   "El 'tarot' no existe como tal en el mundo de Simauria. Lo siento, pero "
   "'No ves nada de eso'.\n"));
 AddDetail(({"plato","plato con sangre","sangre"}),
 "Esperas que esa sangre sea de un pollo...\n");
// Este espejito tendrá alguna clase de 'sorpresa', pero me tengo que pensar cuál...
 AddDetail(({"espejo","espejo negro","enorme espejo negro"}),
 W("Un espejo de cuerpo entero. Te llama la atención el hecho de que su "
   "luna es completamente negra y por lo tanto no devuelve ningún "
   "reflejo. Te preguntas para qué se usará.\n"));
 AddDetail(({"estanterías","estanterias"}),
 W("Cubren las paredes casi por completo. En ellas puedes ver recipientes "
   "de todas las formas, tamaños y colores.\n"));
 AddDetail(({"frascos","recipientes"}),
 W("Acercándote a una de las estanterías compruebas que cada uno de los "
   "recipientes tiene su correspondiente etiqueta, sin duda para facilitar "
   "su rápida localización en caso de ser necesario.\n"));
 AddDetail(({"etiquetas"}),
 W("Miras con atención las etiquetas y compruebas que contienen nombres "
   "tan sugerentes como: 'Sesos de Cucaracha', 'Patas de Araña Bizca', "
   "o 'Tripas de Rana Palpitantes'.\n"));
 // descripción de los 'ingredientes'
 AddDetail(({"Sesos de Cucaracha","Sesos de cucaracha","sesos de Cucaracha",
             "sesos de cucaracha","sesos"}),
 W("La curiosidad es más fuerte que la repulsión y le echas un vistazo al "
   "interior del frasco. Puedes ver una masa viscosa de color indefinido en "
   "la que parecen flotar algunos grumos de color negruzco.\n"));
 AddDetail(({"Sexos de Cucaracha","Sexos de cucaracha","sexos de Cucaracha",
             "sexos de cucaracha","sexos"}),
 W("Espero que se te haya ido el dedo al escribir. Si no ha sido así, deberías "
   "hacértelo mirar, en serio.\n")); // quizá yo también debería... ;)
 AddDetail(({"Patas de Araña Bizca","Patas de Araña bizca","Patas de araña Bizca",
             "Patas de araña bizca","patas de Araña Bizca","patas de Araña bizca",
             "patas de araña Bizca","patas de araña Bizca","patas de araña bizca",
             "Patas de Araña","Patas de araña","patas de Araña","patas de araña",}),
 W("Observas el interior de un tarro transparente que hay sobre una "
   "estantería y ves que la etiqueta no mentía: contiene cientos de "
   "patas de toda clase de arañas. Algunas aún parecen moverse intentando "
   "escapar.\n"));
 AddDetail(({"patas","Patas"}),
 "¿Qué patas? ¿Las de la mesa?\n");
 AddDetail(({"Tripas de Rana Palpitantes","Tripas de Rana palpitantes",
             "Tripas de rana Palpitantes","Tripas de rana palpitantes",
             "tripas de Rana Palpitantes","tripas de Rana palpitantes",
             "tripas de rana Palpitantes","tripas de rana Palpitantes",
             "tripas de rana palpitantes","Tripas de Rana","Tripas de rana",
             "tripas de rana","tripas"}),
 W("Venciendo tu natural repulsión echas un vistazo al interior del "
   "frasco. No sabes si esa masa amarillenta y viscosa serán tripas de "
   "rana, pero lo que sí es cierto es que palpitantes son un rato...\n"));
 AddDetail(({"pelos de pantera","Pelos de pantera","Pelos de Pantera",
             "pelos de Pantera"}),SF(exa_pelos));
// Increíble, 19 AddDetails, si falta algo es pa matarme...
 AddDetail(({"puerta"}),
 "Sin más que atravesarla, llegarás al exterior. Qué adelantos, ¿eh?\n");

// AddItem("nileki",REFRESH_REMOVE, 1);

// AddExit("salir", "fuera");

}