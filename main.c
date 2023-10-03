// Mini exercise
struct customer_t{
    char firstName[61];
    char lastName[61];
    char phoneNumber[19];

};

typedef struct customer_t customer;

void printAllCustomers(customer *cPtrHead, int numOfCustomers);
void getAllCustomers(customer *cPtrHead, int customerIndexNumber);
