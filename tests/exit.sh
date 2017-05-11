#!/bin/bash
./a.out <<< "exit"
./a.out <<< "ls exit"
./a.out <<< "ls -a && echo helloworld; exit"