/****************************************************************************
fichero: _sed.c
autor: kastwey@simauria
Descripci�n: Devuelve el nivel de sed del jugador.
Creaci�n: 23/01/2006
****************************************************************************/


#define MSG_SPEAK "all_speak:"
#define AO TP->QueryGenderEndString()


public int main()
{
    int i = (TP->QueryDrink()*100) / (TP->QueryMaxDrink()||1);
    string bebida;
    switch(i)
    {
        case 90..101:
             bebida = "No puedes beber nada m�s.";
             break;
        case 75.. 89:
             bebida = "Has bebido bastante.";
             break;
        case 50.. 74:
             bebida = "No tienes sed.";
        case 25.. 49:
             bebida = "Deber�as beber algo.";
        case 10.. 24:
             bebida = "Tienes la boca reseca.";
             break;
        case  0.. 9:
             bebida = "Tienes sed.";
             break;
        default:
             i = TP->QueryDrink();
             switch(i)
             {
                 case -10 .. -1:
                      bebida = "Tienes mucha sed.";
                      break;
                 case -50 .. -11:
                      bebida = "Podr�as beberte un barril.";
                      break;
                 case -250 .. -51:
                      bebida = "Tu boca parece un desierto.";
                      break;
                 case -500 .. -251:
                      bebida = "Te est�s muriendo de sed.";
                      break;
                 default:
                      bebida = "Est�s muy sedient" + AO + " (" + i + ").";
             }
    }
    write((TP->QueryTiflo() ? MSG_SPEAK : "") + bebida + "\n");
    return 1;
}