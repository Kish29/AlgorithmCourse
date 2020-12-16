CC := g++
CXX := g++
CPPFLAGS := -mabi=lp64 -march=armv8-a --std=c++11

.PHONY : target clean

target: NQueens.h
	$(CC) $(CPPFLAGS) NQueens.cpp -o target

clean:
	rm -rf target*
