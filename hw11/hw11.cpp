#include <boost/program_options.hpp>
#include <boost/filesystem/operations.hpp>

#include <string>
#include <iostream>
#include <map>
#include <fstream>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

std::map<std::string, std::string> rulesMap;
fs::path root_folder ("../../hw11");
std::string folderPath;

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

void saveFile(fs::directory_entry entry)
{
    auto extension = entry.path().extension();
    auto filename = entry.path().stem();
    
    fs::path dest;

    if (rulesMap.count(extension.string()))
    {
        dest = folderPath + '/' + rulesMap[extension.string()] + '/' + filename.string() + extension.string();
    }
    else
    {
        dest = folderPath + "/Other/" + filename.string() + extension.string();
    }
    if (!fs::exists(dest.parent_path()))
    {
        fs::create_directory(dest.parent_path());
    }

    fs::copy(entry, dest);
    fs::remove(entry);
}

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
                    std::cout << entry << '\n';
                    saveFile(entry);
                    break;
                case fs::directory_file:
                    sortFolder(entry);
                    fs::remove(entry);
                    break;
                default:
                    break;
            }
        }
    }
}

void parseRules(std::string rulesPath)
{
    std::ifstream inp(root_folder/rulesPath);

    if (inp.is_open())
    {
        std::cout << "Rules:\n";

        std::string line;
        while(std::getline(inp, line))
        {
            std::string ext = ".";
            std::string folder = "";
            bool flag = false;

            for(auto e: line)
            {
                if(e == ':')
                {
                    flag = true;
                }
                else
                {
                    if(!flag)
                {
                    ext += e;
                }
                else
                {
                    folder += e;
                }
                }
            }
            
            rulesMap[ext] = folder;
            std::cout << ext << ':' << folder << '\n';
        }

        std::cout << '\n';
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

    if (vm.count("help") || !vm.count("path") || !vm.count("rules")) {
        std::cerr << desc << std::endl;
        return 1;
    }

    fs::path folder = root_folder/vm["path"].as<std::string>();
    folderPath = folder.string();

    std::string rules = vm["rules"].as<std::string>();
    parseRules(rules);
    try
    {
        sortFolder(folder);
        std::cout << "\nFolder " << folder << " was sorted successfully\n";
    }
    catch (std::exception e)
    {
        std::cout << "Error\n";
    }

    return 0;
}