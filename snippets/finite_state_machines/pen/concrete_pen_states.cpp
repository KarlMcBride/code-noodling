#include <iostream>

#include "concrete_pen_states.hpp"

void PenBallpointRetracted::Click(Pen* pen)
{
    std::cout << "Retracted -> Extended" << std::endl;
    pen->SetState(PenBallpointExtended::getInstance());
}

void PenBallpointRetracted::Snap(Pen* pen)
{
    std::cout << "Retracted -> Snapped" << std::endl;
    pen->SetState(PenSnapped::getInstance());
}

PenState& PenBallpointRetracted::getInstance()
{
    static PenBallpointRetracted singleton;
    return singleton;
}

void PenBallpointExtended::Click(Pen* pen)
{
    std::cout << "Extended -> Retracted" << std::endl;
    pen->SetState(PenBallpointRetracted::getInstance());
}

void PenBallpointExtended::Snap(Pen* pen)
{
    std::cout << "Extended -> Snapped" << std::endl;
    pen->SetState(PenSnapped::getInstance());
}

PenState& PenBallpointExtended::getInstance()
{
    static PenBallpointExtended singleton;
    return singleton;
}

void PenSnapped::Click(Pen* pen)
{
    std::cout << "Snapped!" << std::endl;
}

void PenSnapped::Snap(Pen* pen)
{
    std::cout << "Already Snapped" << std::endl;
}

PenState& PenSnapped::getInstance()
{
    static PenSnapped singleton;
    return singleton;
}
