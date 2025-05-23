#!/usr/bin/env bash

################################################################################
## @title Initialization
################################################################################

set -euo pipefail

################################################################################
## @title Functions
################################################################################

usage() {
	cat <<-TXT
		Usage: $0 [-b BUILD_TOOL] [-c]
			-b BUILD_TOOL  Build tool to use (cmake|qmake). Default is cmake.
			-c             Clean before building.
		TXT
}

################################################################################
## @title Arguments
################################################################################

build_tool="cmake"
clean_build=false

while getopts ":b:ch" opt; do
	case "$opt" in
		b)
			build_tool=$OPTARG
			;;
		
		c)
			clean_build=true
			;;
		
		h)
			usage
			exit 0
			;;
		
		\?)
			echo "Invalid option: -$OPTARG" >&2
			usage
			exit 1
			;;
		
		:)
			echo "Option -$OPTARG requires an argument." >&2
			usage
			exit 1
			;;
	esac
done

################################################################################
## @title Script
################################################################################

script_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

cd "$script_dir" || { echo "Can't enter $script_dir" >&2; exit 1; }

nb_procs=$(nproc)

case "$build_tool" in
	cmake)
		echo "[INFO] Building with CMake..."

		if [[ $clean_build == true ]]; then
			echo "[INFO] Cleaning..."
			
			rm -rf build/
		fi

		cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
		cmake --build build -j "$nb_procs"
		cp build/compile_commands.json .
		cp build/guid .
		;;

	qmake)
		echo "[INFO] Building with qmake..."

		if [[ $clean_build == true ]]; then
			echo "[INFO] Cleaning..."
			
			make distclean || true
		fi

		qmake guid.pro
		make -j "$nb_procs"
		;;

	*)
		usage
		exit 1
		;;
esac
