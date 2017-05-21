/*****************************************************************************************
 ARCHIVO:       senderoO02.c
 AUTOR:         Ztico
 FECHA:         19-03-2005
 DESCRIPCI�N:   Sendero Oeste del bosque de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_SENDERO_OESTE;

public int ir_oeste();

create()
{
    if(::create()) return 1;

    AddExit("norte", HAB_BOSQUE_SENDERO("senderoO03.c"));
    AddExit("este", HAB_BOSQUE_SENDERO("senderoO01.c"));
    AddExit("oeste", SF(ir_oeste));
    //AddExit("oeste", HAB_BOSQUE_SENDERO("caminoP01.c"));
}

//Funci�n provisional hasta que abra el camino del pantano.

public int ir_oeste()
{
    write("El camino del pantano est� cortado hasta que el mel�n lo termine, jijiji.\n");
    say(CAP(TNAME) + " intenta ir al oeste pero no puede.\n");
    return 1;
}
