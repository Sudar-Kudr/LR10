#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
using namespace std;
using namespace std::filesystem;

int main()
{
    bool key=1;
    while (key==1){
        cout << "1)вывод на экран текущего каталога (current path);\n";
        cout << "2)вывод на экран содержимого каталога (только названия файлов/каталогов, без пути);\n";
        cout << "3)создание каталога (папки) с предварительной проверкой на существование одноимённого каталога;\n";
        cout << "4)вывод на экран размера файла;\n";
        cout << "5)копирование файла;\n";
        cout << "6)удаление файла;\n";
        cout << "7)удаление каталога с файлами;\n";
        cout << "8)перемещение по каталогам (вверх и вниз по вложенности);\n";
        cout << "9)переименование файлов и каталогов;\n";
        cout << "10)перемещение файлов и каталогов.\n";
        cout << "Введите номер\n";
        int num;
        cin >> num;
        //1
        path cur_path = current_path();
        if (num==1){
            std::cout << "Текущий путь: " << cur_path << endl << endl;
        }
        //2
        if (num==2){
            for (const auto & entry : directory_iterator(cur_path))
                std::cout << entry.path().filename() << std::endl;
        }
        //3
        if (num==3){
            std::string name;
            cout << "Имя\n";
            cin >> name;
            path p(cur_path / name);
            if(exists(p)){
                cout << "Каталог " << name << " уже есть\n";
            }
            else
                create_directory(cur_path / name);
        }
        //4
        if (num==4){
            std::string nameFile;
            std::string text;
            cout << "Имя\n";
            cin >> nameFile;
            nameFile = nameFile +".txt";
            
            if (!exists(nameFile))
            {
                cout << "Запись в " << nameFile << " :\n";
                std::cin.ignore();
                getline (cin, text);
                ofstream of(nameFile);
                of << text << endl;
                of.close();
            }
            else
                cout << nameFile << " размер=" << file_size(nameFile) << endl;
        }
        //5
        if (num==5){
            std::string nameFile, nameFileCopy;
            cout << "Имя файла\n";
            cin >> nameFile;
            nameFileCopy = nameFile + "_copy.txt";
            nameFile = nameFile + ".txt";
            
            if(!exists(nameFileCopy)){
                copy(nameFile, nameFileCopy);
                cout << "Копирование успешно!\n";
            }
            else
                cout << "Файл " << nameFile << " уже скопирован\n";
        }
        //6
        if (num==6){
            int numb;
            cout << "Удаление файла с директорией или без ?\n1)С директорией\n2)без директории\n";
            cin >> numb;
            std::string nameDir;
            std::string nameFile;
            cout << "Имя файла\n";
            cin >> nameFile;
            nameFile = nameFile +".txt";
            
            if (numb == 0){
                remove(nameFile);
                cout << "Удаление успешно!\n";
            }
            else if (numb == 1){
                cout << "Имя каталога\n";
                cin >> nameDir;
                remove(nameDir+"/"+nameFile);
                cout << "Удаление успешно!\n";
            }
            else
                cout << "Ошибка!\n";
        }
        //7
        if (num==7){
            std::string nameDir;
            cout << "Имя каталога\n";
            cin >> nameDir;
            remove_all(nameDir);
            std::cout << "Удаление выполнено\n";
        }
        //8
        if (num==8){
            current_path("..");  //на уровень выше перейти
            cur_path = current_path();
            std::cout << "Current path is " << cur_path << endl << endl;
            
            create_directory("new_cur_dir");
            current_path("new_cur_dir");
            cur_path = current_path();
            std::cout << "Current path is " << cur_path << endl << endl;
            
        }
        //9
        if (num==9){
            bool num1, num2;
            cout << "Переименовать каталог?\nда(1)    нет(0)\n";
            cin >> num1;
            if(num1 == 1){
                std::string nameDir, REnameDir;
                
                cout << "Имя каталога\n";
                cin >> nameDir;
                
                cout << "Переименовать на\n";
                cin >> REnameDir;

                rename(nameDir, REnameDir);
                cout << "Переименование успешно!\n";
            }
            
            cout << "Переименовать файл?\nда(1)    нет(0)\n";
            cin >> num2;
            if (num2 == 1){
                std::string nameFile, REnameFile;
                cout << "Имя файла\n";
                cin >> nameFile;
                nameFile = nameFile + ".txt";
                
                cout << "Переименовать на\n";
                cin >> REnameFile;
                REnameFile = REnameFile + ".txt";

                rename(nameFile, REnameFile);
                cout << "Переименование успешно!\n";
            }
        }
        //10
        if (num==10){
            std::string nameDir, toDir, nameFile;
            bool num1, num2;
            cout << "Переместить каталог?\nда(1)    нет(0)\n";
            cin >> num1;
            if(num1 == 1){
                cout << "Имя каталога\n";
                cin >> nameDir;
                
                cout << "Переместить в\n";
                cin >> toDir;

                rename(nameDir, toDir+"/"+nameDir);
                cout << "Перемещение успешно!\n";
            }
            
            cout << "Переместить файл?\nда(1)    нет(0)\n";
            cin >> num2;
            if (num2 == 1){
                cout << "Имя файла\n";
                cin >> nameFile;
                nameFile = nameFile + ".txt";
                
                cout << "Переместить в\n";
                cin >> toDir;

                rename(nameFile, toDir+"/"+nameFile );
                cout << "Перемещение успешно!\n";
            }
            
        }
        
        cout << "     еще?";
        cout << "ДА(1)    НЕТ(0)\n";
        cin >> key;
    }
    return 0;
}
