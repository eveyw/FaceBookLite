 #include<iostream>
 #include<string>
 #include<cstdio>
 #include<cstring>
 #include"FBLPost.h"
 #include"FBLPostLL.h"
 #include"FBLUser.h"
 #include"FBLUserLL.h"
 using namespace std;

 void ThirdMenu(FBLPost* post)
 {
     string commond;
     string text;
     char argv[3][40];
     int argc;
     cout<<"Third Menu"<<endl;
     do
     {
         getline(cin,commond);
         argc=sscanf(commond.c_str(),"%s%s%s",argv[0],argv[1],argv[2]);
         if(strcmp(argv[0],"COMMENT")==0 && argc==2)
         {
             text.assign(argv[1]);
             post->Comment(text);
             cout<<"COMMENT Success"<<endl;
         }
         if(strcmp(argv[0],"LIKE")==0 && argc==1)
         {
             post->AddLike();
         }
         if(strcmp(argv[0],"READ_AZ")==0 && argc==1)
         {
             post->ReadAZ();
         }
         if(strcmp(argv[0],"READ_ZA")==0 && argc==1)
         {
             post->ReadZA();
         }
     }while(strcmp(argv[0],"DONE")!=0);
 }

 void SceondMenu(FBLUserLL& UserList,FBLUser* user)
 {
     string commond;
     char argv[3][40];
     string text;
     string uid;
     int argc;
     FBLUser* f_uid;
     FBLPost* post;
     cout<<"Second Menu"<<endl;
     do
     {
         getline(cin,commond);
         argc=sscanf(commond.c_str(),"%s%s%s",argv[0],argv[1],argv[2]);
         if(strcmp(argv[0],"POST")==0 && argc==2)
         {
             text.assign(argv[1]);
             user->Post(text);
             cout<<"Post Success"<<endl;
         }
         if(strcmp(argv[0],"READ")==0 && argc==1)
         {
             post=user->ReadTop();
             if(post!=NULL)
             {
                 ThirdMenu(post);
             }
         }
         if(strcmp(argv[0],"FRIEND")==0 && argc==2)
         {
             uid.assign(argv[1]);
             f_uid=UserList.LogIn(uid);
             if(f_uid!=NULL)
             {
                 if(user->AddFriend(f_uid))
                 {
                     cout<<"Add friend success"<<endl;
                 }
                 else
                 {
                     cout<<"Can not add this friend"<<endl;
                 }
             }
             else
             {
                 cout<<"Error UID"<<endl;
             }
         }
         if(strcmp(argv[0],"MYFRIENDS")==0 && argc==1)
         {
             user->ListFriend();
         }
         if(strcmp(argv[0],"MYWALL")==0 && argc==1)
         {
             user->AllWall();
         }
         if(strcmp(argv[0],"MYFEED")==0 && argc==1)
         {
             user->AllPost();
         }
     }while(strcmp(argv[0],"LOGOUT")!=0);
 }

 void TopMenu(FBLUserLL& UserList)
 {
     string commond;
     char argv[6][40];
     string uid;
     string psd;
     string first;
     string last;
     FBLUser* user;
     int argc;
     cout<<"Top Menu"<<endl;
     do
     {
         getline(cin,commond);
         argc=sscanf(commond.c_str(),"%s%s%s%s%s%s",argv[0],argv[1],argv[2],argv[3],argv[4],argv[5]);
         if(strcmp(argv[0],"CREATE")==0 && argc==5)
         {
             uid.assign(argv[1]);
             psd.assign(argv[2]);
             first.assign(argv[3]);
             last.assign(argv[4]);
             if(UserList.InsertUser(uid,psd,first,last))
             {
                 cout<<"Create success"<<endl;
             }
             else
             {
                 cout<<"Create fail"<<endl;
             }
         }
         if(strcmp(argv[0],"LOGIN")==0 && argc==3)
         {
             uid.assign(argv[1]);
             psd.assign(argv[2]);
             user=UserList.LogIn(uid);
             if(user!=NULL && user->CheckPsd(psd))
             {
                 cout<<"Login Success"<<endl;
                 SceondMenu(UserList,user);
             }
             else
             {
                 cout<<"Login fail"<<endl;
             }
         }
         if(strcmp(argv[0],"USERS")==0 && argc==1)
         {
             UserList.PrintAll();
         }
         if(strcmp(argv[0],"SORTUSERS")==0 && argc==1)
         {
             UserList.Sort();
         }
     }while(strcmp(argv[0],"QUIT")!=0);
 }

 int main()
 {
     FBLUserLL UserList;
     TopMenu(UserList);
     return 0;
 }
