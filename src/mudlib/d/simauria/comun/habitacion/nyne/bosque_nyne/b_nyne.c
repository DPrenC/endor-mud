/*
  Generador de descripciones aleatorias para un bosque.
  Las descripciones del bosque seran aleatorias (NO LAS SALIDAS), y asi podran añadirse
  el numero que se desee a este archivo sin que cambie el mapa.
  He ido recogiendo las descripciones de todos los archivos del mismo propósito que
  he encontrado, y aunque parezca una trola, tambien hay bastantes de mi propia cosecha.

  NOTA: AUNQUE YA ESTA COLGADO, NO ESTA ACABADO, Y PROMETO HACERLO EN CUANTO TENGA 5 MINUTOS.
        QUIERO CAMBIAR EL CREATE PARA QUE SE PASE COMO PARAMETRO EL NOMBRE DEL BOSQUE,
        Y ASI SE AÑADAN AUTOMATICAMENTE EN EL SetLocate, EL SetIntShort Y ALGUNAS DESCRIPCIONES
        LARGAS ESPECIALMENTE PREPARADAS PARA ELLO.

  10-10-01 [Bomber] Bomber@simauria.upv.es
  01-05-02 [Bomber] Bajo la posibilidad y cantidad de Trolls en el bosque.
                    En cuanto cuelgue las putas montañas lo bajare mas todavia.

*/

#include "path.h"

