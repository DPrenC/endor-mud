/*
Fichero: calzadao1.c
Autor: Aulë
Fecha: 21/07/2013
Descripción: calzada que parte del portal ocidental de Valmar.
*/
#include "./path.h"
inherit STD_VALINOR("hab_valinor");
create()
{    ::create();
    	SetLocate("Valmar");
    	SetIndoors(0);
    	    SetIntShort("una resplandeciente calzada");
    	    SetIntLong("La calzada en la que te encuentras es una vía ancha, elevada "
    	    "sobre las ondulantes llanuras que se extienden en derredor.\n"
    	    "El suelo está pavimentado con grandes losas de formas regulares y de las más "
    	    "nobles clases de piedra que el seno de Arda puede ofrecer.\n"
    	    "Al este se alzan los muros blancos de Valmar y hacia el oeste la calzada "
    	    "lleva al Anillo del Juicio y aún más allá, a las distantes tierras "
    	    "orientales de Valinor.\n");
    	    AddDetail(({"llanuras", "llanura", "ondulantes", "ondulante"}),
    	    	"La verde llanura de Valmar resplandece bajo el claro cielo de Valinor, "
    	    	"extendiéndose alrededor de la ciudad hasta los pies de  Taniquetil y las "
    	    	"montañas Pelóri en el oeste, los bosques de Oromë y los pastizales de "
    	    	"Yavana al sur, y perdiéndose en la distancia al norte y este.\n");
    	    	AddDetail(({"suelo", "pavimento", "losas", "piedra", "piedras"}),
    	    	"El piso de la calzada está formado por losas de piedra pulida de distintos "
    	    	"tipos como el más puro mármol blanco o el granito más resistente.\n");
    	    	AddDetail(({"ciudad", "valmar"}),
    	    	"Distingues las altas cúpulas y cúspides de las torres de la ciudad e "
    	    	"Valmar, sobresaliendo por sobre los blancos muros que rodean la urbe.\n");
    	    	AddDetail(({"muros", "muro", "muralla", "murallas"}),
    	    	"Los magníficos muros de Valmar centellean con un resplandor blanquecino, "
    	    	"forjados con la más dura piedra de Arda y sellados con el poder de los "
    	    	"Valar.\n"
    	    	"En su interior se engarza la ciudad de Valmar.\n");
    	    	AddDetail(({"anillo", "juicio", "anillo del juicio", "mahanaxar"}),
    	    	"Hacia el oeste la calzada da acceso a un verde motículo coronado por una "
    	    	"explanada circular pavimentada y rodeada por un anillo de altos sitiales.\n");
    	    	AddDetail(({"montañas", "pelori", "pelóri", "montañas pelóri"}),
    	    	"En una ininterrumpida línea que se pierde en el horizonte al norte y al sur, "
    	    	"la cordillera de las Pelóri que rodea y protege el Reino Bendecido, se "
    	    	"levanta desde la llanura rasgando el cielo con sus afiladas cumbres "
    	    	"cubiertas de nieves eternas.\n"
    	    	"Las laderas occidentales descienden con suavidad, cubiertas de pastos y "
    	    	"bosques hasta unirse gentilmente con la llanura.\n"
    	    	"Uno de los picos se extiende a una altura inconmensurable, se trata de "
    	    	"Taniquetil, a cuyos pies descansa Valmar.\n");
    	    	AddDetail(({"montaña", "taniquetil"}),
    	    	"La gran montaña de Taniquetil, también llamada Oiolossë, es la motaña más "
    	    	"alta y poderosa de toda Arda.\n"
    	    	"En su invisible cumbre residen Manwë y Varda, los Reyes de Arda, y desde "
    	    	"allí vigilan y gobiernan el mundo.\n"
    	    	"Distingues el lejano trazado de una senda que trepa por la ladera hasta "
    	    	"perderse en las alturas.\n");
    	    	AddDetail(({"bosque", "bosques", "orome", "bosques de orome"}),
    	    	"Apenas si aciertas a vislumbrar en la lejanía del sur la borrosa línea de "
    	    	"los lindes de los altos bosques de Oromë.\n");
    	    	AddDetail(({"pastizal", "pastizales", "yavana", "pastizales de yavana"}),
    	    	"Desde aquí no aciertas a distinguir los pastizales de Yavana.\n");
    	    	
    	    	
    	    	 
    	    
    	    AddExit("oeste", "./calzadao2");
    	    AddExit("este", "./antepuertao");
    	    }