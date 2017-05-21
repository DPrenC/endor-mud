/*
Fichero: arcada.c
Autor: aulë
Fecha: 12/03/2013
Descripción: bajo la arcada de la posada del Poney Pisador,
es la entrada principal a la posada. 
*/
#include "./path.h"
inherit BREE_ROOM;
#include <moving.h>


string f_sonidos(){
    switch(d20(2)){
        case 1:        	return "Oyes un relincho procedente del sur.\n";
        	case 2:
        		return "Los cascos de una montura resuenan en el camino.\n";
        		case 3:
        			return "Oyes como alguien grita pidiendo cerveza dentro de la posada.\n";
        			case 4:
        				return "Escuchas el lejano canto de un gallo.\n";
        				        				case 5:
        					return "Oyes que alguien grita desde el sur: ¡Maldita sea, amarra bien esa mula!";
        					case 6:
        						return "Oyes pasos apresurados dentro de la posada.\n";
        						case 7:
        							return "Se escucha un profundo relincho procedente de los establos.\n";
        							case 8:
        								return "Alguien grita desde la posada: ¡Sí, trae un poco más de pan!\n";
        								case 9:
        									return "Escuchas un coro de risotadas procedente del interior "
        									"de la posada.\n";
        									case 10:
        										return "Oyes el entrechocar de cacharros procedente de la cocina de la posada.\n";
        										case 11:
        											return "Oyes voces iracundas que discuten en el interior de la posada.\n";
        											case 13:
        												return "Oyes un rebuzno procedente del sur.\n";
        												case 14:
        													return "Alguien grita desde el sur: ¡Prepara el carro de allí, los enanos que llegaron ayer quieren partir enseguida!\n";
        													case 15:
        														return "Un coro de voces se alza entonando una alegre canción de taberna.\n";
        														case 16:
        															return "Oyes que alguien llama a lo lejos.\n";
        															case 17:
        																return "Alguien grita: ¡Id abriendo otro barril de cerveza, este se está acabando! ¡Por el amor del cielo, no puedo estar a todo a la vez!\n";
        																case 18:
        																return "Oyes los pasos en la gravilla del camino de alguien que pasa cerca silbando una alegre tonada.\n";
        																case 19:
        																return "Alguien grita en el establo: ¡Hay que llenar esos pesebres de heno... esa recua de poneys los han dejado sin una brizna!\n";
        																	case 20:
        																		return "Oyes el sonido de voces y el entrechocar de cubiertos y jarras procedente del interior de la posada.\n";
        																		case 21:
        																			return "Alguien grita desde la posada: ¡Abrid otro par de barriles y sacad una olla de carne asada... y el queso de oveja grande! Ah... y el jamón de la esquina! Tengo una maldita tropa de enanos hambrientos e impacientes esperando!\n";
        																			case 22:
        																				return "Alguien grita: ¡Cebadilla, ¿dónde está esa cerveza? ¡tenemos sed!\n";
        																				
 }
    return "";
}

