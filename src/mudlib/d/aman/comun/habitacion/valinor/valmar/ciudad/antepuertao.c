/*
Fichero: antepuertao.c
Autor: Aulë
Fecha: 21/07/2013
Descripción: lugar ante el portal ocidental de Valmar.
*/
#include "./path.h"
inherit STD_VALINOR("hab_valinor");
create()
{    ::create();
    	SetLocate("Valmar");
    	SetIndoors(0);
    	    SetIntShort("ante el portal occidental de Valmar");
    	    SetIntLong("Estás ante el Portal Occidental de Valmar, la ciudad de las muchas "
    	    "campanas y corazón del Reino Bendecido de Valinor.\n"
    	    "Los altos muros se ierguen al este, surgidos del seno de la roca en una "
    	    "sola y vasta construcción circular en cuyo interior se engarza la ciudad, "
    	    "interrumpidos tan solo en este lugar y en un punto idéntico al este, donde se "
    	    "sitúa el gran Portal Oriental.\n"
    	    "El Sol, la Luna y las estrellas arrancan destellos de luz sobre la prístina "
    	    "superficie de piedra y ningún ejército mortal o inmortal podría ser capaz de "
    	    "penetrar estos muros.\n"
    	    "Al oeste una calzada de mármol se extiende hacia el Máhanaxar y las regiones "
    	    "occidentales de Valinor y al oeste se abren los portones que dan acceso a "
    	    "la ciudad.\n");
    	    AddDetail(({"puertas", "portones", "portal", "portales"}),
    	    "El gran portal tiene forma semicircular y los batientes y el marco son de oro "
    	    "macizo, pulido y rutilante. Las puertas están siempre abiertas de par en par, "
    	    "como si dieran la bienvenida al viajero.\n");
    	  AddDetail(({"calzada", "oeste"}),
    	  "Hacia el oeste una calzada de losas de mármol recorre la ondulada llanura de Valmar,"
    	  "rumbo al Anillo del Juicio y las distantes tierras del oeste de Valinor.\n");
    	  AddDetail(({"anillo", "mahanaxar", "juicio", "anillo del juicio"}),
    	  "Tendrías que acercarte más para verlo con detalle, pues desde aquí solo "
    	  "aciertas a ver un montículo coronado por un círculo de piedra blanca.\n");
    	  SetIntNoise("Escuchas el reververante y argénteo tañir de las campanas de Valmar.\n");
    	  SetIntSmell("Aspiras el vivificante aire del Reino Bendecido.\n");
    	    AddExit("oeste", "./calzadao1");
    	    AddExit("este", "./portalo");
    	    }