#include "playwindow.h"
#include "ui_playwindow.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <QDebug>
#include <QList>
#include <map>
#include <Blackjack.h>
#include <cmath>
#include <QString>

PlayWindow::PlayWindow(QWidget *parent, int decks) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow),
    deck_(Deck(decks)),
    discard_(Deck(0)),
    num_of_decks_(decks)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/blackjack_table.png");
    ui->tableLabel->setPixmap(pix);
    ui->tableLabel->lower();
    ui->chipsLabel->setStyleSheet("QLabel {color : white; }");
    ui->betLabel->setStyleSheet("QLabel {color : white; }");
    ui->chipsDisplay->setStyleSheet("QLabel {color : white; }");
    ui->betDisplay->setStyleSheet("QLabel {color : white; }");
    ui->hintLabel->setStyleSheet("QLabel {color : white; }");
    ui->chipsDisplay->setText(QString::number(player_.get_chips_()));
    ui->betDisplay->setText(QString::number(player_.get_bet_()));
    this->statusBar()->setSizeGripEnabled(false);
    this->setFixedSize(690,500);
    loadList();
    deck_.Shuffle();
    burn_();
    ui->stayButton->setEnabled(false);
    ui->hitButton->setEnabled(false);
    ui->doubleButton->setEnabled(false);
    ui->hintButton->setEnabled(false);
}

/**
 * Determines the index in the list of card images that corresponds for a given card
 * @param v is the value of the needed card
 * @param s is the suit of the needed card
 * @return index in cardHolder of needed card
 */
int PlayWindow::DetermineImageIndex(Value v, Suit s) {
    int suit_index;
    int value_index;

    switch (s) {
    case  Suit::Spades : suit_index = 0;
        break;
    case Suit::Hearts : suit_index = 1;
        break;
    case Suit::Clubs : suit_index = 2;
        break;
    case Suit::Diamonds : suit_index = 3;
        break;
    default:
        break;
    }

    switch(v) {

    case Value::A : value_index = 0;
        break;
    case Value::Two : value_index = 1;
        break;
    case Value::Three : value_index = 2;
        break;
    case Value::Four : value_index = 3;
        break;
    case Value::Five : value_index = 4;
        break;
    case Value::Six : value_index = 5;
        break;
    case Value::Seven : value_index = 6;
        break;
    case Value::Eight : value_index = 7;
        break;
    case Value::Nine : value_index = 8;
        break;
    case Value::Ten : value_index = 9;
        break;
    case Value::J : value_index = 10;
        break;
    case Value::Q : value_index = 11;
        break;
    case Value::K : value_index = 12;
        break;
    }

    return ((suit_index * 13) + value_index);
}

/**
 * @brief Display the card png to the gui interface (players only)
 * @param index is the position in cardHolder of the card to display
 * @param label is the position on the screen to place the card
 */
void PlayWindow::ShowCard(int index, int label) {
    switch (label) {

        case 0: ui->card0Label->setPixmap(cardHolder.at(index));
                break;
        case 1: ui->card1Label->setPixmap(cardHolder.at(index));
                break;
        case 2: ui->card2Label->setPixmap(cardHolder.at(index));
                break;
        case 3: ui->card3Label->setPixmap(cardHolder.at(index));
                break;
        case 4: ui->card4Label->setPixmap(cardHolder.at(index));
                break;
        case 5: ui->card5Label->setPixmap(cardHolder.at(index));
                break;
        case 6: ui->card6Label->setPixmap(cardHolder.at(index));
                break;
        case 7: ui->card7Label->setPixmap(cardHolder.at(index));
                break;
        case 8: ui->card8Label->setPixmap(cardHolder.at(index));
                break;
        default : ui->card9Label->setPixmap(cardHolder.at(index));
                break;
    }
}

/**
 * @brief Display the card png to the gui interface (dealers only)
 * @param index is the position in cardHolder of the card to display
 * @param label is the position on the screen to place the card
 */
void PlayWindow::ShowCardDealer(int index, int label) {
    switch (label) {

        case 0: ui->card0Label_2->setPixmap(cardHolder.at(index));
                break;
        case 1: ui->card1Label_2->setPixmap(cardHolder.at(index));
                break;
        case 2: ui->card2Label_2->setPixmap(cardHolder.at(index));
                break;
        case 3: ui->card3Label_2->setPixmap(cardHolder.at(index));
                break;
        case 4: ui->card4Label_2->setPixmap(cardHolder.at(index));
                break;
        case 5: ui->card5Label_2->setPixmap(cardHolder.at(index));
                break;
        case 6: ui->card6Label_2->setPixmap(cardHolder.at(index));
                break;
        case 7: ui->card7Label_2->setPixmap(cardHolder.at(index));
                break;
        case 8: ui->card8Label_2->setPixmap(cardHolder.at(index));
                break;
        default : ui->card9Label_2->setPixmap(cardHolder.at(index));
                break;
    }
}

