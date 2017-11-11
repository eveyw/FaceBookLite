 #include"FBLPostLL.h"

 FBLPostLL::FBLPostLL()
 {
     Data=NULL;
     Next=NULL;
     opt=0;
 }
 FBLPostLL::FBLPostLL(FBLPost* post)
 {
     Data=post;
     Next=NULL;
     opt=0;
 }
 FBLPostLL::~FBLPostLL()
 {
     if(Next!=NULL)
     {
         delete Next;
     }
     if(Data!=NULL && opt==1)
     {
         delete Data;
     }
 }
 FBLPost* FBLPostLL::InsertPost(string text)
 {
     FBLPost* NewData=new FBLPost(text);
     FBLPostLL* NewElement=new FBLPostLL(NewData);
     FBLPostLL* p=this;
     NewElement->opt=1;
     while(p->Next!=NULL)
     {
         p=p->Next;
     }
     p->Next=NewElement;
     return NewData;
 }
 void FBLPostLL::InsertPost(FBLPost* NewData)
 {
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
         tmp->Data=NULL;
         delete tmp;
     }
 }
 FBLPost* FBLPostLL::ReadPost()
 {
     FBLPost* ret=NULL;
     if(Next==NULL)
     {
         cout<<"Nothing to READ"<<endl;
     }
     else
     {
         cout<<*(Next->Data)<<endl;
         ret=Next->Data;
         DeleteTop();
     }
     return(ret);
 }
 void FBLPostLL::ReadAllPost(int opt)
 {
     FBLPostLL* tmp=Next;
     if(tmp==NULL)
     {
         cout<<"Nothing to READ"<<endl;
     }
     else
     {
         while(tmp!=NULL)
         {
             if(opt==1)
             {
                 cout<<"Likes: "<<tmp->Data->GetLike()<<" ";
             }
             cout<<*(tmp->Data)<<endl;
             tmp=tmp->Next;
         }
     }
 }
