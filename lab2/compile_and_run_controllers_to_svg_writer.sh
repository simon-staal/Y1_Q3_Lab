#!/bin/bash

set -e

g++ controller_brownian.cpp -o ./controller_brownian_to_svg_writer
g++ controller_circle.cpp -o ./controller_circle_to_svg_writer
g++ controller_spiral.cpp -o ./controller_spiral_to_svg_writer

./controller_brownian_to_svg_writer > controller_brownian.svg
./controller_circle_to_svg_writer > controller_circle.svg
./controller_spiral_to_svg_writer > controller_spiral.svg

echo "Success"
