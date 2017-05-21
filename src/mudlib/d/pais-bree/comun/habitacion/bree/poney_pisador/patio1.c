/*
Fichero: patio1.c
Autor: aulë
Fecha: 12/03/2013
Descripción: patio entre ambas alas de la posada del Poney Pisador. 
*/
#include "./path.h"
inherit BREE_ROOM;

#include <moving.h>


string f_sonidos(){
    switch(d20(2)){
        case 1:        	return "Oyes un relincho procedente de los establos.\n";
        	case 2:
        		return "Resuena El estruendo de una montaña de cacharros que se derrumba acompañado una retahíla  de blasfemias.\n";
        		case 3:
        			return "Oyes como alguien grita pidiendo cerveza dentro de la posada.\n";
        			case 4:
        				return "Escuchas el lejano canto de un gallo.\n";
        				        				case 5:
        					return "Oyes que alguien grita en la cocina. ¡Eh, tú, pela algunas patatas más";
        					case 6:
        						return "Escuchas los postigos de una ventana que se cierran.\n";
        						case 7:
        							return "Oyes el sonido decacerolas que entrechocan entre sí.\n";
        							case 8:
        								return "Alguien grita desde lejos: ¡Sí, trae un poco más de pan!\n";
        								case 9:
        									return "Escuchas un coro de risotadas procedente del interior "
        									"de la posada.\n";
        									case 10:
        										return "Oyes los golpes de un machete de cocina cortando carne.\n";
        										case 11:
        											return "Alguien grita en la cocina: ¡Llevad otra hogaza y un cuenco de sopa a la mesa de la esquina!\n";
        											case 13:
        												return "Alguien grita desde los establos: ¡maldito asno, me ha mordido!.\n";
        												case 14:
        													return "Alguien grita desde la cocina: ¡Llevadle al montaraz del rincón una pinta y una tajada de carne asada!\n";
        													case 15:
        														return "Un coro de voces se alza entonando una alegre canción de taberna.\n";
        														case 16:
        															return "Oyes que alguien llama a lo lejos.\n";
        															case 17:
        																return "Alguien grita: ¡id abriendo otro barril de cerveza, este se está acabando! ¡Por el amor del cielo, no puedo estar a todo a la vez!\n";
        																case 18:
        																return "Escuchas los golpes de un hacha cortando leña en el este del patio.\n";
        																case 19:
        																return "Alguien grita en la cocina: ¡Llevad dos bandejas de carne, un queso de oveja y cinco jarras grandes de cerveza a los enanos de la mesa junto a la chimenea!\n";
        																	case 20:
        																		return "Alguien silba alegremente en la cocina.\n";
        																		case 21:
        																			return "Alguien grita desde la posada: ¡Abrid otro par de barriles y sacad una olla de carne asada... y el queso de oveja grande! Ah... y el jamón de la esquina! Tengo una maldita tropa de enanos hambrientos e impacientes esperando!\n";
        																			case 22:
        																				return "Alguien grita desde lejos: ¡Cebadilla, ¿dónde está esa cerveza? ¡tenemos sed!\n";
        																				
 }
    return "";
}

string f_olores(){
    switch(d6()){
        case 1:
return "Huele a patatas asadas.\n";
case 2:
	return "Te llega una vaharada a pan recién horneado.\n";
	case 3:
		return "El olor a carne asada invade tus fosas nasales.\n";
		case 4:
			return "Hueles a sopa recién hecha.\n";
			case 5:
				return "Te llega olor a humo de leña.\n";
			    }
    return "";
}



