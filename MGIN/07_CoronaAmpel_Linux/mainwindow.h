#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class LightWidget;
class FileDownloader;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void dataLoaded();

private:
    Ui::MainWindow *ui;
    FileDownloader *mDownloader = nullptr;
    LightWidget *mRedLight;
    LightWidget *mYellowLight;
    LightWidget *mGreenLight;
    void processDownload(QByteArray data);
};
#endif // MAINWINDOW_H
