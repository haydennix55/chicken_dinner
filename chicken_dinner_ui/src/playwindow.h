#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include <Blackjack.h>
#include <cmath>

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = 0, int decks = 6);
    ~PlayWindow();
    QList<QPixmap> cardHolder;
    int deckValues[52];

    Player get_player_() { return player_; }
    Dealer get_dealer_() { return dealer_; }
    Deck get_deck_() { return deck_; }
    Deck get_discard_() { return discard_; }
    float get_true_count_() { return true_count_; }

    void UpdateTrueCount(Card* c);


public slots:
    void loadList();

private slots:

    void on_actionQuit_triggered();

    void on_dealButton_released();

    void on_stayButton_released();

    void on_hitButton_released();

    void on_doubleButton_released();

    void on_hintButton_pressed();

    void on_hintButton_released();

private:
    Ui::PlayWindow *ui;
    Player player_;
    Dealer dealer_;
    Deck deck_;
    Deck discard_;
    int num_of_decks_;
    float count_;
    float true_count_;

    void deal_(Person *p);
    void burn_();
    void DisplayPlayer();
    void DisplayDealerShown();
    void DisplayDealer();
    void ResetDeck();
    void SetupRound();
    int DetermineImageIndex(Value v, Suit s);
    void ShowCard(int index, int label);
    void ShowCardDealer(int index, int label);
    void DoTurn(Action choice);
    void DealerTurn();
    void AssessResults();
    void Clear();

protected:
};



#endif // PLAYWINDOW_H
