#!/bin/bash

./a.out <<< "ls -a || echo helloworld"
./a.out <<< "lv || echo helloworld"
./a.out <<< "echo pass1; echo pass2 && echo pass3 || echo fail1 || echo pass4"
./a.out <<< "ech fail1 || echo pass1 ; echo pass2 && echo pass3 || echo fail2"