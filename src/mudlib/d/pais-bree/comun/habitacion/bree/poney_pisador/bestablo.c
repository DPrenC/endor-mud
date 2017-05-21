/*
Fichero: bestablo.c
Autor: aulë
Fecha: 29/01/2014
Descripción:  base del establo de la posada.
*/
#include "./path.h"
inherit BREE_ROOM;

string f_sonidos(){
    switch(d20()){
        case 1:
            return "Oyes el piafar de un caballo.\n";
        case 2:
 return "Escuchas el suave relincho de un caballo.\n";
 case 3:
 	return "Oyes el hueco  golpeteo de cascos  contra un pesebre.\n";
 	case 4:
 		return "Oyes el vigoroso resoplido de un caballo.\n";
 		case 5:
 			return "Escuchas el estruendoso relincho de un caballo.\n";
 			case 6:
 				return "Oyes un lejano coro de risas procedente de la posada.\n";
 				case 7:
 					return "Oyes los apresurados pasos de alguien que pasa corriendo en el "
 					"exterior de los establos.\n";
 					case 8:
 						return "Escuchas la lejana voz de alguien que grita pidiendo más cerveza.\n";
 						case 9:
 							return "Alguien grita: eh, Bob! ¡Búscales sitio a estos tres poneys!\n";
 							case 10:
 								return "Escuchas el rastrillar de una herramienta contra el piso de "
 								"piedra.\n";
 								case 11:
 									return "Escuchas el golpeteo de cascos de un caballo encabritado "
 									"mientras alguien blasfema con ardor.\n";
 									case 12:
 										return "Escuchas como la grava cruje bajo los rápidos pasos de "
 										"alguien que llega a la posada silbando una alegre tonada.\n";
 										case 13:
 											return "Alguien grita: ¡eh, Bob, la carreta de estos enanos "
 											"necesita un sitio ahí dentro!\n";
 											case 14:
 												return "Alguien grita desde el interior de la posada: ¡Maldita "
 												"sea, apartad esa carne del fuego... no puedo ocuparme yo de todo!\n";
 												case 15:
 													return "Escuchas el ruido de cascos de una montura que es "
 													"conducida fuera de los establos.\n";
 													case 16:
 														return "Oyes el chirriar de ruedas de un carro que sale de "
 														"los establos.\n";
 														    }
    return "";
}

string f_olores(){
    switch(d4()){
        case 1:
return "Huele a estiércol y orines.\n";
case 2:
	return "Aspiras con deleite el olor de la paja seca.\n";
	case 3:
		return "A tus fosas nasales llega un vago olor a comida, mezclado con los olores "
		"habituales de los establos.\n";
		case 4:
			return "Percibes el característico olor a caballo.\n";
			    }
    return "";
}
create()
{
    ::create();
        SetLocate("la posada El Poney Pisador");
    	    SetIndoors(1);
    SetIntBright(21);
    SetIntNoise(SF(f_sonidos));
    SetIntSmell(SF(f_olores));
    AddDetail(({"vigas", "techo"}),
    	"El techo está sustentado por grandes y antiguas vigas de añoso roble, cubiertas "
    	"de polvo y telarañas.\n");
    AddDetail(({"pesebre", "pesebres"}),
    "Constan de gruesos tablones que encierran un espacio contra la pared donde se echa "
    "hierba o heno para alimentar a las monturas. En cada espacio dividido por las "
    "separaciones de madera, el pesebre tiene un agujero oval donde se enganchan las "
    "cadenas o cuerdas que sujetan a los animales.\n");

        AddDetail(({"bebederos", "bebedero"}),
        "Son profundos recipientes de madera cuyas tablillas encajan perfectamente entre "
        "sí, sujetas por bandas metálicas. Contienen agua para los animales.\n");
        AddDetail("canal",
    "Es un canalillo de unos veinte centímetros de anchura y veinte de profundidad que "
    "conduce los orines y excrementos de los animales hacia el exterior de los establos.\n");
    AddDetail(({"piedra", "piedras", "suelo", "pared", "paredes", "muro", "muros"}),
    "muros y paredes están hechos con piedra extraída de la colina, bien cimentada pero "
    "toscamente tallada, conformando una superficie irregular y rugosa.\n");
    AddDetail(({"separaciones", "divisiones"}),
    "Son bajas vallas de madera conformadas por dos trozos de tronco descortezado que surgen de los "
    "pesebres en forma orizontal a distintas alturas, unidas por una serie de tablones "
    "en posición vertical y espaciados entre sí. El conjunto sirve para separar a los "
    "animales estabulados y evitar que sus ataduras se enrreden o estallen peleas.\n");
}