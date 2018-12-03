#ifndef MAINMATH_H
#define MAINMATH_H

//#include <math.h>
#include <string>

namespace  myMath  {

    class Triangle
    {
            public :
            double ab,bc,ac; // стороны треугольника
            double a,b,c; // углы треугольника
            std::string strError; // сообщение об ошибке
            std::string msg; // сообщение для пользователя напимер ход решения задачи
            bool err; // указывает есть ошибка или нет
            const Triangle *inData = nullptr; // здесь хранятся входные данные
            private :
    };
   Triangle SearchAnglesTriangle(Triangle search);
   Triangle SaerchPartiesTriangle(Triangle search);
   Triangle SearchSideVersatile();
   Triangle ForwardTriangleSide(Triangle data);
}

#endif // MAINMATH_H
