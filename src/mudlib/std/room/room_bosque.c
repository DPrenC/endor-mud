/***
orome 20/10/2014
archivo base de bosques para poder encontrar le�a y �rboles talables.
*****/


//inherit ROOM;
int pMaxlenya,pCantidadlenya,pHaylenya;
int pHayarboles,pCantidadarboles,pMaxarboles;
string pTipoarboles="arbol";

//si hay le�a o no.
public int QueryHaylenya()    { return pHaylenya; }
public int SetHaylenya(int i) { return pHaylenya = i; }

// m�ximo de cantidad de le�a
public int QueryMaxLenya()    { return pMaxlenya; }
public int SetMaxLenya(int i) { return pMaxlenya = i; }

//cantidad de le�a que queda
public int QueryCantidadLenya()    { return pCantidadlenya; }
public int SetCantidadLenya(int i) { return pCantidadlenya = i; }
public int AddCantidadLenya (int i) { return SetCantidadLenya(i + QueryCantidadLenya()); }

// que tipo de �rboles puede haber.
public string QueryTipoArboles()         { return pTipoarboles; }
public string SetTipoArboles(string str) { return pTipoarboles = str; }

//si hay �rboles talables o puede haberlos.
public int QueryHayarboles()    { return pHayarboles; }
public int SetHayarboles(int i) { return pHayarboles = i; }

// m�ximo de cantidad de �rboles que se podr�n encontrar.
public int QueryMaxArboles()    { return pMaxarboles; }
public int SetMaxArboles(int i) { return pMaxarboles = i; }

//cantidad de �rboles que quedan por encontrar.
public int QueryCantidadArboles()    { return pCantidadarboles; }
public int SetCantidadArboles(int i) { return pCantidadarboles = i; }
public int AddCantidadArboles (int i) { return SetCantidadArboles(i + QueryCantidadArboles()); }