inherit SIM_ROOM;
create() {
 ::create();

/* Location */
SetLocate("Bosque de Nyne");

/* Estamos al aire libre */
SetIndoors(0);

/* Olores */
switch(random(7)){
 case 0: SetIntSmell("Huele a hierba mojada. Tal vez haya llovido hace poco.\n"); break;
 case 1: SetIntSmell("Huele a hierba seca. De hecho, esta cruje bajo tus pies.\n"); break;
 case 2: SetIntSmell("Parece que hay un animal muerto cerca. El olor es inaguantable.\n"); break;
 case 3: SetIntSmell("Que raro... no huele a nada...\n"); break;
 case 4: SetIntSmell("Alguien ha hecho una fogata cerca no hace mucho.\n"); break;
 case 5: SetIntSmell("No hace mucho que alguien ha cocinado en la zona.\n"); break;
 case 6: SetIntSmell("¿Un tigre?... Esperemos que fuese tu estómago nada mas.\n"); break;
}

/* Sonidos */
switch(random(7)){
 case 0: SetIntNoise("Oyes el trino de los pajaros. Parece que hay muchos.\n"); break;
 case 1: SetIntNoise("Oyes animales corriendo cerca de aqui. Tal vez se trate de un cervatillo.\n"); break;
 case 2: SetIntNoise("Oyes un sonido a tu espalda. Tal vez nada bueno.\n"); break;
 case 3: SetIntNoise("No oyes nada... y eso te molesta.\n"); break;
 case 4: SetIntNoise("Por un momento has creido oir gente cerca, pero no hay nadie.\n"); break;
 case 5: SetIntNoise("Todo esta tranquilo. No oyes nada.\n"); break;
 case 6: SetIntNoise("Oyes el viento silbar entre las ramas.\n"); break;
}

/* Descripcion Corta */
SetIntShort("el bosque de Nyne");

/* Descripcion Larga */
switch(random(18)){
 case 0:
   SetIntLong(W("Estás en una zona poco iluminada del bosque."
                " Aquí las copas de los árboles son un poco más altas de lo normal,"
                " y no parece probable que se pueda escalar hasta ellas,"
                " así que piensas que es mejor ni siquiera intentarlo. "
                "Ves algo moverse rapidamente entre las ramas.\n"));
   AddDetail(({"copa", "ramas"}),W("La copa del arbol está muy alta para llegar a ella."
                                   " Ves unas ardillas saltando entre las ramas.\n"));
   AddDetail(({"ardillas"}),"Es una pequeña ardilla voladora.\n");
 break;
 case 1:
   SetIntLong(W("Estás perdido en medio del bosque. Aquí la luz es más fuerte,"
                " debido a la menor altura de los arboles. La hierba crece por todas partes,"
                " y pequeños roedores se esconden entre ella y huyen al verte."
                " Unos pajarillos saltan alegremente de rama en rama.\n"));
   AddDetail(({"pajaro","pájaro","pajaros","pájaros"}),"Se trata de una pareja de pichones revoloteando.\n");
 break;
 case 2:
   SetIntLong(W("No te gusta esta zona del bosque. Crees que sería mejor largarse."
                " Nunca se sabe que clase de bestia puede estar acechandote por estos lares.\n"));
 break;
 case 3:
   SetIntLong(W("En esta parte del bosque hay una gran cantidad de vegetación,"
                " por lo que te es difícil reconocer algún camino."
                " Al menos sabes que continuas en el bosque... ¿o tal vez no?\n"));
   AddDetail(({"vegetacion","vegetación"}),"Las hierbas son extrañamente altas aquí.\n");
 break;
 case 4:
   SetIntLong(W("Estás rodeado por abundante vegetación. Grandes árboles y"
                " arbustos te rodean en todas direcciones. Solo encuentras"
                " algún que otro resquicio libre para colarte sin que las ramas arañen tu rostro.\n"));
   AddDetail(({"arboles","árboles"}),W(
                "Son bastante altos. Este bosque debe haberse salvado"
                " de taladores durante siglos.\n"));
 break;
 case 5:
   SetIntLong(W("Aunque no hay ninguna senda, hay ciertas zonas hacia"
                " las que puedes avanzar, a pesar de la espesura del bosque."
                " No te gustaría que la noche te sorprendiera aqui solo.\n"));
   AddDetail(("senda"),"No ves ninguna senda.\n");
 break;
 case 6:
   SetIntLong(W("Esta zona no esta demasiado transitada, a juzgar por las"
                " pocas huellas de civilización que encuentras."
                " De hecho, hace tiempo que no distingues huella humana alguna.\n"));
   AddDetail(("huellas"),"Solo huellas de animales. Ni carromatos ni herraduras.\n");
 break;
 case 7:
   SetIntLong(W("Por allí por donde no hay arbustos puedes ver alguna"
                " que otra huella de animales típicos de la zona.\n"));
   AddDetail(("arbustos"),"Enormes arbustos y matorrales crecen a la sombra de los árboles.\n");
   AddDetail(("huellas"),"Distingues las pequeñas huellas de lo que parece ser un conejo.\n");
 break;
 case 8:
   SetIntLong(W("Este bosque es un claro ejemplo de lugar donde puedes"
                " perderte con total facilidad."
                " De hecho, es el claro ejemplo de un lugar donde"
                " no piensas volver en tu vida.\n"));
 break;
 case 9:
   SetIntLong(W("Las ramas de los árboles se entrelazan por encima de ti,"
                " lo que hace que la luz disminuya ligeramente."
                " La poca luz en esta zona hace de ella un lugar propicio"
                " para una emboscada. Deberias largarte cuanto antes.\n"));
   AddDetail(("ramas"),W("Son bastante gruesas, pero están muy altas como"
                         " para que puedas subirte a ellas.\n"));
 break;
 case 10:
   SetIntLong(W("Un suelo lleno de ramas caídas, hojas y pequeñas piedras,"
                " así como un techo natural formado por las frondosas ramas"
		    " de los árboles, es el único paisaje que puedes contemplar.\n"));
   AddDetail(("ramas"),"Las ramas más secas han caido al suelo y se descomponen dia a dia.\n");
   AddDetail(("hojas"),"Te encanta como crujen bajo tus pies.\n");
   AddDetail(("piedras"),W("Pequeñas piedrecillas inutiles, nada"
                           " suficientemente grande como para ser lanzado"
			   " sin que lo frene el mismo aire.\n"));
 break;
 case 11:
   SetIntLong(W("Grandes árboles forman este bosque. Por suerte, en esta"
                " zona están lo suficientemente separados como para que no"
		    " impidan la entrada del sol, de lo contrario sus copas no"
		    " te dejarían distinguir si es de noche o de dia.\n"));
   AddDetail(({"arbol","arboles","árboles"}),"Son realmente enormes.\n");
 break;
 case 12:
   SetIntLong(W("El bosque es más denso y cerrado por aquí. Para avanzar"
                " tienes que evitar e ir apartando cientos de ramas, así"
		    " como sortear algún que otro peñasco.\n"));
   AddDetail(("ramas"),"Si no llevas cuidado te podrian arañar la cara.\n");
 break;
 case 13:
   SetIntLong(W("El bosque es realmente denso. Te encuentras rodeado de árboles"
                " que te impiden el paso en muchas direcciones. Sólo en algunos"
		    " lugares, por la poca proximidad de unos árboles con otros, o"
		    " por las caprichosas formas que estos adoptan, serías capaz de pasar.\n"));
   AddDetail(({"arbol","arboles","árboles"}),W("Las extrañas formas que"
                " toman te hace pensar que no lo han hecho de forma natural.\n"));
 break;
 case 14:
   SetIntLong(W("La vegetación de este punto del bosque es más viva,"
                " aunque no sabes si solo te lo parece a ti al no hallarte"
		    " rodeado de los tétricos árboles que forman el bosque.\n"));
   AddDetail(({"vegetacion","vegetación"}),W("Largas hierbas y flores pueblan"
                " la zona, que parece estar menos cubierta de árboles.\n"));
 break;
 case 15:
   SetIntLong(W("Algunos árboles se retuercen sobre sí mismo, otros forman"
                " extraños arcos curvos. Estos árboles deben ser obra de la"
		    " madre Naturaleza, pero a pesar de sus formas, al menos"
		    " puedes pasar entre ellos.\n"));
 break;
 case 16:
   SetIntLong(W("El paisaje comienza a ser demasiado monótono, árboles y más"
               " árboles, hojas, ramas caídas, piedras y más cosas."
	         " En este bosque es realmente fácil perder la orientación.\n"));
   AddDetail(({"arbol","arboles","árboles"}),"Son de gran tamaño. Te imponen bastante respeto.\n");
   AddDetail(({"hoja","hojas"}),"Hojas secas por todos lados.\n");
   AddDetail(({"piedra","piedras"}),W("En realidad, no llegan ni a piedras."
                                      " Son solo grava.\n"));
   AddDetail(({"rama","ramas"}),"Rotas y secas se esparcen por todos lados.\n");
 break;
 case 17:
   SetIntLong(W("Los grandes árboles te rodean produciéndote una sensación"
                " de protección así como algo de temor. En este oscuro"
                " bosque, habitan diversos tipos de animales, algunos no"
	          " muy amigables con los forasteros.\n"));
   AddDetail(({"arbol","arboles","árboles"}),"Son realmente impresionantes.\n");
 break;
 }

 // añado un troll al azar (33% de prob)
    if (d2()==1)
        AddItem(PNJNYN("troll_nyne"), REFRESH_DESTRUCT, d2());
}


