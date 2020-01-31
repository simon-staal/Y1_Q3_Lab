#ifndef rover_action_writer_hpp
#define rover_action_writer_hpp

#include "vector2d.hpp"
#include "rover.hpp"

class RoverActionWriter : public Rover
{
private:

public:
    RoverActionWriter();
    ~RoverActionWriter();

    ////////////////////////////////////////
    // Find out the state of the rover.

    ///////////////////////////////////////////
    // Manage state and time

    // Advance the rover forwards in time by `dt`, i.e. move to `get_time()+dt`
    // The rover will move at the current speed and angle for that time period.
    void advance_time(float dt);
};

#endif
