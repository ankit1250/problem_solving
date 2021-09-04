#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
int MAX= 200;
int num_tickets=0;
void* ticketBook(void *a){
    if(num_tickets>MAX){
        return NULL;
    }
    pthread_mutex_lock(&lock);
    printf("Booking ticket no. %d",num_tickets);
    num_tickets++;
    pthread_mutex_unlock(&lock);

    return NULL;
}

void* cancelTicket(void *b){
    if(num_tickets<=0){
        return NULL;
    pthread_mutex_lock(&lock);
    printf("\nCancelling a booked ticket\n");
    num_tickets--;
    pthread_mutex_unlock(&lock);

    return NULL;
}
int main(){
    pthread_t t[20];
    int n;
    printf("Enter the number of flights\n");
    scanf("%d",&n);
    int seats;
    printf("Enter the number of seats in the flights: \n");
    scanf("%d",&seats);
    int input;
    printf("1. for booking\n 2. for cancellation 3. check available \n");
    scanf("%d",&input);
    int book;
    pthread_mutex_init(&lock,NULL);
    switch (input)
    {
    case 1
        printf("Enter the Number of seats to be booked: \n");
        scanf("%d",&book);
        for(int i=0;i<book;i++){
            pthread_create(&t[i],NULL,ticketBook,NULL);

        }
        for(int i=0;i<book;i++){
            pthread_join(t[i],NULL);

        }

        break;
    case 2
        pthread_t t1;
        pthread_create(&t1,NULL,cancelTicket,NULL);
        pthread_join(t1,NULL);
    break;
    case 3
       printf("The no. available seats is %d ",num_tickets);
    break;
    default:
    exit(0);
        break;
    }

}