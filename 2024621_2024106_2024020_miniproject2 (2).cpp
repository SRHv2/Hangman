#include <iostream>
#include <cstdlib>
using namespace std;
void clrscr() {
    system("cls");
}
string pick_a_location() {
    string string_countries[] = {
     "Afghanistan", "Albania", "Algeria", "Andorra", "Angola", "Antigua",
     "Argentina", "Armenia", "Australia", "Austria", "Azerbaijan", "Bahamas", "Bahrain",
     "Bangladesh", "Barbados", "Belarus", "Belgium", "Belize", "Benin", "Bhutan", "Bolivia",
     "Bosnia", "Botswana", "Brazil", "Brunei", "Bulgaria", "BurkinaFaso",
     "Burundi", "CaboVerde", "Cambodia", "Cameroon", "Canada", "CentralAfricanRepublic",
     "Chad", "Chile", "China", "Colombia", "Comoros", "Congo",
     "CostaRica", "Croatia", "Cuba", "Cyprus", "Czech Republic", "Denmark",
     "Djibouti", "Dominica", "DominicanRepublic", "Ecuador", "Egypt", "Elsalvador",
     "EquatorialGuinea", "Eritrea", "Estonia", "Eswatini", "Ethiopia",
     "Fiji", "Finland", "France", "Gabon", "Gambia", "Georgia", "Germany", "Ghana", "Greece",
     "Grenada", "Guatemala", "Guinea", "GuinenBissau", "Guyana", "Haiti", "HolySee",
     "Honduras", "Hungary", "Iceland", "India", "Indonesia", "Iran", "Iraq", "Ireland",
     "Israel", "Italy", "Jamaica", "Japan", "Jordan", "Kazakhstan", "Kenya", "Kiribati",
     "Kuwait", "Kyrgyzstan", "Laos", "Latvia", "Lebanon", "Lesotho", "Liberia", "Libya",
     "Liechtenstein", "Lithuania", "Luxembourg", "Madagascar", "Malawi", "Malaysia",
     "Maldives", "Mali", "Malta", "MarshallIslands", "Mauritania", "Mauritius", "Mexico",
     "Micronesia", "Moldova", "Monaco", "Mongolia", "Montenegro", "Morocco", "Mozambique",
     "Myanmar", "Namibia", "Nauru", "Nepal", "Netherlands", "NewZealand",
     "Nicaragua", "Niger", "Nigeria", "NorthKorea", "NorthMacedonia", "Norway", "Oman",
     "Pakistan", "Palau", "Palestine", "Panama", "PapuaNewGuinea", "Paraguay",
     "Peru", "Philippines", "Poland", "Portugal", "Qatar", "Romania", "Russia", "Rwanda",
     "SaintKittsAndNevis", "SaintLucia", "SaintVincentAndTheGrenadines", "Samoa",
     "SanMarino", "SaoTomeAndPrincipe", "SaudiArabia", "Senegal", "Serbia", "Seychelles",
     "SierraLeone", "Singapore", "Slovakia", "Slovenia", "Solomonislands", "Somalia",
     "SouthAfrica", "SouthKorea", "SouthSudan", "Spain", "SriLanka", "Sudan", "Suriname",
     "Sweden", "Switzerland", "Syria", "Tajikistan", "Tanzania", "Thailand", "TimorLeste",
     "Togo", "Tonga", "TrinidadAndTobago", "Tunisia", "Turkey", "Turkmenistan", "Tuvalu",
     "Uganda", "Ukraine", "UnitedArabEmirates", "UnitedKingdom", "UnitedStatesOfAmerica",
     "Uruguay", "Uzbekistan", "Vanuatu", "Venezuela", "Vietnam", "Yemen", "Zambia", "Zimbabwe"
    };

    int random_number = rand() % 196;
    return string_countries[random_number];
}
string  convert_to_underscore(string word, int c) {
    string  hidden_word = "";
    for (int i = 0; i < c; i++) {
        if (word[i] != ' ')
            hidden_word += '_';
        }
    return hidden_word;
}
    int main()
    {
        int countT = 0, countF = 0, chances = 11;
        bool found, win = false;
        char letter;
        srand(static_cast<unsigned int>(time(0)));
        string word = pick_a_location();
        int letter_count = 0;
        for (int i = 0; word[i] != '\0'; i++)
            letter_count++;
        bool matched[50] = { false };
        string hidden_word = convert_to_underscore(word, letter_count);
        cout << "                    __    __       ___      .__   __.   _______ .___  ___.      ___      .__   __.\n";
        cout << "                   |  |  |  |     /   \\     |  \\ |  |  /  _____||   \\/   |     /   \\     |  \\ |  |\n";
        cout << "                   |  |__|  |    /  ^  \\    |   \\|  | |  |  __  |  \\  /  |    /  ^  \\    |   \\|  |\n";
        cout << "                   |   __   |   /  /_\\  \\   |  . `  | |  | |_ | |  |\\/|  |   /  /_\\  \\   |  . `  |\n";
        cout << "                   |  |  |  |  /  _____  \\  |  |\\   | |  |__| | |  |  |  |  /  _____  \\  |  |\\   |\n";
        cout << "                   |__|  |__| /__/     \\__\\ |__| \\__|  \\______| |__|  |__| /__/     \\__\\ |__| \\__|\n\n";
        cout << "                                           Guess the country. Good luck!\n ";
        while (countT < letter_count && countF < 11) {
            cout << hidden_word << endl;
            cout << chances - countF << " chances left.\n";
            cout << "Input a letter: "; cin >> letter;
            letter = toupper(letter);
            found = false;
            if (letter >= 'a' or letter <= 'z' or letter >= 'A' or letter <= 'Z') {
                for (int i = 0; i <= letter_count; i++) {
                    if (!matched[i]) {
                        if (letter == word[i]) {
                            hidden_word[i] = letter;
                            countT++;
                            matched[i] = true;
                            cout << countT << endl;
                            found = true;
                        }
                        if (letter + 32 == word[i]) {
                            hidden_word[i] = (char)letter + 32;
                            countT++;
                            matched[i] = true;
                            cout << countT << endl;
                            found = true;
                        }


                    }
                }
            } clrscr();
            if (!found)
            {
                countF++;
                switch (chances - countF) {
                case (11):
                    cout << "";
                    break;
                case (10):
                    cout << "\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\t|\n";
                    break;
                case (9):
                    cout << "\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\tO " << endl;
                    break;
                case (8):
                    cout << "\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\tO\n\t\t| " << endl;
                    break;
                case (7):
                    cout << "\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\tO\n\t\t|- " << endl;
                    break;
                case (6):
                    cout << "\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\tO\n\t       -|- " << endl;
                    break;
                case (5):
                    cout << "\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\tO\n\t       -|-> " << endl;
                    break;
                case (4):
                    cout << "\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\tO\n\t      <-|-> " << endl;
                    break;
                case (3):
                    cout << "\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\tO\n\t      <-|->\n\t       /" << endl;
                    break;
                case (2):
                    cout << "\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\tO\n\t      <-|->\n\t       / \\" << endl;
                    break;
                case (1):
                    cout << "\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\tO\n\t      <-|->\n\t       / \\" << endl << "\t       '" << endl;
                    break;
                case (0):
                    cout << "\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\t|\n\t\tO\n\t      <-|->\n\t       / \\" << endl << "\t       ' '" << endl;
                    break;
                }
                if (chances - countF == 0) {
                    cout << "  __     ______  _    _   _      ____   _____ ______    \n";
                    cout << "  \\ \\   / / __ \\| |  | | | |    / __ \\ / ____|  ____| \n";
                    cout << "   \\ \\_/ / |  | | |  | | | |   | |  | | (___ | |__       \n";
                    cout << "    \\   /| |  | | |  | | | |   | |  | |\\___ \\|  __|         \n";
                    cout << "     | | | |__| | |__| | | |___| |__| |____) | |____        \n";
                    cout << "     |_|  \\____/ \\____/  |______\\____/|_____/|______|       \n";
                    cout << "                                                               \n";
                    cout << "**************************************************************************\n";
                    cout << "*                                                                        *\n";
                    cout << "*                            GAME OVER! YOU LOST!                        *\n";
                    cout << "*                                                                        *\n";
                    cout << "               		     The country was " << word << "            \n";
                    cout << "*                                                                        *\n";
                    cout << "**************************************************************************\n";



                    return 0;
                }

            }
        }

        cout << " __     ______  _    _    __	      ______  _   _ \n";
        cout << " \\ \\   / / __ \\| |  | |   \\ \\        / / __ \\| \\ | |\n";
        cout << "  \\ \\_/ / |  | | |  | |    \\ \\  /\\  / / |  | |  \\| |\n";
        cout << "   \\   /| |  | | |  | |     \\ \\/  \\/ /| |  | | . ` |\n";
        cout << "    | | | |__| | |__| |      \\  /\\  / | |__| | |\\  |\n";
        cout << "    |_|  \\____/ \\____/        \\/  \\/   \\____/|_| \\_|\n";
        cout << "                                                                          \n";
        cout << "**************************************************************************\n";
        cout << "*                                                                        *\n";
        cout << "*                      CONGRATULATIONS! YOU WON!                         *\n";
        cout << "*                                                                        *\n";
        cout << "*          Celebrate your victory with glory and pride!                  *\n";
        cout << "*                                                                        *\n";
        cout << "**************************************************************************\n";

        return 0;
    }