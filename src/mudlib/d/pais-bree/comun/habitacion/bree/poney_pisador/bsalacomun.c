/*
Fichero: bsalacomun.c
Autor: aulë
Fecha: 03/03/2014
Descripción:  base de la sala común de la posada. 
*/
#include "./path.h"
inherit "/std/pub"; 
#include <moving.h>
#include <sounds.h>

string f_sonidos(){
    switch(d20()){
        case 1:
            return "Escuchas la grave carcajada de un enano algo borracho.\n";
        case 2:
 return "Una voz se alza sobre las demás entonando una canción que pronto es coreada "
 "por más y más parroquianos.\n";
 case 3:
 	return "Oyes el entrechocar de jarras de dos hobbits que brindan.\n";
 	case 4:
 		return "Oyes el arrastrar de un banco por el suelo.\n";
 		case 5:
 			return "Escuchas las arcadas de alguien en el otro extremo de la sala a quien la "
 			"cerveza no le ha sentado bien.\n";
 			case 6:
 				return "Oyes un coro de airadas voces que discuten en el otro extremo de la sala.\n";
 				case 7:
 					return "Alguien grita pidiendo más cerveza.\n";
 					case 8:
 						return "Escuchas  como alguien pide pan y carne asada.\n";
 						case 9:
 							return "Alguien grita: Cebadilla, ¿donde están esas pintas? ¡tenemos sed!\n";
 							case 10:
 								return "Alguien subraya su discurso con una serie de vigorosos "
 								"puñetazos sobre una mesa.\n";
 								case 11:
 									return "Escuchas como alguien grita pidiendo vino.\n";
 									case 12:
 										return "Escuchas el ruidoso arrastrar de una mesa por el suelo.\n";
 										case 13:
 											return "Alguien grita: Cebadilla, ¡trae una bandeja de carne asada y seis pintas más... y otra hogaza de pan!\n";
 											case 14:
 												return "Alguien grita: ¡Sí, trae un poco más de pan!\n";
 												case 15:
 													return "Alguien grita: ¿dónde está esa condenada cerveza?\n";
 													case 16:
 														return "Escuchas un coro de risotadas.\n";
 														    }
    return "";
}

