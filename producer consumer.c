#include<stdio.h>
#include<stdlib.h>
int mutex = 1;  
int full = 0; 
int empty = 10; 
int x = 0;     

void producer() {
    --mutex;   
    ++full;     
    --empty;    
    x++;
    printf("\nProducer produces item %d", x);
    ++mutex;    
}

void consumer() {
    --mutex;   
    --full;     
    ++empty;   
    printf("\nConsumer consumes item %d", x);
    x--;
    ++mutex;    
}

int main() {
    for(int i = 0; i < 5; i++) {
        if (mutex == 1 && empty != 0) {
            producer();
        } else {
            printf("\nBuffer is full!");
        }
    }

    for(int i = 0; i < 3; i++) {
        if (mutex == 1 && full != 0) {
            consumer();
        } else {
            printf("\nBuffer is empty!");
        }
    }

    return 0;
}


//output
Producer produces item 1
Producer produces item 2
Producer produces item 3
Producer produces item 4
Producer produces item 5
Consumer consumes item 5
Consumer consumes item 4
Consumer consumes item 3
