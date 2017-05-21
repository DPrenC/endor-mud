/****************************************************************************
Fichero: /guilds/kisalas/bin/_preparar.c
Autor: Yalin
Fecha: 29/01/2008 17:24
Descripci�n: Archivo de comando (preparar b�lsamo)
****************************************************************************/

#include <properties.h>
#include <skills.h>
#include <guild.h>
#define AQUI    environment(TP)

int main(string str)
{
    int hab, cont, pot, cant;
    object vial, herb, mort;
    string cal;
    if (((TP->QueryGuild()!=GC_KISALA) && (TP->QueryGuild()!=GC_GUARDABOSQUE)) || (TP->HasSkill(HAB_DO_BALSAMO)!=1)) return 0;
    if ((str!="balsamo") && (str!="b�lsamo")) return notify_fail("�Preparar qu�?\n",
        NOTIFY_NOT_VALID);
    if (!(herb=present("balsamo_hierba",TP)))
    {
        return notify_fail("Necesitas unas hierbas especiales para preparar el b�lsamo.\n",
            NOTIFY_NOT_VALID);
    }
    if (!(mort=present("balsamo_mortero",TP)))
    {
        return notify_fail("No tienes mortero para preparar el b�lsamo.\n",
            NOTIFY_NOT_VALID);
    }
    if (!(vial=present("balsamo_vial",TP)))
    {
        return notify_fail("No tienes el recipiente apropiado para recoger el b�lsamo.\n",
            NOTIFY_NOT_VALID);
    }
    if (vial->QueryContent()==6) return notify_fail("El pomo est� completamente lleno, no "
        "tienes donde recoger el b�lsamo.\n",NOTIFY_NOT_VALID);
    hab=TP->UseSkill(HAB_DO_BALSAMO,TP->QueryDex());
    cont=vial->QueryContent();
    cant=6-cont;
    if (herb->QueryContent()<cant)
    {
        tell_object(TP,"No tienes suficientes hierbas en el paquete para llenar el pomo, as� "
            "que usas las que te quedan.\n");
        cant=herb->QueryContent();
    }
    pot=((herb->QueryPowerNumber()+hab)/35)+1;
    herb->SetContent(herb->QueryContent()-cant);
    tell_object(TP,"Pones las hierbas en el mortero, y procedes a machacarlas seg�n la t�cnica "
        "secreta que aprendiste.\n");
    if (TP->QueryInvis()<1) tell_room(AQUI,TNREAL+" pone unas hierbas en un mortero, y procede "
        "a machacarlas con extra�os movimientos...\n",({TP}));
    if (hab<=0)
    {
        tell_object(TP,"Al cabo de un rato obtienes un l�quido asqueroso, y sospechas que tu "
            "poca habilidad te hizo estropear el preparado, as� que lo tiras.\n");
        if (TP->QueryInvis()<1) tell_room(AQUI,"Al cabo de un rato, consigue un l�quido de "
            "aspecto desagradable, y con una expresi�n frustrada en el rostro, lo vierte en el "
            "suelo.\n",({TP}));
    }
    else
    {
        switch(pot)
        {
            case 1:
                cal="muy mala";
            break;
            case 2:
                cal="mala";
            break;
            case 3:
                cal="regular";
            break;
            case 4:
                cal="buena";
            break;
            case 5:
                cal="muy buena";
            break;
            case 6:
                cal="excelente";
            break;
        }
        tell_object(TP,"Consigues elaborar un b�lsamo de calidad "+cal+".\nSin p�rdida de tiempo, "
            "lo pasas al pomo.\n");
        if (TP->QueryInvis()<1) tell_room(AQUI,"Al cabo de un rato, obtiene una crema aceitosa de "
            "un bonito color verde.\n",({TP}));
        pot=((pot*cant)+(cont*vial->QueryPotencia()))/6;
        vial->SetContent(cont+cant);
        vial->SetPotencia(pot);
    }
    if (!herb)
    {
        tell_object(TP, "Has gastado todo el paquete de hierbas.\n");
    }
    else
    {
        tell_object(TP, "Te quedan hierbas para " + herb->QueryContent() + " dosis.\n");
    }
    return 1;
}
