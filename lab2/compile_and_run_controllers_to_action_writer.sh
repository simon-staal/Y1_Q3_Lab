#!/bin/bash

set -e

g++ controller_brownian.cpp -o ./controller_brownian_to_action_writer
g++ controller_circle.cpp -o ./controller_circle_to_action_writer
g++ controller_spiral.cpp -o ./controller_spiral_to_action_writer

./controller_brownian_to_svg_writer > controller_brownian.actions
./controller_circle_to_svg_writer > controller_circle.actions
./controller_spiral_to_svg_writer > controller_spiral.actions

echo "Success"
