#!/bin/bash

#
# Copyright (C) 2013 Sergio Rodrigo
#
# This software may be modified and distributed under the terms
# of the MIT license. See the LICENSE file for details.
#

debug_config="config=Debug"
release_config="config=Release"
if [ $# = 0 ]; then
	echo "Usage: $0 <target> [--config=Debug|Release]"
else
	if [ "$1" = "all" ]; then
		premake4 gmake
	fi
	
	config=$debug_config
	if [ "$2" = "--$release_config" ]; then
		config=$release_config
	fi
	config=$(echo $config| tr '[:upper:]' '[:lower:]')
	
	cd ../build && make $config $1
fi
