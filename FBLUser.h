 #ifndef FBLUSER_H
 #define FBLUSER_H

 #include<iostream>
 #include<string>
 #include"FBLPostLL.h"
 using namespace std;

 class FBLUser
 {
     private:
          string Userid;
          string Password;
          string First;
          string Last;
          FBLPostLL PostList;
     public:
          FBLUser(const string & _Uid,const string & _Psd,const string & _First,const string & _Last);
          bool CheckPsd(const string & _Psd);
          bool CheckUid(const string & _Uid);
          void ReadTop();
          void Post(const string & text);
 };

 #endif // FBLUSER_H
