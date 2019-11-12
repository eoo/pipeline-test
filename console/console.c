#include <stdio.h>
#include <zmq.h>
#include <pthread.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

void * zmqserver(void * arg)
{   

    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    int rc = zmq_bind (responder, "tcp://*:5555");
    assert (rc == 0);
    int stop = 1;

    while (stop) {
        char buffer [10];
        zmq_recv (responder, buffer, 10, 0);
        printf ("Received message from client to: %s\n", buffer);
        sleep(1);
        zmq_send (responder, "OK", 10, 0);

        if(strcmp(buffer, "close") == 0)
        {   
            printf("Closing zmqserver thread...\n");
            stop = 0;
        }

        if(strcmp(buffer, "print") == 0)
        {   
            printf("Printing Nothing\n");
        }

    }

    zmq_close (responder);
    zmq_ctx_destroy (context); 
   
    return (int *)0;
}

int main()
{
    pthread_t zmq_thread;
    void *pthread_ret;
    pthread_create(&zmq_thread, NULL, zmqserver, NULL);

    if (pthread_join(zmq_thread, &pthread_ret) != 0) {
        perror("pthread_join() error");
        exit(3);
    }
    printf("zmqserver thread exited with '%s'\n", pthread_ret);
    return 0; 
}