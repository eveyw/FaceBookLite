 #ifndef FBLPOST_H
 #define FBLPOST_H

 #include<iostream>
 #include<string>
 using namespace std;

 class FBLPost{
     private:
         string Text;
         //int Like
     public:
         FBLPost(const string & str);
         friend ostream & operator << (ostream &out, FBLPost &post);
 };

 #endif
