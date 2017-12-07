 #ifndef FBLCOMMENTLL_H
 #define FBLCOMMENTLL_H

 #include"FBLComment.h"

 class FBLCommentLL
 {
     private:
         FBLComment* Data;
         FBLCommentLL* Next;
         FBLCommentLL* Prev;
     public:
         FBLCommentLL();
         FBLCommentLL(FBLComment* com);
         ~FBLCommentLL();
         void Insert(string text);
         void ReadAtoZ();
         void ReadZtoA();
 };

 #endif
