#include <stdio.h>
#include"hotel_interfacing.h"

int main()
{
    guest custum;
    guest *ptr_custum = &custum;
    int right_flag;
    time_t t;
    int select_program;
    char continue_index = one;
    time (&t);
    hello();
    printf("\n\tDate and Time : %s",ctime(&t));
    right_flag=check_password();        /* if right_flag =1 meaning mail and pass is right will continue our progrom */

    if(one == right_flag)
    {

        printf("========================\n");
        printf("\t 1-booking a room.\n");
        printf("\t 2-your booking data.\n");
        printf("\t 3-modify your data.\n");
        printf("\t 4-exit.\n");
        printf("========================\n");
        printf("\t enter the option u want\n");

        scanf("%d",&select_program);
        fflush(stdin);
        switch (select_program)
        {
        case one:          /* choosen 1 mean booking a room.*/
        {


            if( NULL != ptr_custum)
            {
                booking_room(ptr_custum);
                room_data(ptr_custum);
            }
            else
            {
                printf("\t error function (booking_room) due to null pointer.\n");
            }
            break;
        }

        case two:
        {
            if( NULL != ptr_custum) room_data(ptr_custum);

            else
                printf("\t error function (room_data) due to null pointer.\n");

            break;
        }
        case three:
        {
            if( NULL != ptr_custum) modify_data(ptr_custum);

            else
            {
                //null pointer
            }
            break;

        }
        case  four:
            continue_index = zero;
        }
    }
    else
        printf("sir u entered user name and password wrong 3 time try anther time pls\n");


    return zero;
}
