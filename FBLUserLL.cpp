 #include"FBLUserLL.h"

 FBLUserLL::FBLUserLL()
 {
     Data=NULL;
     Next=NULL;
 }
 FBLUserLL::~FBLUserLL()
 {
     if(Next!=NULL)
     {
         delete Next;
     }
     if(Data!=NULL)
     {
         delete Data;
     }
 }
 FBLUserLL::FBLUserLL(FBLUser* _data)
 {
     Data=_data;
     Next=NULL;
 }
 FBLUser* FBLUserLL::LogIn(const string & _uid)
 {
     FBLUserLL* p;
     p=Next;
     while(p!=NULL && !p->Data->CheckUid(_uid))
     {
         p=p->Next;
     }
     return p->Data;
 }
 bool FBLUserLL::CheckUid(const string & _uid)
 {
     FBLUserLL* p;
     p=Next;
     while(p!=NULL && !p->Data->CheckUid(_uid))
     {
         p=p->Next;
     }
     return (p!=NULL);
 }
 bool FBLUserLL::InsertUser(const string & _Uid,const string & _Psd,const string & _First,const string & _Last)
 {
     if(CheckUid(_Uid))
     {
         return false;
     }
     FBLUserLL* p=this;
     FBLUser* NewData=new FBLUser(_Uid,_Psd,_First,_Last);
     FBLUserLL* NewElement=new FBLUserLL(NewData);
     while(p->Next!=NULL)
     {
         p=p->Next;
     }
     p->Next=NewElement;
     return true;
 }
