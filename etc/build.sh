#!/bin/bash

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
