#!/bin/bash

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`/../lib/

release_config="config=Release"
config="Debug"
if [ "$1" = "--$release_config" ]; then
	config="Release"
fi
cd ../bin/$config/ && ./test
