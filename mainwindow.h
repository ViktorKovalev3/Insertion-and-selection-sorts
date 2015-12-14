#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "QDebug"
#include <cmath>
#include <ctime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_push_generate_clicked();

    void on_push_selection_sort_clicked();

    void on_push_insertion_sort_clicked();

    void on_push_string_mode_clicked();

    void on_push_integer_mode_clicked();

    void on_print_generated_clicked();

    void on_view_result_selection_clicked();

    void on_view_result_selection_2_clicked();

private:
    bool flag_mode; //0 - работа с числами, 1 - со строками
    void generateArray(int size);
    QVector<int> int_input_vector;
    QVector<QString> string_input_vector;

    QVector<int> int_output_vector_for_selection;
    QVector<QString> string_output_vector_for_selection;

    QVector<int> int_output_vector_for_insertion;
    QVector<QString> string_output_vector_for_insertion;

    QString vectorToQString(const QVector<int>& vector);
    QString vectorToQString(const QVector<QString>& vector);
    void QStringToVector(QString& str, QVector<int>&);
    void QStringToVector(QString& str, QVector<QString>&);

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
