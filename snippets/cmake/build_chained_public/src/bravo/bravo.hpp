#ifndef __BRAVO_HPP
#define __BRAVO_HPP

#include "charlie.hpp"

class bravo
{
    public:
        bravo();
        ~bravo();

        void print(void);
        void call_chain(void);
    private:
        charlie m_charlie;
};
#endif // __BRAVO_HPP