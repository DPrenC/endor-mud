
//#include "./path.h"
inherit ROOM;
int pMaxlenya,pCantidadlenya,pHaylenya=1;
string pTipoarbol;
//si hay leña o no.
public int QueryHaylenya()    { return pHaylenya; }
public int SetHaylenya(int i) { return pHaylenya = i; }
// máximo de cantidad de leña
public int QueryMaxLenya()    { return pMaxlenya; }
public int SetMaxLenya(int i) { return pMaxlenya = i; }
//cantidad de leña que queda
public int QueryCantidadLenya()    { return pCantidadlenya; }
public int SetCantidadLenya(int i) { return pCantidadlenya = i; }
// si puede haber árboles cortables.

// que tipo de árboles puede haber.
public string QueryTipoArbol()         { return pTipoarbol; }
public string SetTipoArbol(string str) { return pTipoarbol = str; }

create() {
::create();
}