clean:
	if [ -f bin/testBasicMath ]; then rm bin/testBasicMath; rm out/CBasicMath.o; fi

out/CBasicMath.o : src/CBasicMath.cpp src/CBasicMath.hpp
	g++ -c src/CBasicMath.cpp -lapr-1 -laprutil-1 -llog4cxx -o out/CBasicMath.o

bin/testBasicMath : out/CBasicMath.o src/TestBasicMath.cpp
	g++ -fPIC -o bin/testBasicMath out/CBasicMath.o src/TestBasicMath.cpp -lcppunit -lapr-1 -laprutil-1 -llog4cxx
 
all : bin/testBasicMath
	cp config/* bin;cd bin;./testBasicMath
