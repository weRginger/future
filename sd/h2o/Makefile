CC=g++
CFLAGS=-std=c++11 -pthread

all: 
	$(CC) $(CFLAGS) h2o-v1.cpp -o h2o-v1
	$(CC) $(CFLAGS) h2o-v2.cpp -o h2o-v2
	$(CC) $(CFLAGS) h2o-v3.cpp -o h2o-v3

.PHONY: clean

clean:
	rm h2o-v1 h2o-v2 h2o-v3
