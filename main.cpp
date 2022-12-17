#include <iostream>
#include <vector>
using namespace std;
class Object_Of_Room {
  private:
   int x_coordinate;
   int y_coordinate;
  public:
   void set_x_coordinate(int new_coordinate);
   void set_y_coordinate(int new_coordinate);
   int get_x_coordinate();
   int get_y_coordinate();
   explicit Object_Of_Room(int new_x_coordinate,int new_y_coordinate);

};
void Object_Of_Room::set_x_coordinate(int new_coordinate){
  this->x_coordinate=new_coordinate;
}
void Object_Of_Room::set_y_coordinate(int new_coordinate){
  this->y_coordinate=new_coordinate;
}
int Object_Of_Room::get_x_coordinate(){
  return this->x_coordinate;
}
int Object_Of_Room::get_y_coordinate(){
  return this->y_coordinate;
}
Object_Of_Room::Object_Of_Room(int new_x_coordinate,int new_y_coordinate){
  this->x_coordinate=new_x_coordinate;
  this->y_coordinate=new_y_coordinate;
} 
class Table:public Object_Of_Room {
public:
  using Object_Of_Room::Object_Of_Room;
};
class Bed:public Object_Of_Room {
public:
 using Object_Of_Room::Object_Of_Room;
};
class Carpet:public Object_Of_Room {
public:
 using Object_Of_Room::Object_Of_Room;
};
class Room{
  private:
   vector<Object_Of_Room>vector_of_obj;
  public:
    void adding_an_obj(Object_Of_Room current);
    void delete_an_obj();
    void rearengment_of_obj();
    void review_of_obj();
    Room(vector<Object_Of_Room>new_vector);
    ~Room();
};
void Room::adding_an_obj(Object_Of_Room current){
  this->vector_of_obj.push_back(current);
}
void Room::delete_an_obj(){
  this->vector_of_obj.erase(this->vector_of_obj.end());
}
void Room::rearengment_of_obj(){
    vector<Object_Of_Room>::iterator current_object;
   for (auto current_object = this->vector_of_obj.begin(); current_object != this->vector_of_obj.end(); ++current_object){ 
     current_object->set_x_coordinate(rand());
     current_object->set_y_coordinate(rand());
     }
}
void Room::review_of_obj(){
  vector<Object_Of_Room>::iterator current_object;
   for (auto current_object = this->vector_of_obj.begin(); current_object != this->vector_of_obj.end(); ++current_object){
     cout<<"x is ";
     cout<<current_object->get_x_coordinate()<<" , ";
     cout<<"y is ";
     cout<<current_object->get_y_coordinate()<<endl;
     }
}
Room::Room(vector<Object_Of_Room>new_vector){
  this->vector_of_obj=new_vector;
}
Room::~Room(){
  this->vector_of_obj.clear();
}
int main() {
  vector<Object_Of_Room>vector1;
  Room room1(vector1);
  Table table1(23,423);
  Carpet carpet1(43,53);
  Bed bed1(42,54);
  room1.adding_an_obj(table1);
  room1.adding_an_obj(carpet1);
  room1.adding_an_obj(bed1);
  room1.review_of_obj();
  room1.rearengment_of_obj();
  room1.review_of_obj();
}