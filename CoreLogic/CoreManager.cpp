
#include "../GUI/GUIManager.cpp"

GUIManager::GUIManager(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("My App");
    resize(800, 600);
}