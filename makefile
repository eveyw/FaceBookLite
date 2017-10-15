all: FaceBookLite

clean:
	rm  FaceBookLite FBLPost.o FBLPostLL.o FBLUser.o FBLUserLL.o

FBLUserLL.o: FBLUserLL.cpp
	g++ -Wall -fexceptions -g  -c FBLUserLL.cpp -o FBLUserLL.o

main.o: main.cpp
	g++ -Wall -fexceptions -g  -c main.cpp -o main.o

FaceBookLite: FBLPost.o FBLPostLL.o FBLUser.o FBLUserLL.o main.o     
	g++  -o FaceBookLite FBLPost.o FBLPostLL.o FBLUser.o FBLUserLL.o main.o     
   
