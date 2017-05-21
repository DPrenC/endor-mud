/*
Fichero: gavenida3.c
Autor: Aul�
Fecha: 21/07/2013
Descripci�n: gran avenida que cruza Valmar, en la que situaremos las entradas a las mansiones de los Valar.
*/
#include "./path.h"
inherit HAB_VALMAR("ciudad/base_ciudad");
create()
{    ::create();
	
		SetIntLong(QueryIntLong()+ "Al sur de aqu� se ierguen los palacios de Orom�, que "
		"el Vala Cazador utiliza frecuentemente junto con sus Maiar cuando viene a Valmar.\n");
		AddDetail(({"palacios de orome", "orome"}),
		"Es una gran mansi�n, baja y rectangular pero muy amplia.\n"
		"Las esbeltas columnas del atrio de m�rmol que ocupa toda la fachada,est�n talladas "
		"como troncos de hayas, y motivos de hojas y ramas cubren  la superficie de muros "
		"y  suelo.\n"
		"Dos esbeltos �rboles tallados en piedra se inclinan hasta formar un arco y dar "
		"entrada al umbr�o, y por lo que parece, amplio interior.\n");
    	    AddExit("oeste", "./gavenida2");
    	    AddExit("este", "./gavenida4");
    	    AddExit("sur", "./hab_orome");
    	    
    	    }