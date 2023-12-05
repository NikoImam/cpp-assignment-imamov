#include <boost/program_options.hpp>
#include <boost/filesystem/operations.hpp>

#include <string>
#include <iostream>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

// Код домашнего задания
  // Сортировщик файлов
  // На вход программе подается:
    // 1. путь к папке с файлами
    // 2. путь к файлу с правилами
  // Требуется: Выполнить сортировку файлов на основе правил (Фильтр-файл)
  // 
  // Фильтр-файл:
    // Тип (расширение):Папка
    // Пример = jpg:Images
  //
  // Пример:

    // rules
    // jpg:Images
    // png:Images
    // mp3:Music
    // txt:Docs
    // docx:Docs

    // input_folder
    // - music.mp3
    // - img.png
    // - pic.jpg
    // - inner_folder
    //  - exp1.jpg
    //  - exp2.txt
    //  - exp3.ext
    //  - exp4.docx

  // Результат работы программы
    // input_folder
    // Images
    //  - img.png
    //  - pic.jpg
    //  - exp1.jpg
    // Music
    //  - music.mp3
    // Docs
    //  - exp2.txt
    //  - exp4.docx
    // Other
    //  - exp3.ext

    // Требования
    // - Расширения: png, jpg, docx, txt, mp3
    // - Минимум 5 файлов на каждое расширение
    // - Содержимое файлов не важно
    // - Вложенные директории с файлами
    

int main(int argc, char** argv)
{
    return 0;
}