//Draw card from deck_ and add to Person's hand
void PlayWindow::deal_(Person *p) {
    Card *c = deck_.Draw();
    UpdateTrueCount(c);
    p->AddToHand(c);
}

//Draw a card from the deck and add it to the discard pile
void PlayWindow::burn_() {
    discard_.AddToDeck(deck_.Draw());
}

//Resets the game after a round
void PlayWindow::Clear() {
    std::vector<Card*> player_hand = player_.get_hand_();
    std::vector<Card*> dealer_hand = dealer_.get_hand_();

    //move players hand to discard
    for (int i = 0; i < player_hand.size(); i++) {
        discard_.AddToDeck(player_hand[i]);
    }

    //move dealers hand to discard
    for (int i = 0; i < dealer_hand.size(); i++) {
        discard_.AddToDeck(dealer_hand[i]);
    }

    //clear last rounds data
    player_.ClearHand();
    dealer_.ClearHand();
    player_.Bet(0);

    //These were used to ensure the deck was decrementing corrently, and that it resets properly
    // std::cout << "Deck size: " << deck_.size() << std::endl;
    // std::cout << "Discard size: " << discard_.size() << std::endl;
    std::cout << "Player Chips: " << player_.get_chips_() << std::endl;
    std::cout << std::endl << "----------------------------" << std::endl;

    ui->dealButton->setEnabled(true);

}

//Replaces all discarded cards to deck
void PlayWindow::ResetDeck() {
    for (int i = 0; i < discard_.size(); i++) {
      deck_.AddToDeck(discard_.get_card(i));
    }
    discard_.ClearDeck();
    deck_.Shuffle();
    burn_();
    count_ = 0;
    true_count_ = 0;
}

//Displays players hand in card pngs to the screen
void PlayWindow::DisplayPlayer() {
    Value v;
    Suit s;
    int imageIndex;
    std::cout << std::endl << "Player's hand:\n--------" << std::endl << std::endl;
    for (int i = 0; i < player_.get_hand_().size(); i++) {
        v = player_.get_hand_()[i]->get_val();
        s = player_.get_hand_()[i]->get_suit();
        std::cout << "  -  " << ValueStringify(v) << " of " << SuitStringify(s) << std::endl;
        int imageIndex = DetermineImageIndex(v,s);
        ShowCard(imageIndex, i);
    }
    std::cout << std::endl;
}

//Displays dealers full hand in card pngs to the screen
void PlayWindow::DisplayDealer() {
    //this is a placeholder for now for the UI
    Value v;
    Suit s;
    int imageIndex;
    std::cout << std::endl << "Dealer's hand:\n--------" << std::endl << std::endl;
    for (int i = 0; i < dealer_.get_hand_().size(); i++) {
        v = dealer_.get_hand_()[i]->get_val();
        s = dealer_.get_hand_()[i]->get_suit();
        std::cout << "  -  " << ValueStringify(v) << " of " << SuitStringify(s) << std::endl;
        int imageIndex = DetermineImageIndex(v,s);
        ShowCardDealer(imageIndex, i);
    }
    std::cout << std::endl;
}

//Displays dealers face up and face down card in card pngs
void PlayWindow::DisplayDealerShown() {
  std::cout << std::endl << "Dealer's showing card:\n--------" << std::endl << std::endl;
  std::cout << "  -  " << ValueStringify(dealer_.get_hand_()[0]->get_val()) << " of " << SuitStringify(dealer_.get_hand_()[0]->get_suit()) << std::endl << std::endl;
  ShowCardDealer(DetermineImageIndex(dealer_.get_hand_()[0]->get_val(), dealer_.get_hand_()[0]->get_suit()),0);
  ShowCardDealer(52,1);
}

