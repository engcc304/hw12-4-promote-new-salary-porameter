/*
    ผู้บริหารต้องการวิเคราะห์พัฒนาการของพนักงานในบริษัทและศักยภาพของพนักงานจากทักษะที่พัฒนาขึ้นของแต่ละคน ซึ่งแปลงค่าความสามารถของแต่ละคนออกมาเป็นค่า EXP โดยแบ่งอัตราการขึ้นเงินเดือนของแต่ละคนดังนี้
    EXP อยู่ในช่วง 0-1,000 		จะได้รับเงินเดือน x1
	EXP อยู่ในช่วง 1,000-2,000 	จะได้รับเงินเดือน x1.2
	EXP อยู่ในช่วง 2,000-3,000 	จะได้รับเงินเดือน x1.4
	EXP อยู่ในช่วง 3,000-4,000 	จะได้รับเงินเดือน x1.6
	EXP อยู่ในช่วง 4,000-5,000 	จะได้รับเงินเดือน x1.8
	EXP อยู่ในช่วง 5,000 ขึ้นไป	จะได้รับเงินเดือน x2
    โดยผู้บริหารมอบหมายให้ HR เป็นคนกรอกข้อมูลพนักงานในบริษัทและประเมินค่า EXP ของพนักงานแต่ละคน พร้อมสรุปจำนวนคนที่ได้รับเงินเดือนในแต่ละขั้น และระบุคนชื่อคนที่ได้เงินเดือนเยอะที่สุด และคนที่เงินเดือนน้อยที่สุด (หากกรอกเลข -1 ในช่อง Name จะถือเป็นการหยุดโปรแกรมและเตรียมแสดงผล)
    
    Test case:
        Employee 1 Name : 
            Atom
        EXP : 
            2500
        Employee 2 Name : 
            Aom
        EXP : 
            3230
        Employee 3 Name : 
            Aim
        EXP : 
            4560
        Employee 4 Name : 
            Jom
        EXP : 
            5505
        Employee 5 Name : 
            On
        EXP : 
            950
        Employee 6 Name : 
            Oom
        EXP : 
            3500
        Employee 7 Name : 
            Ky
        EXP : 
            2600
        Employee  Name : 
            -1
    Output:
        **** Salary Result ****
        x1.0 count 1
        x1.2 count 0
        x1.4 count 2
        x1.6 count 2
        x1.8 count 1
        x2.0 count 1
        The Employee get x2.0 is Jom
        The Employee get x1.0 is On

    Test case:
        Employee 1 Name : 
            Aey
        EXP : 
            9956
        Employee 2 Name : 
            J
        EXP : 
            4900
        Employee 3 Name : 
            A
        EXP : 
            4560
        Employee 4 Name : 
            Orio
        EXP : 
            200
        Employee 5 Name : 
            Vistra
        EXP : 
            1656
        Employee 6 Name : 
            Oh
        EXP : 
            2300
        Employee  Name : 
            -1
    Output:
        **** Salary Result ****
        x1.0 count 1
        x1.2 count 1
        x1.4 count 1
        x1.6 count 0
        x1.8 count 2
        x2.0 count 1
        The Employee get x2.0 is Aey
        The Employee get x1.0 is Orio
*/

#include <stdio.h>
#include <string.h>

struct Employee {
    char Name[50] ;
    int EXP ;
} ;

int main() {
    int n = 0 ;
    int x1_count = 0 , x1_2_count = 0 , x1_4_count = 0 , x1_6_count = 0 , x1_8_count = 0 , x2_count = 0 ;
    char maxSalaryName[50] = "" ;
    double maxSalary = 0 ;
    char minSalaryName[50] = "" ;
    double minSalary = 0 ;

    printf( "Employee 1 Name : " ) ;
    char choice[50];
    scanf( " %s" , choice) ;

    while ( strcmp( "-1" , choice ) != 0 ) {
        struct Employee emp ;

        printf( "EXP : " ) ;
        scanf( "%d" , &emp.EXP ) ;

        n++;

        double salary = 0 ;

        if ( emp.EXP >= 0 && emp.EXP < 1000 ) {
            x1_count++ ;
            salary = emp.EXP * 1.0 ;
        } else if ( emp.EXP >= 1000 && emp.EXP < 2000 ) {
            x1_2_count++ ;
            salary = emp.EXP * 1.2 ;
        } else if ( emp.EXP >= 2000 && emp.EXP < 3000 ) {
            x1_4_count++ ;
            salary = emp.EXP * 1.4;
        } else if ( emp.EXP >= 3000 && emp.EXP < 4000 ) {
            x1_6_count++ ;
            salary = emp.EXP * 1.6;
        } else if ( emp.EXP >= 4000 && emp.EXP < 5000 ) {
            x1_8_count++ ;
            salary = emp.EXP * 1.8;
        } else if ( emp.EXP >= 5000 ) {
            x2_count++ ;
            salary = emp.EXP * 2.0 ;
        }

        if ( salary > maxSalary ) {
            maxSalary = salary ;
            strcpy( maxSalaryName , emp.Name ) ;
        }

        if ( n == 1 || salary < minSalary ) {
            minSalary = salary ;
            strcpy( minSalaryName , emp.Name ) ;
        }

        printf( "Employee %d Name : " , n + 1 ) ;
        scanf( " %s" , choice ) ;
    }

    printf( "**** Salary Result ****\n" ) ;
    printf( "x1.0 count %d\n" , x1_count ) ;
    printf( "x1.2 count %d\n" , x1_2_count ) ;
    printf( "x1.4 count %d\n" , x1_4_count ) ;
    printf( "x1.6 count %d\n" , x1_6_count ) ;
    printf( "x1.8 count %d\n" , x1_8_count ) ;
    printf( "x2.0 count %d\n" , x2_count ) ;

    printf( "The Employee get x2.0 is %s\n" , maxSalaryName ) ;
    printf ("The Employee get x1.0 is %s\n" , minSalaryName ) ;

    return 0 ;
}
