#include "cards.hh"


Cards::Cards(): top_(nullptr) {
}

Card_data *Cards::get_topmost()
{
    return top_;
}

void Cards::add(int id)
{
    Card_data* new_card = new Card_data{id, nullptr};
    new_card->next = top_;
    top_ = new_card;



}

void Cards::print_from_top_to_bottom(std::ostream &s)
{
    Card_data* current_card = top_;
    int i = 1;
    while(current_card != nullptr){
        s << i << ": " << current_card->data << std::endl;
        current_card = current_card->next;
        i += 1;
    }
}

bool Cards::remove(int &id)
{
    if (top_ == nullptr){
        return false;
    } else {
        id = top_->data;
        Card_data* item_to_delete = top_;
        top_ = top_->next;
        delete item_to_delete;
        return true;
    }
}

bool Cards::bottom_to_top()
{
    if(top_ == nullptr){
        return false;
    } else if (top_->next == nullptr){
        return true;
    }else {
        Card_data *last = top_;
        Card_data *second_last = top_;
        while (last->next != nullptr) {
            second_last = last;
            last = last->next;
        }
        second_last->next = nullptr;
        last->next = top_;
        top_ = last;
        return true;
    }
}

bool Cards::top_to_bottom()
{
    if(top_ == nullptr){
        return false;
    } else if (top_->next == nullptr){
        return true;
    } else {
        Card_data *last = top_;
        Card_data *new_bottom = top_;
        top_ = top_->next;

        while(last->next !=nullptr){
            last = last->next;
        }
        last->next = new_bottom;
        new_bottom->next = nullptr;
        return true;
    }
}

void Cards::print_from_bottom_to_top(std::ostream &s)
{
    recursive_print(top_, s);
}

Cards::~Cards()
{
    Card_data *temp = top_;
    while (top_ != nullptr) {
        top_ = top_->next;
        delete temp;
        temp = top_;
    }
}

int Cards::recursive_print(Card_data *top, std::ostream &s)
{
    int i = 1;
    if (top->next != nullptr){
        i += recursive_print(top->next, s);
    }
    s << i << ": " << top->data << std::endl;
    return i;
}

