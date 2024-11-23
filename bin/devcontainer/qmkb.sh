#!/bin/bash

# Set default build target 
build_kb="${BUILD_DEF_KB}"
build_km="${BUILD_DEF_KM}"

while getopts "b:m:" opt; do
  case $opt in
    b) build_kb=$OPTARG;;
    m) build_km=$OPTARG;;
    
    \?) exit 1;;
    :) exit 1;;
  esac
done

# Get build target from current path, if matched.
pattern="^${WORKSPACE_FOLDER}(/([^/]+/[^/]+))?(/keymaps/([^/]+))?"
if [[ $(pwd) =~ ${pattern} ]]; then
  if [[ ${BASH_REMATCH[2]} ]]; then
    build_kb=${BASH_REMATCH[2]}
  fi
  if [[ ${BASH_REMATCH[4]} ]]; then
    build_km=${BASH_REMATCH[4]}
  fi
fi

# Execute Build & Copy
echo "Build target: keyboard=${build_kb} / keymap=${build_km}"
read -p "Do you want to proceed? (Y/n): " response
response=${response:-Y}
if [[ "${response}" =~ ^[Yy]$ ]]; then
  qmk compile -j 4 -kb ${build_kb} -km ${build_km}
  if [[ $? -eq 0 ]]; then
    cp "${WORKSPACE_FOLDER}/../.build/${build_kb//\//_}_${build_km}.hex" "${WORKSPACE_FOLDER}/release/"
  fi
fi
