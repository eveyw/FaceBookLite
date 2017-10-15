 #ifndef FBLPOSTLL_H
 #define FBLPOSTLL_H

 #include"FBLPost.h"

 class FBLPostLL
 {
     private:
         FBLPost* Data;
         FBLPostLL* Next;
     public:
         FBLPostLL();
         FBLPostLL(FBLPost* post);
         ~FBLPostLL();
         void InsertPost(string text);
         void DeleteTop();
         void ReadPost();
 };

 #endif