//Initialize the bet, the intial deal, and ensure the deck is properly stocked
void PlayWindow::SetupRound() {
    //ensure card pngs from previous game are cleared
    ui->card0Label->clear();
    ui->card1Label->clear();
    ui->card2Label->clear();
    ui->card3Label->clear();
    ui->card4Label->clear();
    ui->card5Label->clear();
    ui->card6Label->clear();
    ui->card7Label->clear();
    ui->card8Label->clear();
    ui->card9Label->clear();

    ui->card0Label_2->clear();
    ui->card1Label_2->clear();
    ui->card2Label_2->clear();
    ui->card3Label_2->clear();
    ui->card4Label_2->clear();
    ui->card5Label_2->clear();
    ui->card6Label_2->clear();
    ui->card7Label_2->clear();
    ui->card8Label_2->clear();
    ui->card9Label_2->clear();
    ui->resultLabel->clear();

    //If 4/5s of the deck has been player. This is an approximation of normal shuffling. This may be
    //replaces with a semi-random shuffle card (usually, the dealer inserts it toward the bottom)
    if (deck_.size() < (discard_.size() / 4)) {
      ResetDeck();
    }

    player_.Bet(10);

    std::cout << "Player's bet: " << player_.get_bet_() << std::endl;

    //Deal hands alternating to player and dealer
    deal_(&player_);
    deal_(&dealer_);

    deal_(&player_);
    deal_(&dealer_);

    //Show player hand and dealer face up card
    DisplayPlayer();
    DisplayDealerShown();

    //show current bet and chips
    ui->chipsDisplay->setText(QString::number(player_.get_chips_()));
    ui->betDisplay->setText(QString::number(player_.get_bet_()));

}

/**
 * @brief Updates the true count value of the game using the Zen count methodology
 * @param c is the last drawn card, used to update the count and therefore, the true count
 */
void PlayWindow::UpdateTrueCount(Card* c) {
    switch (ValueIntify(c->get_val())) {
        case 2:
        case 3:
        case 7: count_++;
                break;
        case 4:
        case 5:
        case 6: count_ += 2;
                break;
        case 11: count_ -= 1;
                break;
        case 10: count_ -= 2;
                break;
        default:
                break;
    }

    float remaining_decks = ((float)deck_.size() / (num_of_decks_ * 52)) * num_of_decks_;

    remaining_decks = round(remaining_decks * 2) / 2;

    true_count_ = count_ / remaining_decks;

}

/**
 * @brief Handles dealing, additional betting, etc. for new moves
 * @param choice - the chosen action on a given turn
 */
void PlayWindow::DoTurn(Action choice) {

    if (choice == Action::Stay) {

        std::cout << "\nYou chose to stay.\n" ;
        return;

    } else if (choice == Action::Hit) {
        //add card to hand and display new hand
        std::cout << "\nYou chose to hit. Here's your new hand.\n" ;
        deal_(&player_);
        DisplayPlayer();
        DisplayDealerShown();
        return;

    } else if (choice == Action::Double) {
        //Double the bet, add a one and only one card to hand, show new hand
        std::cout << "\nYou double. Here's your new hand.\n" ;
        player_.Payout(player_.get_bet_());
        player_.Bet(player_.get_bet_() * 2);
        deal_(&player_);
        DisplayPlayer();
        DisplayDealerShown();
        return;

    } else {
        //split. This currently isn't implemented and will never occur (see MakeChoice)
        std::cout << "You split" << std::endl;
        return;
    }
}

//Dealer continutes to hit until they have 17 (must hit on soft 17)
void PlayWindow::DealerTurn() {
    while (true) {
        DisplayDealer();
        if (dealer_.HandVal() == 0 || dealer_.HandVal() > 17) {
            break;
        } else if (dealer_.HandVal() == 17 && !dealer_.HasSoftAce()){
            break;
        } else {
            // dealer has less than 17 or a soft 17
            deal_(&dealer_);
        }
    }
}

//Determine Payouts and finalize ui
void PlayWindow::AssessResults() {

    QPixmap win(":/images/images/win.png");
    QPixmap lose(":/images/images/lose.png");
    QPixmap push(":/images/images/push.png");

    //disable action buttons
    ui->hitButton->setEnabled(false);
    ui->doubleButton->setEnabled(false);
    ui->stayButton->setEnabled(false);
    ui->hintButton->setEnabled(false);

    int dealer_score = dealer_.HandVal();
    int player_score = player_.HandVal();
    int bet = player_.get_bet_();

    //Blackjack, pays 3/2
    if (player_score == 21 && dealer_score != 21) {
        if (player_.get_hand_().size() == 2) {
            player_.Payout(bet * 2.5);
            std::cout << "WINNER WINNER CHICKEN DINNER!" << std::endl;
            this->ui->resultLabel->setPixmap(win);
            return;
        }
    }
    if (player_score == 0) {
        std::cout << "You busted..." << std::endl;
        this->ui->resultLabel->setPixmap(lose);
    } else {
        if (player_score > dealer_score) { //win
            std::cout << "You win." << std::endl;
            this->ui->resultLabel->setPixmap(win);
            player_.Payout(bet * 2);
        } else if (player_score == dealer_score) { //tie
            std::cout << "Its a Push." << std::endl;
            this->ui->resultLabel->setPixmap(push);
            player_.Payout(bet);
        } else {  //loss
            if (dealer_score == 21 && dealer_.get_hand_().size() == 2){
                std::cout << "Dealer has Blackjack!" << std::endl;
            }
            std::cout << "You lose." << std::endl;
            this->ui->resultLabel->setPixmap(lose);
            //Because the dealer does not currently keep track of chips,
            //no action is required. (Withdrawn from player when bet)
        }
    }
}

