 #include"FBLPost.h"

 FBLPost::FBLPost(const string & str)
 {
     Text=str;
 }

 ostream & operator << (ostream &out, FBLPost &post)
 {
     out<<post.Text;
     return out;
 }
