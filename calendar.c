#include <stdio.h>
#include <stdlib.h>

//get first day of year
int first_day_of_year(int year) {
    int fd = (year * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
    return fd;
};


int main() {

    char *month_name[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int weeks = 0, space;

    int year = 0;
    printf("Enter Year : ");
    scanf("%d", &year);

    //clear screen 
    system("cls");

    //welcome massage
    printf("<-------------- Welcome to %d year --------------->", year);

    //check leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        days[1] = 29;
    }
    
    //first day of year
    weeks = first_day_of_year(year);
    // printf("week is : %d", week);

    //calculate calendar
    for (int i = 0; i < 12; i++)
    {
        printf("\n\n\n<------------------- %s ------------------->\n\n\n", month_name[i]);
        printf("  SUN  MON  TUE  WED  THU  FRI  SAT\n");
        printf("  ---  ---  ---  ---  ---  ---  ---\n");
        

        //day position
        for (space = 1; space <= weeks; space++)
        {
            printf("     ");
        }
        
        //days
        for (int day = 1; day <= days[i]; day++)
        {
            if (weeks > 6)
            {
                weeks = 0;
                printf("\n");
            }
            weeks++;
            
            printf("%5.2d", day);
        }
        
    }

    //author credit
    printf("\n\n<---------------------------- By Abu Raihan --->\n\n");

    //exit permitios
    int exit;
    printf("\n\nEnter any key to exit : ");
    scanf("%d", &exit);    

    return 0;
}