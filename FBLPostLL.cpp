 #include"FBLPostLL.h"

 FBLPostLL::FBLPostLL()
 {
     Data=NULL;
     Next=NULL;
 }
 FBLPostLL::FBLPostLL(FBLPost* post)
 {
     Data=post;
     Next=NULL;
 }
 FBLPostLL::~FBLPostLL()
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
 void FBLPostLL::InsertPost(string text)
 {
     FBLPost* NewData=new FBLPost(text);
     FBLPostLL* NewElement=new FBLPostLL(NewData);
     FBLPostLL* p=this;
     while(p->Next!=NULL)
     {
         p=p->Next;
     }
     p->Next=NewElement;
 }
 void FBLPostLL::DeleteTop()
 {
     FBLPostLL* tmp;
     if(Next!=NULL)
     {
         tmp=Next;
         Next=tmp->Next;
         tmp->Next=NULL;
         delete tmp;
     }
 }
 void FBLPostLL::ReadPost()
 {
     if(Next==NULL)
     {
         cout<<"Nothing to READ"<<endl;
     }
     else
     {
         cout<<*(Next->Data)<<endl;
         DeleteTop();
     }
 }
