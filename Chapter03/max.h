#ifndef __TEMPLATE_MAX__
#define __TEMPLATE_MAX__


#pragma once

#if 0 //C++11
template <typename T>
T max (T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}
#else //C++14
template <typename T, typename U>
inline auto max (T a, U b)
{
    return a > b ? a : b;
}

#endif

#endif
