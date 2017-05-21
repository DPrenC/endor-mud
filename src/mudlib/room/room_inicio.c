/* ENDOR-MUD
room de paso para mover a cada personaje donde le corresponda según raza y ciudadanía.
*/
#include <wizlevels.h>
#include <moving.h>
#include <properties.h>
#include <stdrooms.h>
#include <bandos.h>
inherit ROOM;

public void sin_enclave(){
    write("Todavía no se ha programado un enclave para la ciudadanía que has elegido para tu personaje.\n"
    "Temporalmente tu enclave será el mismo de los errantes.\n");
}
public void enclaves(){
    switch(TP->QueryCitizenship()){
        case "bahia de forochel": sin_enclave(); TP->move(B_FOROCHEL, M_GO); break;
        case "bosque de druadan": sin_enclave(); TP->move(B_DRUADAN, M_GO); break;
        case "bree": TP->move(BREE, M_GO); break;
        case "calembel": sin_enclave(); TP->move(CALEMBEL, M_GO); break;
        case "carroca": sin_enclave(); TP->move(CARROCA, M_GO); break;
        case "cavernas del viejo pukel": sin_enclave(); TP->move(C_PUKEL, M_GO); break;
        case "ciudad del bosque": sin_enclave(); TP->move(C_BOSQUE, M_GO); break;
        case "ciudad de los trasgos": sin_enclave(); TP->move(C_TRASGOS, M_GO); break;
        case "ciudad del lago": sin_enclave(); TP->move(C_LAGO, M_GO); break;
        case "colinas de hierro": sin_enclave(); TP->move(C_HIERRO, M_GO); break;
        case "cuernavilla": sin_enclave(); TP->move(CUERNAVILLA, M_GO); break;
        case "dol amroth": sin_enclave(); TP->move(AMROTH, M_GO); break;
        case "edoras": sin_enclave(); TP->move(EDORAS, M_GO); break;
        case "erebor": sin_enclave(); TP->move(EREBOR, M_GO); break;
        case "estepas de harad": sin_enclave(); TP->move(E_HARAD, M_GO); break;
        case "estepas del este": sin_enclave(); TP->move(E_ESTE, M_GO); break;
        case "gorgoroth": sin_enclave(); TP->move(GORGOROTH, M_GO); break;
        case "imladris": sin_enclave(); TP->move(IMLADRIS, M_GO); break;
        case "isengard": sin_enclave(); TP->move(ISENGARD, M_GO); break;
        case "lossarnach": sin_enclave(); TP->move(LOSSARNACH, M_GO); break;
        case "lothlorien": sin_enclave(); TP->move(LOTHLORIEN, M_GO); break;
        case "meseta de khand": sin_enclave(); TP->move(M_KHAND, M_GO); break;
        case "minas morgul": sin_enclave(); TP->move(M_MORGUL, M_GO); break;
        case "minas tirith": sin_enclave(); TP->move(M_TIRITH, M_GO); break;
        case "mithlond": sin_enclave(); TP->move(MITHLOND, M_GO); break;
        case "moria": sin_enclave(); TP->move(MORIA, M_GO); break;
        case "nan naugrim": sin_enclave(); TP->move(NAUGRIM, M_GO); break;
        case "pelargir": sin_enclave(); TP->move(PELARGIR, M_GO); break;
        case "refugio dunadan": sin_enclave(); TP->move(R_DUNADAN, M_GO); break;
        case "reino de thranduil": sin_enclave(); TP->move(R_THRANDUIL, M_GO); break;
        case "tierras brunas": sin_enclave(); TP->move(T_BRUNAS, M_GO); break;
        case "umbar": sin_enclave(); TP->move(UMBAR, M_GO); break;
        case "valle": sin_enclave(); TP->move(VALLE, M_GO); break;

        case "errante": default:
            if(TP->QueryBando()== P_BANDO_LUZ || TP->QueryBando()==P_BANDO_NEUTRO){
                TP->move(ERRANTES, M_GO);
            }else{
                write("Todavía no se ha programado una zona donde iniciar a los "
                "personajes errantes aliados de la oscuridad.\n Temporalmente movemos "
                "tu personaje al mismo lugar que el resto de errantes.\n");
                TP->move(DESCAMPADO_1, M_GO);
        }
        break;
    }
}

create(){
    ::create();
    SetLocate("algún lugar de Arda");
     SetIntShort("una estancia de paso");
    SetIntLong("Esta room sólo es para moverte a tu lugar de procedencia.\n");
}

public void init(){
    ::init();
    if(!IS_LEARNER(TP)){
        enclaves();
    }
}