/*      REVISAR (para que sean genericas de cualquier bosque) Y AÑADIR


SetIntLong(W("Esta parte del bosque parece tener miles de años. Los árboles "
"son realmente enormes, y el aspecto que dan es bastante lúgubre, "
"incluso amenazador. Quizás sea por eso por lo que han resistido tanto "
"tiempo, por que prácticamente nadie se aventura por aqui, y quien lo "
"hace cuenta extrañas historias...\n"))

SetIntLong(W("Estás rodeado por lo que podrían ser los abuelos de los árboles "
"del resto del mundo. Siglos y siglos han vivido en relativa paz. Aunque "
"han sido escenario de batallas e invasiones, siempre han sido "
"respetados por los ejércitos, ya sea por respeto o por miedo.\n"));

SetIntLong(W("Allí donde mires verás árboles grandes, oscuros y retorcidos. "
"Estos árboles confieren al bosque un aspecto oscuro, lúgubre... "
"seguramente la zona está plagada de seres peligrosos y agresivos, "
"con los que seguramente es mejor no meterse.\n"));

SetIntLong(W("Ves el suelo recubierto de unos matojos de hierba que "
"seguramente no han sido excesivamente pisados por los habitantes de "
"los alrededores. Ni siquiera los lobos suelen atreverse a "
"adentrarse en esta zona.\n"));

SetIntLong(W("El suelo está salpicado de raíces de todos los árboles que "
"crecen a tu alrededor. Seguramente serán las raíces más largas "
"de toda la zona, teniendo en cuenta el tiempo que llevan aquí. "
"Un escalofrío recorre tu cuerpo y piensas que sería más sensato "
"ir a un lugar más apacible.\n"));

SetIntLong(W("Todo a tu alrededor parece hostil; los árboles que parecen "
"mirarte, las sombras que parecen moverse, algún crujido de alguna "
"rama, el silencio que reina en la zona debido a los pocos animales "
"que por aquí habitan...\n"));

SetIntLong(W("Desde luego no sería excesivamante tranquilizador el "
"perderse por aqui. ¡Quién sabe los peligros que pueden acecharte "
"en este milenario bosque!\n"));

SetIntLong(W("Ante tí ves una senda de tierra fina que conduce hacia el "
"norte y hacia el sur, creada seguramente por los pies de todos los "
"viajeros que van y vienen de la ciudad. Esta parte del bosque no "
"es demasiado frondosa ni la vegetación excesivamente compacta.\n"));

SetIntLong(W("En este suelo bastante pisado no ves demasiada hierba; más "
"bien lo que ves es una tierra fina que cubre toda la zona. Los "
"árboles, aunque grandes, no son enormes, y de vez en cuando ves "
"alguno creciendo entre sus hermanos.\n"));

SetIntLong(W("Ves distintos tipos de árboles, unos más pequeños que otros, "
"aunque ninguno es gigante. Seguramente esta parte del bosque es "
"relativamente nueva, quizás sólo tenga un par de centenares de "
"años.\n"));

SetIntLong(W("Esta parte del bosque no es demasiado frondosa. La senda "
"que ves a tus pies lo recorre en todas direcciones haciendo el "
"camino bastante más facil.\n"));

SetIntLong(W("Ves árboles y arbustos jóvenes, y algún que otro animalillo "
"furtivo espiándote. Las huellas de civilización son bastante "
"evidentes por aquí, puesto que la zona parece bastante transitada "
"como así lo demuestra el suelo desnudo.\n"));

SetIntLong(W("Estás en una parte del bosque en el que la gran cantidad de "
"vegetación te hace bastante difícil el camino, ya que las ramas de "
"los árboles y de los arbustos se entrecruzan ante tí.\n"));

SetIntLong(W("Estás rodeado por una exhuberante vegetación. Por el suelo "
"las raíces se entrecruzan como pueden, haciendo difícil el avance "
"en prácticamente todas las direcciones.\n"));

SetIntLong(W("Los grandes árboles te rodean en todas las direcciones "
"posibles, dejandote algún que otro lugar libre por donde poder "
"colarte, no sin una cierta dificultad.\n"));

SetIntLong(W("Aunque no hay ninguna senda, hay ciertas zonas hacia las "
"que puedes avanzar a pesar de la salvaje y desordenada espesura "
"de la maleza.\n"));

SetIntLong(W("Ves árboles hacia todas las direcciones a las que mires. "
"Todos estos árboles son enormes, aunque por el color y la forma "
"parecen ser jóvenes.\n"));

SetIntLong(W("Ves el suelo recubierto de maleza y musgo. Allí donde se "
"posen tus ojos ves vegetación: árboles, arbustos, hierba, zarzas, "
"matas, matojos... Desde luego un paraíso para quien le guste la "
"naturaleza...\n"));

SetIntLong(W("Este bosque es un claro ejemplo de lugar donde puedes "
"perderte con total facilidad, aunque las zonas a las que puedes "
"ir están bastante limitadas debido a la desmesurada vegetación "
"que crece por la zona.\n"));



 case 0: w="Estás en una parte del bosque en el que la vegetación "
	"es menos densa puesto que todavia te encuentras en los lindes del "
	" bosque, los árboles y de los arbustos se entrecruzan ante tí.\n";
	break;
    case 1: w="Estás rodeado por una exhuberante vegetación. Por el suelo "
    	"las raíces se entrecruzan como pueden, haciendo que te parezca "
    	"todo de lo mas irreal.\n";
    	break;
    case 2: w="Los árboles te rodean en todas las direcciones posibles,"
    	" aunque te dejan todavia sitio por donde poder "
    	"colarte, con apenas dificultad.\n";
    	break;
    case 3: w="Aunque no hay ninguna senda, hay ciertas zonas hacia las "
    	"que puedes avanzar a pesar de la salvaje y desordenada espesura "
    	"de la maleza.\n";
    	break;
    case 4: w="Ves árboles hacia todas las direcciones a las que mires. "
    	"Todos estos árboles son enormes, aunque por el color y la forma "
    	"parecen ser jóvenes.\n";
    case 5: w="Ves el suelo recubierto de maleza y musgo. Allí donde se "
    	"posen tus ojos ves vegetación: árboles, arbustos, hierba, "
    	"matas, matojos... Desde luego un paraíso para quien le guste la "
    	"naturaleza...\n";
    default: w="Este bosque es un claro ejemplo de lugar donde puedes "
    	"perderte con total facilidad, aunque las zonas a las que puedes "
    	"ir están bastante ilimitadas debido a que la vegetación "
    	"que crece por la zona todavia no es muy tupida.\n";


    case  0: w="Estás en una parte del bosque donde la gran cantidad de "
	     "vegetación te hace difícil el camino.\n";
	  break;

    case  1: w="Estás rodeado por una exhuberante vegetación. Las raices "
	     "de los árboles y arbustos se entrecruzan como pueden por entre el "
	     "suelo.\n";
	  break;

    case  2: w="Los grandes árboles y arbustos te rodean en "
	     "todas las direcciones posibles, dejandote algun que otro lugar "
	     "libre por donde poder colarte.\n";
	  break;

    case  3: w="Aunque no hay ninguna senda, hay ciertas zonas hacia las "
	     "que puedes avanzar a pesar de la espesura del bosque.\n";
	  break;

    case  4: w="Esta zona no esta demasiado transitada, a juzgar por las "
	     "pocas huellas de civilizacion que encuentras.\n";
	  break;

    case  5: w="Por alli por donde no hay arbustos puedes ver alguna que "
	     "otra huella de pequeños (y no tan pequeños) animales que habitan "
	     "por la zona.\n";
	  break;

    case  6: w="Este bosque es un claro ejemplo de lugar donde puedes "
	     "perderte con total facilidad.\n";
	  break;

    case  7: w="Las ramas de los árboles se cierran sobre tu cabeza, de una "
	     "manera que te recuerdan dedos entrelazados.\n";
	  break;

    case  8: w="Un suelo lleno de ramas caidas, hojas y pequeñas piedras, "
	     "asi como un techo natural formado por las frondosas ramas de los "
	     "árboles, son el único paisaje que puedes contemplar.\n";
	  break;

    case  9: w="No es nada aconsejable permanecer en lugares como este, "
	     "nadie sabe que se puede esconder tras los arbustos, las frondosas "
	     "ramas, o todavia peor, nadie sabe a que bestia te podrias encontrar.\n";
	  break;

    case 10: w="Grandes arboles forman este bosque. Por suerte, en esta zona "
	     "estan lo suficientemente separados como para que no impidan la "
	     "entrada del sol, de lo contrario sus copas no te dejarian "
	     "distinguir si es de noche o de dia.\n";
	 break;

    case 11: w="El bosque es mas denso y cerrado por aqui, para avanzar tienes "
	     "que evitar e ir apartando cientos de ramas, asi como sortear algun "
	     "que otro peñasco.\n";
	 break;

    case 12: w="Las ramas de los arboles se entrecruzan sobre tu cabeza protegiendote "
	     "de las posibles inclemencias del tiempo, aunque, por otra parte, no "
	     "contribuyen a la iluminación del bosque.\n";
	 break;

    case 13: w="El bosque es realmente denso, te encuentras rodeado de arboles que te "
	     "impiden el paso en muchas direcciones. Solo en algunos lugares por la "
	     "poca proximidad de unos arboles con otros o por las caprichosas formas "
	     "que estos adoptan serias capaz de pasar.\n";
	 break;

    case 14: w="La vegetación de este punto del bosque es más viva, aunque no sabes si "
	     "solo te lo parece a ti al no hallarte rodeado de los tetricos árboles "
	     "que forman el bosque.\n";
	 break;

    case 15: w="Algunos árboles se retuercen sobre sí mismo, otros forman extraños arcos "
	     "curvos. Estos árboles deben ser obra de la madre Naturaleza, pero a pesar "
	     "de sus formas, al menos puedes pasar entre ellos.\n";
	 break;

    case 16: w="Un suelo lleno de ramas caidas, hojas y pequeñas piedras, asi como un "
	     "techo natural formado por las frondosas ramas de los árboles, son el único "
	     "paisaje que puedes contemplar.\n";
	 break;

    case 17: w="El paisaje comienza a ser demasiado monotono, árboles y mas árboles, "
	     "hojas, ramas caidas, piedras y mas cosas. En este bosque es realmente "
	     "facil perder la orientación.\n";
	 break;

    case 18: w="Los grandes árboles te rodean produciendote una sensacion de protección "
	     "asi como algo de temor. En este oscuro bosque, habitan diversos tipos de "
	       "animales, algunos no muy amigables con los forasteros.\n";
NOTA:
LAS DEL BOSQUE DE ZARKAM HAY QUE COGERLAS UNA A UNA.

*/

