
//#include "./path.h"
inherit ROOM;
int pMaxlenya,pCantidadlenya,pHaylenya=1;
string pTipoarbol;
//si hay le�a o no.
public int QueryHaylenya()    { return pHaylenya; }
public int SetHaylenya(int i) { return pHaylenya = i; }
// m�ximo de cantidad de le�a
public int QueryMaxLenya()    { return pMaxlenya; }
public int SetMaxLenya(int i) { return pMaxlenya = i; }
//cantidad de le�a que queda
public int QueryCantidadLenya()    { return pCantidadlenya; }
public int SetCantidadLenya(int i) { return pCantidadlenya = i; }
// si puede haber �rboles cortables.

// que tipo de �rboles puede haber.
public string QueryTipoArbol()         { return pTipoarbol; }
public string SetTipoArbol(string str) { return pTipoarbol = str; }

create() {
::create();
}