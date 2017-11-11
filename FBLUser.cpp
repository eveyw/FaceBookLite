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
 FBLPost* FBLUser::ReadTop()
 {
     return(PostList.ReadPost());
 }
 void FBLUser::Post(const string & text)
 {
     unsigned i;
     FBLPost* tmp;
     tmp=WallList.InsertPost(text);
     for(i=0;i<FriendList.size();i++)
     {
         FriendList[i]->PostList.InsertPost(tmp);
     }
 }
 bool FBLUser::AddFriend(FBLUser* user)
 {
     unsigned i;
     if(this==user) return false;
     for(i=0;i<FriendList.size();i++)
     {
         if(FriendList[i]==user)
         {
             return false;
         }
     }
     FriendList.push_back(user);
     user->FriendList.push_back(this);
     return true;
 }
 void FBLUser::ListFriend()
 {
     unsigned i;
     for(i=0;i<FriendList.size();i++)
     {
         cout<<FriendList[i]->First<<" "<<FriendList[i]->Last<<endl;
     }
 }
 void FBLUser::AllWall()
 {
     WallList.ReadAllPost(1);
 }

 void FBLUser::AllPost()
 {
     PostList.ReadAllPost();
 }

 string FBLUser::GetLast()
 {
     return(Last);
 }

 ostream & operator << (ostream &out, FBLUser &user)
 {
     out<<user.Last<<", "<<user.First<<" <"<<user.Userid<<">";
     return out;
 }
