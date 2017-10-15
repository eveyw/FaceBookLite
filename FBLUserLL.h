 #ifndef FBLUSERLL_H
 #define FBLUSERLL_H

 #include"FBLUser.h"

 class FBLUserLL
 {
     private:
         FBLUser* Data;
         FBLUserLL* Next;
     public:
         FBLUserLL();
         ~FBLUserLL();
         FBLUserLL(FBLUser* _data);
         FBLUser* LogIn(const string & _uid);
         bool CheckUid(const string & _uid);
         bool InsertUser(const string & _Uid,const string & _Psd,const string & _First,const string & _Last);
 };
 #endif // FBLUSERLL_H

