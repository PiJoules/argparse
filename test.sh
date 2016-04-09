#!/usr/bin/env bash

g++ *.cpp -o test_argparse -std=c++11
./test_argparse arg1

if [ "$?" != "0" ]; then
    echo "Test failed"
    exit 1;
else
    echo "Success!"
fi