create()
{
    ::create();
     SetIntShort("patio de la posada");
    SetIntLong("Este es el patio de la posada, un espacio rectangular albergado entre "
    "las dos alas del edificio.\n"
    "Al igual que la posada, el patio se haya socavado en la falda de la colina y se ve "
    "limitado en su parte este por un alto muro constituido por el propio monte.\n"
    "Por lo que se puede ver, el lugar se suele utilizar para depositar toneles y "
    "tinajas vacías, guardar algún carro que no entre en el establo cuando este está "
    "repleto y almacenar la gran cantidad de leña que se quema en las chimeneas y "
    "fogones del establecimiento de los Mantecona.\n"
    "Se puede observar que las ventanas de la cocina dan al patio desde el norte y "
    "mirando hacia arriba se pueden ver las ventanas de los pisos superiores.\n");
    SetIntSmell(SF(f_olores));
            SetIntNoise(SF(f_sonidos));
        AddDetail("suelo",
    "El suelo está cubierto de gravilla mezclada con tierra batida y serrín que forman "
    "un duro conglomerado ligeramente irregular.\n");
    AddDetail("carro",
    "Ahora mismo no ves ninguno por aquí.\n");
    AddDetail(({"toneles", "tinajas"}),
    "Algunos toneles y tinajas vacíos se amontonan junto al muro este.\n");
    AddDetail("muro",
    "Un grueso muro de piedras irregulares que contiene y sostiene la tierra de la "
    "falda de la colina, evitando que esta se desmorone con las lluvias invadiendo el patio.\n");
    AddDetail("leña",
    "Un enorme montón de leña se levanta en el este del patio.\n");
    AddDetail(({"ventana", "ventanas"}),
    "Al patio dan tanto las ventanas de la cocina como las de los pisos superiores.\n");
    AddDetail("ventanas de la cocina",
    "Observas a través de la ventana de la cocina el ir y venir del personal de la "
    "posada llevando y trayendo bandejas, jarras y recipientes de todo tipo mientras "
    "otros dan vueltas a asadores y grandes cazuelas.\n"
    "El fulgor de los fogones ilumina todo el trajín.\n");
    AddDetail("ventanas de los pisos superiores",
    "Alzas la mirada y observas las ventanas de las plantas superiores que rodean el "
    "patio. Algunas están iluminadas y la luz se filtra através de los pesados "
    "cortinajes mientras que otras permanecen a oscuras.\n"
    "Una de ellas es algo más grande que el resto.\n");
    AddDetail("ventana grande",
    "Es una ventana con dos hojas y grandes postigos de madera.\n"
    "Está situada en el primer piso, sobre la cocina.\n");
    AddDetail(({"colina", "falda"}),
    "La colina de Bree sealza más allá del patio ascendiendo en forma cada vez más "
    "abrupta. Vislumbras algunas entradas de agujeros hobbits a lo largo de la ladera.\n");
  AddDetail(({"entradas", "agujeros hobbits", "agujeros"}),
  "Distingues apenas los perfiles redondos de las entradas a los agujeros hobbits de la "
  "aldea, situados en la parte alta de la ladera de la colina.\n");
  
        AddExit("oeste", "./arcada");
     AddExit("este", "./patio2"); 
   }
     


     public void init()
     {
        ::init();
            call_out("entrada");
	}

	public void entrada(){
		switch(d20(2)){
			case 1:
				tell_room(TO, "Un hombre borracho llega apresuradamente y vomita sacudido por "
				"las arcadas. Luego se limpia la boca con el dorso de la mano y se va.\n");
				break;
				tell_room(TO, "Estalla una agria discusión en la cocina.\n");
				break;
				case 3:
					tell_room(TO, "Alguien grita: ¡aparta hombre! ¿no ves que no puedo cargar con "
					"más jarras?\n");
					break;
						case 4:
						tell_room(TO, "Alguien grita en la cocina: ¡Sacad otro barril de la bodega!\n");
						break;
						case 5:
							tell_room(TO, "Los ecos de una canción coreada por el entrechocar de "
							"jarras y cubiertos sobre las mesas surge del interior de la posada.\n");
							break;
							case 6:
								tell_room(TO, "Un hobbit pasa trotando cargado con un barril vacío.\n");
								break;
								case 7:
									tell_room(TO, "Alguien silba una canción en la cocina mientras los golpes de un machete partiendo una pieza de carne resuenan metódicamente.\n");
									break;
									case 8:
										tell_room(TO, "Un gorrión chacharea posado sobre el muro del fondo del patio.\n");
										break;
										case 9:
											tell_room(TO, "Alguien grita desde la posada: ¡Poned esa olla de "
											"sopa al fuego! ¡Los forasteros de la mesa del fondo quieren "
											"entrar en calor!\n");
   break;
   case 10:
   	tell_room(TO, "Las palomas arrullan suavemente desde los aleros del tejado.\n");
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
   					tell_room(TO, "Se escuchan toses y carraspeos convulsivos que surgen de una de las ventanas de los pisos superiores.\n");
   					break;
   					case 15:
   						tell_room(TO, "Un mozo de la posada pasa cerca con un enorme cesto repleto de leña.\n");
   						break;
   						case 16:
   							tell_room(TO, "Un mozo de la posada se dirige al este del patio con un enorme cesto vacío.\n");
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
   											tell_room(TO, "Un caballo relincha largamente cerca.\n");
   											break;
   											case 21:
   												tell_room(TO, "Se escucha el crujido de unos postigos que se abren en los pisos superiores de la posada.\n");
   												break;
   												case 22:
   													tell_room(TO, "Se escucha un portazo en la distancia.\n");
   													break;


					}
					return;

				}