// Source: https://aleksandrhovhannisyan.github.io/blog/dev/finite-state-machine-fsm-tutorial-implementing-an-fsm-in-c/

#include <iostream>

#include "pen.hpp"
#include "concrete_pen_states.hpp"

Pen::Pen()
{
    // All pens are initially turned off
    currentState = &PenBallpointRetracted::getInstance();
}

void Pen::SetState(PenState& newState)
{
    currentState->OnExit(this);  // do stuff before we change state
    currentState = &newState;  // actually change states now
    currentState->OnEnter(this); // do stuff after we change state
}

void Pen::Click()
{
    // Delegate the task of determining the next state to the current state
    currentState->Click(this);
}

void Pen::Snap()
{
    // Delegate the task of determining the next state to the current state
    currentState->Snap(this);
}