#ifndef LITESCREENGUI_H
#define LITESCREENGUI_H

#include <QMainWindow>

namespace Ui {
class litescreengui;
}

class litescreengui : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit litescreengui(QWidget *parent = 0);
    ~litescreengui();

private slots:

    void on_client_start_clicked();

    void on_server_start_clicked();
    
private:
    Ui::litescreengui *ui;
    QMenu *fileMenu;
    QMenu *helpMenu;

    QAction *exitaction;
    QAction *helpaction;
    QAction *aboutaction;





    /** The Following two fuctions generates credentials that can be used to connect to server from a client **/
    char* setServerIP();  //Sets the IP Address of the server in the textbox in server Tab
    long setServerPort(); //Sets a free random port number in the server in the textbox in server tab
};

#endif // LITESCREENGUI_H
