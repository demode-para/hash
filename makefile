game.exe : 
	g++ Index.cpp -o game.exe

clean :
	rm -f *.exe

build : game.exe
	echo "building"