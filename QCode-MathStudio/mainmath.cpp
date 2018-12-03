#include "mainmath.h"

#include <ostream>
#include <string>
#include <math.h>
#include <cmath>

namespace myMath
{
    /// Поиск углов треугольника (пока не реализовано)
    Triangle SearchAnglesTriangle(Triangle search)
    {
        Triangle tmpData;
        tmpData.inData = &search;
/*
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
            }*/

            tmpData.b = search.b;
            tmpData.ab = search.ab;
            tmpData.ac = search.ac;
            tmpData.bc = search.bc;
            tmpData.c = search.c;
            return tmpData;
     }

    /// Поиск неизвестных сторон произвольного треугольника
    Triangle SaerchPartiesTriangle(Triangle search)
    {
        Triangle tmpData;
        tmpData.err = false;
        tmpData.inData = &search;
//TODO  проверка углов
        if (search.a + search.b + search.c > 180 )
        {
                tmpData.strError = "Сумма углов треугольника больше 180!";
                tmpData.err = true;
        }
        if( search.a + search.b + search.c < 180 )
        {
            tmpData.strError = "Сумма углов треугольника меньше 180!";
            tmpData.err = true;
        }
        else
     {
        // по теореме косинусов (через две стороны и угол)
        if (search.ab == 0.0 && search.ac > 0 && search.bc > 0 && search.c > 0) {
            // ищем сторону ab
            tmpData.ab = sqrt(pow(search.ac, 2) + pow(search.bc, 2) - 2 * search.ac * search.bc * (cos(search.c) < 0 ? cos(search.c)*-1 : cos(search.c)));
            tmpData.msg = "По теореме косинусов сторора AB = %g", search.ab;
        } else if (search.bc == 0.0 && search.ac > 0 && search.ab > 0 && search.a > 0) {
            // ищем сторону bc
            tmpData.bc = sqrt(pow(search.ac, 2) + pow(search.ab, 2) - 2 * search.ac * search.ab * (cos(search.a) < 0 ? cos(search.a)*-1 : cos(search.a)));
            tmpData.msg = "По теореме косинусов сторора BC = %g", search.bc;
        } else if (search.ac == 0.0 && search.bc > 0 && search.ab > 0 && search.b > 0) {
            // ищем сторону ac
            tmpData.ac = sqrt(pow(search.bc, 2) + pow(search.ab, 2) - 2 * search.bc * search.ab * (cos(search.b) < 0 ? cos(search.b)*-1 : cos(search.b)));
            tmpData.msg = "По теореме косинусов сторора AC = %g", search.ac;
        }

        // по теореме синусов (через два угла и одну сторону)
        if (search.ab == 0.0 && search.ac > 0 && search.bc == 0.0 && search.c > 0 && search.b > 0) {
            // ищем сторону ab
            tmpData.ab = search.ac * sin(search.c)/sin(search.b);
            tmpData.msg = "По теореме синусов сторора AB = %g", search.ab;
        } else if (search.bc == 0.0 && search.ac == 0.0 && search.ab > 0.0 && search.c > 0 && search.a > 0) {
            // ищем сторону bc
            tmpData.bc = search.ab * sin(search.a)/sin(search.c);
            tmpData.msg = "По теореме синусов сторора BC = %g", search.bc;
        } else if (search.ac == 0.0 && search.bc > 0 && search.ab == 0.0 && search.b > 0 && search.c > 0) {
            // ищем сторону ac
            tmpData.ac = search.bc * sin(search.b)/sin(search.c);
            tmpData.msg = "По теореме синусов сторора AC = %g", search.ac;
        }
}
        //tmpData.a = search.a;
        //tmpData.ab = search.ab;
        //tmpData.ac = search.ac;
        //tmpData.b = search.b;
        return  tmpData;
    }

    Triangle SearchSideVersatile(Triangle search)
    {
        // переменная поиска
        // Формула : (a =sqrt(b^2 + c^2 - 2bc *  cos(alpha)))
        //  тут как в примере  надо
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

    //TODO  проверка углов
        if (search.a + search.b + search.c > 180 )
        {
                tmpData.strError = "Сумма углов треугольника больше 180!";
                tmpData.err = true;
        }
        if( search.a + search.b + search.c < 180 )
        {
            tmpData.strError = "Сумма углов треугольника меньше 180!";
            tmpData.err = true;
        }
        else
     {
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

        if (output.a + output.b + output.c > 180 )
        {
                output.strError = "Сумма углов треугольника больше 180!";
                output.err = true;
        }
        if( output.a + output.b + output.c < 180 )
        {
            output.strError = "Сумма углов треугольника меньше 180!";
            output.err = true;
        }
        else
     {
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

    }
        return output;
    }
}
