#include "Inventory.h"

#include <iostream>
#include "helper.h"
#include <iomanip>

using std::string;
using std::vector;

Inventory::Inventory() {
    items = *new LinkedList();

}

Inventory::~Inventory() {
    // TODO
}

bool Inventory::LoadItems(string file_name){
        std::ifstream stock_file(file_name);
        if (!stock_file)
        {
            std::cout << file_name << " : " << "file error" << std::endl;
            return false;
        }


        std::string line;
        while (std::getline(stock_file, line))
        { 
    
            std::vector<std::string> tokens = {};
            Helper::splitString(line, tokens, "|");

            if (tokens.size() == 5){
                if (!this->AddItem(tokens)){
                    std::cout << file_name << " : " << "could not insert" << std::endl;
                }
            }else{
                std::cout << file_name << " : " << "tokens.size() != 5" << std::endl;
            }

        }

        return true;
}

bool Inventory::AddItem(std::vector<std::string> data){

    std::vector<std::string> price_tokens = {};
    Helper::splitString(data[3], price_tokens, ".");

    if (price_tokens.size() != 2){
        std::cout << "Price Error" << std::endl;
        return false;
    }

    Price price = *(new Price());
    price.dollars = std::stoi(price_tokens[0]);
    price.cents = std::stoi(price_tokens[1]);


    Stock *new_stock = new Stock();
    new_stock->id = data[0];
    new_stock->name = data[1];
    new_stock->description = data[2];
    new_stock->on_hand = std::stoi(data[4]);
    new_stock->price = price;

    items.Insert(new_stock);

    return true;

}





