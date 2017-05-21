/*
  Generador de descripciones aleatorias para un bosque.
  Las descripciones del bosque seran aleatorias (NO LAS SALIDAS), y asi podran a�adirse
  el numero que se desee a este archivo sin que cambie el mapa.
  He ido recogiendo las descripciones de todos los archivos del mismo prop�sito que
  he encontrado, y aunque parezca una trola, tambien hay bastantes de mi propia cosecha.

  NOTA: AUNQUE YA ESTA COLGADO, NO ESTA ACABADO, Y PROMETO HACERLO EN CUANTO TENGA 5 MINUTOS.
        QUIERO CAMBIAR EL CREATE PARA QUE SE PASE COMO PARAMETRO EL NOMBRE DEL BOSQUE,
        Y ASI SE A�ADAN AUTOMATICAMENTE EN EL SetLocate, EL SetIntShort Y ALGUNAS DESCRIPCIONES
        LARGAS ESPECIALMENTE PREPARADAS PARA ELLO.

  10-10-01 [Bomber] Bomber@simauria.upv.es
  01-05-02 [Bomber] Bajo la posibilidad y cantidad de Trolls en el bosque.
                    En cuanto cuelgue las putas monta�as lo bajare mas todavia.

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
 case 6: SetIntSmell("�Un tigre?... Esperemos que fuese tu est�mago nada mas.\n"); break;
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
   SetIntLong(W("Est�s en una zona poco iluminada del bosque."
                " Aqu� las copas de los �rboles son un poco m�s altas de lo normal,"
                " y no parece probable que se pueda escalar hasta ellas,"
                " as� que piensas que es mejor ni siquiera intentarlo. "
                "Ves algo moverse rapidamente entre las ramas.\n"));
   AddDetail(({"copa", "ramas"}),W("La copa del arbol est� muy alta para llegar a ella."
                                   " Ves unas ardillas saltando entre las ramas.\n"));
   AddDetail(({"ardillas"}),"Es una peque�a ardilla voladora.\n");
 break;
 case 1:
   SetIntLong(W("Est�s perdido en medio del bosque. Aqu� la luz es m�s fuerte,"
                " debido a la menor altura de los arboles. La hierba crece por todas partes,"
                " y peque�os roedores se esconden entre ella y huyen al verte."
                " Unos pajarillos saltan alegremente de rama en rama.\n"));
   AddDetail(({"pajaro","p�jaro","pajaros","p�jaros"}),"Se trata de una pareja de pichones revoloteando.\n");
 break;
 case 2:
   SetIntLong(W("No te gusta esta zona del bosque. Crees que ser�a mejor largarse."
                " Nunca se sabe que clase de bestia puede estar acechandote por estos lares.\n"));
 break;
 case 3:
   SetIntLong(W("En esta parte del bosque hay una gran cantidad de vegetaci�n,"
                " por lo que te es dif�cil reconocer alg�n camino."
                " Al menos sabes que continuas en el bosque... �o tal vez no?\n"));
   AddDetail(({"vegetacion","vegetaci�n"}),"Las hierbas son extra�amente altas aqu�.\n");
 break;
 case 4:
   SetIntLong(W("Est�s rodeado por abundante vegetaci�n. Grandes �rboles y"
                " arbustos te rodean en todas direcciones. Solo encuentras"
                " alg�n que otro resquicio libre para colarte sin que las ramas ara�en tu rostro.\n"));
   AddDetail(({"arboles","�rboles"}),W(
                "Son bastante altos. Este bosque debe haberse salvado"
                " de taladores durante siglos.\n"));
 break;
 case 5:
   SetIntLong(W("Aunque no hay ninguna senda, hay ciertas zonas hacia"
                " las que puedes avanzar, a pesar de la espesura del bosque."
                " No te gustar�a que la noche te sorprendiera aqui solo.\n"));
   AddDetail(("senda"),"No ves ninguna senda.\n");
 break;
 case 6:
   SetIntLong(W("Esta zona no esta demasiado transitada, a juzgar por las"
                " pocas huellas de civilizaci�n que encuentras."
                " De hecho, hace tiempo que no distingues huella humana alguna.\n"));
   AddDetail(("huellas"),"Solo huellas de animales. Ni carromatos ni herraduras.\n");
 break;
 case 7:
   SetIntLong(W("Por all� por donde no hay arbustos puedes ver alguna"
                " que otra huella de animales t�picos de la zona.\n"));
   AddDetail(("arbustos"),"Enormes arbustos y matorrales crecen a la sombra de los �rboles.\n");
   AddDetail(("huellas"),"Distingues las peque�as huellas de lo que parece ser un conejo.\n");
 break;
 case 8:
   SetIntLong(W("Este bosque es un claro ejemplo de lugar donde puedes"
                " perderte con total facilidad."
                " De hecho, es el claro ejemplo de un lugar donde"
                " no piensas volver en tu vida.\n"));
 break;
 case 9:
   SetIntLong(W("Las ramas de los �rboles se entrelazan por encima de ti,"
                " lo que hace que la luz disminuya ligeramente."
                " La poca luz en esta zona hace de ella un lugar propicio"
                " para una emboscada. Deberias largarte cuanto antes.\n"));
   AddDetail(("ramas"),W("Son bastante gruesas, pero est�n muy altas como"
                         " para que puedas subirte a ellas.\n"));
 break;
 case 10:
   SetIntLong(W("Un suelo lleno de ramas ca�das, hojas y peque�as piedras,"
                " as� como un techo natural formado por las frondosas ramas"
		    " de los �rboles, es el �nico paisaje que puedes contemplar.\n"));
   AddDetail(("ramas"),"Las ramas m�s secas han caido al suelo y se descomponen dia a dia.\n");
   AddDetail(("hojas"),"Te encanta como crujen bajo tus pies.\n");
   AddDetail(("piedras"),W("Peque�as piedrecillas inutiles, nada"
                           " suficientemente grande como para ser lanzado"
			   " sin que lo frene el mismo aire.\n"));
 break;
 case 11:
   SetIntLong(W("Grandes �rboles forman este bosque. Por suerte, en esta"
                " zona est�n lo suficientemente separados como para que no"
		    " impidan la entrada del sol, de lo contrario sus copas no"
		    " te dejar�an distinguir si es de noche o de dia.\n"));
   AddDetail(({"arbol","arboles","�rboles"}),"Son realmente enormes.\n");
 break;
 case 12:
   SetIntLong(W("El bosque es m�s denso y cerrado por aqu�. Para avanzar"
                " tienes que evitar e ir apartando cientos de ramas, as�"
		    " como sortear alg�n que otro pe�asco.\n"));
   AddDetail(("ramas"),"Si no llevas cuidado te podrian ara�ar la cara.\n");
 break;
 case 13:
   SetIntLong(W("El bosque es realmente denso. Te encuentras rodeado de �rboles"
                " que te impiden el paso en muchas direcciones. S�lo en algunos"
		    " lugares, por la poca proximidad de unos �rboles con otros, o"
		    " por las caprichosas formas que estos adoptan, ser�as capaz de pasar.\n"));
   AddDetail(({"arbol","arboles","�rboles"}),W("Las extra�as formas que"
                " toman te hace pensar que no lo han hecho de forma natural.\n"));
 break;
 case 14:
   SetIntLong(W("La vegetaci�n de este punto del bosque es m�s viva,"
                " aunque no sabes si solo te lo parece a ti al no hallarte"
		    " rodeado de los t�tricos �rboles que forman el bosque.\n"));
   AddDetail(({"vegetacion","vegetaci�n"}),W("Largas hierbas y flores pueblan"
                " la zona, que parece estar menos cubierta de �rboles.\n"));
 break;
 case 15:
   SetIntLong(W("Algunos �rboles se retuercen sobre s� mismo, otros forman"
                " extra�os arcos curvos. Estos �rboles deben ser obra de la"
		    " madre Naturaleza, pero a pesar de sus formas, al menos"
		    " puedes pasar entre ellos.\n"));
 break;
 case 16:
   SetIntLong(W("El paisaje comienza a ser demasiado mon�tono, �rboles y m�s"
               " �rboles, hojas, ramas ca�das, piedras y m�s cosas."
	         " En este bosque es realmente f�cil perder la orientaci�n.\n"));
   AddDetail(({"arbol","arboles","�rboles"}),"Son de gran tama�o. Te imponen bastante respeto.\n");
   AddDetail(({"hoja","hojas"}),"Hojas secas por todos lados.\n");
   AddDetail(({"piedra","piedras"}),W("En realidad, no llegan ni a piedras."
                                      " Son solo grava.\n"));
   AddDetail(({"rama","ramas"}),"Rotas y secas se esparcen por todos lados.\n");
 break;
 case 17:
   SetIntLong(W("Los grandes �rboles te rodean produci�ndote una sensaci�n"
                " de protecci�n as� como algo de temor. En este oscuro"
                " bosque, habitan diversos tipos de animales, algunos no"
	          " muy amigables con los forasteros.\n"));
   AddDetail(({"arbol","arboles","�rboles"}),"Son realmente impresionantes.\n");
 break;
 }

 // a�ado un troll al azar (33% de prob)
    if (d2()==1)
        AddItem(PNJNYN("troll_nyne"), REFRESH_DESTRUCT, d2());
}


/*      REVISAR (para que sean genericas de cualquier bosque) Y A�ADIR


SetIntLong(W("Esta parte del bosque parece tener miles de a�os. Los �rboles "
"son realmente enormes, y el aspecto que dan es bastante l�gubre, "
"incluso amenazador. Quiz�s sea por eso por lo que han resistido tanto "
"tiempo, por que pr�cticamente nadie se aventura por aqui, y quien lo "
"hace cuenta extra�as historias...\n"))

SetIntLong(W("Est�s rodeado por lo que podr�an ser los abuelos de los �rboles "
"del resto del mundo. Siglos y siglos han vivido en relativa paz. Aunque "
"han sido escenario de batallas e invasiones, siempre han sido "
"respetados por los ej�rcitos, ya sea por respeto o por miedo.\n"));

SetIntLong(W("All� donde mires ver�s �rboles grandes, oscuros y retorcidos. "
"Estos �rboles confieren al bosque un aspecto oscuro, l�gubre... "
"seguramente la zona est� plagada de seres peligrosos y agresivos, "
"con los que seguramente es mejor no meterse.\n"));

SetIntLong(W("Ves el suelo recubierto de unos matojos de hierba que "
"seguramente no han sido excesivamente pisados por los habitantes de "
"los alrededores. Ni siquiera los lobos suelen atreverse a "
"adentrarse en esta zona.\n"));

SetIntLong(W("El suelo est� salpicado de ra�ces de todos los �rboles que "
"crecen a tu alrededor. Seguramente ser�n las ra�ces m�s largas "
"de toda la zona, teniendo en cuenta el tiempo que llevan aqu�. "
"Un escalofr�o recorre tu cuerpo y piensas que ser�a m�s sensato "
"ir a un lugar m�s apacible.\n"));

SetIntLong(W("Todo a tu alrededor parece hostil; los �rboles que parecen "
"mirarte, las sombras que parecen moverse, alg�n crujido de alguna "
"rama, el silencio que reina en la zona debido a los pocos animales "
"que por aqu� habitan...\n"));

SetIntLong(W("Desde luego no ser�a excesivamante tranquilizador el "
"perderse por aqui. �Qui�n sabe los peligros que pueden acecharte "
"en este milenario bosque!\n"));

SetIntLong(W("Ante t� ves una senda de tierra fina que conduce hacia el "
"norte y hacia el sur, creada seguramente por los pies de todos los "
"viajeros que van y vienen de la ciudad. Esta parte del bosque no "
"es demasiado frondosa ni la vegetaci�n excesivamente compacta.\n"));

SetIntLong(W("En este suelo bastante pisado no ves demasiada hierba; m�s "
"bien lo que ves es una tierra fina que cubre toda la zona. Los "
"�rboles, aunque grandes, no son enormes, y de vez en cuando ves "
"alguno creciendo entre sus hermanos.\n"));

SetIntLong(W("Ves distintos tipos de �rboles, unos m�s peque�os que otros, "
"aunque ninguno es gigante. Seguramente esta parte del bosque es "
"relativamente nueva, quiz�s s�lo tenga un par de centenares de "
"a�os.\n"));

SetIntLong(W("Esta parte del bosque no es demasiado frondosa. La senda "
"que ves a tus pies lo recorre en todas direcciones haciendo el "
"camino bastante m�s facil.\n"));

SetIntLong(W("Ves �rboles y arbustos j�venes, y alg�n que otro animalillo "
"furtivo espi�ndote. Las huellas de civilizaci�n son bastante "
"evidentes por aqu�, puesto que la zona parece bastante transitada "
"como as� lo demuestra el suelo desnudo.\n"));

SetIntLong(W("Est�s en una parte del bosque en el que la gran cantidad de "
"vegetaci�n te hace bastante dif�cil el camino, ya que las ramas de "
"los �rboles y de los arbustos se entrecruzan ante t�.\n"));

SetIntLong(W("Est�s rodeado por una exhuberante vegetaci�n. Por el suelo "
"las ra�ces se entrecruzan como pueden, haciendo dif�cil el avance "
"en pr�cticamente todas las direcciones.\n"));

SetIntLong(W("Los grandes �rboles te rodean en todas las direcciones "
"posibles, dejandote alg�n que otro lugar libre por donde poder "
"colarte, no sin una cierta dificultad.\n"));

SetIntLong(W("Aunque no hay ninguna senda, hay ciertas zonas hacia las "
"que puedes avanzar a pesar de la salvaje y desordenada espesura "
"de la maleza.\n"));

SetIntLong(W("Ves �rboles hacia todas las direcciones a las que mires. "
"Todos estos �rboles son enormes, aunque por el color y la forma "
"parecen ser j�venes.\n"));

SetIntLong(W("Ves el suelo recubierto de maleza y musgo. All� donde se "
"posen tus ojos ves vegetaci�n: �rboles, arbustos, hierba, zarzas, "
"matas, matojos... Desde luego un para�so para quien le guste la "
"naturaleza...\n"));

SetIntLong(W("Este bosque es un claro ejemplo de lugar donde puedes "
"perderte con total facilidad, aunque las zonas a las que puedes "
"ir est�n bastante limitadas debido a la desmesurada vegetaci�n "
"que crece por la zona.\n"));



 case 0: w="Est�s en una parte del bosque en el que la vegetaci�n "
	"es menos densa puesto que todavia te encuentras en los lindes del "
	" bosque, los �rboles y de los arbustos se entrecruzan ante t�.\n";
	break;
    case 1: w="Est�s rodeado por una exhuberante vegetaci�n. Por el suelo "
    	"las ra�ces se entrecruzan como pueden, haciendo que te parezca "
    	"todo de lo mas irreal.\n";
    	break;
    case 2: w="Los �rboles te rodean en todas las direcciones posibles,"
    	" aunque te dejan todavia sitio por donde poder "
    	"colarte, con apenas dificultad.\n";
    	break;
    case 3: w="Aunque no hay ninguna senda, hay ciertas zonas hacia las "
    	"que puedes avanzar a pesar de la salvaje y desordenada espesura "
    	"de la maleza.\n";
    	break;
    case 4: w="Ves �rboles hacia todas las direcciones a las que mires. "
    	"Todos estos �rboles son enormes, aunque por el color y la forma "
    	"parecen ser j�venes.\n";
    case 5: w="Ves el suelo recubierto de maleza y musgo. All� donde se "
    	"posen tus ojos ves vegetaci�n: �rboles, arbustos, hierba, "
    	"matas, matojos... Desde luego un para�so para quien le guste la "
    	"naturaleza...\n";
    default: w="Este bosque es un claro ejemplo de lugar donde puedes "
    	"perderte con total facilidad, aunque las zonas a las que puedes "
    	"ir est�n bastante ilimitadas debido a que la vegetaci�n "
    	"que crece por la zona todavia no es muy tupida.\n";


    case  0: w="Est�s en una parte del bosque donde la gran cantidad de "
	     "vegetaci�n te hace dif�cil el camino.\n";
	  break;

    case  1: w="Est�s rodeado por una exhuberante vegetaci�n. Las raices "
	     "de los �rboles y arbustos se entrecruzan como pueden por entre el "
	     "suelo.\n";
	  break;

    case  2: w="Los grandes �rboles y arbustos te rodean en "
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
	     "otra huella de peque�os (y no tan peque�os) animales que habitan "
	     "por la zona.\n";
	  break;

    case  6: w="Este bosque es un claro ejemplo de lugar donde puedes "
	     "perderte con total facilidad.\n";
	  break;

    case  7: w="Las ramas de los �rboles se cierran sobre tu cabeza, de una "
	     "manera que te recuerdan dedos entrelazados.\n";
	  break;

    case  8: w="Un suelo lleno de ramas caidas, hojas y peque�as piedras, "
	     "asi como un techo natural formado por las frondosas ramas de los "
	     "�rboles, son el �nico paisaje que puedes contemplar.\n";
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
	     "que otro pe�asco.\n";
	 break;

    case 12: w="Las ramas de los arboles se entrecruzan sobre tu cabeza protegiendote "
	     "de las posibles inclemencias del tiempo, aunque, por otra parte, no "
	     "contribuyen a la iluminaci�n del bosque.\n";
	 break;

    case 13: w="El bosque es realmente denso, te encuentras rodeado de arboles que te "
	     "impiden el paso en muchas direcciones. Solo en algunos lugares por la "
	     "poca proximidad de unos arboles con otros o por las caprichosas formas "
	     "que estos adoptan serias capaz de pasar.\n";
	 break;

    case 14: w="La vegetaci�n de este punto del bosque es m�s viva, aunque no sabes si "
	     "solo te lo parece a ti al no hallarte rodeado de los tetricos �rboles "
	     "que forman el bosque.\n";
	 break;

    case 15: w="Algunos �rboles se retuercen sobre s� mismo, otros forman extra�os arcos "
	     "curvos. Estos �rboles deben ser obra de la madre Naturaleza, pero a pesar "
	     "de sus formas, al menos puedes pasar entre ellos.\n";
	 break;

    case 16: w="Un suelo lleno de ramas caidas, hojas y peque�as piedras, asi como un "
	     "techo natural formado por las frondosas ramas de los �rboles, son el �nico "
	     "paisaje que puedes contemplar.\n";
	 break;

    case 17: w="El paisaje comienza a ser demasiado monotono, �rboles y mas �rboles, "
	     "hojas, ramas caidas, piedras y mas cosas. En este bosque es realmente "
	     "facil perder la orientaci�n.\n";
	 break;

    case 18: w="Los grandes �rboles te rodean produciendote una sensacion de protecci�n "
	     "asi como algo de temor. En este oscuro bosque, habitan diversos tipos de "
	       "animales, algunos no muy amigables con los forasteros.\n";
NOTA:
LAS DEL BOSQUE DE ZARKAM HAY QUE COGERLAS UNA A UNA.

*/

