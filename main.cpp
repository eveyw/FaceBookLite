 #include<iostream>
 #include<string>
 #include<cstdio>
 #include<cstring>
 #include"FBLPost.h"
 #include"FBLPostLL.h"
 #include"FBLUser.h"
 #include"FBLUserLL.h"
 using namespace std;

 void SceondMenu(FBLUser* user)
 {
     string commond;
     char argv[3][40];
     string text;
     int argc;
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
             user->ReadTop();
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
         if(strcmp(argv[0],"LOGIN")==0 && argc==2)
         {
             uid.assign(argv[1]);
             user=UserList.LogIn(uid);
             if(user!=NULL)
             {
                 cout<<"Login Success"<<endl;
                 SceondMenu(user);
             }
             else
             {
                 cout<<"Login fail"<<endl;
             }
         }
     }while(strcmp(argv[0],"QUIT")!=0);
 }

 int main()
 {
     FBLUserLL UserList;
     TopMenu(UserList);
     return 0;
 }
