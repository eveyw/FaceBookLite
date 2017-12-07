 #ifndef FBLCOMMENT_H
 #define FBLCOMMENT_H

 #include<iostream>
 #include<string>
 using namespace std;

 class FBLComment{
     private:
         string Text;
     public:
         FBLComment(const string & str);
         friend ostream & operator << (ostream &out, FBLComment &com);
 };

 #endif