/*    AQUI ESTAN TODOS LOS DETALLES AÑADIDOS ARRIBA. ESTO NO DEBERIA SALIR ALEATORIO, SINO
     QUE AL AÑADIR UNA NUEVA DESCRIPCION SE PUEDEN ELEGIR UNO O VARIOS DE LOS DE AQUI. SI
     QUIERES AÑADIR UNO NUEVO, TE RUEGO QUE LO AÑADAS AQUI TAMBIEN.

   AddDetail(({"pajaro","pájaro","pajaros","pájaros"}),"Se trata de una pareja de pichones revoloteando.\n");
   AddDetail(({"vegetacion","vegetación"}),"Las hierbas son extrañamente altas aquí.\n");
   AddDetail(("senda"),"No ves ninguna senda.\n");
   AddDetail(("huellas"),"Solo huellas de animales. Ni carromatos ni herraduras.\n");
   AddDetail(("arbustos"),"Enormes arbustos y matorrales crecen a la sombra de los árboles.\n");
   AddDetail(("huellas"),"Distingues las pequeñas huellas de lo que parece ser un conejo.\n");
   AddDetail(("hojas"),"Te encanta como crujen bajo tus pies.\n");
   AddDetail(("piedras"),W("Pequeñas piedrecillas inutiles, nada"
   AddDetail(({"vegetacion","vegetación"}),W("Largas hierbas y flores pueblan"
   AddDetail(({"hoja","hojas"}),"Hojas secas por todos lados.\n");
   AddDetail(({"piedra","piedras"}),W("En realidad, no llegan ni a piedras."

   AddDetail(("ramas"),"Si no llevas cuidado te podrian arañar la cara.\n");
   AddDetail(("ramas"),W("Son bastante gruesas, pero están muy altas como"
   AddDetail(("ramas"),"Las ramas más secas han caido al suelo y se descomponen dia a dia.\n");
   AddDetail(({"copa", "ramas"}),W("La copa del arbol está muy alta para llegar a ella."
                                   " Ves unas ardillas saltando entre las ramas.\n"));
   AddDetail(({"ardillas"}),"Es una pequeña ardilla voladora.\n");

   AddDetail(({"arbol","arboles","árboles"}),"Son realmente impresionantes.\n");
   AddDetail(({"arbol","arboles","árboles"}),"Son de gran tamaño. Te imponen bastante respeto.\n");
   AddDetail(({"arbol","arboles","árboles"}),"Son realmente enormes.\n");
   AddDetail(({"arbol","arboles","árboles"}),W("Las extrañas formas que"
   AddDetail(({"arboles","árboles"}),W(
                "Son bastante altos. Este bosque debe haberse salvado"
                " de taladores durante siglos.\n"));


*/