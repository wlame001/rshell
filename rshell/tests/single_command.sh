#!/bin/bash

../bin/./a.out <<< "ls"
./a.out <<< "echo helloworld"
./a.out <<< "mkdir testdir"
./a.out <<< "ls -h"