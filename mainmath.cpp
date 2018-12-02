#include "mainmath.h"
#include <QDebug>
#include "math.h"

namespace myMath  {
    Triangle SearchSideRight()
    {
        Triangle search;
        Triangle tmpData;

            if (search.ac == 0)
            {
                if (search.bc > 0)
                {

                    if (search.ab > 0)
                    {
                        search.ab = sqrt(search.bc* search.bc - search.ab * search.ab);
                    }

                    if (search.c > 0)
                    {
                        search.ac = search.bc * cos(search.c);
                    }
                    if (search.b > 0)
                    {
                        search.ac = search.bc* sin(search.b);
                    }
                }
                if (search.ab >0 && search.b > 0)
                {
                    search.ac = search.ab * tan(search.b);
                }

            }

            if (search.ab == 0)
            {
                if (search.bc > 0)
                {
                    if (search.ac > 0)
                    {
                        search.ab = sqrt(search.bc* search.bc - search.ac * search.ac);
                    }
                    if (search.c > 0)
                    {
                        search.ab = search.bc * cos(search.b);
                    }
                    if (search.b > 0)
                    {
                        search.ab = search.bc* sin(search.b);
                    }
                }
                if (search.ac >0 && search.c > 0)
                {
                    search.ab = search.ac * tan(search.b);
                }
            }

            if (search.bc == 0)
            {
                if (search.ac > 0)
                {
                    if (search.b > 0)
                    {
                        search.bc = search.ac / sin(search.b);
                    }
                    if (search.c > 0)
                    {
                        search.bc = search.ac / cos(search.c);
                    }
                }

                if (search.ab > 0)
                {
                    if (search.b > 0)
                    {
                        search.bc = search.ac / cos(search.b);
                    }
                    if (search.c > 0)
                    {
                        search.bc = search.ac / sin(search.c);
                    }
                }

               if (search.ac > 0 && search.ab > 0)
               {
                   search.bc = sqrt(search.ab * search.b + search.ac * search.ac);
               }
            }
            tmpData.b = search.b;
            tmpData.ab = search.ab;
            tmpData.ac = search.ac;
            tmpData.bc = search.bc;
            tmpData.c = search.c;
            return tmpData;
     }

