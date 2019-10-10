#!/bin/sh

# set the project directory

PROJECT_DIR=$(pwd)

# delete the project directory
if [ -d build ]; then
    echo "Deleting build directory"
    cd build;
    make distclean;
    cd ${PROJECT_DIR};
    rm -R build;
fi

echo "Creating new build directory"
mkdir build
echo "Running autogen.sh"
./autogen.sh
echo "Configuring project"
cd build
../configure --enable-debug --enable-tests
make check

