 #ifndef FBLPOST_H
 #define FBLPOST_H

 #include<iostream>
 #include<string>
 #include"FBLCommentLL.h"
 using namespace std;

 class FBLPost{
     private:
         string Text;
         int Like;
         FBLCommentLL ComList;
     public:
         FBLPost(const string & str);
         friend ostream & operator << (ostream &out, FBLPost &post);
         int GetLike();
         void AddLike();
         void Comment(const string & text);
         void ReadAZ();
         void ReadZA();
 };

 #endif
