 #ifndef FBLPOSTLL_H
 #define FBLPOSTLL_H

 #include"FBLPost.h"

 class FBLPostLL
 {
     private:
         FBLPost* Data;
         FBLPostLL* Next;
         int opt;
     public:
         FBLPostLL();
         FBLPostLL(FBLPost* post);
         ~FBLPostLL();
         FBLPost* InsertPost(string text);
         void InsertPost(FBLPost* NewData);
         void DeleteTop();
         FBLPost* ReadPost();
         void ReadAllPost(int opt=0);
 };

 #endif