//Create 'cardHolder' of pngs of all the cards
void PlayWindow::loadList(){

    // Clear List
    cardHolder.clear();

    QPixmap card1(":/images/images/cards/ace_of_spades.png");
    QPixmap card2(":/images/images/cards/2_of_spades.png");
    QPixmap card3(":/images/images/cards/3_of_spades.png");
    QPixmap card4(":/images/images/cards/4_of_spades.png");
    QPixmap card5(":/images/images/cards/5_of_spades.png");
    QPixmap card6(":/images/images/cards/6_of_spades.png");
    QPixmap card7(":/images/images/cards/7_of_spades.png");
    QPixmap card8(":/images/images/cards/8_of_spades.png");
    QPixmap card9(":/images/images/cards/9_of_spades.png");
    QPixmap card10(":/images/images/cards/10_of_spades.png");
    QPixmap card11(":/images/images/cards/jack_of_spades2.png");
    QPixmap card12(":/images/images/cards/queen_of_spades2.png");
    QPixmap card13(":/images/images/cards/king_of_spades2.png");

    QPixmap card14(":/images/images/cards/ace_of_hearts.png");
    QPixmap card15(":/images/images/cards/2_of_hearts.png");
    QPixmap card16(":/images/images/cards/3_of_hearts.png");
    QPixmap card17(":/images/images/cards/4_of_hearts.png");
    QPixmap card18(":/images/images/cards/5_of_hearts.png");;
    QPixmap card19(":/images/images/cards/6_of_hearts.png");
    QPixmap card20(":/images/images/cards/7_of_hearts.png");
    QPixmap card21(":/images/images/cards/8_of_hearts.png");
    QPixmap card22(":/images/images/cards/9_of_hearts.png");
    QPixmap card23(":/images/images/cards/10_of_hearts.png");
    QPixmap card24(":/images/images/cards/jack_of_hearts2.png");
    QPixmap card25(":/images/images/cards/queen_of_hearts2.png");
    QPixmap card26(":/images/images/cards/king_of_hearts2.png");

    QPixmap card27(":/images/images/cards/ace_of_clubs.png");
    QPixmap card28(":/images/images/cards/2_of_clubs.png");
    QPixmap card29(":/images/images/cards/3_of_clubs.png");
    QPixmap card30(":/images/images/cards/4_of_clubs.png");
    QPixmap card31(":/images/images/cards/5_of_clubs.png");
    QPixmap card32(":/images/images/cards/6_of_clubs.png");
    QPixmap card33(":/images/images/cards/7_of_clubs.png");
    QPixmap card34(":/images/images/cards/8_of_clubs.png");
    QPixmap card35(":/images/images/cards/9_of_clubs.png");
    QPixmap card36(":/images/images/cards/10_of_clubs.png");
    QPixmap card37(":/images/images/cards/jack_of_clubs2.png");
    QPixmap card38(":/images/images/cards/queen_of_clubs2.png");
    QPixmap card39(":/images/images/cards/king_of_clubs2.png");

    QPixmap card40(":/images/images/cards/ace_of_diamonds.png");
    QPixmap card41(":/images/images/cards/2_of_diamonds.png");
    QPixmap card42(":/images/images/cards/3_of_diamonds.png");
    QPixmap card43(":/images/images/cards/4_of_diamonds.png");
    QPixmap card44(":/images/images/cards/5_of_diamonds.png");
    QPixmap card45(":/images/images/cards/6_of_diamonds.png");
    QPixmap card46(":/images/images/cards/7_of_diamonds.png");
    QPixmap card47(":/images/images/cards/8_of_diamonds.png");
    QPixmap card48(":/images/images/cards/9_of_diamonds.png");
    QPixmap card49(":/images/images/cards/10_of_diamonds.png");
    QPixmap card50(":/images/images/cards/jack_of_diamonds2.png");
    QPixmap card51(":/images/images/cards/queen_of_diamonds2.png");
    QPixmap card52(":/images/images/cards/king_of_diamonds2.png");
    QPixmap card53(":/images/images/cards/back.png");

    cardHolder.append(card1);
    cardHolder.append(card2);
    cardHolder.append(card3);
    cardHolder.append(card4);
    cardHolder.append(card5);
    cardHolder.append(card6);
    cardHolder.append(card7);
    cardHolder.append(card8);
    cardHolder.append(card9);
    cardHolder.append(card10);
    cardHolder.append(card11);
    cardHolder.append(card12);
    cardHolder.append(card13);

    cardHolder.append(card14);
    cardHolder.append(card15);
    cardHolder.append(card16);
    cardHolder.append(card17);
    cardHolder.append(card18);
    cardHolder.append(card19);
    cardHolder.append(card20);
    cardHolder.append(card21);
    cardHolder.append(card22);
    cardHolder.append(card23);
    cardHolder.append(card24);
    cardHolder.append(card25);
    cardHolder.append(card26);

    cardHolder.append(card27);
    cardHolder.append(card28);
    cardHolder.append(card29);
    cardHolder.append(card30);
    cardHolder.append(card31);
    cardHolder.append(card32);
    cardHolder.append(card33);
    cardHolder.append(card34);
    cardHolder.append(card35);
    cardHolder.append(card36);
    cardHolder.append(card37);
    cardHolder.append(card38);
    cardHolder.append(card39);

    cardHolder.append(card40);
    cardHolder.append(card41);
    cardHolder.append(card42);
    cardHolder.append(card43);
    cardHolder.append(card44);
    cardHolder.append(card45);
    cardHolder.append(card46);
    cardHolder.append(card47);
    cardHolder.append(card48);
    cardHolder.append(card49);
    cardHolder.append(card50);
    cardHolder.append(card51);
    cardHolder.append(card52);

    cardHolder.append(card53);

}


