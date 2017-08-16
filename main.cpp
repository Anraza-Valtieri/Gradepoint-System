// WAS a 'Hello World!' program
#include <iostream>
#include <iomanip>
void consultgrades(){

}

int main()
{
    std::cout << "Welcome to ABC University" << std::endl;
    std::cout << "Grade point Consulting System\n" << std::endl;
    //consultgrades();

    std::string letterpoint[] = {"A+","A","A-",
                                 "B+","B","B-",
                                 "C+","C","D+",
                                 "D","F"};
    float gradepoint[] = {5.0,5.0,4.5,
                          4,3.5,3,
                          2.5,2,1.5,
                          1,0};
    // Continue Flag
    std::string conti = "Y";
    while(conti == "Y") {
        // input grades
        std::string grade;
        std::cout << "Enter Letter grade: ";
        std::cin >> grade;

        // FORCE UPPERCASE cause Y and y are not friends!
        //std::cout << "[DEBUG] Entered grade = " << grade <<std::endl;
        std::transform(grade.begin(), grade.end(), grade.begin(), ::toupper);
        //std::cout << "[DEBUG] grade forced uppercase = " << grade <<std::endl;
        int i;
        int max = sizeof(letterpoint) / sizeof(letterpoint[0])-1;
        for (i = 0; i != max; i++) {
            //std::cout << "[DEBUG] i is now : " << std::to_string(i) << " Max is " << max << std::endl;
            if (grade == letterpoint[i]) {
                // Set for 1 deci placing for the float using setprec and fixed
                std::cout << "Your grade point is " << std::setprecision(1) << std::fixed << gradepoint[i] << std::endl;
                std::cout << "Continue?: ";
                std::cin >> conti;
                std::transform(conti.begin(), conti.end(), conti.begin(), ::toupper);
                if (conti == "Y") {
                    std::cout << std::endl;
                    break;
                } else {
                    std::cout << "\nAll the best ";
                    return 0;
                }

            }
            if(i == max){
                std::cout << "[DEBUG] Out of range, likely invalid grade: " << grade <<std::endl;
                std::cout << "Invalid Grade" << std::endl;
                std::cout << "Continue?: ";
                std::cin >> conti;
                std::transform(conti.begin(), conti.end(), conti.begin(), ::toupper);
                if (conti == "Y") {
                    std::cout << std::endl;
                } else{
                    std::cout << "\nAll the best ";
                    return 0;
                }
            }
        }

    }
    std::cout << "Grade point Consulting System exit\n" << std::endl;
    return 0;
}

