/*
Fichero: bsalacomun.c
Autor: aul�
Fecha: 03/03/2014
Descripci�n:  base de la sala com�n de la posada. 
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
 return "Una voz se alza sobre las dem�s entonando una canci�n que pronto es coreada "
 "por m�s y m�s parroquianos.\n";
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
 					return "Alguien grita pidiendo m�s cerveza.\n";
 					case 8:
 						return "Escuchas  como alguien pide pan y carne asada.\n";
 						case 9:
 							return "Alguien grita: Cebadilla, �donde est�n esas pintas? �tenemos sed!\n";
 							case 10:
 								return "Alguien subraya su discurso con una serie de vigorosos "
 								"pu�etazos sobre una mesa.\n";
 								case 11:
 									return "Escuchas como alguien grita pidiendo vino.\n";
 									case 12:
 										return "Escuchas el ruidoso arrastrar de una mesa por el suelo.\n";
 										case 13:
 											return "Alguien grita: Cebadilla, �trae una bandeja de carne asada y seis pintas m�s... y otra hogaza de pan!\n";
 											case 14:
 												return "Alguien grita: �S�, trae un poco m�s de pan!\n";
 												case 15:
 													return "Alguien grita: �d�nde est� esa condenada cerveza?\n";
 													case 16:
 														return "Escuchas un coro de risotadas.\n";
 														    }
    return "";
}

string f_olores(){
    switch(d4()){
        case 1:
return "En la enrrarecida atm�sfera se unen el olor a tabaco, comida, cerveza y le�a.\n";
case 2:
	return "Aspiras el olor de carne reci�n asada procedente de la bandeja que acaban de "
	"servir en una mesa cercana.\n";
	case 3:
		return "Huele intensamente a cerveza derramada.\n";
		case 4:
			return "Huele a sopa reci�n hecha y pan reci�n horneado.\n";
			    }
    return "";
}
create()
{
    ::create();
    	    AddDetail("ventanas",
    	    "Las ventanas de la sala miran al oeste y a trav�s de ellas puedes ver la "
    	    "falda de la colina ocupada por las casas de piedra de la aldea y que "
    	    "desciende hasta la difusa l�nea de la empalizada y el foso.\n");
    	    AddDetail("cortinas",
    	    "Espesas cortinas algo oscurecidas por el humo cuelgan frente a las ventanas.\n");
    	    AddDetail("bancos",
    	    "Bancos consistentes en un simple tabl�n apoyado sobre otras dos secciones "
    	    "cuadradas de madera. Hay multitud de ellos alrededor de las mesas y su "
    	    "altura permite que tanto hombres como hobbits puedan sentarse c�modos.\n");
    	    AddDetail("mesas",
    	    "Las hay peque�as, para dos o cuatro personas pero tambi�n largas, para "
    	    "acomodar grupos m�s grandes. Est�n hechas de gruesos tablones sobre macizas "
    	    "patas sin tallar y multitud de marcas, cortes y rasgu�os las cubren,  "
    	    "denunciando su larga vida.\n");
    	    AddDetail(({"paredes", "muros", "muro", "pared"}),
    	    "Los muros de la sala com�n son de maciza piedra m�s o menos alisada. El humo ennegrece su superficie.\n");
    	    AddDetail("chimenea",
    	    "Una gran chimenea se alza en el lado sur de la sala.\n"
    	    "Est� hecha de piedra y se apoya sobre dos pilastras  con el resto de lados "
    	    "abiertos. El fuste ligeramente ennegrecido desaparece entre las vigas del "
    	    "techo y de �l cuelga un tablero.\n"
    	    "En su interior arde a todas horas un llameante fuego.\n");
    	    AddDetail("fuego",
    	    "Un llameante fuego de gruesos troncos arde en la chimenea de la sala.\n");
    	    AddDetail(({"vigas", "techo"}),
    	    "El techo de madera est� soportado por grandes vigas de roble de las que "
    	    "cuelgan tres faroles. El humo ennegrece su superficie.\n");
    	    AddDetail("suelo",
    	    "El suelo de piedra est� cubierto de serr�n y pese a estar limpio no pueden "
    	    "dejar de notarse huellas de botas sucias y alguna mancha de cerveza o comida.\n");
    	    AddDetail("humo",
    	    "El humo se arremolina en el techo entre ls vigas y se adhiere a muros y "
    	    "cortinajes.\n");
    	  AddDetail(({"concurrencia", "clientela", "clientes", "parroquianos"}),
    	  "Aldeanos de todas las edades, hobbits y hombres, toscos pero alegres y "
    	  "hospitalarios, venidos de las cuatro aldeas del Pa�s de Bree, algunos "
    	  "forasteros de piel cetrina que parecen ser dunlendinos, varios grupos de enanos "
    	  "que est�n de paso hacia el este o el oeste, adem�s de una variopinta serie de "
    	  "figuras vagas que el humo y la penumbra no permiten observar con mayor detalle.\n");
    	  AddDetail("faroles",
    	  "Tres faroles colocados de forma equidistante cuelgan de las oscuras vigas del "
    	  "techo. Sus gruesos vidrios est�n velados por el humo por lo que solo producen "
    	  "un d�bil resplandor.\n");
    	  AddDetail("tablero",
    	  "Un tablero de madera cuelga del fuste de la chimenea y en �l se puede ver "
    	  "escrito con grandes letras una lista de bebidas y comidas que conforma el "
    	  "men� del Poney Pisador.\n");
    	  AddDetail("cartel",
    	  "Un Cartel cuelga junto a la puerta de la sala com�n.\n");
    	  
    	    
    	    SetIndoors(1);
    SetIntBright(25);
    SetIntNoise(SF(f_sonidos));
    SetIntSmell(SF(f_olores));
             SetSoundEnvironment(SOUND_AMBIENTES("taberna"), 40);
             AddDrink("agua", "una peque�a jarra de", 2, 0, 7, 0, "Calmas tu sed con una jarra de agua fr�a reci�n sacada del manantial de la posada.\n");
             AddDrink("vino tinto", "un vaso", 4, 6, 2, 0, "Bebes con deleite un vaso de vino tinto de exquisito aroma y hermoso color.\n");
             AddFood("queso curado", "una porci�n", 7, 7, 0, "Saboreas una porci�n de "
             "queso de cabra, bien estacionado y de fuerte sabor y aroma, acompa�ado "
             "por una rebanada de pan de hogaza de corteza crujiente y miga compacta.\n");
             AddFood("carne guisada", "un plato de", 8, 8, 0, "Te sirven un humeante "
             "plato de carne guisada acompa�ada de patatas asadas y guisantes.\n"
             "Est� ligeramente tostada por fuera y tiene una sabrosa salsa.\n");

}


    
     


     public void init()
     {        ::init();
            call_out("entrada");
	}

	public void entrada(){
		switch(d20(2)){
			case 1:
				tell_room(TO, "Un aldeano medio borracho grita pidiendo m�s cerveza.\n");
				break;
				tell_room(TO, "Un grupo de forasteros discuten en una mesa cercana.\n");
				break;
				case 3:
					tell_room(TO, "Alguien grita: S�, �trae un poco m�s de pan!\n");
					break;
						case 4:
						tell_room(TO, "Alguien grita: �Una canci�n, queremos una canci�n!\n");
						break;
						case 5:
							tell_room(TO, "Un hobbit salta sobre una mesa y comienza a cantar una "
							"antigua canci�n de taberna que pronto es coreada por el resto de la concurrencia entre risas y entrechocar de jarras.\n");
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
											tell_room(TO, "Un aldeano grita: Cebadilla, �trae otra ronda de cerveza negra!\n");
   break;
   case 10:
   	tell_room(TO, "Cebadilla pasa cerca a la carrera cargando una bandeja colmada de jarras llenas hasta el borde.\n");
   	break;
   	case 11:
   		tell_room(TO, "Un forastero le grita entre risas a un compa�ero que se tambalea en su silla: �no sabes beber!\n");
   		break;
   		 case 12:
   			tell_room(TO, "Un hombre vvestido con ra�das ropas pardas entra sigilosamente en la sala com�n y se acomoda en un rinc�n.\n");
   			break;
   			case 13:
   				tell_room(TO, "Cebadilla pasa al trote cargando una olla de sopa mientras grita: "
   					"�eh, Nob!�d�nde est�s, camastr�n "
   				"de pies lanudos?\n");
   				break;
   				case 14:
   					tell_room(TO, "Un grupo de forasteros de piel cetrina se levantan y salen de la sala com�n preguntando por sus habitaciones.\n");
   					break;
   					case 15:
   						tell_room(TO, "Cebadilla charla con una pareja de enanos junto a la chimenea.\n");
   						break;
   						case 16:
   							tell_room(TO, "Una mesa a la que se sientan numerosos lugare�os "
   							"hobbits y humanos estalla en atronadoras carcajadas cuando un hobbit termina de contar una an�cdota local.\n");
   							break;
   							case 17:
   								tell_room(TO, "Cebadilla abandona la sala com�n a la carrera gritando: �Medio minuto, enseguida lo traigo todo! �No tengo seis manos ni seis piernas!\n");
   								break;
   								case 18:
   									tell_room(TO, "La boca se te hace agua cuando percibes el olor de la "
   									"carne asada y el pan reci�n tostado de la bandeja con la que Cebadilla pasa cerca en direcci�n a una de las mesas.\n");
   									break;
   									case 19:
   										tell_room(TO, "Un parroquiano arrastra su silla y sale de la sala com�na toda prisa dando traspi�s. Parece que la cerveza no le ha sentado demasiado bien.\n");
   										break;
   										case 20:
   											tell_room(TO, "El espeso humo se arremolina alrrededor de las vigas del techo.\n");
   											break;
   											case 21:
   												tell_room(TO, "Un par de hombres encapuchados y vestidos con "
   												"ropas de tonos pardos charlan en voz baja en un rinc�n mientras beben sendas jarras de cerveza.\n");
   												break;
   												case 22:
   													tell_room(TO, "Un grupo de aldeanos entra en la sala com�n y la corriente de aire que produce la puerta abierta hace tremolear las llamas de la chimenea.\n");
   													break;
   													case 23:
   tell_room(TO, "Un viejo aldeano entra renqueando en la sala com�n y se deja caer pesadamente en un banco.\n");
      													break;
   													case 24:
   tell_room(TO, "Un hobbit discute con un hombre de Bree sobre la pr�xima cosecha del trigo.\n");
      													break;
   													case 25:
   tell_room(TO, "Algunos aldeanos, hobbits y humanos charlan sobre la crianza de  ovejas.\n");
      													break;
   													case 26:
   tell_room(TO, "Un hombre y un hobbit cierran la venta de un poney de tiro con un apret�n de manos y entrechocando sus jarras.\n");
      													break;
   													case 27:
   tell_room(TO, "Dos rudos aldeanos charlan sobre vacas lecheras, cosechas de heno y crianza de terneros.\n");
      													break;
   													case 28:
   tell_room(TO, "Un anciano encorvado, de larga barba gris, sombrero picudo y "
   "apoy�ndose en un bast�n entra en la sala com�n y charla durante unos momentos con Cebadilla.\n");
      													break;
   													case 29:
   tell_room(TO, "Un hombre encapuchado  y ataviado con gastadas ropas clava sus brillantes ojos en ti, sentado en un oscuro rinc�n.\n");
      													break;
   													case 30:
   tell_room(TO, "Unos enanos charlan sobre minas y comercio de metales.\n");
      													break;
   													case 31:
   tell_room(TO, "Un aldeano ebrio sale de la sala com�n riendo y dando traspi�s.\n");
      													break;
   													case 32:
   tell_room(TO, "Unos dunlendinos discuten agriamente entre s� dando pu�etazos sobre la mesa.\n");
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