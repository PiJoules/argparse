#!/usr/bin/env bash

g++ *.cpp -o test_argparse -std=c++11
./test_argparse arg1 --opt1 opt1_arg

if [ "$?" != "0" ]; then
    echo "Test failed"
    exit 1;
else
    echo "Success!"
fi

