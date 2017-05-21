#include "path.h"
#include <properties.h>
#include <colours.h>
#include <moving.h>
#include <lock.h>
#include <search.h>
inherit "std/room/items";
inherit "/obj/chest";
#define  ABIERTO    TO->QueryLockState()
#define AO (TP->QueryGender()==GENERO_FEMENINO?"a":"o")

public string ver_espejo()
{
    int aln;
    string msg;
	  if (TP && !TP->QueryHidden() && !TP->QueryInvis())
    {
        msg="Te ves a ti mism"+AO+" reflejad"+AO+" en el espejo:\n"+TP->QueryAttribute("OwnLong");
		    aln=(1000+TP->QueryAlign())*17/2000;
		    if (aln>16) aln=16;
		    else if (aln<0) aln=0;
		    msg+="Te ves rodead"+AO+" por un aura ";
		    switch (aln)
		    {
    			  case 0..6: msg+=TC_RED+"roja"+TC_NORMAL; break;
  			    case 7..9: msg+=TC_BLUE+"azul"+TC_NORMAL; break;
			      case 10..16: msg+=TC_WHITE+"blanca"+TC_NORMAL; break;
		    }
		    msg += ".\n";
		    return msg;
    }
    return "Ves la brillante superficie de la l�mina de plata escrupulosamente pulida, que "
        "adherida a la parte interior del vidrio, le confiere su cualidad de espejo.\n";
}

public int abrir_(string str)
{
    if (TO->id(str))
    {
        if (ABIERTO == LOCK_OPEN)
        {
            write("El armario ya est� abierto.\n");
            return 1;
        }
        if (TP == YALIN)
        {
            //aqu� bloque de c�digo para abrir
            say(TNAME+" murmura unas palabras que no entiendes antes de acercarse al armario.\n",TP);
            return 0;
        }
        write("Una fuerza m�gica te impide acercar tu mano al armario. Parece ser que s�lo la "
            "reina y su ni�o pueden abrirlo.\n");
        say(TNAME+" intenta abrir el armario, pero parece ser que una fuerza m�gica se lo impide.\n");
        return 1;
    }
    return 0;
}

public int cerrar_(string str)
{
    if (TO->id(str))
    {
        if (ABIERTO == LOCK_CLOSED)
        {
            write("El armario ya est� cerrado.\n");
            return 1;
        }
        if (TP == YALIN)
        {
            //aqu� bloque de c�digo para cerrar
            say(TNAME+" murmura unas palabras que no entiendes antes de acercarse al armario.\n",TP);
            return 0;
        }
        write("Una fuerza m�gica te impide acercar tu mano al armario. Parece ser que s�lo la "
            "la reina y su ni�o pueden cerrarlo.\n");
        say(TNAME+" intenta cerrar el armario, pero parece ser que una fuerza m�gica se lo impide.\n");
        return 1;
    }
    return 0;
}

create()
{
    "*"::create();
    SetIds(({"armario"}));
    SetShort("el armario");
    SetAds(({"de"}));
    SetLong("Es un gran armario de la misma madera de s�ndalo que el resto del mobiliario.\nEs en "
        "forma de gran paralelep�pedo, colocado contra la pared frente a la cama.\n La puerta est� cubierta en su "
        "totalidad por un gran espejo, donde puedes verte enter"+TP->QueryGenderEndString()+".\n");
    AddId(({"armario"}));
    AddAdjective(({"madera","pesado","gran","grande"}));
    AddSubDetail(({"puerta","espejo"}),SF(ver_espejo),1);
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NOGET,"S� claro, �y qu� m�s?");
    Set(P_LOCKSTATE,LOCK_OPEN);
    SetMaxIntWeight(50000);
    AddItem("tunica",REFRESH_REMOVE,2);
    AddItem("zapatillas",REFRESH_REMOVE,2);
    AddItem("daga");
    AddItem("espada");
    Set(P_LOCKSTATE,LOCK_CLOSED);
}
  
init()
{
    ::init();
    add_action("cerrar_","cerrar");
    add_action("abrir_","abrir");
}
        