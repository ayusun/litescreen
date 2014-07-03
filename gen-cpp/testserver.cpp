#include "servernode.h"
int main() {
    ServerNode node("localhost",5000);
    node.bootup();
}
