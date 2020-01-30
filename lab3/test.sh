#!/bin/bash

set -e

g++ controller_spiral.cpp rover_svg_writer.cpp vector2d.cpp rover_action_writer.cpp rover_factory.cpp -o controller_spiral_to_svg_writer
g++ controller_circle.cpp rover_svg_writer.cpp vector2d.cpp rover_action_writer.cpp rover_factory.cpp -o controller_circle_to_svg_writer
g++ controller_brownian.cpp rover_svg_writer.cpp vector2d.cpp rover_action_writer.cpp rover_factory.cpp -o controller_brownian_to_svg_writer

./controller_brownian_to_svg_writer > controller_brownian.svg
./controller_circle_to_svg_writer > controller_circle.svg
./controller_spiral_to_svg_writer > controller_spiral.svg

diff controller_brownian.svg controller_brownian.ref.svg
diff controller_spiral.svg controller_spiral.ref.svg
diff controller_circle.svg controller_circle.ref.svg

echo "Success"
