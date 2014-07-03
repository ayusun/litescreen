#include "litescreengui.h"
#include "ui_litescreengui.h"

#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <stdlib.h>
#include <errno.h>
#include <iostream>
#include <unistd.h>
#include <boost/thread.hpp>

#include "../gen-cpp/servernode.h"
#include "../gen-cpp/clientnode.h"

litescreengui::litescreengui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::litescreengui)
{
    ui->setupUi(this);

    /** Generating Menu **/
    exitaction  = new QAction(("&Exit    (Alt+F4)"), this);

    helpaction  = new QAction("&Help", this);
    aboutaction = new QAction("&About", this);

    fileMenu = menuBar()->addMenu("&File");
    helpMenu = menuBar()->addMenu("&Help");

    fileMenu->addAction(exitaction);

    helpMenu->addAction(helpaction);
    helpMenu->addAction(aboutaction);

    // Makes the window of standard size, So that it can't be maximised or resized
    setWindowFlags( (windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowMaximizeButtonHint);
    setFixedSize(width(), height());

    // Fill the credentials in the textbox that will be used by the server to bind the connections

    char* ip = setServerIP();
    this->ui->txt_server_ip->setText(ip);

    long portnum = setServerPort();
    if(portnum > 0)
        this->ui->txt_server_port->setText(QString::number(portnum));
}

litescreengui::~litescreengui()
{
    delete ui;
}

// Generating system IP Address(IPV4)
char* litescreengui :: setServerIP(){
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;
    char *addr;

    getifaddrs (&ifap);
    for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr->sa_family==AF_INET) {
            sa = (struct sockaddr_in *) ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);
            if(strcmp(ifa->ifa_name, "lo") !=0 )
                return addr; //return the first address thats not loopback
        }
    }
    return "undefined";
}

long litescreengui :: setServerPort() {
    struct sockaddr_in serv_addr;

    srand (time(NULL));

    long portnum =  rand() % 55534 + 10000; // generates a random number between 10000 and 65534
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if( sockfd < 0 ) {
            return 0;
     }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portnum);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        return setServerPort();
    }

    // Close the socket so that it can be used to bind to that port again
    if (::close (sockfd) < 0 ) { //search close in global Context, For some weird reason,without (::) it is searching it inside class
        return errno;
    }
    return portnum;
}
/** When "Start ScreenShare" Button on Client tab in GUI is Clicked **/
void litescreengui::on_client_start_clicked()
{
    const char* ip_from_txt = this->ui->to_server_ip->text().toStdString().c_str();
    long port = this->ui->to_server_port->text().toLong();
    char *ip = new char[16];
    strcpy(ip,ip_from_txt);

    ClientNode *client = new ClientNode(ip, port);
    client->bootup();
    client->initializeHandshake();
    //client.captureAndSend();
    boost::thread clientthread(&ClientNode ::captureAndSend,client);
}

/** When "Start ScreenShare" Button on server tab in GUI is Clicked **/
void litescreengui::on_server_start_clicked()
{
    long port = this->ui->txt_server_port->text().toLong();

    //Create a server object and boot it up
    ServerNode *node = new ServerNode("localhost", port); //thought to make this node as class's private field but couldn't include servernode.h there hence allocated it from here
    boost::thread serverthread(&ServerNode :: bootup,node);

}
