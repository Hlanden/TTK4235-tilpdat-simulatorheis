#include <assert.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <pthread.h>

#include "hardware.h"

static int sockfd;
static pthread_mutex_t sockmtx;

int hardware_init() {
    char ip[16] = "localhost";
    char port[8] = "15657";

    pthread_mutex_init(&sockmtx, NULL);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(sockfd != -1 && "Unable to set up socket");

    struct addrinfo hints = {
        .ai_family      = AF_INET,
        .ai_socktype    = SOCK_STREAM,
        .ai_protocol    = IPPROTO_TCP,
    };
    struct addrinfo* res;
    getaddrinfo(ip, port, &hints, &res);

    int fail = connect(sockfd, res->ai_addr, res->ai_addrlen);
    assert(fail == 0 && "Unable to connect to simulator server");

    freeaddrinfo(res);

    send(sockfd, (char[4]) {0}, 4, 0);

    return 1; //jalla
}




void hardware_command_movement(HardwareMovement movement) {
    pthread_mutex_lock(&sockmtx);
    send(sockfd, (char[4]) {1, movement}, 4, 0);
    pthread_mutex_unlock(&sockmtx);
}


void hardware_command_order_light(int floor, HardwareOrder order_type, int on) {
    assert(floor >= 0);
    assert(floor < HARDWARE_NUMBER_OF_FLOORS);
    assert(order_type >= 0);
    assert(order_type < HARDWARE_NUMBER_OF_BUTTONS);

    pthread_mutex_lock(&sockmtx);
    send(sockfd, (char[4]) {2, order_type, floor, on}, 4, 0);
    pthread_mutex_unlock(&sockmtx);
}


void hardware_command_floor_indicator_on(int floor) {
    assert(floor >= 0);
    assert(floor < HARDWARE_NUMBER_OF_FLOORS);

    pthread_mutex_lock(&sockmtx);
    send(sockfd, (char[4]) {3, floor}, 4, 0);
    pthread_mutex_unlock(&sockmtx);
}


void hardware_command_door_open(int door_open) {
    pthread_mutex_lock(&sockmtx);
    send(sockfd, (char[4]) {4, door_open}, 4, 0);
    pthread_mutex_unlock(&sockmtx);
}


void hardware_command_stop_light(int on) {
    pthread_mutex_lock(&sockmtx);
    send(sockfd, (char[4]) {5, on}, 4, 0);
    pthread_mutex_unlock(&sockmtx);
}



int hardware_read_order(int floor, HardwareOrder order_type) {
    pthread_mutex_lock(&sockmtx);
    send(sockfd, (char[4]) {6, order_type, floor}, 4, 0);
    char buf[4];
    recv(sockfd, buf, 4, 0);
    pthread_mutex_unlock(&sockmtx);
    return buf[1];
}


int hardware_read_floor_sensor(int floor) {
    pthread_mutex_lock(&sockmtx);
    send(sockfd, (char[4]) {7}, 4, 0);
    char buf[4];
    recv(sockfd, buf, 4, 0);
    pthread_mutex_unlock(&sockmtx);
    return buf[1] ? buf[2] == floor : 0;
}


int hardware_read_stop_signal(void) {
    pthread_mutex_lock(&sockmtx);
    send(sockfd, (char[4]) {8}, 4, 0);
    char buf[4];
    recv(sockfd, buf, 4, 0);
    pthread_mutex_unlock(&sockmtx);
    return buf[1];
}


int hardware_read_obstruction_signal(void) {
    pthread_mutex_lock(&sockmtx);
    send(sockfd, (char[4]) {9}, 4, 0);
    char buf[4];
    recv(sockfd, buf, 4, 0);
    pthread_mutex_unlock(&sockmtx);
    return buf[1];
}
