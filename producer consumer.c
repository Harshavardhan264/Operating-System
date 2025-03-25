#include <stdio.h>
#include <stdlib.h>

// Semaphores
int mutex = 1;
int full = 0;
int empty = 10;
int x = 0;

void wait(int *s);
void signal(int *s);
void producer();
void consumer();

// Function Definitions
void wait(int *s) {
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void producer() {
    wait(&mutex);  
    if (empty > 0) {      
        signal(&full);
        wait(&empty);
        x++;
        printf("\nProducer produces item %d", x);
    } else {
        printf("\nBuffer is full!");
    }
    signal(&mutex); 
}

void consumer() {
    wait(&mutex); 
    if (full > 0) {       
        wait(&full);
        signal(&empty);
        printf("\nConsumer consumes item %d", x);
        x--;
    } else {
        printf("\nBuffer is empty!");
    }
    signal(&mutex); 
}

int main() {
    for (int i = 0; i < 5; i++) {
        producer(); 
    }

    for (int i = 0; i < 3; i++) {
        consumer();  
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
