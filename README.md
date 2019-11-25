# Calculator
[![Build Status](https://github.com/RomainL972/Calculator/workflows/C/C++%20CI/badge.svg)](https://github.com/RomainL972/Calculator/actions)

This is an arbitrary-precision calculator

## Building
This project uses cmake
```
mkdir build
cd build
cmake ..
make -j(number of cores+1)
```

## Testing
I use my own php script for testing, tests.php
```
../tests.php
```

## Running
```
./Calculator 0123456789
1+1
```
