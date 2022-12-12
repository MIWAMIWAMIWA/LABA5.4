#include <iostream>
class table{
 public:
  int x;
  int y;
  table(int x, int y);
};
table::table(int a, int b) {
  x = a;
  y = b;
}
class carpet{
 public:
  int x;
  int y;
  carpet(int x, int y);
};
carpet::carpet(int a, int b) {
  x = a;
  y = b;
}
class bed{
 public:
  int x;
  int y;
  bed(int x, int y);
};
bed::bed(int a, int b) {
  x = a;
  y = b;
}
class room{
 public:
 bed *ptr1[1000];
 int beds_c=0;
 carpet *ptr2[1000];
 int carpets_c=0;
 table *ptr3[1000];
 int tables_c=0;
 void adding(int x,int y,int id);
 void remove(int id);
 void rearengment();
 ~room();
};
void room::adding(int x,int y, int id){
  switch(id){
    case 1:
      bed *b_current;
      b_current=new bed(x,y);
      ptr1[beds_c++]=b_current;
      break;
    case 2:
      carpet *c_current;
      c_current=new carpet(x,y);
      ptr2[carpets_c++]=c_current;
      break;
    case 3:
      table *t_current;
      t_current=new table(x,y);
      ptr3[tables_c++]=t_current;
      break;
    default:
      std::cout<<"unknown id\n";
}
  }
void room::remove(int id){
  switch(id){
    case 1:
      bed *b_current;
      b_current=ptr1[--beds_c];
      delete b_current;
      break;
    case 2:
      carpet *c_current;
      c_current=ptr2[--carpets_c];
      delete c_current;
      break;
    case 3:
      table *t_current;
      t_current=ptr3[--tables_c];
      delete t_current;
      break;
    default:
      std::cout<<"unknown id\n";
  }
}
void room::rearengment(){
  int i=0;
  bed *b_current;
  carpet *c_current;
  table *t_current;
  while (i<beds_c){
    b_current=ptr1[i];
    b_current->x=rand();
    b_current->y=rand();
    i++;
  }
  i=0;
  while (i<carpets_c){
    c_current=ptr2[i];
    c_current->x=rand();
    c_current->y=rand();
    i++;
}
  i=0;
  while (i<tables_c){
    t_current=ptr3[i];
    t_current->x=rand();
    t_current->y=rand();
    i++;
    }
  }
room::~room(void){
  int i=0;
  bed *b_current;
  carpet *c_current;
  table *t_current;
  while (i<beds_c){
    b_current=ptr1[i];
    delete b_current;
    i++;
  }
  i=0;
  while (i<carpets_c){
    c_current=ptr2[i];
    delete c_current;
    i++;
}
  i=0;
  while (i<tables_c){
    t_current=ptr3[i];
    delete c_current;
    i++;
    }
  std::cout<<"destructor called\n";
}
int main() {
  room room1;
  room1.adding(23,54,1);
  room1.adding(54,67,2);
  room1.remove(2);
  room1.rearengment();
  std::cout<<room1.ptr1[0]->x<<std::endl;
  std::cout<<room1.ptr1[0]->y<<std::endl;
}