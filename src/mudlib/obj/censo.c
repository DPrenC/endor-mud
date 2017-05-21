/**
 * /obj/censo.c
 * censo Simauria
 */

#define NDATOS 2
// el dato 0 es la fecha de censado y el 1 es la ciudad

#define DATOS "/log/CENSO"

public int C_Censo(string jugador);
public int Censar(string jugador,string ciudad);

public varargs void CargarTabla();
private void CrearTabla();
private int TablaCargada;
private int TablaCreada;
public mapping censo;

/* funciones */

public varargs void CargarTabla(){
    /*  Carga el censo */
    if(censo) return;
    restore_object(DATOS);
    TablaCargada=1;
}

public varargs void SalvarTabla() {
    /* salva la tabla */
    save_object(DATOS);
}

private void CrearTabla() {
    if (censo) return;
    censo = m_allocate(0,NDATOS);
    TablaCreada=1;
}

public int Censado(string jugador) {
    /* Comprueba que el jugador esta censado o no */
    mixed indices;
    string *idx,jug;
    int num_ind,i,verdad;

    verdad=0;
    if (!TablaCargada) CargarTabla();
    if (!TablaCreada) CrearTabla();
    num_ind=sizeof(censo);
    if (num_ind<1) return 0;
    idx = m_indices(censo);
    jug = idx[0];
    for(i=0;i<num_ind;i++) {
        if (find_savefile(idx[i])||find_object(lower_case(idx[i]))) {
            verdad=1;
            jug=idx[i];
        }
        if (verdad==0) {
            censo = m_delete(censo,jug);
            SalvarTabla();
        }
    }
    return member(censo,jugador);
}

/* funcion principal, censa a un jugador */
public int Censar(string jugador, string ciudad) {
    if (!jugador || !stringp(ciudad) || !sizeof(ciudad)) return 0;
    if (!TablaCargada) CargarTabla();
    if (!TablaCreada) CrearTabla();
    if (!Censado(jugador)) {
        censo[jugador,1] = ciudad;
        censo[jugador,0] = ctime();
        write(capitalize(jugador)+" ha sido censado en la ciudad de "+ciudad+"\n");
    }
    else {
        censo[jugador,1] = ciudad;
        censo[jugador,0] = ctime();
        write(capitalize(jugador)+" ha cambiado la residencia a "+ciudad+"\n");
    }
    SalvarTabla();
    return 1;
}

/* funcion para comprobar donde esta censado alguien */
public int C_Censo(string jugador) {
    if (!TablaCargada) CargarTabla();
    if (!TablaCreada) CrearTabla();
    if (Censado(jugador)) {
        write(capitalize(jugador)+" esta censado en la ciudad de "+censo[jugador,1]+".\n");
    }
    else write(capitalize(jugador)+" no esta censado en ninguna ciudad.\n");
    return 1;
}
