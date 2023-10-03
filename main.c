// Mini exercise
#include <stdio.h>
#include <stdlib.h>
struct customer_t{
    char firstName[61];
    char lastName[61];
    char phoneNumber[19];

};

typedef struct customer_t customer;

void printAllCustomers(customer *cPtrHead, int numOfCustomers);
void getAllCustomers(customer *cPtrHead, int customerIndexNumber);


int main()
{
    int numberOfCustomers = 0;
    customer* arrOfCustomers;
    char instruction;

    while(1 == 1){

        //if a new customer comes in and take their data and if no new customers,
        // print an exit.
        printf("\nEnter Y to record new customer of Q to exit: ");
        fflush(stdin);
        scanf("%c", &instruction);

        if(instruction == 'Y'){
            numberOfCustomers++;
            if(numberOfCustomers == 1){
                arrOfCustomers = (customer*) malloc(numberOfCustomers*sizeof(customer));
                if(arrOfCustomers == NULL){
                    printf("\nERROR: Failed to allocate memory.");
                }
                else{
                    printf("\nSuccess %d bytes were allocated", numberOfCustomers*sizeof(customer));
                }
            }
            else{
                arrOfCustomers = (customer*) realloc(arrOfCustomers,numberOfCustomers*sizeof(customer));
                if(arrOfCustomers == NULL){
                printf("\nERROR: Failed to allocate memory.");
                }
                else{
                    printf("\nSuccess %d bytes were allocated", numberOfCustomers*sizeof(customer));
                }
            }
            getAllCustomers(arrOfCustomers,numberOfCustomers-1); //since it is array indexing get [0] of the array.
        }

        else if(instruction == 'Q'){
            //do some printing
            printf("\n\nPrinting all the customers available on list:");
            printf("\n--------------------------------------------");
            printAllCustomers(arrOfCustomers, numberOfCustomers);
            break;

        }else{
            //if something other than Y or Q print error input.
            printf("Error: wrong input!");
        }

    }
    free(arrOfCustomers);
    while(getchar() != '\n'){

    }
    // getchar();
    getchar();
    return 0;
}


void printAllCustomers(customer *cPtrHead, int numOfCustomers){

    for(int i=0; i< numOfCustomers; i++){
        printf("\n\nCustomer Number: %d", i +1);
        printf("\nFirst Name: %s", cPtrHead[i].firstName);
        printf("\nLast Name: %s", cPtrHead[i].lastName);
        printf("\nPhone Number: %s", cPtrHead[i].phoneNumber);
    }
    printf("\n\n");
}



void getAllCustomers(customer *cPtrHead, int customerIndexNumber){

        printf("\n\nCustomer Number: %d", customerIndexNumber +1);

        printf("\nFirst Name:");
        fflush(stdin);
        scanf("%s", &cPtrHead[customerIndexNumber].firstName);

        printf("Last Name:");
        fflush(stdin);
        scanf("%s", &cPtrHead[customerIndexNumber].lastName);

        printf("Phone Number:");
        fflush(stdin);
        scanf("%s", &cPtrHead[customerIndexNumber].phoneNumber);
    }
