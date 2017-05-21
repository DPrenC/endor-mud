/*
Fichero: patio2.c
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
     SetIntLong("Esta parte del patio se encuentra ocupada en parte por algunos toneles "
     "y tinajas vacías aunque la mayoría del espacio  lo ocupa un enorme montón de leña "
     "partida para el fuego y una pila de troncos y ramas, aún sin cortar.\n"
     "Un alto muro de piedra cierra el extremo este del recinto y por encima se alza la "
     "ladera de la colina. Al sur hay una gruesa puerta y junto a la leña hay un"
     " gran tocón rodeado de astillas y serrín. Al norte ves las ventanas iluminadas de "
     "la cocina y al oeste el patio se extiende hasta la entrada de la posada.\n");
         SetIntSmell(SF(f_olores));
            SetIntNoise(SF(f_sonidos));
        AddDetail("suelo",
    "El suelo está cubierto de gravilla mezclada con tierra batida, serrín y birutas "
    "que forman un duro conglomerado ligeramente irregular.\n");
    AddDetail(({"tocon", "tocón"}),
    "Un gran tocón añoso con multitud de tajos de hacha en su rugosa superficie que se "
    "utiliza para partir leña.\n");
    AddDetail(({"toneles", "tinajas"}),
    "Algunos toneles y tinajas vacíos se amontonan junto al muro este, llegando hasta "
    "la mitad de la altura del mismo.\n");
    AddDetail("muro",
    "Un grueso muro de piedras irregulares que contiene y sostiene la tierra de la "
    "falda de la colina, evitando que esta se desmorone con las lluvias invadiendo el patio.\n"
    "Tendrá unos tres metros de altura y en algunos puntos un suave musgo crece en los "
    "intersticios de las piedras.\n");
    AddDetail(({"leña", "monton", "montón", "montón de leña", "monton de leña"}),
    "Un enorme montón de astillas cortadas para el fuego de unos dos metros de altura se "
    "sitúa junto a un tocón.\n");
    AddDetail(({"ventana", "ventanas"}),
    "Al patio dan tanto las ventanas de la cocina como las de los pisos superiores.\n");
    AddDetail("ventanas de la cocina",
    "Observas a través de la ventana de la cocina el ir y venir del personal de la "
    "posada llevando y trayendo bandejas, jarras y recipientes de todo tipo mientras "
    "otros dan vueltas a asadores y grandes cazuelas.\n"
    "De vez en cuanto alguien entra y sale de una pequeña puerta llevando provisiones, botellas o algún pequeño barril.\n"
    "El fulgor de los fogones ilumina todo el trajín.\n");
    AddDetail("ventanas de los pisos superiores",
    "Alzas la mirada y observas las ventanas de las plantas superiores que rodean el "
    "patio. Algunas están iluminadas y la luz se filtra através de los pesados "
    "cortinajes mientras que otras permanecen a oscuras.\n");
    AddDetail(({"colina", "falda"}),
    "Apenas alcanzas a distinguir algo de la empinada ladera que se alza sobre el muro.\n");
    AddDetail("astillas",
    "Restos de madera que se amontonan junto al tocón.\n");
    AddDetail("serrín",
    "Un montón de serrín cubre la parte baja del tocón en el que se parte la leña.\n");
    AddDetail(({"ramas", "troncos", "pila"}),
    	"Gran cantidad de gruesos troncos y ramas irregulares se amontonan esperando ser "
    	"cortadas para el fuego.\n");
      
    AddExit("oeste", "./patio1");
         AddExit("sur", "./destileria");
              AddDoor("sur", "un ancho portón",
     "Es un ancho portón de tablones de doble batiente. Ambos batientes disponen de "
     "sendas anillas de hierro que se cierran con una cadena con candado.\n",
     ({"porton", "portón", "sur", "s", "puerta sur", "puerta s"})); 


    }
    
     


     public void init()
     {
        ::init();
            call_out("entrada");
	}

	public void entrada(){
		switch(d20(2)){
			case 1:
				tell_room(TO, "Un hombre borracho llega apresuradamente y vomita junto al "
				"muro sacudido por las arcadas. Luego se limpia la boca con el dorso de la "
				"mano y se va.\n");
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
								tell_room(TO, "Un hobbit llega y deja un barril vacío junto al muro, alejándose luego al trote.\n");
								break;
								case 7:
									tell_room(TO, "Alguien silba una canción en la cocina mientras los golpes de un machete partiendo una pieza de carne resuenan metódicamente.\n");
									break;
									case 8:
										tell_room(TO, "Unos gorriones chacharean posados sobre el muro.\n");
										break;
										case 9:
											tell_room(TO, "Alguien grita desde la cocina: ¡Poned esa olla de "
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
   			"gallinero cercano.\n");
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
   							tell_room(TO, "Un mozo de la posada llega con un enorme cesto que llena de leña, alejándose luego gruñendo por el esfuerzo.\n");
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
   										tell_room(TO, "Un ganso grazna cerca.\n");
   										break;
   										case 20:
   											tell_room(TO, "Se escuchan rebuznos procedentes de los establos.\n");
   											break;
   											case 21:
   												tell_room(TO, "Se escucha el crujido de un postigo que se cierra en los pisos superiores de la posada.\n");
   												break;
   												case 22:
   													tell_room(TO, "Se escucha un portazo en la distancia.\n");
   													break;


					}
					return;

				}