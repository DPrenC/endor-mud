/*
Fichero: c1_jardin.c
Autor: aulë
Fecha: 12/10/2014
Descripción: Jardín delantero de la casa*/
#include "./path.h"
inherit BREE_ROOM;
#include <moving.h>


string f_sonidos(){
    switch(d6()){
        case 1:        	return "Oyes un relincho procedente del establo situado al norte.\n";
        	case 2:
        		return "Los cascos de una montura resuenan en el camino.\n";
        		case 3:
        			return "Se escucha el rítmico sonido de una azada trabajando la tierra al suroeste de aquí.\n";
        			case 4:
        				return "Unas aves alborotan y cacarean dentro del establo.\n";
        				        				case 5:
        					return "Alguien tararea y trajina dentro de la casa.\n";
        					case 6:
        						return "Se escuchan una serie de agudos maullidos procedentes de la parte alta del establo.\n";
        						}
    return "";
}
create()
{
    ::create();
    	SetIntShort("el jardín delantero");
    	SetIntLong(
    	"Estás en una especie de jardín que ocupa una pequeña parcela más o menos cuadrada.\n"
    	"Al norte un espeso seto que llega al pecho de un hombre cierra la propiedad y la "
    	"separa del camino. Al sur se levanta una pequeña casa de dos pisos con un "
    	"edificio anexo construído al este y que se extiende hacia el norte cerrando el "
    	"jardín por ese lado. En el jardín hay algunos arbustos y plantas aunque en su "
    	"mayor parte está cubierto de hierba. Contra el muro de la casa hay un sencillo "
    	"banco y al suroeste puede rodearse la casa y acceder a otras zonas de la "
    	"propiedad.\n");
    	AddDetail("seto",
    	"Es un espeso seto vegetal que llega a la altura del pecho de un hombre. Está cerrado en el punto medio por una cancela que da acceso al camino.\n");
    	AddDetail("casa",
    	"Una casita cuadrada, de piedra sin alisar ni tallar, con techo a dos aguas de "
    	"tejas simples. Tiene una ventana a cada lado de la puerta en la planta inferior y "
    	"una ventana sobre la misma en la planta superior. El alero avanza algo más de un "
    	"metro permitiendo así cobijarse de los elementos. Un tablón de madera sustentado "
    	"sobre dos bloques de piedra hace las veces de banco bajo la ventana situada más "
    	"al oeste.\n");
    	AddDetail(({"edificio", "edificio norte", "establo"}),
    	"Es un edificio  de piedra y tosca argamasa pegado a la casa y que se alarga "
    	"hacia el norte. El techo de inclinación suave, desciende hacia ese lado, hecho de "
    	"tejas planas. Junto a la puerta hay una ventana cerrada con barrotes de madera y "
    	"un enrrejado de varillas metálicas y justo encima hay lo que parece ser una "
    	"puerta baja y cuadrada.\n");
    	AddDetail("suroeste",
    	"Tendrás que rodear la casa para verlo.\n");
    	AddDetail("camino",
    	"Más allá del seto ves el camino que asciende serpeando la falda de la colina "
    	"entre las casas dispersas de la aldea.\n");
    	AddDetail("plantas",
    	"Algunas plantas vagamente ornamentales se distribuyen junto a las paredes de los "
    	"edificios y junto al seto aunque parecen algo descuidadas.\n");
    	AddDetail("arbustos",
    	"Son un par de arbustos bajos. Al fijarte con más detenimiento adviertes que son "
    	"frutales pues de ellos cuelgan algunas bayas.\n");
        SetIntNoise(SF(f_sonidos));
    SetIntSmell("Percibes una mezcla de olores de hierba seca, comida recién hecha y estiércol");
    	    AddExit("suroeste", "./c1_huerto1");
     AddExit("este", "./c1_establo1");
     AddExit("sur", "./c1_piso1");
     AddExit("norte", "./viao2");
     AddDoor("norte", "la cancela del camino",
     "Es una cancela de tablas de madera verticales terminadas en punta triangular, "
     "soportadas por tres tablones horizontales. Cierra el seto en su parte media y se "
     "sustenta en dos postes cuadrados. El pestillo, las grandes bisagras y el pasador "
     "inferior son de hierro.\n",
     ({"puerta", "n", "norte", "cancela", "puerta norte", "puerta n"}));
     AddDoor("sur", "la puerta de la casa",
     "Una puerta de madera lisa pintada de verde con una manilla y una aldava de bronce "
     "para llamar.\n",
    ({"puerta", "s", "sur", "casa", "principal", "puerta de la casa"}));
    AddDoor("este", "la puerta del establo",
    "Es una gruesa puerta de grandes tablones cuadrados de madera toscamente trabajada "
    "clavados sobre un armazón de soportes macizos del mismo material. Consta de una "
    "parte inferior y un cuarterón superior que puede abrirse de forma independiente.\n"
    "No hay cerradura ni manilla, la puerta se abre con un simple empujón.\n",
    ({"este", "e", "puerta este", "puerta e", "establo", "puerta del establo", "puerta"}));
  }