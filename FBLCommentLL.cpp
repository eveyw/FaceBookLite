 #include"FBLCommentLL.h"

 FBLCommentLL::FBLCommentLL()
 {
     Data=NULL;
     Next=this;
     Prev=this;
 }
 FBLCommentLL::FBLCommentLL(FBLComment* com)
 {
     Data=com;
     Next=this;
     Prev=this;
 }
 FBLCommentLL::~FBLCommentLL()
 {
     if(Prev!=NULL)
     {
         Prev->Next=NULL;
     }
     if(Next!=NULL)
     {
         Next->Prev=NULL;
         delete Next;
     }
     if(Data!=NULL)
     {
         delete Data;
     }
 }
 void FBLCommentLL::Insert(string text)
 {
     FBLComment* NewData=new FBLComment(text);
     FBLCommentLL* NewElement=new FBLCommentLL(NewData);
     NewElement->Next=this;
     NewElement->Prev=this->Prev;
     Prev->Next=NewElement;
     Prev=NewElement;
 }
 void FBLCommentLL::ReadAtoZ()
 {
     FBLCommentLL* tmp=Next;
     if(tmp==this)
     {
         cout<<"Nothing to READ"<<endl;
     }
     else
     {
         while(tmp!=this)
         {
             cout<<*(tmp->Data)<<endl;
             tmp=tmp->Next;
         }
     }
 }
 void FBLCommentLL::ReadZtoA()
 {
     FBLCommentLL* tmp=Prev;
     if(tmp==this)
     {
         cout<<"Nothing to READ"<<endl;
     }
     else
     {
         while(tmp!=this)
         {
             cout<<*(tmp->Data)<<endl;
             tmp=tmp->Prev;
         }
     }
 }