string f_olores(){
    switch(d6()){
        case 1:
return "Te llega el olor a estiércol, paja y animales procedente de los establos.\n";
case 2:
	return "Te llega una vaharada a pan recién horneado.\n";
	case 3:
		return "El olor a carne asada invade tus fosas nasales.\n";
		case 4:
			return "Hueles a sopa recién hecha.\n";
			case 5:
				return "Te llega olor a humo.\n";
			    }
    return "";
}


        																				
create()
{
    ::create();
    	SetIntShort("bajo la enseña del Poney Pisador");
    	SetIntLong("Te encuentras bajo una amplia arcada que une las dos alas de la posada.\n"
    	"Al este se abre un patio cobijado entre ambas partes del edificio y al oeste se "
    	"sale a la vía principal de la aldea. Al sur se puede ver una sólida puerta de "
    	"doble batiente que parece dar acceso a los establos y al norte, bajo un letrero y "
    	"sobre unos amplios escalones, se sitúa la puerta de la posada, de la que manan "
    	"luz, calor y voces alegres.\n"
    	"El suelo es de tierra batida mezclada con piedrecillas y bajo la arcada cuelga"
    	"un gran farol sobre un tablero que se balancea suavemente movido por el viento.\n");
    AddDetail(({"vía", "via", "camino"}),
    "El camino traza una curva frente a la posada, bajando por la falda de la colina "
    "hasta la puerta occidental de la aldea y mordeando la colina hasta la puerta sur.\n");
    AddDetail("escalones",
    "Cuatro amplios escalones de piedra que suben hasta la puerta de la posada.\n");
        	AddDetail("tablero",
    	"Es un gran tablero de madera que cuelga bajo la arcada. Tiene pintado  un poney "
    	"blanco encabritado.\n");
    	AddDetail("letrero",
    	"Sobre la puerta de la posada hay un letrero con algo escrito.\n");
    	AddDetail("patio",
    	"Un largo patio se extiende hacia el este entre ambas alas de la posada.\n"
    	"A él dan numerosas ventanas de las principales dependencias del edificio.\n"
    	"Ves una gran pila de leña y algunos toneles vacíos que se amontonan contra la "
    	"pared del fondo, socavada en la falda de la colina.\n");
    	AddDetail("farol",
    	"Un gran farol de aceite, construído con un armazón de bronce  y gruesos vidrios "
    	"cuelga bajo la arcada iluminando los alrededores por la noche.\n");
    	    SetIndoors(1);
    SetIntBright(30);
        SetIntNoise(SF(f_sonidos));
        AddReadMsg("letrero",
        "|||||||||||||||||||||||||EL PONEY PISADOR|||||||||||||||||||||||||\n\n"
        "de Cebadilla Mantecona\n\n");
    SetIntSmell(SF(f_olores));
    	    AddExit("oeste", HABITACION+"bree/anteposada");
     AddExit("este", "./patio1");
     AddExit("sur", "./establo1");
     AddExit("norte", "./recibidor");
     AddDoor("norte", "la puerta de la posada",
     "Es una gran puerta de sólidos tablones perfectamente encajados entre sí y cuya "
     "superficie pulimentada no denota la indudable antigüedad de su construcción.\n"
     "Un par de aldabas de bronce reluciente situadas a la altura de un humano y un "
     "hobbit respectivamente sirven para llamar a la puerta.\n",
     ({"puerta", "n", "norte", "puerta de la posada", "puerta norte", "puerta n"}));
     AddDoor("sur", "la puerta de los establos",
     "Es una gran puerta de doble batiente que da acceso a los establos de la posada.\n"
     "Está formada por anchos tablones sin pulir, unidos en posición vertical mediante "
     "grandes travesaños de madera de roble colocados en su parte interior y sujetos "
     "con enormes clavos de hierro.\n"
     "Pesados cerrojos con una cadena de hierro permiten atrancarla desde el exterior.\n",
    ({"puerta", "s", "sur", "porton", "portón", "puerta de los establos"}));
  }
  


     public void init()
     {
        ::init();
            call_out("entrada");
	}

	public void entrada(){
		switch(d20(2)){
			case 1:
				tell_room(TO, "Un par de aldeanos salen tambaleándose de la posada y se alejan "
				"por el camino.\n");
				break;
				tell_room(TO, "Una tromba de risotadas surgen de la puerta del norte.\n");
				break;
				case 3:
					tell_room(TO, "Alguien grita desde el sur: ¡Hay que llenar esos bebederos y "
					"cambiar la paja a esos poneys!\n");
					break;
						case 4:
						tell_room(TO,"Alguien grita desde el norte: ¡Cebadilla, más cerveza por "
						"aquí! ¡y trae un poco de pan y una olla de carne asada!\n");
						break;
						case 5:
							tell_room(TO, "Los ecos de una canción coreada por el entrechocar de "
							"jarras y cubiertos sobre las mesas surge del interior de la posada.\n");
							break;
							case 6:
								tell_room(TO, "Un hobbit llega y entra en la posada.\n");
								break;
								case 7:
									tell_room(TO, "Un grupo de hombres sale de la posada, riendo y "
									"tambaleándose, y se alejan por el camino.\n");
									break;
									case 8:
										tell_room(TO, "Tres hobbits salen de la posada y se alejan charlando y riendo por "
										"el camino.\n");
										break;
										case 9:
											tell_room(TO, "Alguien grita desde la posada: ¡Poned esa olla de "
											"sopa al fuego! ¡Los forasteros de la mesa del fondo quieren "
											"entrar en calor!\n");
   break;
   case 10:
   	tell_room(TO, "Un hombre alto, envuelto en una amplia y gastada capa verde oliva y "
   	"con la capucha echada sobre la cara entra a grandes y silenciosos trancos en la posada.\n");
   	break;
   	case 11:
   		tell_room(TO, "Se escucha el ladrido de un perro en la distancia.\n");
   		break;
   		 case 12:
   			tell_room(TO, "Se escucha Un coro de alborotados cacareos procedente de algún "
   			"corral cercano.\n");
   			break;
   			case 13:
   				tell_room(TO, "Alguien grita desde la posada: ¡eh, Nob!¿dónde estás, camastrón "
   				"de pies lanudos?\n");
   				break;
   				case 14:
   					tell_room(TO, "Un viejo aldeano entra renqueando en la posada.\n");
   					break;
   					case 15:
   						tell_room(TO, "Un jinete sale de los establos y se aleja trotanto por el "
   						"camino.\n");
   						break;
   						case 16:
   							tell_room(TO, "Un mozo de la posada entra en el edificio con un enorme "
   							"cesto lleno de leña.\n");
   							break;
   							case 17:
   								tell_room(TO, "Un gato maulla melancólicamente en alguna parte de la "
   								"aldea.\n");
   								break;
   								case 18:
   									tell_room(TO, "Un soplo de viento te trae el olor del pan recién "
   									"horneado y la carne dorada al fuego.\n");
   									break;
   									case 19:
   										tell_room(TO, "Un animal resopla en los establos.\n");
   										break;
   										case 20:
   											tell_room(TO, "Un mozo entra en la posada cargando un barril de "
   											"cerveza y gruñendo por el esfuerzo.\n");
   											break;
   											case 21:
   												tell_room(TO, "Se escucha el rascado de una herramienta "
   												"metálica contra la piedra en el interior de los establos.\n");
   												break;
   												case 22:
   													tell_room(TO, "Se escucha un portazo en la distancia.\n");
   													break;


					}
					return;

				}