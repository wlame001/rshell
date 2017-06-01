#!/bin/bash

../bin/./a.out <<< "(echo hello)"
../bin/./a.out <<< "echo A || echo B || echo C)"
../bin/./a.out <<< "(test -e test/file/path || (echo helloworld)) || echo helloworld2"
