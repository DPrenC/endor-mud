/***
orome 20/10/2014
archivo base de bosques para poder encontrar leña y árboles talables.
*****/


//inherit ROOM;
int pMaxlenya,pCantidadlenya,pHaylenya;
int pHayarboles,pCantidadarboles,pMaxarboles;
string pTipoarboles="arbol";

//si hay leña o no.
public int QueryHaylenya()    { return pHaylenya; }
public int SetHaylenya(int i) { return pHaylenya = i; }

// máximo de cantidad de leña
public int QueryMaxLenya()    { return pMaxlenya; }
public int SetMaxLenya(int i) { return pMaxlenya = i; }

//cantidad de leña que queda
public int QueryCantidadLenya()    { return pCantidadlenya; }
public int SetCantidadLenya(int i) { return pCantidadlenya = i; }
public int AddCantidadLenya (int i) { return SetCantidadLenya(i + QueryCantidadLenya()); }

// que tipo de árboles puede haber.
public string QueryTipoArboles()         { return pTipoarboles; }
public string SetTipoArboles(string str) { return pTipoarboles = str; }

//si hay árboles talables o puede haberlos.
public int QueryHayarboles()    { return pHayarboles; }
public int SetHayarboles(int i) { return pHayarboles = i; }

// máximo de cantidad de árboles que se podrán encontrar.
public int QueryMaxArboles()    { return pMaxarboles; }
public int SetMaxArboles(int i) { return pMaxarboles = i; }

//cantidad de árboles que quedan por encontrar.
public int QueryCantidadArboles()    { return pCantidadarboles; }
public int SetCantidadArboles(int i) { return pCantidadarboles = i; }
public int AddCantidadArboles (int i) { return SetCantidadArboles(i + QueryCantidadArboles()); }
