#include <config.h>
int main()
{
  write("Son las "+CHRONOS->QueryHour()+" horas "+CHRONOS->QueryMinute()+" minutos "+CHRONOS->QuerySecond()+" segundos del día "+CHRONOS->QueryDay()+" del mes "+CHRONOS->QueryMonth()+" del año "+CHRONOS->QueryYear()+".\n");
  return 1;
}
