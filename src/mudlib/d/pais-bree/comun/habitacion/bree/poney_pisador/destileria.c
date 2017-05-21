/*
Fichero: destileria.c
Autor: aulë
Fecha: 27/02/2014
Descripción:  un almacén secundario que también oficia como destilería de la posada. 
*/
#include "./path.h"
inherit BREE_ROOM;

string f_sonidos(){
    switch(d20(2)){
        case 1:        	return "Oyes un relincho procedente de los establos.\n";
        	case 2:
        		return "Escuchas el suave crujir del techo producido por los pasos de "
        		"alguien en el piso de arriba.\n";
        		case 3:
        			return "Oyes como alguien grita pidiendo cerveza en la lejanía.\n";
        			case 4:
        				return "Escuchas el lejano canto de un gallo.\n";
        				        				case 5:
        					return "Oyes que alguien grita dando órdenes.\n";
        					case 6:
        						return "Escuchas el débil sonido de unos postigos  que se cierran.\n";
        						case 7:
        							return "Oyes el lejano sonido decacerolas que entrechocan entre sí.\n";
        							case 8:
        								return "Alguien grita desde lejos pidiendo algo.\n";
        								case 9:
        									return "Escuchas risas a lo lejos.\n";
        									case 10:
        										return "Se escuchan los golpes de un hacha partiendo leña en el patio.\n";
        										case 11:
        											return "Alguien grita en el patio: ¿llevo otro cesto de leña?\n";
        											case 13:
        												return "Alguien grita desde los establos: ¡maldito poney, me ha mordido!.\n";
        												case 14:
        													return "Uno de los barriles cruje suavemente";
        													case 15:
        														return "Oyes los débiles ecos de una canción de taberna.\n";
        														case 16:
        															return "Oyes que alguien llama a lo lejos.\n";
        															case 17:
        																return "Se escucha el golpe de algo que cae en el piso de arriba";
        																case 18:
        																return "Escuchas como alguien arroja astillas a un cesto en el patio.\n";
        																case 19:
        																return "El techo cruje cuando alguien camina lentamente en el piso de arriba";
        																	case 20:
        																		return "Alguien silba alegremente mientras parte leña en el patio.\n";
        																		case 21:
        																			return "Oyes voces airadas que discuten en el piso de arriba";
        																			case 22:
        																				return "Oyes el arrastrar de algo pesado en el piso de arriba.\n";
        																				
 }
    return "";
}

string f_olores(){
    switch(d6()){
        case 1:
return "Huele al vino de las barricas.\n";
case 2:
	return "Huele a la cerveza almacenada en barriles y toneles.\n";
	case 3:
		return "Hueles a madera seca.\n";
		case 4:
			return "Te llega un débil olor a comida.\n";
			case 5:
				return "Te llega olor a humo de leña.\n";
			    }
    return "";
}




    create(){

::create();
    	SetIntShort("un almacén");
    	SetIntLong("Estás en un largo almacén secundario situado bajo el ala sur de la "
    	"posada.\n"
   "Largas hileras de barriles, barricas y toneles se alinean unos sobre otros a lo "
   "largo de los muros este y oeste. Junto a la puerta cuelgan  una gran variedad de "
   "herramientas y bajo ellas se apilan tablas, postes y tablones. En la pared del "
   "frente se localiza un largo banco de trabajo junto al que se acumulan algunos cubos "
   "de distintos tipos que reposan sobre el suelo.\n");
   AddDetail("postes",
   "Varios postes alisados y descortezados se apoyan contra el muro esperando ser "
   "utilizados para algún menester.\n");
   AddDetail("tablas",
   "Una pila de tablas reposan junto a la pared esperando ser utilizadas.\n");
   AddDetail("tablones",
   "Gruesos tablones de roble se apilan junto a la pared.\n");
   AddDetail("suelo",
   "Es irregular, hecho de piedra y está cubierto por restos de serrín, birutas y algo "
   "de paja seca.\n");
   AddDetail(({"pared", "paredes", "muro", "muros"}),
   "Los muros están levantados con gruesas piedras irregulares con numerosos entrantes, "
   "salientes y recovecos.\n");
   AddDetail("barricas",
   "Pequeñas y rechonchas barricas de vino de algo menos de un metro de altura y "
   "confeccionados con tablillas verticales sujetas por un par de aros de hierro.\n");
   AddDetail("barriles",
   "Grandes barriles de madera cuyo contenido no podrías precisar.\n");
   AddDetail("toneles",
   "Son enormes toneles de grandes tablones curvos sujetos por tres anchos aros de "
   "hierro. Su tamaño permite que un hombre quepa dentro de pie.\n");
   AddDetail("herramientas",
   "Rastrillos, palas, alguna azada, un par de escobas, tres grandes martillos, un "
   "mazo, dos hachuelas y dos hachas, y una palanca cuelgan del muro este.\n");
   AddDetail("banco",
   "Un largo banco de trabajo formado por la mitad de un tronco alisado apoyado sobre "
   "cuatro gruesos y cortos pilares de madera descortezada. Encima hay colocados un par "
   "de martillos pequeños, unas tenazas, un serrucho y una larga lima para madera.\n");
   AddDetail("cubos",
   "Cubos de madera con asas de hierro. Los hay de distintos tamaños y están metidos "
   "unos dentro de otros para ahorrar espacio.\n");
   AddDetail("techo",
   "Grandes vigas de roble soportan un techo de tablones cubierto de polvo y "
   "algunas telarañas.\n");
    	    SetIndoors(1);
    	             SetIntSmell(SF(f_olores));
            SetIntNoise(SF(f_sonidos));
    SetIntBright(25);
     AddExit("norte", "./patio2");
     AddDoor("norte", "un ancho portón",
     "Es un ancho portón de tablones de doble batiente. Dos gruesos travesaños de "
     "madera recorren la parte superior e inferior para reforzar el conjunto y uno de "
     "los batientes se asegura en su sitio mediante un par de pasadores de hierro que se "
     "insertan en el suelo y en el marco superior.\n",
     ({"porton", "portón", "norte", "n", "puerta norte", "puerta n"})); 
     }