/*
Fichero: despensa.c
Autor: aul�
Fecha: 18/03/2013
Descripci�n:  despensa del Poney Pisador. 
*/
#include "./path.h"
inherit BREE_ROOM;
create()
{
    ::create();
    	SetIntShort("una surtida despensa");
    	SetIntLong("Indudablemente, est�s en la despensa de la que salen los ingredientes "
    	"para los exquisitos platos que se sirven en el Poney Pisador.\n"
    	"Es una larga habitaci�n de techo no muy alto, orientada hacia el este y a "
    	"juzgar por la rugosidad de los muros y el frescor del ambiente, excavada en la "
    	"ladera rocosa de la colina.\n"
    	"Por todas partes se acumulan infinidad de alimentos. Una secci�n del suelo de "
    	"piedra junto a la pared, delimitada por un tronco descortezado, est� repleta de patatas "
    	"de todos los tama�os, y sobre ella, numerosos ganchos de hierro sostienen manojos "
    	"de ajos y ramos de cebollas. En un caj�n se amontonan infinidad de nabos, y en "
    	"unos estantes clavados a la pared reposan varios quesos de distintos tama�os y "
    	"algunos recipientes met�licos repletos de mantequilla y crema pastelera.\n"
    	"Varias tartas est�n colocadas en una valda junto a la puerta, listas para "
    	"partirse en porciones y servirse. De la pared del fondo, cuelgan sobre unos sacos "
    	"de harina varios jamones y embutidos y trozos de carne que al parecer est�n "
    	"sserenando. A un lado hay dos enormes barriles de cerveza algo separados entre s�.\n"
    	"Por �ltimo, en la zona m�s fresca de la despensa hay apoyadas en el suelo un par "
    	"de grandes lecheras repletas de leche fresca.\n");
    	AddDetail(({"pared", "paredes", "muro", "muros", "techo"}),
    	"Su superficie es rugosa, pues est� formada por la misma roca viva de la colina y "
    	"a�n se perciben las marcas de las herramientas con las que se llev� a cabo la "
    	"excavaci�n.\n");
    	AddDetail("alimentos",
    	"La despensa est� bien surtida de jamones, embutidos, carne, nabos, patatas, "
    	"cebollas, ajos, leche, manteca, quesos y toda clase de provisiones./n");
    	AddDetail("patatas",
    	"Las patatas que se amontonan al pie del muro parecen grandes y de buena calidad.\n");
    	AddDetail(({"manjojos", "ajos"}),
    	"De varios ganchos cuelgan peque�os manojos de ajos bien anudados.\n");
    	AddDetail(({"ramos", "cebollas"}),
    		"Son grandes ramos formados por cinco o seis cebollas cada uno, anudadas entre "
    		"s� por el seco tallo posterior para colgarlos de los ganchos de la pared.\n");
    		AddDetail("nabos",
    		"Gran cantidad de nabos de buena calidad llenan hasta los topes un caj�n de "
    		"madera.\n");
    		AddDetail("quesos",
    		"Enormes quesos de oveja, de vaca y mixtos reposan sobre las valdas de la pared.\n");
    		AddDetail(({"mantequilla", "crema"}),
    		"Grandes recipientes met�licos contienen mantequilla de vaca y crema "
    		"pastelera para cubrir y rellenar distintos alimentos.\n");
    		AddDetail("tartas",
    		"Tartas redondas y reci�n hechas cubren uno de los estantes. Las hay de fresas, "
    		"de manzana, de crema, de queso, de mora, de frutos del bosque...\n");
    		AddDetail(({"sacos", "harina"}),
    		"Unos cuantos sacos de harina se apoyan contra uno de los muros.\n");
    		AddDetail(({"trozos", "carne", "trozos de carne"}),
    		"Son piezas de carne de diversa forma que cuelgan de ganchos del muro.\n");
    		AddDetail("jamones",
    		"Cuentas hasta media docena de gran tama�o que cuelgan de la pared.\n"
    		"Uno de ellos est� empezado y le falta al menos la mitad.\n");
    		AddDetail("embutidos",
    			"Chorizos, gruesas salchichas y algunas morcillas de aspecto apetitoso "
    			"cuelgan de la pared.\n");
    			AddDetail("lecheras",
    			"Son lecheras de lat�n de unos diez litros que contienen leche reci�n orde�ada.\n");
    	AddDetail("estantes",
    	"Los distintos estantes y valdas soportan la carga de parte de los alimentos de la "
    	"despensa, entre ellos grandes quesos de oveja.\n"
   "Adviertes que entre dos filas de estantes, en la esquina formada por el muro sur y "
   "el este, Hay una peque�a puerta.\n");
   SetIntSmell("Aspiras la mezcla de olores a todo tipo de carnes, l�cteos y tub�rculos, "
   "embutidos curados y madera seca.\n");
   SetIntNoise("Escuchas el constante traj�n de la cocina contigua a la despensa.\n");
    	SetIndoors(1);
    SetIntBright(20);
     AddExit("oeste", "./cocina2");
     AddExit("sureste", "./bodega");
         HideExit("sureste",1);
     AddDoor("oeste", "la puerta",
     "Es una puerta  hecha de gruesas tablas unidas por un par de travesa�os "
     "horizontales  colocados en su parte inferior y superior.\n"
     "Las grandes bisagras de hierro que la unen al marco de piedra est�n "
     "ligeramente oxidadas.\n",
    ({"oeste", "o", "cocina", "puerta"}));
    AddDoor("sureste", "una peque�a puerta",
    "Es una peque�a puerta situada en el fondo de la despensa, medio oculta entre los "
    "estantes.\n"
    "Hecha con una sola pieza de madera cuadrada, cuenta con  pestillo y tres gruesas bisagras "
    "de hierro lo suficientemente s�lidas para soportar el peso del macizo tabl�n que "
    "la constituye.\n",
    ({"se", "sureste", "peque�a", "baja", "peque�a puerta", "puertecita", "bodega"}));
     
    }