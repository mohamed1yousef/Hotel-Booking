#ifndef HOTEL_INTERFACING_H_INCLUDED
#define HOTEL_INTERFACING_H_INCLUDED

enum states
{
    zero,
    one,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine
};



/**********used data type******************/
typedef struct
{
    unsigned int  room_number;
    char name[30];
    char phone_num[15];
    char address[30];
    char nation[10];
    char email[20];
    char arrival_date[15];
    unsigned int period;

} guest;



/********** functions prototype ******************/
void hello();
int check_password();
void booking_room(guest *ptr_custum);
void room_data(guest *ptr_custum);
void modify_data(guest *ptr_custum);



#endif // HOTEL_INTERFACING_H_INCLUDED
