#ifndef __ALPHA_HPP
#define __ALPHA_HPP

#include "bravo.hpp"

// Note - Charlie call is possible without explicit include as it is obtained
// by including bravo.hpp.

class alpha
{
    public:
        alpha();
        ~alpha();

        void print(void);
        void call_chain(void);

    private:
        bravo m_bravo;
        charlie m_charlie;
};

#endif // __ALPHA_HPP