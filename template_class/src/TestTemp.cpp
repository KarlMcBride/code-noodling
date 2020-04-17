// TestTemp.cpp
#include "TestTemp.hpp"

template <class T>
TestTemp<T>::TestTemp()
{
}

template <class T>
void TestTemp<T>::SetValue( T obj_i )
{
}

template <class T>
T TestTemp<T>::Getalue()
{
    return m_Obj;
}

// No need to call this TemporaryFunction() function,
// it's just to avoid link error.
void TemporaryFunction ()
{
    TestTemp<int> TempObj;
}