PlayWindow::~PlayWindow()
{
    delete ui;
}


//SLOTS

void PlayWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

//Set up round and check for blackjacks
void PlayWindow::on_dealButton_released()
{
    SetupRound();

    //Either dealer, player, or both have blackjack, so round ends
    if (player_.HandVal() == 21 || dealer_.HandVal() == 21) {
        //TODO: handle insurance if dealer has blackjack
        DisplayDealer();
        AssessResults();
        Clear();
        return;
    }

    ui->hitButton->setEnabled(true);
    ui->doubleButton->setEnabled(true);
    ui->stayButton->setEnabled(true);
    ui->hintButton->setEnabled(true);
    ui->dealButton->setEnabled(false);
}

//Move on to dealers turn and reset game
void PlayWindow::on_stayButton_released()
{
    DealerTurn();
    AssessResults();
    Clear();
    ui->chipsDisplay->setText(QString::number(player_.get_chips_()));
    ui->betDisplay->setText(QString::number(player_.get_bet_()));
}

//Add card, if busted, reset game
void PlayWindow::on_hitButton_released()
{
    DoTurn(Action::Hit);
    if (player_.HandVal() == 0) {
        DisplayDealer();
        AssessResults();
        Clear();
        ui->chipsDisplay->setText(QString::number(player_.get_chips_()));
        ui->betDisplay->setText(QString::number(player_.get_bet_()));

    }
    //disabling double, as you can only double on a two card hand
    ui->doubleButton->setEnabled(false);
}

//Add one card, then move on to dealer turn
void PlayWindow::on_doubleButton_released()
{
    DoTurn(Action::Double);
    DealerTurn();
    AssessResults();
    Clear();
    ui->chipsDisplay->setText(QString::number(player_.get_chips_()));
    ui->betDisplay->setText(QString::number(player_.get_bet_()));

}

//Basic Strategy suggestion appears when holding down hint button
void PlayWindow::on_hintButton_pressed()
{
    std::string a = "Basic strategy would say to " + ActionStringify(player_.BasicStrategy(dealer_.get_hand_()[0]));
    ui->hintLabel->setText(QString::fromStdString(a));
}

//Basic Strategy suggestion disappears when hint button is released
void PlayWindow::on_hintButton_released()
{
     ui->hintLabel->setText(QString::fromStdString(""));
}
