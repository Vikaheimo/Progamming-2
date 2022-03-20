#include "cards.hh"


Cards::Cards(): top_(nullptr), bottom_(nullptr) {
}

void Cards::add(int id)
{
    Card_data* new_card = new Card_data{id, nullptr};
    if (top_ == nullptr){
        top_ = new_card;
        bottom_ = new_card;
    } else {
        bottom_->next = new_card;
        bottom_ = new_card;
    }


}

void Cards::print_from_top_to_bottom(std::ostream &s)
{

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

}

bool Cards::top_to_bottom()
{

}

void Cards::print_from_bottom_to_top(std::ostream &s)
{

}

Cards::~Cards()
{

}

int Cards::recursive_print(Card_data *top, std::ostream &s)
{

}

