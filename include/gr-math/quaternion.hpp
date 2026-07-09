#pragma once

#include "quat_operator.inl"

/*
* (W) O componente w do quatérnion, que é a parte do número real do quatérnion.
* (X) O componente x do quatérnion, que é o coeficiente do vetor de unidade i no quatérnion.
* (Y) O componente y do quatérnion, que é o coeficiente do vetor de unidade j no quatérnion.
* (Z) O componente z do quatérnion, que é o coeficiente do vetor de unidade k no quatérnion.
*/

template <typename T>
struct type_traits<quaternion<T>>
{
    static constexpr quaternion<T> identity =
        { T(1),  T(0),  T(0),  T(0) };

    static constexpr quaternion<T> zero =
        { T(0),  T(0),  T(0),  T(0) };
};





