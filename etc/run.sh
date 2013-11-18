#!/bin/bash

#
# Copyright (C) 2013 Sergio Rodrigo
#
# This software may be modified and distributed under the terms
# of the MIT license. See the LICENSE file for details.
#

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`/../lib/

release_config="config=Release"
config="Debug"
if [ "$1" = "--$release_config" ]; then
	config="Release"
fi
cd ../bin/$config/ && ./test
