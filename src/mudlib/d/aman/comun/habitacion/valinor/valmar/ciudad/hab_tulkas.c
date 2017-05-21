/*
Fichero: tulkas.c
Autor: Aul�
Fecha: 15/10/2012
Descripci�n: workroom del vago de Tulkas
*/
#include "./path.h"
inherit STD_VALINOR("hab_valinor");
create()
{
    ::create();
    	SetLocate("Valmar");
    SetIntShort("estancias de Tulkas");
    SetIntLong("Te encuentras en un amplio sal�n exento de columnas en cuyos muros \n"
    "blancos se desarrolla toda una galer�a de relieves que representan las diversas \n"
    "batallas en las que los Valar han participado desde la creaci�n de Arda.\n"
    "Al sur una poderosa arcada soportada por columnas de m�rmol da paso al exterior \n"
    "del edificio.\n"
    "El suelo de la estancia es de m�rmol blanco y largas mesas de banquete se alinean \n"
    "junto a las paredes, siguiendo el trazado de las mismas.\n"
    "En la secci�n norte se alza un estrado tambi�n de m�rmol al que conducen unos \n"
    "amplios escalones y sobre �l se levanta una gran mesa donde el anfitri�n y sus m�s \n"
    "pr�ximos compa�eros toman asiento.\n"
    "En el muro se alinea toda una panoplia de magn�ficas armas y armaduras que relucen \n"
    "suavemente.\n"
    "Estas son las estancias de Tulkas el Campe�n de los Valar, cuyos banquetes son \n"
    "famosos en toda Valmar.\n");
    //AddExit("trans", "./trans_endor");
    AddExit("sur", "./gavenida5");
    SetIntBright(40);
    SetIntSmell("El olor de los m�s exquisitos manjares y licores inunda tus fosas nasales.\n");
    SetIntNoise("Crees percibir las distantes llamadas de cuernos y gritos de guerra que llaman al combate...\n");
     
  }public void init()
{
	::init();
	write("Atraviesas la arcada soportada por columnas y penetras en los salones de Tulkas.\n");
}