all: isUnique check_permutation URLify

isUnique: isUnique.cpp
	g++ -o isUnique isUnique.cpp

check_permutation: check_permutation.cpp
	g++ -o check_permutation check_permutation.cpp

URLify: URLify.cpp
	g++ -o URLify URLify.cpp 