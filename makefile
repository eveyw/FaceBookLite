all: FaceBookLite

clean:
	rm  FaceBookLite FBLPost.o FBLPostLL.o FBLUser.o FBLUserLL.o main.o FBLComment.o FBLCommentLL.o

FBLUserLL.o: FBLUserLL.cpp
	g++ -Wall -fexceptions -g  -c FBLUserLL.cpp -o FBLUserLL.o

main.o: main.cpp
	g++ -Wall -fexceptions -g  -c main.cpp -o main.o

FaceBookLite: FBLPost.o FBLPostLL.o FBLUser.o FBLUserLL.o main.o FBLCommentLL.o FBLComment.o
	g++  -o FaceBookLite FBLPost.o FBLPostLL.o FBLUser.o FBLUserLL.o FBLCommentLL.o FBLComment.o main.o
