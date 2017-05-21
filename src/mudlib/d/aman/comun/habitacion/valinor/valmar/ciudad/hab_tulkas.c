/*
Fichero: tulkas.c
Autor: Aulë
Fecha: 15/10/2012
Descripción: workroom del vago de Tulkas
*/
#include "./path.h"
inherit STD_VALINOR("hab_valinor");
create()
{
    ::create();
    	SetLocate("Valmar");
    SetIntShort("estancias de Tulkas");
    SetIntLong("Te encuentras en un amplio salón exento de columnas en cuyos muros \n"
    "blancos se desarrolla toda una galería de relieves que representan las diversas \n"
    "batallas en las que los Valar han participado desde la creación de Arda.\n"
    "Al sur una poderosa arcada soportada por columnas de mármol da paso al exterior \n"
    "del edificio.\n"
    "El suelo de la estancia es de mármol blanco y largas mesas de banquete se alinean \n"
    "junto a las paredes, siguiendo el trazado de las mismas.\n"
    "En la sección norte se alza un estrado también de mármol al que conducen unos \n"
    "amplios escalones y sobre él se levanta una gran mesa donde el anfitrión y sus más \n"
    "próximos compañeros toman asiento.\n"
    "En el muro se alinea toda una panoplia de magníficas armas y armaduras que relucen \n"
    "suavemente.\n"
    "Estas son las estancias de Tulkas el Campeón de los Valar, cuyos banquetes son \n"
    "famosos en toda Valmar.\n");
    //AddExit("trans", "./trans_endor");
    AddExit("sur", "./gavenida5");
    SetIntBright(40);
    SetIntSmell("El olor de los más exquisitos manjares y licores inunda tus fosas nasales.\n");
    SetIntNoise("Crees percibir las distantes llamadas de cuernos y gritos de guerra que llaman al combate...\n");
     
  }public void init()
{
	::init();
	write("Atraviesas la arcada soportada por columnas y penetras en los salones de Tulkas.\n");
}