/*    AQUI ESTAN TODOS LOS DETALLES A�ADIDOS ARRIBA. ESTO NO DEBERIA SALIR ALEATORIO, SINO
     QUE AL A�ADIR UNA NUEVA DESCRIPCION SE PUEDEN ELEGIR UNO O VARIOS DE LOS DE AQUI. SI
     QUIERES A�ADIR UNO NUEVO, TE RUEGO QUE LO A�ADAS AQUI TAMBIEN.

   AddDetail(({"pajaro","p�jaro","pajaros","p�jaros"}),"Se trata de una pareja de pichones revoloteando.\n");
   AddDetail(({"vegetacion","vegetaci�n"}),"Las hierbas son extra�amente altas aqu�.\n");
   AddDetail(("senda"),"No ves ninguna senda.\n");
   AddDetail(("huellas"),"Solo huellas de animales. Ni carromatos ni herraduras.\n");
   AddDetail(("arbustos"),"Enormes arbustos y matorrales crecen a la sombra de los �rboles.\n");
   AddDetail(("huellas"),"Distingues las peque�as huellas de lo que parece ser un conejo.\n");
   AddDetail(("hojas"),"Te encanta como crujen bajo tus pies.\n");
   AddDetail(("piedras"),W("Peque�as piedrecillas inutiles, nada"
   AddDetail(({"vegetacion","vegetaci�n"}),W("Largas hierbas y flores pueblan"
   AddDetail(({"hoja","hojas"}),"Hojas secas por todos lados.\n");
   AddDetail(({"piedra","piedras"}),W("En realidad, no llegan ni a piedras."

   AddDetail(("ramas"),"Si no llevas cuidado te podrian ara�ar la cara.\n");
   AddDetail(("ramas"),W("Son bastante gruesas, pero est�n muy altas como"
   AddDetail(("ramas"),"Las ramas m�s secas han caido al suelo y se descomponen dia a dia.\n");
   AddDetail(({"copa", "ramas"}),W("La copa del arbol est� muy alta para llegar a ella."
                                   " Ves unas ardillas saltando entre las ramas.\n"));
   AddDetail(({"ardillas"}),"Es una peque�a ardilla voladora.\n");

   AddDetail(({"arbol","arboles","�rboles"}),"Son realmente impresionantes.\n");
   AddDetail(({"arbol","arboles","�rboles"}),"Son de gran tama�o. Te imponen bastante respeto.\n");
   AddDetail(({"arbol","arboles","�rboles"}),"Son realmente enormes.\n");
   AddDetail(({"arbol","arboles","�rboles"}),W("Las extra�as formas que"
   AddDetail(({"arboles","�rboles"}),W(
                "Son bastante altos. Este bosque debe haberse salvado"
                " de taladores durante siglos.\n"));


*/