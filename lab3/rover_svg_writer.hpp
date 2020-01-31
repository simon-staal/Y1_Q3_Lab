#ifndef rover_svg_writer_hpp
#define rover_svg_writer_hpp

#include "vector2d.hpp"
#include "rover.hpp"

class RoverSVGWriter
  : public Rover
{
private:

public:
    RoverSVGWriter();
    ~RoverSVGWriter();

    ////////////////////////////////////////
    // Find out the state of the rover.

    ///////////////////////////////////////////
    // Manage state and time

    // Advance the rover forwards in time by `dt`, i.e. move to `get_time()+dt`
    // The rover will move at the current speed and angle for that time period.
    void advance_time(float dt);
};

#endif
