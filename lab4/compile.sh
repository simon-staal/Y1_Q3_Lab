#!/bin/bash

set -e

g++ process_wave.cpp  factory_parameters.cpp wave_factory.cpp  sink_factory.cpp -o process_wave

echo "Success"
