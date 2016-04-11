.PHONY: test

test:
	g++ test.cpp Argparse.cpp -std=c++11 -o test_argparse
	bash test.sh

