#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City
{
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tours
{
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours{"Tours Ticket Prices from Miami",
                {
                    {
                        "Colombia",
                        {{"Bogota", 8778000, 400.98},
                         {"Cali", 2401000, 424.12},
                         {"Medellin", 2464000, 350.98},
                         {"Cartagena", 972000, 345.34}},
                    },
                    {
                        "Brazil",
                        {{"Rio De Janiero", 13500000, 567.45},
                         {"Sao Paulo", 11310000, 975.45},
                         {"Salvador", 18234000, 855.99}},
                    },
                    {
                        "Chile",
                        {{"Valdivia", 260000, 560.12},
                         {"Santiago", 7040000, 520.00}},
                    },
                    {
                        "Argentina",
                        {{"Buenos Aires", 3010000, 723.77}},
                    },
                }

    };


    const int table_width{70};
    const int country_column_width{20};
    const int city_column_width{20};
    const int population_column_width{15};
    const int cost_column_width{15};
    int title_length = tours.title.length();


    std::cout << std::setw((table_width - title_length) / 2) << "" << std::right << tours.title << std::endl << std::endl;
    std::cout << std::setw(country_column_width) << std::left << "Country"
              << std::setw(city_column_width) << std::left << "City"
              << std::setw(population_column_width) << std::right << "Population"
              << std::setw(cost_column_width) << std::right << "Price"
              << std::endl;
    std::cout << std::setw(table_width) << std::setfill('-') << ""
              << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setprecision(2) << std::fixed;
    for(const auto &country: tours.countries) {
        for(size_t i{}; i < country.cities.size(); i++) {
            std::cout << std::setw(country_column_width) << std::left << ((i == 0) ? country.name : "");
            std::cout << std::setw(city_column_width) << std::left << country.cities.at(i).name
                      << std::setw(population_column_width) << std::right << country.cities.at(i).population
                      << std::setw(cost_column_width) << std::right << country.cities.at(i).cost
                      << std::endl;
        }
    }
    return 0;
}
