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
     if(p!=NULL)
         return p->Data;
     else
         return NULL;
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
     FBLUser* NewData=new FBLUser(_Uid,_Psd,_First,_Last);
     FBLUserLL* NewElement=new FBLUserLL(NewData);
     NewElement->Next=Next;
     Next=NewElement;
     return true;
 }

 void FBLUserLL::PrintAll()
 {
     FBLUserLL* tmp=Next;
     while(tmp!=NULL)
     {
         cout<<*(tmp->Data)<<endl;
         tmp=tmp->Next;
     }
 }

 void FBLUserLL::Sort()
 {
     FBLUserLL* p=Next;
     FBLUserLL* q=Next;
     FBLUser* tmp;
     while(p!=NULL)
     {
         q=p->Next;
         while(q!=NULL)
         {
             if(p->Data->GetLast()>q->Data->GetLast())
             {
                 tmp=p->Data;
                 p->Data=q->Data;
                 q->Data=tmp;
             }
             q=q->Next;
         }
         p=p->Next;
     }
 }
