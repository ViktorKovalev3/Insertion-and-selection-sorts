#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "insertion-sort.h"
#include "selection-sort.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    flag_mode(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_push_generate_clicked(){
    generateArray( (ui->number_for_generate->text()).toInt() );
    ui->input_plain->clear();
}

void MainWindow::generateArray(int size){
    srand (time(NULL));
    if (!flag_mode){
        //0 - int
        int_input_vector.clear();
        for (int i = 0; i < size; ++i){
            int_input_vector.push_back(rand() % 1000);
        }
    }else{
        //1 - string
        string_input_vector.clear();
        for (int i = 0; i < size; ++i){
            string_input_vector.push_back( QString(rand() % 1000) );
        }
    }
}

QString MainWindow::vectorToQString(const QVector<int> &vector)
{
    QString tmp_str;
    for (auto iter = vector.begin(); iter < vector.end(); ++iter){
        tmp_str += QString::number(*iter);
        tmp_str += " ";
    }
    tmp_str = tmp_str.left(tmp_str.length() - 1); //Remove last character
    return tmp_str;
}

QString MainWindow::vectorToQString(const QVector<QString> &vector)
{
    QString tmp_str;
    for (auto iter = vector.begin(); iter < vector.end(); ++iter){
        tmp_str += *iter;
        tmp_str += " ";
    }
    tmp_str = tmp_str.left(tmp_str.length() - 1); //Remove last character

    return tmp_str;
}

void MainWindow::on_push_selection_sort_clicked()
{
    if ( (ui->input_plain->toPlainText()).isEmpty() && int_input_vector.isEmpty()){
        ui->output_plain_selection->clear();
        ui->output_plain_selection->insertPlainText("Пустые входные данные!");
    }else{
        if (!flag_mode){
            //0 - int
            int_output_vector_for_selection.clear();
            if (int_input_vector.isEmpty()){
                //Read from QEdit
                QString tmp = ui->input_plain->toPlainText();
                QStringList list = tmp.split(" ");
                list.removeLast();
                foreach (const QString &str, list)
                    int_output_vector_for_selection << str.toInt();
                list.clear(); tmp.clear();
            }else{
                int_output_vector_for_selection = int_input_vector;
            }

            std::time_t start_time = std::clock();
            selection_sort(int_output_vector_for_selection.begin(), int_output_vector_for_selection.end());
            std::time_t end_time = std::clock();

            ui->time_selection_sort->clear();
            ui->time_selection_sort->insert(QString::number(end_time - start_time)+" мс");
            ui->output_plain_selection->clear();

        }else{
            //1 -str
            if (string_input_vector.isEmpty()){
                string_output_vector_for_selection.clear();
                QString tmp = ui->input_plain->toPlainText();
                QStringList list = tmp.split(" ");
                foreach (const QString &str, list)
                    string_output_vector_for_selection << str;
                list.clear(); tmp.clear();
            }else{
                string_output_vector_for_selection = string_input_vector;
            }

            std::time_t start_time = std::clock();
            selection_sort(string_output_vector_for_selection.begin(), string_output_vector_for_selection.end());
            std::time_t end_time = std::clock();

            ui->time_selection_sort->clear();
            ui->time_selection_sort->insert(QString::number(end_time - start_time)+" мс");
            ui->output_plain_selection->clear();
        }
    }
}
#include <QDataStream>
void MainWindow::on_push_insertion_sort_clicked()
{
    if ( (ui->input_plain->toPlainText()).isEmpty() && int_input_vector.isEmpty()){
        ui->output_plain_insertion->clear();
        ui->output_plain_insertion->insertPlainText("Пустые входные данные!");
    }else{
        if (!flag_mode){
            //0 - int
            if (int_input_vector.isEmpty()){
                //Read from QEdit
                QString tmp = ui->input_plain->toPlainText();
                QStringList list = tmp.split(" ");
                list.removeLast();
                foreach (const QString &str, list)
                    int_output_vector_for_insertion << str.toInt();
                list.clear(); tmp.clear();
            }else{
                int_output_vector_for_insertion = int_input_vector;
            }

            std::time_t start_time = std::clock();
            insertion_sort(int_output_vector_for_insertion.begin(), int_output_vector_for_insertion.end());
            std::time_t end_time = std::clock();

            ui->time_insertion_sort->clear();
            ui->time_insertion_sort->insert(QString::number(end_time - start_time)+" мс");
            ui->output_plain_insertion->clear();
        }else{
            //1 -str
            if (string_input_vector.isEmpty()){
                string_output_vector_for_insertion.clear();
                QString tmp = ui->input_plain->toPlainText();
                QStringList list = tmp.split(" ");
                foreach (const QString &str, list)
                    string_output_vector_for_insertion << str;
                list.clear(); tmp.clear();
            }else{
                string_output_vector_for_insertion = string_input_vector;
            }

            std::time_t start_time = std::clock();
            insertion_sort(string_output_vector_for_insertion.begin(), string_output_vector_for_insertion.end());
            std::time_t end_time = std::clock();

            ui->time_insertion_sort->clear();
            ui->time_insertion_sort->insert(QString::number(end_time - start_time)+" мс");
            ui->output_plain_insertion->clear();
        }
    }
}

void MainWindow::on_push_string_mode_clicked()
{
    flag_mode = 1;
}

void MainWindow::on_push_integer_mode_clicked()
{
    flag_mode = 0;
}



void MainWindow::on_print_generated_clicked()
{
    ui->input_plain->clear();
    if (!int_input_vector.isEmpty()){
        if (!flag_mode){
            //0 - int
            ui->input_plain->insertPlainText(vectorToQString(int_input_vector));
        }else {
            //1 - string
            ui->input_plain->insertPlainText(vectorToQString(string_input_vector));
        }
    }
}

void MainWindow::on_view_result_selection_clicked()
{
    ui->output_plain_selection->clear();
    if (!flag_mode){
        //0 - int
        ui->output_plain_selection->insertPlainText(vectorToQString(int_output_vector_for_selection));
    }else{
        //1 - string
        ui->output_plain_selection->insertPlainText(vectorToQString(string_output_vector_for_selection));
    }
}

void MainWindow::on_view_result_selection_2_clicked()
{
    ui->output_plain_insertion->clear();
    if (!flag_mode){
        //0 - int
        ui->output_plain_insertion->insertPlainText(vectorToQString(int_output_vector_for_insertion));
    }else{
        //1 - string
        ui->output_plain_insertion->insertPlainText(vectorToQString(string_output_vector_for_insertion));
    }
}
