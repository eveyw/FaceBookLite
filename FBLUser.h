 #ifndef FBLUSER_H
 #define FBLUSER_H

 #include<iostream>
 #include<string>
 #include<vector>
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
          FBLPostLL WallList;
          vector<FBLUser*> FriendList;
     public:
          FBLUser(const string & _Uid,const string & _Psd,const string & _First,const string & _Last);
          bool CheckPsd(const string & _Psd);
          bool CheckUid(const string & _Uid);
          FBLPost* ReadTop();
          void Post(const string & text);
          bool AddFriend(FBLUser* user);
          void ListFriend();
          void AllWall();
          void AllPost();
          string GetLast();
          friend ostream & operator << (ostream &out, FBLUser &user);
 };

 #endif // FBLUSER_H
