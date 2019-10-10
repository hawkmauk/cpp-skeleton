Overview
========

# Dependencies
```
$ sudo apt-get install libboost-program-options-dev libboost-base-dev libboost-test-dev
```

# Build
```
$ ./autogen.sh
$ mkdir build
$ cd build
$ ../configure
$ make
```
# Configure options

## Debugging
You can enable debugging for the executables by running configure with the ```--enable-debug``` option
```
../configure --enable-debug
```
## Integration testing
You can enable the integration test suite by running configure with the ```--enable-tests``` option
```
../configure --enable-tests
``` 
