#!/bin/bash

set -e

g++ house.cpp -o ./house
g++ spiral.cpp -o ./spiral

./house > house.gov.svg
./spiral > spiral.gov.svg

diff house.gov.svg house.ref.svg
diff spiral.gov.svg spiral.gov.svg
