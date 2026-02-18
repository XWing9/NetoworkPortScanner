#include "GUIManager.h"

#ifdenf GUIMANAGER_H
#define GUIMANAGER_H

#include <QMainWindow>

class GUIManager : public QMainWindow {
    Q_OBJECT;

public:
    GUIManager(QWidget *parent = nullptr);
};

#endif