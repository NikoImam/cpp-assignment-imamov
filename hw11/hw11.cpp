#include <boost/program_options.hpp>
#include <boost/filesystem/operations.hpp>

#include <string>
#include <iostream>
#include <map>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

std::vector<std::string> images;
std::vector<std::string> music;
std::vector<std::string> docs;
std::vector<std::string> other;

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
    
void sortFolder(const fs::path& folder)
{
    if(fs::exists(folder) && fs::is_directory(folder))
    {
        
        for (const auto& entry : fs::directory_iterator(folder))
        {
            fs::file_status st = entry.status();
            switch (st.type())
            {
                case fs::regular_file:
                    break;
                case fs::directory_file:
                    sortFolder(entry);
                    break;
                default:
                    break;
            }
        }
    }
}

int main(int argc, char** argv)
{
    

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "print usage message")
        ("path,p", po::value<std::string>()->default_value("path"), "Path to input_folder")
        ("rules,r", po::value<std::string>()->default_value("rules.txt"), "Path to rules file");
    
    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
    po::notify(vm);

    fs::path root_folder = "../hw11";

    fs::path folder = root_folder.string() + vm["path"].as<std::string>();
    std::string rules = vm["rules"].as<std::string>();   

    return 0;
}