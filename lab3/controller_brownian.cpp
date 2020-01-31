#include "rover.hpp"
#include "rover_svg_writer.hpp"
#include "rover_factory.hpp"

#include <cmath>
#include <random>

int main(int argc, const char **argv)
{
    // This object represents a random number generator
    mt19937 rng;
    rng.seed(time(0)); // Randomises based on the current time

    // An object representing the gaussian distribution
    normal_distribution<> normal_dist(0,0.04);

    float PI=3.14159265;

    string input;
    if(argc == 1){
      input = "svg";
    }else{
      input = argv[1];
    }
    Rover *concrete_r = rover_factory(input);
    Rover &r = *concrete_r;

    r.set_pen_down(true);

    float dt=0.1;
    while(r.get_time() < 100){
        // Generate a pair of gaussian distributed random steps in x and y
        float dx = normal_dist(rng);
        float dy = normal_dist(rng);

        // recover the angle using tan
        float angle = atan2(dx, dy);
        // get the distance travelled
        float distance = sqrt(dx*dx + dy*dy);

        r.set_speed( distance/dt );
        r.set_angle(angle);
        r.advance_time( dt );
    }
    delete &r;
}
