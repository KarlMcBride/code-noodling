#ifndef __CONCRETE_PEN_STATES_HPP__
#define __CONCRETE_PEN_STATES_HPP__

#include "pen_states.hpp"
#include "pen.hpp"

class PenBallpointRetracted : public PenState
{
    public:
        void OnEnter(Pen* pen) {}
        void Click(Pen* pen);
        void Snap(Pen* pen);
        void OnExit(Pen* pen) {}
        static PenState& getInstance();

    private:
        PenBallpointRetracted() {}
        PenBallpointRetracted(const PenBallpointRetracted& other);
        PenBallpointRetracted& operator=(const PenBallpointRetracted& other);
};

class PenBallpointExtended : public PenState
{
    public:
        void OnEnter(Pen* pen) {}
        void Click(Pen* pen);
        void Snap(Pen* pen);
        void OnExit(Pen* pen) {}
        static PenState& getInstance();

    private:
        PenBallpointExtended() {}
        PenBallpointExtended(const PenBallpointExtended& other);
        PenBallpointExtended& operator=(const PenBallpointExtended& other);
};

class PenSnapped : public PenState
{
    public:
        void OnEnter(Pen* pen) {}
        void Click(Pen* pen);
        void Snap(Pen* pen);
        void OnExit(Pen* pen) {}
        static PenState& getInstance();

    private:
        PenSnapped() {}
        PenSnapped(const PenSnapped& other);
        PenSnapped& operator=(const PenSnapped& other);
};

#endif // __CONCRETE_PEN_STATES_HPP__