    Triangle SearchSideIsosceles()
    {
        Triangle search;
        Triangle tmpData;
        tmpData.inData = &search;
        if(search.ac == 0)
        {
            if (search.ab > 0  && search.b > 0)
            {
                search.ac = 2*search.ab*sin(search.b / 2);
            }
           if(search.ab > 0 && search.a > 0)
           {
               search.ac = 2 * search.ab * cos(search.a);
           }
        }
        if(search.ab == 0)
        {
            if (search.ac > 0 && search.b > 0)
            {
                search.ab = search.ac / 2 * sin(search.b /2);
            }
            if(search.ac > 0 && search.a > 0)
            {
                search.ab = search.ac / 2 * cos (search.a);
            }
        }

        tmpData.a = search.a;
        tmpData.ab = search.ab;
        tmpData.ac = search.ac;
        tmpData.b = search.b;
        return  tmpData;
    }
    Triangle SearchSideVersatile()
 {
 // переменная поиска
      // Формула : (a =sqrt(b^2 + c^2 - 2bc *  cos(alpha)))
      //  тут как в примере  надо
      Triangle search;
      Triangle tmpData;
      tmpData.inData = &search;
      // так программа понимает где входные данне, а где данные которые ты получаешь
       // аносишь уже tmpData.ab tmpData.ac и т.д.
      // нечего если я продолжу писать вот так - search.ab
      // просто тебе потом в конце фенкции придется делать так tmpData.ab = search.ab
    // чnобы получить результат работы функции
      // просто некоррекитно будет если в середиине другим стилем начну писать а пару строк и секунд мне не жалко
      //\ ЧТО МНЕ ПИСАТЬ В РЕТЕРН нн
      // ну тогда я пошел пелить прогу
      //  поглядуй на нижнюю функцию

      if (search.ab == 0 && search.ac > 0 && search.bc > 0 && search.c > 0)
      {
          search.ab = sqrt(search.bc*search.bc +  search.ac * search.ac - 2* search.ac * search.bc * cos(search.c));
      }

      if (search.bc == 0 && search.ab > 0 && search.ac > 0 && search.a > 0)
      {
          search.ab = sqrt(search.ab * search.ab + search.ac * search.ac - 2* search.ac * search.ab * cos(search.a));
      }

      if (search.ac == 0 && search.ab > 0 && search.bc > 0 && search.b > 0)
      {
          search.ac = sqrt(search.ab * search.ab + search.bc * search.bc - 2* search.bc * search.ab * cos(search.b));
      }

       //Формула : a = b*sin(alpha)/sin(beta)
      if (search.ab == 0 && search.ac > 0 && search.c > 0 && search.b > 0)
      {
          search.ab = search.ac * sin(search.c) / sin(search.b);
      }

      if (search.bc == 0 && search.ac > 0 && search.a > 0 && search.b > 0)
      {
          search.bc = search.ac * sin(search.a) / sin(search.b);
      }

      if (search.ac == 0 && search.ab > 0 && search.a > 0 && search.b > 0)
      {
          search.ac = search.ab * sin(search.a) / sin(search.b);
      }

      //Формула :  a = b sin(alpha)/sin(alpha + zeta)
         if (search.ab  == 0 && search.ab > 0 && search. a > 0 && search.c > 0 )
         {
            search.ab = search.ac * sin(search.c) / sin(search.c + search.a);
         }

         if (search.bc == 0 && search.ab > 0 && search. a > 0 && search.b > 0 )
         {
             search.bc = search.ac *sin(search.b) / sin(search.b + search.a);
         }

         if (search.ac == 0 && search.ab > 0 && search. c > 0 && search.b > 0 )
         {
             search.ac = search.ab *sin(search.b) / sin(search.b +  search.c);
         }

        //Формула : a = b sin (beta + zeta) /  sin beta
         if(search.ab == 0 && search.ac > 0 && search.b > 0 &&  search.a > 0)
         {
             search.ab = search.ac * sin(search.b + search.a) / sin(search.b);
         }
         if(search.bc == 0 && search.ac > 0 && search.b > 0 && search.c > 0)
         {
             search.bc = search.ac * sin(search.b + search.c) / sin(search.b);
         }

         if (search.ac == 0 && search.ab > 0 && search. a > 0 && search.c > 0 )
         {
             search.ac = search.ab *sin(search.c + search.a) / sin(search.c);
         }

        tmpData.a = search.a;
        tmpData.ab = search.ab;
        tmpData.ac = search.ac;
        tmpData.b = search.b;
        tmpData.bc = search.bc;
        tmpData.c = search.c;

      return  tmpData;
}
    Triangle ForwardTriangleSide(Triangle data)
    {
        Triangle output;

        // сохраняем входные данные
        // в дальнейшем  можно работать только с ними
        // но надо быть внимательным они не должны менятся
        output.inData = &data;
        // изначально выставляем флаг ошибки в false
        output.err = false;
        // проверка на существование треугольника по трем сторонам
        if (((output.inData->ab + output.inData->bc) > output.inData->ac)
                && ((output.inData->bc + output.inData->ac) != output.inData->ab)
                && ((output.inData->ab+output.inData->ac) != output.inData->bc))
        {
            // заполняем выходные данные
            output.ab = data.ab;
            output.bc = data.bc;
            output.ac = data.ac;
            // выводим сообщение
            // сюда можно расписывать ход решения задачи
            output.msg = "Треугольник може сущ";

        } else  {
            // заполняем выходные данные
            output.ab = data.ab;
            output.bc = data.bc;
            output.ac = data.ac;
            // если возникает ошибка при выполнении задачи надо установить влаг в true
            output.err = true;
            // при необходимости добавить описание ошибки
            output.strError = "Треугольника не существует";  }


        return output;
    }
}
