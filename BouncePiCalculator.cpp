#include <iostream>
#include <string>
#include <cmath>
#include <chrono>

int main()
{
    std::cout << "Enter precision (d.p.): ";

    int precision = 0;

    std::cin >> precision;


    double m1 = pow(10, (precision * 2));

    std::cout << "Using mass of " + std::to_string(m1) + "\n";

    double m2 = 1;
    double u1 = 1;
    double u2 = 0;

    long long int i = 0;
    
    std::cout << "Show working? (Y/N): ";
    std::string showWorkingInput = "";

    std::cin >> showWorkingInput;

    bool showWorking = showWorkingInput == "Y" | showWorkingInput == "y";

    bool showProgress = false;
    if (!showWorking)
    {
        std::cout << "Show progress? (Y/N): ";
        std::string showProgressInput = "";
        std::cin >> showProgressInput;
        showProgress = showProgressInput == "Y" | showProgressInput == "y";
    }

    //Stopwatch stopwatch = new Stopwatch();
    //stopwatch.Start();

    auto start = std::chrono::high_resolution_clock::now();

    while (!(u1 < 0 & u1 < u2))
    {
        //  Elastic bounce equations
        double v1 = (((m1 - m2) / (m1 + m2)) * u1) + (((2 * m2) / (m1 + m2)) * u2);

        double v2 = (((m2 - m1) / (m1 + m2)) * u2) + (((2 * m1) / (m1 + m2)) * u1);

        i++;

        if (showWorking)
        {
            std::cout << "After bounce      " + std::to_string(i) + " - V1 = " + std::to_string(v1) + ", V2 = " + std::to_string(v2) + "\n";
        }

        u1 = v1;

        //Wall bounce
        if (v2 > 0)
        {
            u2 = -v2;
            i++;
            if (showWorking)
            {
                std::cout << "After wall bounce " + std::to_string(i) + " - V1 = " + std::to_string(v1) + ", V2 = " + std::to_string(v2) + "\n";
            }
            else if ((i % 10000000 == 0) & showProgress)
            {
                std::cout << "Bounce: " + std::to_string(i) + "\n";
            }
        }
        else
        {
            break;
        }

    }

    auto finish = std::chrono::high_resolution_clock::now();
    //stopwatch.Stop();

    std::chrono::duration<double> elapsed = finish - start;

    std::string outString = std::to_string(i);

    if (outString.size() > 1)
    {
        std::cout << "Pi: " + outString.substr(0, 1) + "." + outString.substr(1) + "   Total bounces: " + std::to_string(i) + "\n";
    }
    else
    {
        std::cout << "Pi: " + outString + "   Total bounces: " + std::to_string(i) + "\n";
    }

    std::cout << "Finished in " + std::to_string(elapsed.count()*1000) + "ms (Time may be heavily impacted by showing working)" + "\n";

    //Console.WriteLine("Finished in " + stopwatch.ElapsedMilliseconds + "ms (Time may be heavily impacted by showing working)");

    std::cin.get();
}
