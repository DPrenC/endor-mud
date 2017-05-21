/*****************************************************************************************
 ARCHIVO:       sendero_oeste.c
 AUTOR:         Ztico
 FECHA:         16-03-2005
 DESCRIPCI�N:   Habitaci�n est�ndar para elo sendero occidental del bosque.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit HAB_VALMAR("hab_bosque");

public string f_escuchar();
public string f_oler();

create()
{
    if(::create()) return 1;

    SetLocate("Bosques de Valmar");
    SetIntShort("el sendero Oeste del Bosque");
    SetIndoors(0);
    switch(random(60))
    {
        case 0..9:
            SetIntLong("Est�s en el sendero m�s occidental del bosque, el cual se une "
                "al del este y conecta el bosque central con el de las Dr�adas. A "
                "ambos lados del sendero ves hierbas s�lvajes, raices y mont�culos. "
                "Una hilera de �rboles te impide ir en cualquier otra direcci�n que "
                "no sea la vereda y sientes impulsos muy extra�os que te obligan a "
                "seguir caminando.\n");
            break;
        case 10..19:
            SetIntLong("Caminas por el sendero que une el bosque central con el de las "
                "Dr�adas, fusionandose imperceptiblemente con el Sendero del este. Te "
                "maravillas ante la belleza de los parajes y sientes deseos de no "
                "abandonarlo jam�s.\n");
            break;
        case 20..29:
            SetIntLong("Est�s recorriendo el Sendero Oeste del bosque. El aroma de las "
                "hierbas y plantas que pueblan el sendero te reconforta y te invita a "
                "continuar explorando el bosque.\n");
            break;
        case 30..39:
            SetIntLong("Los �rboles extrechan la vereda en este punto, haci�ndote "
                "imposible moverte en otra direcci�n que no sea la del sendero.\n");
            break;
        case 40..49:
            SetIntLong("Avanzas por el sendero occidental de los grandes bosques de Valmar. "
                "A ambos lados observas florecillas y hierbas que alegran la vereda y "
                "que dotan al paisaje de colorido y de un suave aroma a madreselva.\n");
            break;
        case 50..60:
            SetIntLong(".\n");
            break;
    }

    SetIntSmell(SF(f_oler));
    SetIntNoise(SF(f_escuchar));
}

public string f_oler()
{
    if(member(RAZASENEMIGAS, TP->QueryRace()) >= 0)
        return "Este olor tan puro te repugna.\n";
    return "Huele a roc�o y madreselva.\n";
}

public string f_escuchar()
{
    if(member(RAZASENEMIGAS, TP->QueryRace()) >= 0)
        return "Tus oidos no captan nada especial.\n";
    return "Escuchas suaves melod�as procedentes del coraz�n del bosque.\n";
}
