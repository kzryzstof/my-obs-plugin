// #include "threading.h"
//
// #include <obs-module.h>
// #include <util/threading.h>
//
// #include "util/bmem.h"
// #include <pthread.h>
//
// typedef struct thread_state {
//     int delay_in_ms;
//     void *func;
// } thread_state_t;
//
// static void *delayed_update_thread(void *arg) {
//
//     thread_state_t *thread_state = arg;
//
//     os_sleep_ms(thread_state->delay_in_ms);  // 2 seconds delay
//     thread_state->func();
//
//     return NULL;
// }
//
// void call_after(void *func, int ms) {
//
//     if (!func) {
//         return;
//     }
//
//     thread_state_t *thread_state = bzalloc(sizeof(thread_state_t));
//     thread_state->delay_in_ms   = ms;
//     thread_state->func          = func;
//
//     pthread_t thread;
//     pthread_create(&thread, NULL, delayed_update_thread, NULL);
//     pthread_detach(thread);
// }