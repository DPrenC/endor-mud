/*
Fichero: antepuertao.c
Autor: Aul�
Fecha: 21/07/2013
Descripci�n: lugar ante el portal ocidental de Valmar.
*/
#include "./path.h"
inherit STD_VALINOR("hab_valinor");
create()
{    ::create();
    	SetLocate("Valmar");
    	SetIndoors(0);
    	    SetIntShort("ante el portal occidental de Valmar");
    	    SetIntLong("Est�s ante el Portal Occidental de Valmar, la ciudad de las muchas "
    	    "campanas y coraz�n del Reino Bendecido de Valinor.\n"
    	    "Los altos muros se ierguen al este, surgidos del seno de la roca en una "
    	    "sola y vasta construcci�n circular en cuyo interior se engarza la ciudad, "
    	    "interrumpidos tan solo en este lugar y en un punto id�ntico al este, donde se "
    	    "sit�a el gran Portal Oriental.\n"
    	    "El Sol, la Luna y las estrellas arrancan destellos de luz sobre la pr�stina "
    	    "superficie de piedra y ning�n ej�rcito mortal o inmortal podr�a ser capaz de "
    	    "penetrar estos muros.\n"
    	    "Al oeste una calzada de m�rmol se extiende hacia el M�hanaxar y las regiones "
    	    "occidentales de Valinor y al oeste se abren los portones que dan acceso a "
    	    "la ciudad.\n");
    	    AddDetail(({"puertas", "portones", "portal", "portales"}),
    	    "El gran portal tiene forma semicircular y los batientes y el marco son de oro "
    	    "macizo, pulido y rutilante. Las puertas est�n siempre abiertas de par en par, "
    	    "como si dieran la bienvenida al viajero.\n");
    	  AddDetail(({"calzada", "oeste"}),
    	  "Hacia el oeste una calzada de losas de m�rmol recorre la ondulada llanura de Valmar,"
    	  "rumbo al Anillo del Juicio y las distantes tierras del oeste de Valinor.\n");
    	  AddDetail(({"anillo", "mahanaxar", "juicio", "anillo del juicio"}),
    	  "Tendr�as que acercarte m�s para verlo con detalle, pues desde aqu� solo "
    	  "aciertas a ver un mont�culo coronado por un c�rculo de piedra blanca.\n");
    	  SetIntNoise("Escuchas el reververante y arg�nteo ta�ir de las campanas de Valmar.\n");
    	  SetIntSmell("Aspiras el vivificante aire del Reino Bendecido.\n");
    	    AddExit("oeste", "./calzadao1");
    	    AddExit("este", "./portalo");
    	    }