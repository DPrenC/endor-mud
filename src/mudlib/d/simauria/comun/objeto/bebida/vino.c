/****************************************************************************
Fichero: vino.c
Autor: Kastwey
Fecha: 02/04/2006
Descripción: Botella de vino para el castillo de Nandor (reescrita 100%)
****************************************************************************/


#include <properties.h>
#include <nightday.h>
#include <colours.h>


#define TAM_PEQUE 1
#define TAM_MEDIANA 2
#define TAM_GRANDE 3
#define FORMA_REDONDA 1
#define FORMA_CUADRADA 2

inherit DRINK;

// sobrecargamos la función empty_vessel para que no borre las ids antiguas

public void empty_vessel()
{
    string *idents = QueryIds();
    ::empty_vessel();
    SetIds(idents);
}




public void SetTipo(int tamano, int forma)
{
    string str_tam, str_form;
    if (tamano > 3) tamano = 3;
    if (tamano < 1) tamano = 1;
    if (forma < 1) forma = 1;
    if (forma > 2) forma = 2;

    Set_Drink_Name("vino");
    switch (tamano)
    {
        case TAM_PEQUE:
             str_tam = "pequeña";
             Set_Vessel_Value(100);
             Set_Vessel_Weight(250);
             Set_Vessel_Volume(500);
             break;
        case TAM_MEDIANA:
             str_tam = "mediana";
             Set_Vessel_Value(200);
             Set_Vessel_Weight(400);
             Set_Vessel_Volume(1000);
             break;
        case TAM_GRANDE:
             str_tam = "grande";
             Set_Vessel_Value(400);
             Set_Vessel_Weight(700);
             Set_Vessel_Volume(2000);
             break;
    }

    switch(forma)
    {
        case FORMA_CUADRADA: str_form = "cuadrada"; break;
        case FORMA_REDONDA: str_form = "redonda"; break;
    }
    Set_Vessel_Name("botella " + str_tam);
    SetLong("Es una botella " + str_tam + " de vino, con forma " + str_form + ". "
            "Lleva pegada una etiqueta que podrías leer.\n");
    SetFoodMsg1("Tomas un gran trago de vino.");
    SetFoodMsg2("toma un gran trago de vino.");
    SetFoodHeal(10);
    SetFoodAlc(70);
    Set_Vessel_Gender(GENDER_FEMALE);
    AddId(({"botella", "vino", "botella " + str_form, "botella " + str_tam, "vino_bodegas_nandor"}));
    AddSubReadMsg("etiqueta", "En la etiqueta puedes leer:\n" +
                           TC_RED + "VINO DE LAS BODEGAS DE NANDOR, COSECHA DEL AÑO " +
                           (CHRONOS->QueryYear() - (1 + random(5))) + "\n\n" +
                           TC_NORMAL);

}
