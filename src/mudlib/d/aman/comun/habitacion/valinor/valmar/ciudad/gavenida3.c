/*
Fichero: gavenida3.c
Autor: Aulë
Fecha: 21/07/2013
Descripción: gran avenida que cruza Valmar, en la que situaremos las entradas a las mansiones de los Valar.
*/
#include "./path.h"
inherit HAB_VALMAR("ciudad/base_ciudad");
create()
{    ::create();
	
		SetIntLong(QueryIntLong()+ "Al sur de aquí se ierguen los palacios de Oromë, que "
		"el Vala Cazador utiliza frecuentemente junto con sus Maiar cuando viene a Valmar.\n");
		AddDetail(({"palacios de orome", "orome"}),
		"Es una gran mansión, baja y rectangular pero muy amplia.\n"
		"Las esbeltas columnas del atrio de mármol que ocupa toda la fachada,están talladas "
		"como troncos de hayas, y motivos de hojas y ramas cubren  la superficie de muros "
		"y  suelo.\n"
		"Dos esbeltos árboles tallados en piedra se inclinan hasta formar un arco y dar "
		"entrada al umbrío, y por lo que parece, amplio interior.\n");
    	    AddExit("oeste", "./gavenida2");
    	    AddExit("este", "./gavenida4");
    	    AddExit("sur", "./hab_orome");
    	    
    	    }