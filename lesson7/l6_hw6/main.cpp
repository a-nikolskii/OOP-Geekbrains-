#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

const std::string FILENAME = "../l6_hw6/Yandex.html";
const std::string exchange_rates = "<span class=\"inline-stocks__value_inner\">";
const std::string span_tag_end = "</span>";
const std::string news_reference = "";

void search(std::string s, const std::string& span_tag_context, std::vector<std::string>& values_arr) {
    if (s.size() >= span_tag_context.size()){
        int pos_begin = s.find(span_tag_context);
        if (pos_begin != -1){ // проверка нужна так как find() возвращает -1, если не нашел строку и строка ниже выбрасывает exception
            s = s.substr(pos_begin + span_tag_context.size());
            int pos_end = s.find(span_tag_end);
            values_arr.push_back(s.substr(0, pos_end));
            search(s, span_tag_context, values_arr);
        }
    } else return;
}


int main(int argc, char *argv[])
{
    std::ifstream yandex_html;
    yandex_html.open(FILENAME);

    if (!yandex_html.is_open()) {
        std::cout << FILENAME << " open failed!\n";
        return 1;
    }

    std::cout << FILENAME << " is opened!" << std::endl;

    std::string tmp = "";
    std::vector<std::string> values_arr;

    do {
        tmp = "";
        getline(yandex_html,tmp);
        search(tmp, exchange_rates, values_arr);
    } while(!yandex_html.eof());

    yandex_html.close();
    std::cout << FILENAME << " closed!" << std::endl;

    for (auto it = values_arr.begin(); it != values_arr.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
