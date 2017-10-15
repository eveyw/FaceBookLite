 #include"FBLUser.h"
 FBLUser::FBLUser(const string & _Uid,const string & _Psd,const string & _First,const string & _Last)
 {
     Userid=_Uid;
     Password=_Psd;
     First=_First;
     Last=_Last;
 }
 bool FBLUser::CheckPsd(const string & _Psd)
 {
     return(Password==_Psd);
 }
 bool FBLUser::CheckUid(const string & _Uid)
 {
     return(Userid==_Uid);
 }
 void FBLUser::ReadTop()
 {
     PostList.ReadPost();
 }
 void FBLUser::Post(const string & text)
 {
     PostList.InsertPost(text);
 }
