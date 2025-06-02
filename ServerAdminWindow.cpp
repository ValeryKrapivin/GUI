#include "ServerAdminWindow.h"
#include <QHeaderView>
#include <QMessageBox>

// Конструктор
ServerAdminWindow::ServerAdminWindow(QWidget *parent) : QMainWindow(parent) {
    setupUI();
    loadMessages();
    loadUsers();
}

// Настройка интерфейса
void ServerAdminWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Создаем таблицы
    messagesTable = new QTableWidget(this);
    usersTable = new QTableWidget(this);

    // Настройка таблицы сообщений
    messagesTable->setColumnCount(3);
    QStringList msgHeaders = {"ID", "Отправитель", "Сообщение"};
    messagesTable->setHorizontalHeaderLabels(msgHeaders);
    messagesTable->horizontalHeader()->setStretchLastSection(true);
    messagesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    messagesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Настройка таблицы пользователей
    usersTable->setColumnCount(3);
    QStringList userHeaders = {"ID", "Имя пользователя", "Статус"};
    usersTable->setHorizontalHeaderLabels(userHeaders);
    usersTable->horizontalHeader()->setStretchLastSection(true);
    usersTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    usersTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Кнопки управления пользователями
    banButton = new QPushButton("Забанить выбранного пользователя");
    disconnectButton = new QPushButton("Отключить выбранного пользователя");

    connect(banButton, &QPushButton::clicked, this, &ServerAdminWindow::banUser);
    connect(disconnectButton, &QPushButton::clicked, this, &ServerAdminWindow::disconnectUser);

    // Макеты для кнопок
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(banButton);
    buttonsLayout->addWidget(disconnectButton);

    // Основной макет
    QVBoxLayout *mainLayout = new QVBoxLayout;
    
    // Раздел сообщений
     QLabel *messagesLabel = new QLabel("Все сообщения");
     mainLayout->addWidget(messagesLabel);
     mainLayout->addWidget(messagesTable);

     // Раздел пользователей
     QLabel *usersLabel = new QLabel("Пользователи");
     mainLayout->addWidget(usersLabel);
     mainLayout->addWidget(usersTable);
     mainLayout->addLayout(buttonsLayout);

     centralWidget->setLayout(mainLayout);

     // Стиль оформления (минимальный)
     setStyleSheet(R"(
        QWidget {
            font-family: Arial;
            font-size: 14px;
        }
        QTableWidget {
            background-color: #f0f0f0;
            gridline-color: #ccc;
        }
        QPushButton {
            background-color: #4CAF50; 
            color: white; 
            padding: 8px 16px; 
            border: none; 
            border-radius: 4px;
        }
        QPushButton:hover {
            background-color: #45a049;
        }
     )");
}

// Загрузка сообщений (заглушка)
void ServerAdminWindow::loadMessages() {
   // Здесь должна быть логика получения данных из базы Postgres.
   // Для примера добавим фиктивные сообщения.
   messagesTable->setRowCount(3);

   QStringList msgs = {
       "1|user1|Hello!",
       "2|user2|Hi there!",
       "3|user1|Private message to user2"
   };

   for (int i=0; i<msgs.size(); ++i) {
       QStringList parts = msgs[i].split("|");
       for (int j=0; j<parts.size(); ++j) {
           QTableWidgetItem *item = new QTableWidgetItem(parts[j]);
           messagesTable->setItem(i,j,item);
       }
   }
}

// Загрузка пользователей (заглушка)
void ServerAdminWindow::loadUsers() {
   // Аналогично, фиктивные данные.
   usersTable->setRowCount(3);

   QStringList users = {
       "1|user1|Онлайн",
       "2|user2|Онлайн",
       "3|user3|Забанен"
   };

   for (int i=0; i<users.size(); ++i) {
       QStringList parts = users[i].split("|");
       for (int j=0; j<parts.size(); ++j) {
           QTableWidgetItem *item = new QTableWidgetItem(parts[j]);
           usersTable->setItem(i,j,item);
       }
   }
}

// Бан пользователя
void ServerAdminWindow::banUser() {
   auto selectedItems = usersTable->selectedItems();
   if (selectedItems.isEmpty()) {
       QMessageBox::warning(this, "Выбор пользователя", "Пожалуйста, выберите пользователя для бана.");
       return;
   }

   int row = selectedItems.first()->row();
   QString userId = usersTable->item(row, 0)->text();

   // Тут должна быть логика бана через базу данных.
   QMessageBox::information(this, "Бан пользователя", "Пользователь ID " + userId + " забанен.");

   // Обновляем статус в таблице (для примера)
   usersTable->setItem(row, 2, new QTableWidgetItem("Забанен"));
}

// Отключение пользователя
void ServerAdminWindow::disconnectUser() {
   auto selectedItems = usersTable->selectedItems();
   if (selectedItems.isEmpty()) {
       QMessageBox::warning(this, "Выбор пользователя", "Пожалуйста, выберите пользователя для отключения.");
       return;
   }

   int row = selectedItems.first()->row();
   QString userId = usersTable->item(row, 0)->text();

   // Логика отключения через базу данных.
   QMessageBox::information(this, "Отключение пользователя", "Пользователь ID " + userId + " отключен.");

   // Можно обновить статус или удалить из списка.
}
