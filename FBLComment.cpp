 #include"FBLComment.h"

 FBLComment::FBLComment(const string & str)
 {
     Text=str;
 }

 ostream & operator << (ostream &out, FBLComment &com)
 {
     out<<com.Text;
     return out;
 }


