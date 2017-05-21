/*
 ARCHIVO:	aguja.c
 AUTOR:		Aulë
 FECHA:		24/10/2014
 COMENTARIOS:	Una aguja para coser, tejer, zurzir, reparar ropajes.. */


#include <properties.h>

inherit THING;

create () {
 ::create();

 SetShort("una aguja");
 SetLong("Es una elaborada aguja de acero, fina y afilada, con una hendedura en la parte "
 "trasera para enebrar el hilo. Sirve para coser cualquier tipo de tejido, realizar "
 "bordados o tejer.\n");
 SetIds(({"aguja","aguja de coser", "alfiler", "herramienta"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_SMALL);
 SetWeight(2);
 SetValue(010);
}