string f_olores(){
    switch(d4()){
        case 1:
return "En la enrrarecida atmósfera se unen el olor a tabaco, comida, cerveza y leña.\n";
case 2:
	return "Aspiras el olor de carne recién asada procedente de la bandeja que acaban de "
	"servir en una mesa cercana.\n";
	case 3:
		return "Huele intensamente a cerveza derramada.\n";
		case 4:
			return "Huele a sopa recién hecha y pan recién horneado.\n";
			    }
    return "";
}
create()
{
    ::create();
    	    AddDetail("ventanas",
    	    "Las ventanas de la sala miran al oeste y a través de ellas puedes ver la "
    	    "falda de la colina ocupada por las casas de piedra de la aldea y que "
    	    "desciende hasta la difusa línea de la empalizada y el foso.\n");
    	    AddDetail("cortinas",
    	    "Espesas cortinas algo oscurecidas por el humo cuelgan frente a las ventanas.\n");
    	    AddDetail("bancos",
    	    "Bancos consistentes en un simple tablón apoyado sobre otras dos secciones "
    	    "cuadradas de madera. Hay multitud de ellos alrededor de las mesas y su "
    	    "altura permite que tanto hombres como hobbits puedan sentarse cómodos.\n");
    	    AddDetail("mesas",
    	    "Las hay pequeñas, para dos o cuatro personas pero también largas, para "
    	    "acomodar grupos más grandes. Están hechas de gruesos tablones sobre macizas "
    	    "patas sin tallar y multitud de marcas, cortes y rasguños las cubren,  "
    	    "denunciando su larga vida.\n");
    	    AddDetail(({"paredes", "muros", "muro", "pared"}),
    	    "Los muros de la sala común son de maciza piedra más o menos alisada. El humo ennegrece su superficie.\n");
    	    AddDetail("chimenea",
    	    "Una gran chimenea se alza en el lado sur de la sala.\n"
    	    "Está hecha de piedra y se apoya sobre dos pilastras  con el resto de lados "
    	    "abiertos. El fuste ligeramente ennegrecido desaparece entre las vigas del "
    	    "techo y de él cuelga un tablero.\n"
    	    "En su interior arde a todas horas un llameante fuego.\n");
    	    AddDetail("fuego",
    	    "Un llameante fuego de gruesos troncos arde en la chimenea de la sala.\n");
    	    AddDetail(({"vigas", "techo"}),
    	    "El techo de madera está soportado por grandes vigas de roble de las que "
    	    "cuelgan tres faroles. El humo ennegrece su superficie.\n");
    	    AddDetail("suelo",
    	    "El suelo de piedra está cubierto de serrín y pese a estar limpio no pueden "
    	    "dejar de notarse huellas de botas sucias y alguna mancha de cerveza o comida.\n");
    	    AddDetail("humo",
    	    "El humo se arremolina en el techo entre ls vigas y se adhiere a muros y "
    	    "cortinajes.\n");
    	  AddDetail(({"concurrencia", "clientela", "clientes", "parroquianos"}),
    	  "Aldeanos de todas las edades, hobbits y hombres, toscos pero alegres y "
    	  "hospitalarios, venidos de las cuatro aldeas del País de Bree, algunos "
    	  "forasteros de piel cetrina que parecen ser dunlendinos, varios grupos de enanos "
    	  "que están de paso hacia el este o el oeste, además de una variopinta serie de "
    	  "figuras vagas que el humo y la penumbra no permiten observar con mayor detalle.\n");
    	  AddDetail("faroles",
    	  "Tres faroles colocados de forma equidistante cuelgan de las oscuras vigas del "
    	  "techo. Sus gruesos vidrios están velados por el humo por lo que solo producen "
    	  "un débil resplandor.\n");
    	  AddDetail("tablero",
    	  "Un tablero de madera cuelga del fuste de la chimenea y en él se puede ver "
    	  "escrito con grandes letras una lista de bebidas y comidas que conforma el "
    	  "menú del Poney Pisador.\n");
    	  AddDetail("cartel",
    	  "Un Cartel cuelga junto a la puerta de la sala común.\n");
    	  
    	    
    	    SetIndoors(1);
    SetIntBright(25);
    SetIntNoise(SF(f_sonidos));
    SetIntSmell(SF(f_olores));
             SetSoundEnvironment(SOUND_AMBIENTES("taberna"), 40);
             AddDrink("agua", "una pequeña jarra de", 2, 0, 7, 0, "Calmas tu sed con una jarra de agua fría recién sacada del manantial de la posada.\n");
             AddDrink("vino tinto", "un vaso", 4, 6, 2, 0, "Bebes con deleite un vaso de vino tinto de exquisito aroma y hermoso color.\n");
             AddFood("queso curado", "una porción", 7, 7, 0, "Saboreas una porción de "
             "queso de cabra, bien estacionado y de fuerte sabor y aroma, acompañado "
             "por una rebanada de pan de hogaza de corteza crujiente y miga compacta.\n");
             AddFood("carne guisada", "un plato de", 8, 8, 0, "Te sirven un humeante "
             "plato de carne guisada acompañada de patatas asadas y guisantes.\n"
             "Está ligeramente tostada por fuera y tiene una sabrosa salsa.\n");

}


    
     


     public void init()
     {        ::init();
            call_out("entrada");
	}

	public void entrada(){
		switch(d20(2)){
			case 1:
				tell_room(TO, "Un aldeano medio borracho grita pidiendo más cerveza.\n");
				break;
				tell_room(TO, "Un grupo de forasteros discuten en una mesa cercana.\n");
				break;
				case 3:
					tell_room(TO, "Alguien grita: Sí, ¡trae un poco más de pan!\n");
					break;
						case 4:
						tell_room(TO, "Alguien grita: ¡Una canción, queremos una canción!\n");
						break;
						case 5:
							tell_room(TO, "Un hobbit salta sobre una mesa y comienza a cantar una "
							"antigua canción de taberna que pronto es coreada por el resto de la concurrencia entre risas y entrechocar de jarras.\n");
							break;
							case 6:
								tell_room(TO, "Un tropel de enanos entra en la sala y se acomoda "
								"alrededor de una larga mesa pidiendo cerveza y comida a voces.\n");
								break;
								case 7:
									tell_room(TO, "Unos hobbits intercambian rumores con dos aldeanos sentados en la mesa de enfrente.\n");
									break;
									case 8:
										tell_room(TO, "Unos troncos restallan y chasquean al arder en la gran chimenea.\n");
										break;
										case 9:
											tell_room(TO, "Un aldeano grita: Cebadilla, ¡trae otra ronda de cerveza negra!\n");
   break;
   case 10:
   	tell_room(TO, "Cebadilla pasa cerca a la carrera cargando una bandeja colmada de jarras llenas hasta el borde.\n");
   	break;
   	case 11:
   		tell_room(TO, "Un forastero le grita entre risas a un compañero que se tambalea en su silla: ¡no sabes beber!\n");
   		break;
   		 case 12:
   			tell_room(TO, "Un hombre vvestido con raídas ropas pardas entra sigilosamente en la sala común y se acomoda en un rincón.\n");
   			break;
   			case 13:
   				tell_room(TO, "Cebadilla pasa al trote cargando una olla de sopa mientras grita: "
   					"¡eh, Nob!¿dónde estás, camastrón "
   				"de pies lanudos?\n");
   				break;
   				case 14:
   					tell_room(TO, "Un grupo de forasteros de piel cetrina se levantan y salen de la sala común preguntando por sus habitaciones.\n");
   					break;
   					case 15:
   						tell_room(TO, "Cebadilla charla con una pareja de enanos junto a la chimenea.\n");
   						break;
   						case 16:
   							tell_room(TO, "Una mesa a la que se sientan numerosos lugareños "
   							"hobbits y humanos estalla en atronadoras carcajadas cuando un hobbit termina de contar una anécdota local.\n");
   							break;
   							case 17:
   								tell_room(TO, "Cebadilla abandona la sala común a la carrera gritando: ¡Medio minuto, enseguida lo traigo todo! ¡No tengo seis manos ni seis piernas!\n");
   								break;
   								case 18:
   									tell_room(TO, "La boca se te hace agua cuando percibes el olor de la "
   									"carne asada y el pan recién tostado de la bandeja con la que Cebadilla pasa cerca en dirección a una de las mesas.\n");
   									break;
   									case 19:
   										tell_room(TO, "Un parroquiano arrastra su silla y sale de la sala comúna toda prisa dando traspiés. Parece que la cerveza no le ha sentado demasiado bien.\n");
   										break;
   										case 20:
   											tell_room(TO, "El espeso humo se arremolina alrrededor de las vigas del techo.\n");
   											break;
   											case 21:
   												tell_room(TO, "Un par de hombres encapuchados y vestidos con "
   												"ropas de tonos pardos charlan en voz baja en un rincón mientras beben sendas jarras de cerveza.\n");
   												break;
   												case 22:
   													tell_room(TO, "Un grupo de aldeanos entra en la sala común y la corriente de aire que produce la puerta abierta hace tremolear las llamas de la chimenea.\n");
   													break;
   													case 23:
   tell_room(TO, "Un viejo aldeano entra renqueando en la sala común y se deja caer pesadamente en un banco.\n");
      													break;
   													case 24:
   tell_room(TO, "Un hobbit discute con un hombre de Bree sobre la próxima cosecha del trigo.\n");
      													break;
   													case 25:
   tell_room(TO, "Algunos aldeanos, hobbits y humanos charlan sobre la crianza de  ovejas.\n");
      													break;
   													case 26:
   tell_room(TO, "Un hombre y un hobbit cierran la venta de un poney de tiro con un apretón de manos y entrechocando sus jarras.\n");
      													break;
   													case 27:
   tell_room(TO, "Dos rudos aldeanos charlan sobre vacas lecheras, cosechas de heno y crianza de terneros.\n");
      													break;
   													case 28:
   tell_room(TO, "Un anciano encorvado, de larga barba gris, sombrero picudo y "
   "apoyándose en un bastón entra en la sala común y charla durante unos momentos con Cebadilla.\n");
      													break;
   													case 29:
   tell_room(TO, "Un hombre encapuchado  y ataviado con gastadas ropas clava sus brillantes ojos en ti, sentado en un oscuro rincón.\n");
      													break;
   													case 30:
   tell_room(TO, "Unos enanos charlan sobre minas y comercio de metales.\n");
      													break;
   													case 31:
   tell_room(TO, "Un aldeano ebrio sale de la sala común riendo y dando traspiés.\n");
      													break;
   													case 32:
   tell_room(TO, "Unos dunlendinos discuten agriamente entre sí dando puñetazos sobre la mesa.\n");
         													break;
   													case 33:
   tell_room(TO, "Un mozo de la posada alimenta la chimenea con unos troncos.\n");
         													break;
   													case 34:
   tell_room(TO, "Uno de los parroquianos atisba hacia el exterior entre las cortinas.\n");
         													break;
   													case 35:
   tell_room(TO, "Un joven aldeano sale de la posada charlando con un hobbit.\n");
      													break;
   													case 36:
   tell_room(TO, "Cebadilla llega corriendo y sirve una pinta de cerveza a un viejo hobbit.\n");
   












					}
					return;

				}