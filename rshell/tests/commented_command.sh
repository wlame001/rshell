#!/bin/bash

./a.out <<< "ls -a #this will not be executed"
./a.out <<< "#entire command is empty"
./a.out <<< "#echo fail"
./a.out <<< "ech fail1 || echo pass1 ; echo pass2 && echo pass3 || echo fail2"