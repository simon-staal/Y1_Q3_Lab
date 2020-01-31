#!/bin/bash

set -e

echo "Compiling..."

g++ controller_spiral.cpp rover_svg_writer.cpp vector2d.cpp rover_action_writer.cpp rover_factory.cpp -o controller_spiral
g++ controller_circle.cpp rover_svg_writer.cpp vector2d.cpp rover_action_writer.cpp rover_factory.cpp -o controller_circle
g++ controller_brownian.cpp rover_svg_writer.cpp vector2d.cpp rover_action_writer.cpp rover_factory.cpp -o controller_brownian

echo "Compiled successfully"
echo "Capturing output..."

./controller_brownian > controller_brownian.svg
./controller_circle > controller_circle.svg
./controller_spiral > controller_spiral.svg

./controller_brownian action > controller_brownian.action
./controller_circle action > controller_circle.action
./controller_spiral action > controller_spiral.action

echo "Output captured"
echo "Comparing..."

diff controller_brownian.svg controller_brownian.ref.svg
diff controller_spiral.svg controller_spiral.ref.svg
diff controller_circle.svg controller_circle.ref.svg

diff controller_brownian.action controller_brownian.ref.action
diff controller_spiral.action controller_spiral.ref.action
diff controller_circle.action controller_circle.ref.action

echo "Success"
