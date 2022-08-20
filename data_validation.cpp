#include <iostream>
#include <regex>

bool email_val(std::string str) {
    std::string mail = "@gmail.com";
    if ((str.size() < 5 || str.size() > 41) || (str[0] < 'a' || str[0] > 'z')) {
        return false;
    }
    int i = 0;
    while (i < str.size() - 10) {
        if (str[i] >= 'a' && str[i] <= 'z') { }
        else if (str[i] >= '0' && str[i] <= '9') { }
        else if (str[i] == '-' || str[i] == '_' || str[i] == '.') {
            if ((str[i] == '-' && str[i+1] == '-') || (str[i] == '_' && str[i+1] == '_') || (str[i] == '.' && str[i+1] == '.')) {
                return false;
            }
            ++i;
        }
        else
            return false;
        ++i;
    }
    while (i < str.size()) {
        for (int j = 0; j < mail.size(); ++j) {
            if (str[i] != mail[j]) {
                return false;
            }
            ++i;
        }
    }
    return true;
}

bool data_val(std::string str) {
    int i = 1;
    while (str[i] != '.') {
        if (str[0] >= '0' && str[0] <= '3' && str[i] >= '0' && str[i] <= '9') {
            if ((str[0] == '0' && str[i] == '0') || (str[0] == '3' && str[i] > '1')) {
                return false;
            }
        }
        else
            return false;
        ++i;
    }
    ++i;
    while (str[i] != '.') {
        if (str[i] >= '0' && str[i] <= '1') {
            ++i;
            if (str[i] >= '0' && str[i] <= '2') {
                ++i;
            }
            else
                return false;
        }
        else
            return false;
    }
    ++i;
    int count = 0;
    while (i < str.size()) {
        if (str[i] >= '0' && str[i] <= '9') {
            ++i;
            ++count;
        }
        else
            return false;
    }
    if (count == 4) {
        return true;
    }
}

bool cred_card_val(std::string str) {
    int count = 0;
    if (str.size() != 19) {
        return false;
    }
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != ' ') {
            if (str[i] >= '0' && str[i] <= '9') {
                ++count;
            }
        }
    }
    return count == 16;
}

bool phone_num_val(std::string str) {
    int count = 0;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != ' ') {
            if (str[i] >= '0' && str[i] <= '9') {
                ++count;
            }
            else
                return false;
        }
    }
    return count == 9;
}

bool website_val(std::string str) {
    const std::regex pattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");

    if (regex_match(str, pattern)) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    //std::string str = "17.12.2012";
    //std::cout << data_val(str);
    //std::string mail = "adfghh@gmail.com";
    //std::cout << email_val(mail);
    //std::string str3 = "1234 5678 9012 3456";
    //std::cout << cred_card_val(str3);
    //std::string str4 = "094 85 64 57";
    //std::cout << phone_num_val(str4);
    //std::string str5 = "https://am.linkedin.com/company/picsart-academy";
    //std::cout << website_val(str5);
}
