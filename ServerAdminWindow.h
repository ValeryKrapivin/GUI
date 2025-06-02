#ifndef SERVERADMINWINDOW_H
#define SERVERADMINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>

class ServerAdminWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit ServerAdminWindow(QWidget *parent = nullptr);
private slots:
    void loadMessages();
    void loadUsers();
    void banUser();
    void disconnectUser();

private:
    QTableWidget *messagesTable;
    QTableWidget *usersTable;
    QPushButton *banButton;
    QPushButton *disconnectButton;

    void setupUI();
};
#endif // SERVERADMINWINDOW_H
