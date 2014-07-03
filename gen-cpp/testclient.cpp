#include "clientnode.h"

using namespace std;
int main() {
    ClientNode client("localhost",65369);
    client.bootup();
    client.initializeHandshake();
    client.captureAndSend();
}
