#ifndef __PEN_HPP__
#define __PEN_HPP__

#include "pen_states.hpp"

class Pen
{
    public:
        Pen();
        PenState* GetCurrentState() const { return currentState; }
        void Click();
        void Snap();
        void SetState(PenState& newState);

    private:
        PenState* currentState;
};

#endif // __PEN_HPP__