#include "Table.hpp"

Table::Table(int number):
    philosophersNumber(number), forks(number) {

    for(int i = 0; i < number-1; i++){
      std::string name = "F" + std::to_string(i+1);
          Philosopher newPhilosopher {name, forks[i], forks[i+1]};
        philosophers.emplace_back(std::move(newPhilosopher));
    }
    std::string name = "F" + std::to_string(number);
    Philosopher lastPhilosopher  {name, forks[number-1], forks[0]};
    philosophers.emplace_back(std::move(lastPhilosopher));

    for(auto& elem: philosophers)
        elem.startThread();
}

void Table::showTable(){
    std::string tableView("\n");
    
    for(auto& elem: philosophers){
        if(elem.getHaveForks() == true)
            tableView += "-" + elem.getPhilosopherName() + "-";
        else tableView += " " + elem.getPhilosopherName() + " ";
    }
    
    tableView += '\n';
    
    std::stringstream ssTableView;
    ssTableView << tableView;
    std::cout << ssTableView.str();
}

bool Table::stopEating(){
    bool checker = true;
    auto it = philosophers.begin();
    
    do{
        if(it->getHaveForks() == true)
            checker = false;
    }while(checker and ++it != philosophers.end());
    
    return checker;
}
