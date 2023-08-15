extern void abort(void);

void reach_error() { assert(0); }

#define USAGE "./twostage <param1> <param2>n"

static int iTThreads = 2;
static int iRThreads = 1;
static int data1Value = 0;
static int data2Value = 0;


void svp_simple_333_001_isr_1(void *param) {
    data1Value = 1;
    data2Value = data1Value + 1;
}

void svp_simple_333_001_isr_2(void *param) {
    int t1 = -1;
    int t2 = -1;

    t1 = data1Value;
   
    t2 = data2Value;

    return NULL;
}

int svp_simple_333_001_main(int argc, char *argv[]) {
    int i,err;

    

    data1Lock = (// pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
    data2Lock = (// pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
    if (0 != (err = // pthread_mutex_init(data1Lock, NULL))) {
        fprintf(stderr, "// pthread_mutex_init error: %dn", err);
        exit(-1);
    }
    if (0 != (err = // pthread_mutex_init(data2Lock, NULL))) {
        fprintf(stderr, "// pthread_mutex_init error: %dn", err);
        exit(-1);
    }

    // pthread_t tPool[iTThreads];
    // pthread_t rPool[iRThreads];

    for (i = 0; i < iTThreads; i++) {
        if (0 != (err = // pthread_create(&tPool[i], NULL, &funcA, NULL))) {
            fprintf(stderr, "Error [%d] found creating 2stage thread.n", err);
            exit(-1);
        }
    }

    for (i = 0; i < iRThreads; i++) {
        if (0 != (err = // pthread_create(&rPool[i], NULL, &funcB, NULL))) {
            fprintf(stderr, "Error [%d] found creating read thread.n", err);
            exit(-1);
        }
    }

    for (i = 0; i < iTThreads; i++) {
        if (0 != (err = // pthread_join(tPool[i], NULL))) {
            fprintf(stderr, "pthread join error: %dn", err);
            exit(-1);
        }
    }

    for (i = 0; i < iRThreads; i++) {
        if (0 != (err = // pthread_join(rPool[i], NULL))) {
            fprintf(stderr, "pthread join error: %dn", err);
            exit(-1);
        }
    }

    return 0;
}

void lock(// pthread_mutex_t *lock) {
    int err;
    if (0 != (err = // pthread_mutex_lock(lock))) {
        fprintf(stderr, "Got error %d from // pthread_mutex_lock.n", err);
        exit(-1);
    }
}

void unlock(// pthread_mutex_t *lock) {
    int err;
    if (0 != (err = // pthread_mutex_unlock(lock))) {
        fprintf(stderr, "Got error %d from // pthread_mutex_unlock.n", err);
        exit(-1);
    }
}
   
