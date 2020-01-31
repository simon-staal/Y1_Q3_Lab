#include "rover_action_writer.hpp"
#include "rover_svg_writer.hpp"

Rover *rover_factory(const string &type)
{
  if(type == "svg"){
    Rover *r =  new RoverSVGWriter;
    return r;
  }
  if(type == "action"){
    Rover *r = new RoverActionWriter;
    return r;
  }
  else{
    std::cerr<<"invalid input";
    exit(1);
  }
}
