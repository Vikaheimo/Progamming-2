#include "account.hh"
#include <iostream>

Account::Account(const std::string& owner, bool has_credit):
    owner_(owner), saldo_(0){
    generate_iban();
    if (has_credit){
        credit_limit_ = 0;
    } else{
        credit_limit_ = -1;
    }
}


// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}
void Account::print() const{
    std::cout << owner_ << " : " << iban_ << " : " << saldo_ << std::endl;
}

void Account::set_credit_limit(int new_limit){
    if (credit_limit_ == -1){
        std::cout << "Cannot set credit limit: the account has no credit card" << std::endl;
    } else {
        credit_limit_ = new_limit;
    }
}

void Account::save_money(int money_amount){
    saldo_ += money_amount;
}

bool Account::take_money(int money_amount){
    if (saldo_ >= money_amount){
        saldo_ -= money_amount;
        std::cout << money_amount << " euros taken: new balance of " << iban_ << " is "<< saldo_ <<" euros" << std::endl;
        return true;

    } else if (saldo_ + credit_limit_ >= money_amount ){
        saldo_ -= money_amount;
        std::cout << money_amount << " euros taken: new balance of " << iban_ << " is "<< saldo_ <<" euros" << std::endl;
        return true;

    } else if  (credit_limit_ == -1){
        std::cout << "Cannot take money: balance underflow" << std::endl;
        return false;

    } else{
        std::cout << "Cannot take money: credit limit overflow" << std::endl;
        return false;

    }
}
void Account::transfer_to(Account& target, int money_amount){
    if (take_money(money_amount)){
        target.save_money(money_amount);
    } else {
        std::cout << "Transfer from " << iban_ << " failed" << std::endl;
    }
}
