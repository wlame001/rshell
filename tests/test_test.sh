#!/bin/bash

../bin/./a.out <<< "test -e test/file/path || echo helloworld"
../bin/./a.out <<< "[ -e test/file/path ] || echo helloworld"
../bin/./a.out <<< "[ test/file/path ] || echo helloworld"
mkdir b
../bin/./a.out <<< "[ ../tests ] || echo helloworld"
../bin/./a.out <<< "[ b ]"