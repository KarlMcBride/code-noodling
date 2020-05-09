#ifndef __PEN_STATES_HPP__
#define __PEN_STATES_HPP__

// Forward declaration to resolve circular dependency/include
class Pen;

class PenState
{
    public:
        virtual void OnEnter(Pen* pen) = 0;
        virtual void Click(Pen* pen) = 0;
        virtual void Snap(Pen* pen) = 0;
        virtual void OnExit(Pen* pen) = 0;
        virtual ~PenState() {}
};

#endif // __PEN_STATES_HPP__