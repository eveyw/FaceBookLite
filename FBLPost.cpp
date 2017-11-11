 #include"FBLPost.h"

 FBLPost::FBLPost(const string & str)
 {
     Text=str;
     Like=0;
 }

 ostream & operator << (ostream &out, FBLPost &post)
 {
     out<<post.Text;
     return out;
 }

 int FBLPost::GetLike()
 {
     return(Like);
 }

 void FBLPost::AddLike()
 {
     Like++;
 }

 void FBLPost::Comment(const string & text)
 {
     ComList.Insert(text);
 }
 void FBLPost::ReadAZ()
 {
     ComList.ReadAtoZ();
 }
 void FBLPost::ReadZA()
 {
     ComList.ReadZtoA();
 }
