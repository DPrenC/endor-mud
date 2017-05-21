// c_nileki.c

/*
 Carromato-vivienda de Nileki y Baskari.
 (c) [n] nemesis@simauria
 Creaci�n:  29-sep-2002 17:04:15 CEST [n]
 Modificado:

*/

#include <moving.h>

#include "./path.h"

inherit SIM_ROOM;

string exa_pelos() {
 if(!TI->Query("know_hair"))
  return "No ves ese ingrediente en particular.\n";
 else return
  W("En una esquina de la estanter�a ves un peque�o tarro etiquetado "
    "como: 'Pelos de Pantera'. Por desgracia, est� totalmente vac�o, "
    "de forma que la �nica soluci�n ser� conseguir que Lady Morkobva "
    "te d� algunos...\n");
}

create() {
 ::create();

 SetLocate("Bosque de Lengor");
 SetIntShort("el carromato de Madamme Nileki");
 SetIntLong(
 W("Te encuentras en un carromato tenuemente iluminado por la luz de "
   "varios candelabros. En el fondo de la estancia hay una mesa sobre la "
   "que puedes ver diversos artefactos utilizados en el arte de la adivinaci�n. "
   "Junto a ella, un enorme espejo negro llama tu atenci�n. Las paredes "
   "est�n cubiertas por estanter�as atestadas de toda clase de frascos y "
   "recipientes. A pesar de todo, no parece un lugar tan siniestro como "
   "pudiera pensarse. Hay una puerta que conduce fuera.\n"));
 SetIndoors(1);
 SetIntBright(45);
 SetIntSmell("Hay un extra�o olor en el aire, como de hierbas ex�ticas o incienso.\n");

 AddDetail("carromato",TO->QueryIntLong());
 AddDetail(({"candelabros"}),
 W("Una serie de candelabros iluminan tenuemente la estancia. Curiosamente, "
   "las velas no parecen sufrir desgaste alguno.\n"));
 AddDetail(({"velas","velas de los candelabros","velas de candelabros"}),
 "Curiosamente, no parecen gastadas. Tal vez sean m�gicas.\n");
 AddDetail(({"artefactos","artefactos de adivinaci�n","artefactos de adivinacion"}),
 W("Hay una bola de cristal, un par de barajas, un plato con sangre,... "
   "En fin, de todo un poco.\n"));
 AddDetail(({"bola de cristal","bola"}),
 W("Una esfera de cristal transl�cido. Es probable que Madamme Nileki "
   "la utilice para predecir el futuro.\n"));
 AddDetail(({"barajas","cartas","baraja"}),
 W("Un mont�n de l�minas con extra�os dibujos que la pitonisa extiende sobre "
   "la mesa para intentar predecir el futuro de los incaut... estooo... de sus "
   "clientes.\n"));
 AddDetail(({"tarot","cartas del tarot","barajas de tarot","baraja de tarot"}),
 W("�Te has parado a pensar que en un mundo de fantas�a es posible que "
   "las cosas no se llamen exactamente como en el nuestro? Pues �ste es el caso. "
   "El 'tarot' no existe como tal en el mundo de Simauria. Lo siento, pero "
   "'No ves nada de eso'.\n"));
 AddDetail(({"plato","plato con sangre","sangre"}),
 "Esperas que esa sangre sea de un pollo...\n");
// Este espejito tendr� alguna clase de 'sorpresa', pero me tengo que pensar cu�l...
 AddDetail(({"espejo","espejo negro","enorme espejo negro"}),
 W("Un espejo de cuerpo entero. Te llama la atenci�n el hecho de que su "
   "luna es completamente negra y por lo tanto no devuelve ning�n "
   "reflejo. Te preguntas para qu� se usar�.\n"));
 AddDetail(({"estanter�as","estanterias"}),
 W("Cubren las paredes casi por completo. En ellas puedes ver recipientes "
   "de todas las formas, tama�os y colores.\n"));
 AddDetail(({"frascos","recipientes"}),
 W("Acerc�ndote a una de las estanter�as compruebas que cada uno de los "
   "recipientes tiene su correspondiente etiqueta, sin duda para facilitar "
   "su r�pida localizaci�n en caso de ser necesario.\n"));
 AddDetail(({"etiquetas"}),
 W("Miras con atenci�n las etiquetas y compruebas que contienen nombres "
   "tan sugerentes como: 'Sesos de Cucaracha', 'Patas de Ara�a Bizca', "
   "o 'Tripas de Rana Palpitantes'.\n"));
 // descripci�n de los 'ingredientes'
 AddDetail(({"Sesos de Cucaracha","Sesos de cucaracha","sesos de Cucaracha",
             "sesos de cucaracha","sesos"}),
 W("La curiosidad es m�s fuerte que la repulsi�n y le echas un vistazo al "
   "interior del frasco. Puedes ver una masa viscosa de color indefinido en "
   "la que parecen flotar algunos grumos de color negruzco.\n"));
 AddDetail(({"Sexos de Cucaracha","Sexos de cucaracha","sexos de Cucaracha",
             "sexos de cucaracha","sexos"}),
 W("Espero que se te haya ido el dedo al escribir. Si no ha sido as�, deber�as "
   "hac�rtelo mirar, en serio.\n")); // quiz� yo tambi�n deber�a... ;)
 AddDetail(({"Patas de Ara�a Bizca","Patas de Ara�a bizca","Patas de ara�a Bizca",
             "Patas de ara�a bizca","patas de Ara�a Bizca","patas de Ara�a bizca",
             "patas de ara�a Bizca","patas de ara�a Bizca","patas de ara�a bizca",
             "Patas de Ara�a","Patas de ara�a","patas de Ara�a","patas de ara�a",}),
 W("Observas el interior de un tarro transparente que hay sobre una "
   "estanter�a y ves que la etiqueta no ment�a: contiene cientos de "
   "patas de toda clase de ara�as. Algunas a�n parecen moverse intentando "
   "escapar.\n"));
 AddDetail(({"patas","Patas"}),
 "�Qu� patas? �Las de la mesa?\n");
 AddDetail(({"Tripas de Rana Palpitantes","Tripas de Rana palpitantes",
             "Tripas de rana Palpitantes","Tripas de rana palpitantes",
             "tripas de Rana Palpitantes","tripas de Rana palpitantes",
             "tripas de rana Palpitantes","tripas de rana Palpitantes",
             "tripas de rana palpitantes","Tripas de Rana","Tripas de rana",
             "tripas de rana","tripas"}),
 W("Venciendo tu natural repulsi�n echas un vistazo al interior del "
   "frasco. No sabes si esa masa amarillenta y viscosa ser�n tripas de "
   "rana, pero lo que s� es cierto es que palpitantes son un rato...\n"));
 AddDetail(({"pelos de pantera","Pelos de pantera","Pelos de Pantera",
             "pelos de Pantera"}),SF(exa_pelos));
// Incre�ble, 19 AddDetails, si falta algo es pa matarme...
 AddDetail(({"puerta"}),
 "Sin m�s que atravesarla, llegar�s al exterior. Qu� adelantos, �eh?\n");

// AddItem("nileki",REFRESH_REMOVE, 1);

// AddExit("salir", "fuera");

}