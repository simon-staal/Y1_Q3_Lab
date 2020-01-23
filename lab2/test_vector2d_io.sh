#!/bin/bash

set -e

g++ test_vector2d.cpp -o ./test_vector2d

<test_vector2d_io_in.txt ./test_vector2d >test_vector2d_io_out.txt

diff test_vector2d_io_out.txt test_vector2d_io_out_ref.txt

echo "Success"
