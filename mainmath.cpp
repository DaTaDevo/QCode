#include "mainmath.h"
#include <QDebug>

namespace myMath  {

    myMath::Triangle myMath::ForwardTriangleSide(myMath::Triangle data)
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
            output.strError = "Треугольника не существует";
        }

        return output;
    }
}
