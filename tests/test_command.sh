#!/bin/bash

#../bin/./a.out <<< "test -e test/file/path || echo helloworld"
../bin/./a.out <<< "[ -e test/file/path ] || echo helloworld"