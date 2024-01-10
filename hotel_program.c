#include <stdio.h>
#include"hotel_interfacing.h"


/**********function for print the welcome message******************/

void hello()
{

    printf("\t\t=============================================\n");
    printf("\t\t|                                           |\n");
    printf("\t\t|       ----------------------------        |\n");
    printf("\t\t|           HOTEL BOOKING SYSTEM            |\n");
    printf("\t\t|     WELCOME WE ARE   in your service      |\n");
    printf("\t\t|       ----------------------------        |\n");
    printf("\t\t|                                           |\n");
    printf("\t\t|                                           |\n");
    printf("\t\t|                                           |\n");
    printf("\t\t=============================================\n\n\n");


}

/**********function for enter the mail and pass and check them******************/

int check_password()
{
    int check_flag = zero;
    int right_flag = zero;        /* right_flag var to check the mail and pass right and and the func will return it  */

    char counter;
    char email[5]= {"admin"};
    int pass= 12345;
    char enter_name[5];
    int enter_pass;
label:
    printf("====================================\n");
    printf("\tplease enter your email\n");
    printf("====================================\n");
    gets(enter_name);
    fflush(stdin);
    printf("\tplease enter your password\n");
    printf("====================================\n");
    scanf("%d",&enter_pass);
    fflush(stdin);

    printf("wait .");

    for (counter = zero; counter < 15; counter++)
    {

        printf(".");
        Sleep(50);
    }
    printf("\n");
    for(counter=zero; counter<=5; counter++)
    {
        if((enter_name[counter] == email[counter] )&&(enter_pass == pass))
        {
            right_flag = one;
        }
    }
    if(one == right_flag)
    {
        printf("========login successfully========\n");
    }
    else
    {
        check_flag++;
        if( three != check_flag )
        {
            printf("\t invalid email or password. \n try agin. \n");
            goto label;
        }


        else
        {
            right_flag = zero;
        }

    }


    return right_flag;
}

/**********function for booking a room******************/

void booking_room(guest *ptr_custum)
{
    if( NULL != ptr_custum)
    {
        printf("\t sir/ please enter the room number which u want to book it.\n");
        scanf("%i",&(ptr_custum->room_number));
        fflush(stdin);
        printf("\t sir/ please enter your name.\n");
        gets(ptr_custum->name);
        fflush(stdin);
        printf("\t sir/ please enter the address.\n");
        gets(ptr_custum->address);
        fflush(stdin);
        printf("\t sir/ please enter your arrival_date.\n");
        gets((ptr_custum->arrival_date));
        fflush(stdin);
        printf("\t sir/ please enter the number of days u want to book.\n");
        scanf("%i",&(ptr_custum->period));
        fflush(stdin);
        printf("\t sir/ please enter your nationality.\n");
        gets(ptr_custum->nation);
        fflush(stdin);
        printf("\t sir/ please enter your phone_num.\n");
        gets(ptr_custum->phone_num);
        fflush(stdin);
        printf("\t sir/ please enter your email.\n");
        gets(ptr_custum->email);
        fflush(stdin);
        printf("\t booking room %i is successfully thank sir\n",ptr_custum->room_number);
        FILE *PTR = (FILE *)fopen("room_booking.txt","w");
        fprintf(PTR,
                "\t ROOM:[%d]\t\n customer name:- %s\t\n address: %s\t\n arrival_date:- %s\t\n period :- %d\t\n customer nationality:- %s\t\n customer phone_num:- %s\t\n customer email:%s\t\n",
                ptr_custum->room_number,ptr_custum->name,ptr_custum->address,ptr_custum->arrival_date,ptr_custum->period,ptr_custum->nation,ptr_custum->phone_num,ptr_custum->email);
        fclose(PTR);
    }
    else
    {
        printf("\t error function (booking_room) due to null pointer.\n");
    }



}

/**********function for print data of booking a room******************/

void room_data(guest *ptr_custum)
{
    char counter=zero;
    printf("===========================================================\n");
    printf("\t wait .");

    for (counter = zero; counter < 15; counter++)
    {

        printf(".");
        Sleep(50);
    }
    fflush(stdin);
    printf("\n              details of your booked room                     \n");
    printf("\t your room NO.%d located at third floor,corridor No.4\n",ptr_custum->room_number);
    printf("\t name :- %s\n",ptr_custum->name);
    printf("\t arrival_date :- %s\n",ptr_custum->arrival_date);
    printf("\t period :- %d\n",ptr_custum->period);
    printf("\t address :- %s\n",ptr_custum->address);
    printf("\t email :- %s\n",ptr_custum->email);
    printf("\t nation :- %s\n",ptr_custum->nation);
    printf("\t phone_num :- %s\n",ptr_custum->phone_num);
    printf("===========================================================\n");
}

/**********function for modify data of booking a room******************/

void modify_data(guest *ptr_custum)
{
    char select=zero;
    int agin=1;
    char data[30];
    unsigned int intger_data;

    while(one == agin)
    {
        printf("\t for modify your booking.\n");
        printf("===========================================================\n");
        printf("\t 1-room number.\n");
        printf("\t 2-arrival_date.\n");
        printf("\t 3-address.\n");
        printf("\t 4-phone_num.\n");
        printf("\t 5-nationllaty.\n");
        printf("\t 6-number of days u book.\n");
        printf("\t 7-email.\n");
        printf("\t 8-name.\n");
        printf("\t 9-exit.\n");
        printf("===========================================================\n");
        printf("\t enter the option u want to modify\n");
        scanf("%d",&select);
        fflush(stdin);

        switch (select)
        {

        case one:
            printf("\t enter the new room number.\n");
            scanf("%i",&intger_data);
            ptr_custum->room_number = intger_data;

            break;

        case two:
            printf("\t enter the new arrival_date.\n");
            fflush(stdin);
            gets(data);
            memcpy(ptr_custum->arrival_date,data,30);
            break;


        case three:
            printf("\t enter the new address.\n");
            fflush(stdin);
            gets(data);
            memcpy(ptr_custum->address,data,30);
            break;

        case four:
            printf("\t enter the new phone_num.\n");
            fflush(stdin);
            scanf("%d",&data);
            memcpy(ptr_custum->phone_num,data,30);
            break;

        case five:
            printf("\t enter the new nation.\n");
            fflush(stdin);
            gets(data);
            memcpy(ptr_custum->nation,data,30);
            break;

        case six:
            printf("\t enter the new numer of days u want to book.\n");
            fflush(stdin);
            scanf("%i",&intger_data);
            ptr_custum->period = intger_data;
            break;

        case seven:
            printf("\t enter the new email.\n");
            fflush(stdin);
            gets(data);
            memcpy(ptr_custum->email,data,30);
            break;

        case eight:
            printf("\t enter the new name.\n");
            fflush(stdin);
            gets(data);
            memcpy(ptr_custum->name,data,30);
            break;

        case nine:
            break;


        }
        room_data(ptr_custum);
        printf("\t press \n 1 for modify more data.\n any key for continue.\n");
        scanf("%d",&agin);
    }
}
