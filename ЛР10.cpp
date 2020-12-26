#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
using namespace std;
using namespace std::filesystem;

int main()
{
    //1
    path cur_path = current_path();
    std::cout << "Текущий путь: " << cur_path << endl << endl;
    
    //2
    for (const auto & entry : directory_iterator(cur_path))
        std::cout << entry.path().filename() << std::endl;
    
    //3
    path p(cur_path / "new_dir");
    if(exists(p)){
        cout << "Каталог new_dir уже есть\n";
    }
    else
        create_directory(cur_path / "new_dir");
    
    //4
    ofstream of("test.txt");
    of << "Hello World!" << endl;
    of.close();
    cout << "Test.txt` размер=" << file_size("test.txt") << endl;
    
    //5
    if(!exists("new_dir/test.txt")){
        copy("test.txt", "new_dir/test.txt");
        cout << "Копирование успешно!\n";
    }
    else
        cout << "Файл test.txt уже существует в new_dir каталоге!\n";
    
    //6
    remove("new_dir/test.txt");
    cout << "Удаление успешно!\n";
    
    //7
    copy("test.txt", "new_dir/test1.txt");
    copy("test.txt", "new_dir/test2.txt");
    create_directory("new_dir/new_dir2");
    std::uintmax_t n = remove_all("new_dir");
    std::cout << "Удаление " << n << " каталога с файлами\n";
    
    //8
    create_directory("new_cur_dir");
    current_path("new_cur_dir");
    cur_path = current_path();
    std::cout << "Current path is " << cur_path << endl << endl;
    
    current_path("..");
    cur_path = current_path();
    std::cout << "Current path is " << cur_path << endl << endl;
    
    //9
    rename("new_cur_dir", "new_cur_dir_rename");
    rename("test.txt", "test2.txt");
    cout << "Переименование успешно!\n";
    
    //10
    rename("test2.txt", "new_cur_dir_rename/test2.txt");
    cout << "Перемещение успешно!\n";
    
    return 0;
}
